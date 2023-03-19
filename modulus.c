
#include "modulus.h"
#include<stdlib.h>
Number modulusOfTwoLinkedLists(Number firstNo,Number secondNo){

    
        Number temp = copyNumber(secondNo);
        Number temp1 = copyNumber(firstNo);
       Number resultOfDivision = divideOptimizedTwoLinkedLists(temp1,temp);
        initNumber(&temp);
        temp = copyNumber(secondNo);
       resultOfDivision = multiply(resultOfDivision,temp);

       resultOfDivision = subtractTwoLinkedLists(firstNo,resultOfDivision);

       return resultOfDivision;
}