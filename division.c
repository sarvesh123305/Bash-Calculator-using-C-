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

// 21 
// 2
// 10 
int compareLinkedLists(List mulResult,List Number){
    int size1 = getSize(mulResult);
    int size2 = getSize(Number);
    

//0 3 
//
    // reverse(&Number);
// printf("dsassa");
reverse(&mulResult);
    // display(mulResult);
    // display(Number);
    // exit(0);
    // display(Number);
    //30 30
    if(size1 > size2){
        return 0;
        //Answer would be 0 as number is lesser
    }
    else{
        if(size1 == size2){
            Node* temporary1 = mulResult;
            Node* temporary2 = Number;

            int flag = 1;
            while(temporary1 && temporary2){
                if(temporary1 -> data > temporary2 -> data){
                    flag = -1;
                    //break kro kuch nahi ho sakta ab
                    break;
                }
                //10 11
                else if(temporary2 -> data > temporary1 -> data){
                    flag = 2;
                    //if list 1 is bigger return 2
                    //try krte raho
                    break;
                }
                temporary1 = temporary1 -> next;
                temporary2 = temporary2 -> next;

            }

            if(flag == 2){
                // printf("2");
                return 2;
            }
            else if(flag == -1){
                return -1;
            }
            //indicates numbers are equal
            return 1;
                
        }else{
            //try karte raho
            return 2;
        }
    }
}
Node* divideTwoLinkedLists(Node* first,Node* second){
    int size1 = getSize(first);
    int size2 = getSize(second);
    // display(first);
    // display(second);
    Node* secondNo = second;
    // reverse(&first);
    reverse(&second); 
    display(first);
    display(second);
// 
    List result;
    initList(&result);
    int test = 0;
    if(size2 == 1){
        if(second -> data == 0){
            printf("\nDivide by 0 exception\n");
            exit(0);
        }
    }
    //20 
    //1
    //
    for(int i = 1 ; i <= 30; i++){
        List firstNo = first;
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
      display(l1);   
      break;
    //   reverse(&first);
        // display(first);

        // break;
    //   int ans = compareLinkedLists(l1,firstNo);
    //   if(ans == 1){
    // //   result = temp; 
    //         test++;
    //         // display(l1);
    //         printf("%d",test);
    //         // display(temp);
    //         break;
    //         // return l1;S
    //   }
    //   else if(ans == -1){
    //     // display(l1);
    //         printf("%d",test);
    //         // display(temp);
    //     break;
    //     // return l1;
    //   }
    //   else{
    //     // display(l1);

    //   }
    //         test++;

    //   display(l1);
    }

        // return NULL;
    //20
    //10
    
}
