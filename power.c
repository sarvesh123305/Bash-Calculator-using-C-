#ifndef POWER_H
#define POWER_H
#include "multiplication.h"
#include "divisionOptimized.h"
#include "modulus.h"

#include<stdio.h>
#include<stdlib.h>
#include "power.h"
#endif
Number powerOfTwoLinkedLists(Number first,Number second){

    //Optimized Approach in powerOptimized() function (Can calculate power upto 9000)
    //#RECURSION
            Number temp = second;

        if(second.count != second.decimal){
            int target = second.count - second.decimal;
            second.count = second.decimal;
            int i = 0 ; 
            
            while(temp.num -> next && target--){
                temp.count--;
                temp.num = temp.num -> next;
            }
        }
//            int ct = (first.count - first.decimal ) + (second.count - second.decimal);
// int getMax = max((first.count - first.decimal ),(second.count - second.decimal));
        first.decimal = first.count;
// printf("Get Count :  %d %d \n",first.count,second.count);
// printf(" Count :  %d \n",ct);

        
        return   powerOptimized(first,temp);

    //Brute force Approach (Limitation - Can calculate power upto 500 only) 

        // int sizeOfList1 = getSize(first.num);
        // int sizeOfList2 = getSize(second.num);

        // Number result;
        // initNumber(&result);
        // append(&result.num,1);

        // int flag = -1;
        // if(second.num -> data % 2 == 0){
        //     flag = 0;
        // }

        // if(second.sign == '-'){
        //     second.sign = '+';
        //     result.num -> data = 0;
        //     return result;
        // } 
        // reverse(&second.num);


        // Number temp;
        // Number staticSub ;
        // initNumber(&staticSub);
        // append(&staticSub.num,1);
        // staticSub.count = staticSub.decimal = 1;   
        // Number iterator = second;
        // iterator.count = iterator.decimal = second.count;   

        // while(iterator.num && iterator.num -> data != 0){
        //     temp = copyNumber(first);
        //     temp.count = temp.decimal = first.count;
        //     result = multiply(temp,result);
        //     iterator = subtractTwoLinkedLists(reverseNumber(iterator),staticSub);
        // }

        // if(flag == -1 && first.sign == '-'){
        //     result.sign = '-';
        // }
        // return result;
}
Number powerOptimized(Number x,Number y)
{
    
    
    if(isTheNumberZero(y)){
        Number nowGo;
        initNumber(&nowGo);
        append(&nowGo.num,1);
        nowGo.count = nowGo.decimal = 1;
        return nowGo;
    }

    Number staticNo;
    initNumber(&staticNo);
    append(&staticNo.num,2);
    staticNo.count = staticNo.decimal = 1;
    Number temp = powerOptimized(x,divideOptimizedTwoLinkedLists(y,staticNo));

    Number result = modulusOfTwoLinkedLists(y,staticNo);
    if(y.num -> data % 2 == 0){
        return multiply(temp,temp);
    }
    else{
        return multiply(temp,multiply(x,temp));
    }
}