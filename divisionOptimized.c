#ifndef DIVISIONOPTIMIZED_H
#define DIVISIONOPTIMIZED_H
//ifndef is directive , the preprocessor is supposed to determine if any provided macros exist before any subsequent code is included.
#include "divisionOptimized.h" 
#include<stdio.h>
#include<stdlib.h>
#endif

Number divideOptimizedTwoLinkedLists(Number divident,Number divisor){
        //divident - jyala divide krto
        //divisor - jyane divide krto

        if(divident.decimal != divident.count){
            int ct = divident.count-divident.decimal;           //If decimal points present in divident then remove it 
            while(ct--){
                divident.num = divident.num -> next;
            }
            divident.count = divident.decimal;
        }
        
        reverse(&divident.num);     //Just reverse the divident because we start to divide a number from MSB
      
        char sign ;
        if((divident.sign == '+' && divisor.sign == '-' ) || divident.sign == '-' && divisor.sign == '+'){
            sign = '-';                       //Checking for current signs and assigning signs as per maths rules
        }
        else{
            sign = '+';
        }

        if(isTheNumberZero(divisor)){
            printf("\nRuntime Error : Divide by Zero Exception\n");            //Number cant be divided by zero
            exit(0);
        }
        
        int count = divident.count - divident.decimal;

        while(count--){
            Number k ;
            initNumber(&k);
            insertFront(&k.num,1);
            insertFront(&k.num,0);
            Number tempCopy ;
            initNumber(&tempCopy);
            tempCopy = copyNumber(divisor);
            divisor = multiply(tempCopy,k);
            divident.decimal++;
        }
      

        Number tdivisor,result,tdivident,iterator,tempAns;
        initNumber(&tdivisor);
        initNumber(&tdivident);       //Initing lists requied for division
        initNumber(&tempAns);
        initNumber(&result);

        
        int ans;
        int flag = 0;           

      
        Number temp;
        initNumber(&temp);


         //LOGIC : I have used the method of divident,divisor,quotient and remainder
        // i.e suppose number is 21456 / 21
        //I keep adding number digit by digit in temporary list and keep multiplying 21 from  0 -> 9
        //Then I subtract those number and continue the same
        
        while(divident.num){             //while divident exists till then the division should be followed

            insertFront(&tdivident.num,divident.num -> data);//tdivident is temporary divident
            (tdivident).count += 1;
            (tdivident).decimal += 1;    
            divident.num = divident.num -> next;
    

            for(int i = 0 ; i <= 9 ; i++){
             
                initNumber(&iterator);
                append(&iterator.num,i);
                 (iterator).count += 1;
                 (iterator).decimal += 1;   
              
                temp = multiply(iterator,divisor);
                
                Number temp1,temp2;
                initNumber(&temp1);
                initNumber(&temp2);

                temp1 = copyNumber(tdivident);
                temp2 = copyNumber(temp);
               

                ans = compareLinkedLists(reverseList(temp2.num),reverseList(temp1.num));
                  //Compare list returns this
                // 0 -> Number cant be divided
                // 1 -> Numbers are equal
                // 11 -> list 1 is bigger
                // 22 -> list 2 is bigger
                if(ans == 0){
                    iterator.num -> data -=1;     //Numbers cant be divided hence answer is last iterator
                    break;
                }
                else if(ans == 1){
                    break;               //Number is perfectly divisible hence answer is current iterator
                }
                else if(ans == 11){
                    iterator.num -> data -=1; //List 1 is bigger hence answer is last iterator
                    break;
                }
                else if(i == 9){
                    flag = 1;                     //Now here number can be multiplied only by 9 at max so flag is set         
                    break;
                }
               
            }
            
            insertFront(&tempAns.num,iterator.num -> data);
            tempAns.count++;
            tempAns.decimal++;

            
                if(ans == 1){
                    initNumber(&tdivident); 
                }
                else if(ans == 0 || ans == 11){ 
                    //Multiplying the tdivisor with last iterator
                    //Now difference is got so init temporary divident to 0 and adding difference to temporary divident
                    temp = subtractTwoLinkedLists(tdivident,multiply(iterator,divisor));
                    initNumber(&tdivident);    

                    while(temp.num){
                        append(&tdivident.num,temp.num -> data);
                        (tdivident).count += 1;
                        (tdivident).decimal += 1;   
                        temp.num = temp.num -> next;
                    }
                   
                }
                else if(flag){              
                    flag = 0;       //if flag is set ,reset it and subtract the  numbers and reinitng temporary divident and adding diff to it
                    temp = subtractTwoLinkedLists(tdivident,temp);
                     initNumber(&tdivident);
                    while(temp.num){
                        append(&tdivident.num,temp.num -> data);
                       (tdivident).count += 1;
                        (tdivident).decimal += 1;  
                        temp.num = temp.num -> next;
                    }
                }
    
                    append(&result.num ,tempAns.num -> data);
                    result.decimal++;
                    result.count++;

                  
        }
        freeNumber(&tdivisor);
        freeNumber(&tdivident);     
        freeNumber(&iterator);
        freeNumber(&divisor);           //Freeing the lists used
        freeNumber(&divident);
        freeNumber(&temp);
        removeZerosFromFront(&result);
        result = reverseNumber(result);
      
        result.sign = sign;     
   
    return result;
  
}
