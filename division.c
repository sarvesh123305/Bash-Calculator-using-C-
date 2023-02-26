#ifndef DIVISION_H
#define DIVISION_H

#include "division.h"
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

Node* divideTwoLinkedLists(Node* first,Node* second){

    removePreceedingZeros(&first);
    removePreceedingZeros(&second);

    int size1 = getSize(first);
    int size2 = getSize(second);
    
    Node* secondNo = second;
   
    List result;
    initList(&result);

    if(size2 == 1){
        if(second -> data == 0){
            printf("\nDivide by 0 exception\n");
            exit(0);
        }
    }
    
    int canWeDivide = compareLinkedLists(first,second);
    switch(canWeDivide){
        case -1 :
        case 2 : 
                 append(&result,0);
                 return result;
                 break;

    }
    
    long long int i ;
    // long long temp = 1;
    // for(int j = 0 ; j < i ; j++){
        // temp = temp * 10 ;
    // }
    // printf("%lld",temp);
    // exit(0);
    //9
    //8
    for( i = 1 ; ; i++){
        // printf("%lld\n",i);
        Node* firstNo  = first;
        secondNo = second;

        List temp;
        initList(&temp);

        if(i <= 9 )
            append(&temp,i);
        else {
            getNumberAndAddToLinkedList(&temp,i);
        }

    List temporary ;
    initList(&temporary);

    Node* iteratorTemp = temp;
    
    while(temp){
        append(&temporary,temp -> data);
        temp = temp -> next;
    }

    List secondTemp ;
    initList(&secondTemp);

     while(secondNo){
        append(&secondTemp,secondNo -> data);
        secondNo =  secondNo -> next;
    }

      List l1 = multiply(secondTemp,temporary);

      int ans = compareLinkedLists(l1,firstNo);

      if(ans == 1){
            result = iteratorTemp; 
            break;
      }
      else if(ans == -1){
            break;
      }
      else{
            result = iteratorTemp;
      }
    }
        return result;
}
