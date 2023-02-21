#ifndef DIVISION_H
#define DIVISION_H

#include "division.h"
#include<stdio.h>
#include<stdlib.h>

#endif

void getNumberAndAddToLinkedList(List* temp,int number){
    // if((*temp)){
        // return ;
    // }
    if(number <= 0){
        reverse(temp);
    // display(*temp);
        return ;
    }
    append(temp,number%10);
    getNumberAndAddToLinkedList(temp,number/10);
}
int compareLinkedLists(List mulResult,List Number){
    int size1 = getSize(mulResult);
    int size2 = getSize(Number);
    
    if(size1 > size2){
        return 0;
    }
    else{
        if(size1 == size2){
            Node* temporary1 = mulResult;
            Node* temporary2 = Number;

            int flag = 1;
            while(temporary1 && temporary2){
                if(temporary1 -> data > temporary2 -> data){
                    flag = 2;
                    break;
                }
                else if(temporary2 -> data > temporary1 -> data){
                    flag = 0;
                    break;
                }
                temporary1 = temporary1 -> next;
                temporary2 = temporary2 -> next;

                
            }
            if(flag == 2){
                return 2;
            }
            else if(flag == 0){
                return 0;
            }
            
            return 1;
                
        }
    }
}
Node* divideTwoLinkedLists(Node* first,Node* second){
    int size1 = getSize(first);
    int size2 = getSize(second);
    // display(first);
    // display(second);

    Node* secondNo = second;
    reverse(&first);
    reverse(&second); 
    display(first);
    display(second);

    List result;
    initList(&result);

    if(size2 == 1){
        if(second -> data == 0){
            printf("\nDivide by 0 exception\n");
            exit(0);
        }
    }
    //20 / 10
    //10*0
    for(int i = 1 ; i < 15; i++){
        secondNo = second;
        List temp;
        initList(&temp);
        if(i <= 9 )
            append(&temp,i);
        else {
            getNumberAndAddToLinkedList(&temp,i);
        }
        // display(first);
        // display( multiply(first,temp));
      List l1 = multiply(second,temp);
      int ans = compareLinkedLists(l1,first);
      if(ans == 1){
            display(l1);
      }
      else if(ans == 2){
            display(l1);
            break;
      }
    //   display(l1);
    }

    //20
    //10
    
}
