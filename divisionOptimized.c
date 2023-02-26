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
        display(divident);
        display(divisor);


        printf("\nAnswer : \n");
        List remainder,quotient,tdivisor,tdivident,tempMul,temp,tempSub,result;
        initList(&remainder);
        initList(&quotient);
        initList(&tdivisor);
        initList(&tdivident);
        initList(&tempMul);
        initList(&temp);
        initList(&tempSub);
        initList(&result);

        List tempDivisor ;
        initList(&tempDivisor);

        int size1 = getSize(divident);
        int size2 = getSize(divisor);

        // printf("size : %d",size1);
        // printf("\nsize : %d",size2);
    while(divident){
        int i = 0;

        initList(&tempSub);

        while(divident &&getSize(tdivident) < size2 && i < size2){
            append(&tdivident,divident -> data);
            divident = divident -> next;
            i++;
        }

        // printf("\n");
        display(tdivident);
        // display(divisor);
        // printf("\n");

        for(int i = 0 ; i < 10 ; i++){
            tempDivisor = divisor;
            List iteratorTemp;
            initList(&iteratorTemp);
            append(&iteratorTemp,i);
            initList(&tdivisor);
            while(tempDivisor){
                append(&tdivisor,tempDivisor -> data);
                tempDivisor = tempDivisor -> next;
            }
            // display(tdivident);

            // display(tdivisor);
            tempMul = multiply(iteratorTemp,tdivisor);
            // display(tempMul);
            // exit(0);    
            int ans = compareLinkedLists(tempMul,tdivident);
            // printf("%d",ans);
            if(ans == 1){
                temp = iteratorTemp;
                // initList(&tdivident);
                break;
            }
            else if(ans == -1  ){
                tempSub = subtractTwoLinkedLists(tempMul,tdivident);
                break;
            }
            else if(ans == 0)
            {
                List newnode ;
                initList(&newnode);
                append(&newnode,0);
                temp = newnode;
                break; 
            }
            else{
                temp = iteratorTemp;
            }
        }

        initList(&tdivident);
        if(tempSub )
        append(&tdivident,tempSub -> data);
        append(&result,temp -> data);
        // display(tdivident);
    }
        removePreceedingZeros(&result);
        display(result);
        exit(0);

  
    
}
