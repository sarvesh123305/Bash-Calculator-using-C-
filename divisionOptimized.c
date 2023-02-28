#ifndef DIVISIONOPTIMIZED_H
#define DIVISIONOPTIMIZED_H
//ifndef is directive , the preprocessor is supposed to determine if any provided macros exist before any subsequent code is included.
#include "divisionOptimized.h" 
#include<stdio.h>
#include<stdlib.h>

#endif

// void getNumberAndAddToLinkedList(List* temp,int number){
//     // if((!*temp)){
//         // return ;
//     // }
//     if(number <= 0){
//         reverse(temp);      //If number is less than zero just reverse and return ;
//         return ;
//     }

//     append(temp,number%10);         //Append Number to temporay linked list via digits logic via RECURSION 
//     getNumberAndAddToLinkedList(temp,number/10);
// }

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

        List tdivisor,result,tdivident,iterator,tempMul,tempAns,lastIterator,tempSub;
        initList(&tdivisor);
        initList(&tdivident);       //Initing lists requied for division
        initList(&tempMul);
        initList(&tempAns);
        initList(&tempSub);
        initList(&result);

        
        int ans;
        int flag = 0;           

        //LOGIC : I have used the method of divident,divisor,quotient and remainder
        // i.e suppose number is 21456 / 21
        //I keep adding number digit by digit in temporary list and keep multiplying 21 from  0 -> 9
        //Then I subtract those number and continue the same

        while(divident ){                           //while divident exists till then the division should be followed
            append(&tdivident,divident -> data);    //tdivident is temporary divident
            divident = divident -> next;

            for(int i = 0 ; i <= 9 ; i++){
               
                initList(&tdivisor);                //When I traverse in the loop value of divisor is somewhere lost so at each iteration I 
                List temp = divisor;                //reinit the divisor
                while(temp){
                    append(&tdivisor,temp -> data);
                    temp = temp -> next;
                }

                initList(&lastIterator);
                append(&lastIterator,i > 0 ? i-1 : i);  //Keeping the track of last iterator as well which would be helpul in division at times
                initList(&iterator);
                append(&iterator,i);
                
                tempMul = multiply(iterator,tdivisor);
                ans = compareLinkedLists(tempMul,tdivident);
                //Compare list returns this
                // 0 -> Number cant be divided
                // 1 -> Numbers are equal
                // 11 -> list 1 is bigger
                // 22 -> list 2 is bigger
                if(ans == 0){
                    tempAns = lastIterator;             //Numbers cant be divided hence answer is last iterator
                    break;
                }
                else if(ans == 1){
                    tempAns = iterator;                 //Number is perfectly divisible hence answer is current iterator
                    break;
                }
                else if(ans == 11){
                    tempAns = lastIterator;             //List 1 is bigger hence answer is last iterator
                    break;
                }
                else if(i == 9){
                    flag = 1;                           //Now here number can be multiplied only by 9 at max so flag is set 
                    tempAns = iterator;
                    break;
                }
                
            }
            List reInitingDivisor = divisor;                //Due to operations divisor track is lost somewhere hence reinitng divisor
            initList(&tdivisor);
            while(reInitingDivisor){
                append(&tdivisor,reInitingDivisor -> data);
                reInitingDivisor = reInitingDivisor -> next;
            }

                if(ans == 1){
                    initList(&tdivident);               //Number is perfeclty divisble hence initing temporary divident to 0
                }
                else if(ans == 0 || ans == 11){
                    tempMul = multiply(lastIterator,tdivisor);       //Multiplying the tdivisor with last iterator
                    tdivident -> sign = '+';                        //setting sign always to + as we can later fix the signs by rules
                    tempMul -> sign = '+';
                    tempSub = subtractTwoLinkedLists(tdivident,tempMul);  //Subtracting temporary divident and temporary Multiplication

                    initList(&tdivident);           //Now difference is got so init temporary divident to 0 and adding difference to temporary divident
                    while(tempSub){
                        append(&tdivident,tempSub -> data);
                        tempSub = tempSub -> next;
                    }
                }
                else if(flag){                  //if flag is set ,reset it and subtract the  numbers and reinitng temporary divident and adding diff to it
                    flag = 0;
                    tdivident -> sign = '+';
                    tempMul -> sign = '+';
                    tempSub = subtractTwoLinkedLists(tdivident,tempMul);

                     initList(&tdivident);
                    while(tempSub){
                        append(&tdivident,tempSub -> data);
                        tempSub = tempSub -> next;
                    }
                }
                    append(&result ,tempAns -> data);
        }

        removePreceedingZeros(&result);     //removing preeceding zeros and setting result sign
        result -> sign = sign;      
        
    return result;
  
    
}
