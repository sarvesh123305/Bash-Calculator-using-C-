#ifndef DIVISIONOPTIMIZED_H
#define DIVISIONOPTIMIZED_H

#include "divisionOptimized.h"
#include<stdio.h>
#include<stdlib.h>

#endif

void getNumberAndAddToLinkedList(List* temp,int number){
    // if((!*temp)){
        // return ;
    // }
    if(number <= 0){
        reverse(temp);      //If number is less than zero just reverse and return ;
        return ;
    }

    append(temp,number%10);         //Append Number to temporay linked list via digits logic via RECURSION 
    getNumberAndAddToLinkedList(temp,number/10);
}

Node* divideOptimizedTwoLinkedLists(Node* divident,Node* divisor){
        //divident - jyala divide krto
        //divisor - jyane divide krto

        removePreceedingZeros(&divident);
        removePreceedingZeros(&divisor);
        // display(divident);
        // display(divisor);
        char sign ;
        if((divident -> sign == '+' && divisor -> sign == '-' ) || divident -> sign == '-' && divisor -> sign == '+'){
            sign = '-';
        }
        else{
            sign = '+';
        }

        if(getSize(divisor) == 1 && divisor -> data == 0){
            printf("\nDivide by Zero Exception\n");
            exit(0);
        }
        printf("\nAnswer : \n");
        List tdivisor,result,tdivident,iterator,tempMul,tempAns,lastIterator,tempSub;
        initList(&tdivisor);
        initList(&tdivident);
        initList(&tempMul);
        initList(&tempAns);
        initList(&tempSub);
        initList(&result);



        int size1 = getSize(divident);
        int size2 = getSize(divisor);

        
        int ans;
        int flag = 0;
        int j = 0;
        while(divident ){
            append(&tdivident,divident -> data);
            divident = divident -> next;
j++;
                // display(tdivident);

            for(int i = 0 ; i <= 9 ; i++){
                // List temporaryDivident = tdivident;
                // initList(&tdivident);
                // while(temporaryDivident){
                //     append(&tdivident,temporaryDivident -> data);
                //     temporaryDivident = temporaryDivident -> next;
                // }
                // display(tdivident);
                initList(&tdivisor);
                List temp = divisor;
                while(temp){
                    append(&tdivisor,temp -> data);
                    temp = temp -> next;
                }
                initList(&lastIterator);
                append(&lastIterator,i > 0 ? i-1 : i);
                initList(&iterator);
                append(&iterator,i);
                
                tempMul = multiply(iterator,tdivisor);
                ans = compareLinkedLists(tempMul,tdivident);
                // display(tdivident);
                // switch(ans){}
                if(ans == 0){
                    //12 9
                    tempAns = lastIterator;
                    // display(lastIterator);
                    break;
                }
                else if(ans == 1){
                    tempAns = iterator;
                    // display(iterator);
                    break;
                }
                else if(ans == 11){
                    tempAns = lastIterator;
                    // display(lastIterator);

                    break;
                }
                else if(i == 9){
                    flag = 1;
                    tempAns = iterator;
                    break;
                }
                // else if(ans == 22){
                    
                // }
                // exit(0);
                
            }
            // exit(0);
            // display(tdivident);
            List abc = divisor; 
            initList(&tdivisor);
            while(abc){
                append(&tdivisor,abc -> data);
                abc = abc -> next;
            }
            // List xyz = tdivident;
            // initList(&tdivident);

            // while(xyz){
            //     append(&tdivident,xyz -> data);
            //     xyz = xyz -> next;
            // }
            // while()
                if(ans == 1){
                    initList(&tdivident);
                    // append(&tdivident,0);
                }
                else if(ans == 0 || ans == 11){
                    // display(tdivisor);
                    tempMul = multiply(lastIterator,tdivisor);
                    // display(tempMul);
                    tdivident -> sign = '+';
                    tempMul -> sign = '+';
                    // printf("Hii Divi");
                    // display(tdivident);
                    // display(tempMul);
                    tempSub = subtractTwoLinkedLists(tdivident,tempMul);
                    // display(tempSub);
                    // printf("End");

                    initList(&tdivident);
                    while(tempSub){
                        append(&tdivident,tempSub -> data);
                        tempSub = tempSub -> next;
                    }
                }
                else if(flag){
                    flag = 0;
                    // display(tdivident);
                    // display(tempMul);
                    tdivident -> sign = '+';
                    tempMul -> sign = '+';
                    tempSub = subtractTwoLinkedLists(tdivident,tempMul);
                    // display(tempSub);

                     initList(&tdivident);
                    while(tempSub){
                        append(&tdivident,tempSub -> data);
                        tempSub = tempSub -> next;
                    }
                }
                    // display(tdivident);
                    append(&result ,tempAns -> data);
                    // display(tempAns);
        }

        removePreceedingZeros(&result);
        // display(result);
        result -> sign = sign;      
        // printf("size : %d",size1);
        // printf("\nsize : %d",size2);
        
     
       
    return result;
  
    
}
