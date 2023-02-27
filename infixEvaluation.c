#include<stdio.h>
#include "characterStack/stack.h"
#include "numberStack/stack.h"
#include "multiplication.h"
#include "divisionOptimized.h"
#include<stdlib.h>
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

Node* applyOp(Node* a, Node* b, char op){
    List result;
    initList(&result);  
    switch(op){
        case '+': 
         if((a -> sign == '+' && b -> sign == '+')  ){     
                    result = addTwoLinkedLists(a,b);
                    result -> sign = '+';
                 }               
                else if((a -> sign == '-' && b -> sign == '+') || (a -> sign == '+' && b -> sign == '-'))
                {
                    result = subtractTwoLinkedLists(a,b);
                }
                else{
                    result = addTwoLinkedLists(a,b);
                    result -> sign = '-';
                }   
                break;
        case '-': 
         if(a -> sign == '+' && b -> sign == '+'){
                    result = subtractTwoLinkedLists(a,b);
                 }               
                else if((a -> sign == '-' && b -> sign == '+') || (a -> sign == '+' && b -> sign == '-'))
                {
                    //-10 - 12
                    //10 - - 12
                    if( a -> sign == '-'){
                        result = addTwoLinkedLists(a,b);
                        result -> sign = '-';
                    }
                    else{
                        result = addTwoLinkedLists(a,b);
                        result -> sign = '+';
                    }
                }
                else{
                    result = addTwoLinkedLists(a,b);
                    result -> sign = '-';
                }
                break;
        case '*': 
        result = multiply(a,b); 
                if(a -> sign == '+' && b -> sign == '+'){
                    result -> sign = '+';
                }else if(a -> sign == '-' && b -> sign == '+' || a -> sign == '+' && b -> sign == '-')
                {
                    result -> sign = '-';
                }
                 else{
                    result -> sign = '+';
                }
                break;
        case '/': 
               result =  divideOptimizedTwoLinkedLists(a,b);
               if((a -> sign == '-' && b -> sign  == '+' ) || (a -> sign == '+' && b -> sign == '-')){
                    result -> sign = '-';
               }
               else{
                result -> sign = '+';   
                }
    }
}
void infixEvaluation(char *str){

    charStack cStack;
    Stack nStack;

    List l1,l2,result;
    initList(&l1);
    initList(&l2);
    initList(&result);
    
    int count = 0 , count1 = 0;
    for(int i = 0 ; str[i] != '\0' ; i++){
        if(str[i] == '+' || str[i] == '-' || str[i] == '/' || str[i] == '*' || str[i] == '(' || str[i] == ')')
        count1++;
        count++;
    }
    int n = count1++;
    initStackN(&nStack);
    initStackC(&cStack,n);
    for(int i = 0 ; i < count+1; i++){
        char ch = str[i];
        int num = ch - '0';
        // printf("%c %d\n",ch,i);
        if(ch == ' ')
        continue;
        if(ch == '('){
            if(l1){
                display(l1);
                pushN(&nStack,l1);
                initList(&l1);
            }
            
            pushC(&cStack,'(');
        }
        
        else if(isNumber(ch)){
        // printf("%c %d\n",ch,i);
        if(l1 && !(l1 -> next)){
                // printf("sa");
            if(!isEmptyC(cStack)){
                l1 -> sign = topC(cStack);
                // printf("sa");
                // display(l1);
            }else{
                l1 -> sign = '+';
            }
        }
            append(&l1,num);
// exit(0);

            // pushN(&nStack,num);
        }
        else if(ch == ')'){
            if(l1){
                // display(l1);

                pushN(&nStack,l1);
                initList(&l1);
            }
            while(!isEmptyC(cStack) && topC(cStack) != '(')
              {
                if(getSizeOfStackN(nStack) < 2)
                break;
                // printf("Size %d",getSizeOfStackN(nStack));
                // exit(0);
                Node* val2 = popN(&nStack);
                 
                Node* val1 = popN(&nStack);
                 
                char op = topC(cStack);
                popC(&cStack);
                 
                pushN(&nStack,applyOp(val1,val2,op));
              }
             
            if(!isEmptyC(cStack))
                popC(&cStack);
        }
        else{
            if(l1){
                // display(l1);
                pushN(&nStack,l1);
                initList(&l1);
            }
            while(topC(cStack) != ' ' && precedence(topC(cStack)) >= precedence(ch)){
                if(getSizeOfStackN(nStack) < 2)
                break;
                Node* b = popN(&nStack);
                Node* a = popN(&nStack);
                // printf("%d %d",b,a);

                char ch = popC(&cStack);
                pushN(&nStack,applyOp(a,b,ch));
            }
            pushC(&cStack,ch);
        }
    }
    displayN(nStack);

    // printf("\nsaraf");
}