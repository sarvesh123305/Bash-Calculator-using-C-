#include<stdio.h>
#include "characterStack/stack.h"
#include "numberStack/stack.h"
#include "multiplication.h"
// #include "divisionOptimized.h"
#include "modulus.h"
#include "power.h"

#include<stdlib.h>
int isNumber(char ch){
    int num = ch - '0';
    return (num <= 9 && num>=0);
}


int isOperator(char ch){
     return ((ch == '+' || ch == '-' || ch == '/' || ch == '*' || ch == '(' || ch == ')' || ch == '%' || ch == '^'));
}

int isCharacter(char ch){
   return (ch >= 'a' && ch <= 'z' )|| (ch >= 'A' && ch <= 'Z');
}

int isAnythingOther(char ch){
   return (ch == '.' || ch == ',' || ch == ']' || ch == '['  );
}

int precedence(char symb){

    if(symb == '(')
    return 0;

    if(symb == '^')
    return 3;

    if(symb == '*' || symb == '/' || symb == '%')
    return 2;

    if(symb == '+' || symb == '-')
    return 1;

    return 0;

}

int getAndReturnSignsOfNumber(Number a,Number b){
    int sign = 0;
        if((a.sign == '+' && b.sign == '+')  ){     
            sign = 1;
            }               
        else if((a.sign == '-' && b.sign == '+') || (a.sign == '+' && b.sign == '-'))
        {
              sign = 2;
        }
        else{
            sign = -1;
        }   
        return sign;

}

Number applyOp(Number a, Number b, char op){
    Number result;
    initNumber(&result);  
        int detectOp = getAndReturnSignsOfNumber(a,b);

    switch(op){
        case '+': 

                if(detectOp == 1){
                    result = addTwoLinkedLists(a,b);
                    result.sign = '+';
                }
                else if(detectOp == 2){
                    result = subtractTwoLinkedLists(a,b);
                }
                else{
                    result = addTwoLinkedLists(a,b);
                            result.sign = '-';
                }
                break;
       
        case '-': 
                 if(a.sign == '-' && b.sign == '-'){
                    b.sign = '+';
                    result = subtractTwoLinkedLists(a,b);

                 }
                else if(detectOp == 1){
                    result = subtractTwoLinkedLists(a,b);
                }
                else if(detectOp == 2){
                    if( a.sign == '-'){
                                result = addTwoLinkedLists(a,b);
                                result.sign = '-';
                            }
                            else{
                                result = addTwoLinkedLists(a,b);
                                result.sign = '+';
                            }
                }
              

                else{
                            result = addTwoLinkedLists(a,b);
                            result.sign = '-';
                        }
                break;

        
        case '*': 
                result = multiply(a,b); 
                if(detectOp == 2){
                            result.sign = '-';
                }
                else{
                    result.sign = '+';
                }
                break;
                    
                case '/': 
                    result =  divideOptimizedTwoLinkedLists(a,b);
                        if(detectOp == 2){
                            result.sign = '-';
                        }
                        else{
                            result.sign = '+';
                        }
                break;

         case '%': result = modulusOfTwoLinkedLists(a,b);
                    if(detectOp == 2){
                        result.sign = '-';
                    }
                    else{
                        result.sign = '+';
                    }
                    break;
        case '^' : result = powerOfTwoLinkedLists(a,b);
        
                    break;
    }   
    
    return result;
}
void infixEvaluation(char *str){

    charStack cStack;
    Stack nStack;

    Number l1,l2,result;
    initNumber(&l1);
    initNumber(&l2);
    initNumber(&result);
    
    int count = 0 , count1 = 0;
    for(int i = 0 ; str[i] != '\0' ; i++){
        if(isOperator(str[i]))
        count1++;
        count++;
    }

    int n = count1;
    initStackN(&nStack);
    initStackC(&cStack,n);
    int flag = -1;
    int check = 0 ;
    for(int i = 0 ; i < count+1; i++){
        char ch = str[i];
        int num = ch - '0';

        if(ch == ' ')
        continue;

        if(ch == '('){
           
            if(l1.num){
                pushN(&nStack,l1);
                initNumber(&l1);
            }

            pushC(&cStack,'(');
        }
        
        else if(isNumber(ch)){
          
            append(&l1.num,num);
            
              if(l1.num && !l1.num -> next){
                if(flag == 1){
                    flag = 0;
                    l1.sign = '-';
                }
                else if(check == 2){
                    check = 0;
                    if(l1.sign == '-' )
                    l1.sign = '+';
                    else
                    l1.sign = '-';
                   
                }
             else if(check == 3){
                 check = 0;
                if(l1.sign == '-')
                l1.sign = '-';
                else
                l1.sign = '+';
            }
             else{
                    check = 0;
                }
                
            }

        }

        else if(ch == ')'){

            if(l1.num){
                pushN(&nStack,l1);
                initNumber(&l1);
            }
            if(i == 0 && (ch == '-'|| ch == '+') ){
                if(ch == '-')
                flag = 1;
                continue;
            }
            else if(str[i-1] == '('){
                if(ch == '-' ){
                    check = 2;
                    continue;
                }
                else if( ch == '+'){
                    check = 3;
                    continue;
                }
            }
            while(!isEmptyC(cStack) && topC(cStack) != '(')
              {
                 if(getSizeOfStackN(nStack) < 2)
                {
                    printf("Invalid Operands");
                    exit(0);
                }

                Number val2 = popN(&nStack);
                Number val1 = popN(&nStack);
                 
                //  printf("Signs %c %c",val1.sign,val2.sign);

                char op = topC(cStack);
                popC(&cStack);
                 
                pushN(&nStack,applyOp(val1,val2,op));
              }
             
            if(!isEmptyC(cStack))
                popC(&cStack);
        }
        else if(isAnythingOther(ch)){
                printf("Invalid Operands Indide Anything Other\n");
                exit(0);
        }
        else{
            if(l1.num){
                pushN(&nStack,l1);
                initNumber(&l1);
            }
            if(i == 0 && (ch == '-'|| ch == '+') ){
                if(ch == '-')
                flag = 1;
                continue;
            }
            else if(str[i-1] == '('){
                if(ch == '-' ){
                    check = 2;
                    continue;
                }
                else if( ch == '+'){
                    check = 3;
                    continue;
                }
            }

            while(topC(cStack) != ' ' && precedence(topC(cStack)) >= precedence(ch)){
                if(getSizeOfStackN(nStack) < 2)
                {
                    printf("Invalid Operands");
                    exit(0);
                }
                Number b = popN(&nStack);
                Number a = popN(&nStack);


                // printf("%c %c",a.sign,b.sign);
                // displayN(nStack);exit(0);

                char ch = popC(&cStack);
                pushN(&nStack,applyOp(a,b,ch));
            }
            pushC(&cStack,ch);
        }
    }
    displayN(nStack);

}