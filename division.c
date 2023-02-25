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

int compareLinkedLists(List mulResult,List Number){
    int size1 = getSize(mulResult);
    int size2 = getSize(Number);

    if(size1 > size2){
        return 0;                //Answer would be 0 as number is lesser
    }
    else{
        if(size1 == size2){
            Node* temporary1 = mulResult;
            Node* temporary2 = Number;

            int flag = 1;
            while(temporary1 && temporary2){
                if(temporary1 -> data > temporary2 -> data){
                    flag = -1;   //break kro kuch nahi ho sakta ab
                    break;
                }
                else if(temporary2 -> data > temporary1 -> data){
                    flag = 2;   //if list 1 is bigger return 2
                    break;      //Answer nahi aya abhi tak bhago answer ki taraf as like pointer 
                }
                
                temporary1 = temporary1 -> next;
                temporary2 = temporary2 -> next;

            }

            if(flag == 2){
                return 2;       //temporary Answer
            }
            else if(flag == -1){
                return -1;     //Exceeding answer 
            }
            return 1;       //indicates numbers are equal i.e answer is got perfectly
                
        }else{
            return 2;       //try karte raho
        }
    }
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
    for(int i = 1 ;; i++){

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
