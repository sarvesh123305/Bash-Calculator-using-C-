#include<stdio.h>
#include "characterStack/stack.h"
#include "numberStack/stack.h"

int isNumber(char ch){
    int num = ch - '0';
    return (num <= 9 && num>=0);
}

int precedence(char symb){

    if(symb == '(')
    return 0;

    if(symb == '*' || symb == '/')
    return 2;

    if(symb == '+' || symb == '-')
    return 1;

    return 0;

}

int applyOp(Node* a, Node* b, char op){
    switch(op){
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
    }
}
void infixEvaluation(char str[]){

    charStack cStack;
    numberStack nStack;
    initStackN(&nStack,n);
    initStackC(&cStack,n);

    List l1,l2,result;
    initList(&l1);
    initList(&l2);
    initList(&result);

    for(int i = 0 ; str[i] != '\0'; i++){
        char ch = str[i];
        int num = ch - '0';
        // printf("%c %d\n",ch,i);
        // if(ch == ' ')
        // continue;
        if(ch == '('){
            if(l1){
                pushN(&nStack,num);
                initList(&l1);
            }
            
            pushC(&cStack,'(');
        }
        else if(isNumber(ch)){
        // printf("%c %d\n",ch,i);
            append(&l1,num);
            // pushN(&nStack,num);
        }
        else if(ch == ')'){
            if(l1){
                pushN(&nStack,num);
                initList(&l1);
            }
            while(!isEmptyC(cStack) && topC(cStack) != '(')
              {
                Node* val2 = topN(nStack);
                popN(&nStack);
                 
                Node* val1 = topN(nStack);
                popN(&nStack);
                 
                char op = topC(cStack);
                popC(&cStack);
                 
                pushN(&nStack,applyOp(val1,val2,op));
              }
             
            if(!isEmptyC(cStack))
                popC(&cStack);
        }
        else{
            if(l1){
                pushN(&nStack,num);
                initList(&l1);
            }
            while(topC(cStack) != ' ' && precedence(topC(cStack)) > precedence(ch)){
                int b = popN(&nStack);
                int a = popN(&nStack);
                // printf("%d %d",b,a);

                char ch = popC(&cStack);
                pushN(&nStack,applyOp(a,b,ch));
            }
            pushC(&cStack,ch);
        }
    }
    printf("\n");
    displayN(nStack);
}