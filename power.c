#ifndef POWER_H
#define POWER_H
#include "multiplication.h"
#include "divisionOptimized.h"
#include<stdio.h>
#include<stdlib.h>
#include "power.h"
#endif
Number powerOfTwoLinkedLists(Number first,Number second){
        removePreceedingZeros(&first.num);
        removePreceedingZeros(&second.num);

        int sizeOfList1 = getSize(first.num);
        int sizeOfList2 = getSize(second.num);

        Number result;
        initNumber(&result);
        append(&result.num,1);

        int flag = -1;
        if(second.num -> data % 2 == 0){
            flag = 0;
        }

        if(second.sign == '-'){
            second.sign = '+';
            result.num -> data = 0;
            return result;
        } 
        Number temp;
        Number staticSub ;
        initNumber(&staticSub);
        append(&staticSub.num,1);
        Number iterator = second;
        

        while(iterator.num && iterator.num -> data != 0){
            temp = copyNumber(first);
            result = multiply(temp,result);
            iterator = subtractTwoLinkedLists(iterator,staticSub);
        }

        if(flag == -1 && first.sign == '-'){
            result.sign = '-';
        }
        return result;
}