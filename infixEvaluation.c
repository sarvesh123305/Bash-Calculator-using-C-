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

int isCharacter(char ch){
   return (ch >= 'a' && ch <= 'z' )|| (ch >= 'A' && ch <= 'Z');
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

int getAndReturnSignsOfNumber(Node* a,Node* b){
    int sign = 0;
        if((a -> sign == '+' && b -> sign == '+')  ){     
            sign = 1;
            }               
        else if((a -> sign == '-' && b -> sign == '+') || (a -> sign == '+' && b -> sign == '-'))
        {
              sign = 2;
        }
        else{
            sign = -1;
        }   
        return sign;
}

int isOperator(char ch){
     return ((ch == '+' || ch == '-' || ch == '/' || ch == '*' || ch == '(' || ch == ')'));
}
Node* applyOp(Node* a, Node* b, char op){
    List result;
    initList(&result);  
        int detectOp = getAndReturnSignsOfNumber(a,b);
    switch(op){
        case '+': 
                if(detectOp == 1){
                    result = addTwoLinkedLists(a,b);
                    result -> sign = '+';
                }
                else if(detectOp == 2){
                    result = subtractTwoLinkedLists(a,b);
                }
                else{
                    result = addTwoLinkedLists(a,b);
                            result -> sign = '-';
                }
                break;

       
        case '-': 
                if(detectOp == 1){
                    result = subtractTwoLinkedLists(a,b);
                }
                else if(detectOp == 2){
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
                if(detectOp == 2){
                            result -> sign = '-';
                }
                else{
                    result -> sign = '+';
                }
                break;
                    
                case '/': 
                    result =  divideOptimizedTwoLinkedLists(a,b);
                        if(detectOp == 2){
                            result -> sign = '-';
                        }
                        else{
                            result -> sign = '+';
                        }
                break;
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
        if(isOperator(str[i]))
        count1++;
        count++;
    }

    int n = count1;
    initStackN(&nStack);
    initStackC(&cStack,n);
    for(int i = 0 ; i < count+1; i++){
        char ch = str[i];
        int num = ch - '0';

        if(ch == ' ')
        continue;

        if(ch == '('){

            if(l1){
                pushN(&nStack,l1);
                initList(&l1);
            }

            pushC(&cStack,'(');
        }
        
        else if(isNumber(ch)){
            append(&l1,num);
        }

        else if(ch == ')'){

            if(l1){
                pushN(&nStack,l1);
                initList(&l1);
            }

            while(!isEmptyC(cStack) && topC(cStack) != '(')
              {
                 if(getSizeOfStackN(nStack) < 2)
                {
                    printf("Invalid Operands");
                    exit(0);
                }

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
                pushN(&nStack,l1);
                initList(&l1);
            }

            while(topC(cStack) != ' ' && precedence(topC(cStack)) >= precedence(ch)){
                if(getSizeOfStackN(nStack) < 2)
                {
                    printf("Invalid Operands");
                    exit(0);
                }

                Node* b = popN(&nStack);
                Node* a = popN(&nStack);

                char ch = popC(&cStack);
                pushN(&nStack,applyOp(a,b,ch));
            }
            pushC(&cStack,ch);
        }
    }
    displayN(nStack);

}