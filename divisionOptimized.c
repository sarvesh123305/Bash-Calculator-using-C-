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

        if(getSize(divisor) == 1 && divisor -> data == 0){
            printf("\nDivide by Zero Exception\n");
            exit(0);
        }
        printf("\nAnswer : \n");
        List remainder,quotient,tdivisor,tdivident,tempMul,temp,tempSub,result,manyTemp;
        initList(&remainder);
        initList(&quotient);
        initList(&tdivisor);
        initList(&tdivident);
        initList(&tempMul);
        initList(&temp);
        initList(&tempSub);
        initList(&result);
        initList(&manyTemp);


        List tempDivisor ;
        initList(&tempDivisor);

        int size1 = getSize(divident);
        int size2 = getSize(divisor);

        // printf("size : %d",size1);
        // printf("\nsize : %d",size2);
        Node* hehe = divident;
    while(divident){
        int i = 0;

        initList(&tempSub);
        int tempSize = size2;
        if(hehe == divident){
            tempSize -= -1;
        }
        while(divident && getSize(tdivident) < tempSize+1 && i < tempSize+1){
            append(&tdivident,divident -> data);
            divident = divident -> next;
            i++;
        }

        // printf("\n");
        // display(tdivident);
        // display(divisor);
        // printf("\n");
        int ans;
        for(int i = 0 ; i < 10 ; i++){
            tempDivisor = divisor;
            List iteratorTemp;
            initList(&iteratorTemp);
            append(&iteratorTemp,i);
            // initList(&tdivisor);
            display(tdivisor);
            // printf("asda");
            while(tempDivisor){
                append(&tdivisor,tempDivisor -> data);
                tempDivisor = tempDivisor -> next;
            }
            // display(tdivident);
            // display(tdivisor);
            initList(&manyTemp);
            while(tempMul){
                append(&manyTemp,tempMul -> data);
                tempMul = tempMul -> next;
            }

            tempMul = multiply(iteratorTemp,tdivisor);
            // tempMul -> sign = '+';
            initList(&tdivisor);
            // display(tempMul);
             ans = compareLinkedLists(tempMul,tdivident);
            // printf("%d ",ans);
            // display(tempMul);
            // display(tdivident);  

            if(ans == 1){
                temp = iteratorTemp;
            // initList(&tdivident);
                // printf("Yeszava");
                // initList (&tdivident);
                //  List newnode ;
                // initList(&newnode);
                // append(&newnode,0);
                // temp = newnode;
                break;
            }
            // else if(ans == 22 ){
            //     // display(tempMul);
            //     // display(tdivident);
            //     // exit(0);
            //     tempMul -> sign = '+';
            //     tempSub = subtractTwoLinkedLists(tempMul,tdivident);
            //     // display(tempSub);
            //     break;
            // }
            else if(ans == 11){
                // tempSub = subtractTwoLinkedLists(tempMul,tdivident);
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
        // display(manyTemp);
        display(tdivident);
        // if(ans == 11)
        // tempSub = subtractTwoLinkedLists(tdivident,manyTemp);
            // initList(&tdivident);
        // display(tempSub);
        if( ans == 1)
        {
            initList(&tdivident);
            append(&tdivident,0);
        }
        // display(tdivident);
    //         else if(ans == 22){
    // //             initList(&tdivident);
    // // // printf("sa");
    // //             tempSub = subtractTwoLinkedLists(tdivident,temp);
    // //             while(tempSub){
    // //                 append(&tdivident,tempSub -> data);
    // //                 tempSub = tempSub -> next;
    // //             } 
                

    //         }
        else if(ans == 11 ){
            // tempSub = subtractTwoLinkedLists(tdivident,manyTemp);
            initList(&tdivident);
            while(tempSub){
                append(&tdivident,tempSub -> data);
                tempSub = tempSub -> next;
            }
        }
        append(&result,temp -> data);
        // if(i == 1)
            // break;
        // display(tdivident);
    }
        removePreceedingZeros(&result);
        printf("\nRESULT\n");
        display(result);
        exit(0);

  
    
}
