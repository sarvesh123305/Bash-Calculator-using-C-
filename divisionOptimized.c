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

Number divideOptimizedTwoLinkedLists(Number divident,Number divisor){
        //divident - jyala divide krto
        //divisor - jyane divide krto

        removePreceedingZeros(&divident.num);
        removePreceedingZeros(&divisor.num);
        // display(divident);
        // display(divisor);
        char sign ;
        if((divident.sign == '+' && divisor.sign == '-' ) || divident.sign == '-' && divisor.sign == '+'){
            sign = '-';
        }
        else{
            sign = '+';
        }

        if(getSize(divisor.num) == 1 && divisor.num -> data == 0){
            printf("\nDivide by Zero Exception\n");
            exit(0);
        }

        Number tdivisor,result,tdivident,iterator,tempAns;
        initNumber(&tdivisor);
        initNumber(&tdivident);       //Initing lists requied for division
        initNumber(&tempAns);
        initNumber(&result);

        
        int ans;
        int flag = 0;           

        //LOGIC : I have used the method of divident,divisor,quotient and remainder
        // i.e suppose number is 21456 / 21
        //I keep adding number digit by digit in temporary list and keep multiplying 21 from  0 -> 9
        //Then I subtract those number and continue the same
Number temp;
        while(divident.num){                           //while divident exists till then the division should be followed
            append(&tdivident.num,divident.num -> data);    //tdivident is temporary divident
            divident.num = divident.num -> next;

            for(int i = 0 ; i <= 9 ; i++){
               
                initNumber(&tdivisor);                //When I traverse in the loop value of divisor is somewhere lost so at each iteration I 
                temp = divisor;                //reinit the divisor
                while(temp.num){
                    append(&tdivisor.num,temp.num -> data);
                    temp.num = temp.num -> next;
                }

                initNumber(&iterator);
                append(&iterator.num,i);
                
                temp = multiply(iterator,tdivisor);
                ans = compareLinkedLists(temp.num,tdivident.num);
                //Compare list returns this
                // 0 -> Number cant be divided
                // 1 -> Numbers are equal
                // 11 -> list 1 is bigger
                // 22 -> list 2 is bigger
                tempAns = iterator;
                if(ans == 0){
                    iterator.num -> data -=1;     //Numbers cant be divided hence answer is last iterator
                    break;
                }
                else if(ans == 1){
                    break;               //Number is perfectly divisible hence answer is current iterator
                }
                else if(ans == 11){
                    iterator.num -> data -=1;  // //List 1 is bigger hence answer is last iterator
                    break;
                }
                else if(i == 9){
                    flag = 1;                           //Now here number can be multiplied only by 9 at max so flag is set 
                    break;
                }
                
            }
            Number reInitingDivisor = divisor;                //Due to operations divisor track is lost somewhere hence reinitng divisor
            initNumber(&tdivisor);
            while(reInitingDivisor.num){
                append(&tdivisor.num,reInitingDivisor.num -> data);
                reInitingDivisor.num = reInitingDivisor.num -> next;
            }

                if(ans == 1){
                    initNumber(&tdivident);               //Number is perfeclty divisble hence initing temporary divident to 0
                }
                else if(ans == 0 || ans == 11){
                           //Multiplying the tdivisor with last iterator
                    // tdivident -> sign = '+';                        //setting sign always to + as we can later fix the signs by rules
                    temp = subtractTwoLinkedLists(tdivident,multiply(iterator,tdivisor));  //Subtracting temporary divident and temporary Multiplication

                    initNumber(&tdivident);           //Now difference is got so init temporary divident to 0 and adding difference to temporary divident
                    while(temp.num){
                        append(&tdivident.num,temp.num -> data);
                        temp.num = temp.num -> next;
                    }
                }
                else if(flag){                  //if flag is set ,reset it and subtract the  numbers and reinitng temporary divident and adding diff to it
                    flag = 0;
                    temp = subtractTwoLinkedLists(tdivident,temp);

                     initNumber(&tdivident);
                    while(temp.num){
                        append(&tdivident.num,temp.num -> data);
                        temp.num = temp.num -> next;
                    }
                }
                    append(&result.num ,tempAns.num -> data);
        }

        freeNumber(&tdivisor);
        freeNumber(&tdivident);
        freeNumber(&iterator);
        freeNumber(&divisor);
        freeNumber(&divident);
        freeNumber(&temp);
        removePreceedingZeros(&result.num);     //removing preeceding zeros and setting result sign
        result.sign = sign;      
        
    return result;
  
}
