#include<stdio.h>
#include<stdlib.h>
#include "subtraction.h"

Number subtractTwoLinkedLists(Number L1,Number L2){

    Number L3;
    initNumber(&L3);

    removePreceedingZeros(&L1.num);
    removePreceedingZeros(&L2.num);

    //My Function is implemented with always subtracting smaller no from bigger no
    //So if first no is smaller we would swap nos 

    int sizeOfList1 = getSize(L1.num);
    int sizeOfList2 = getSize(L2.num);

    List head1 = NULL;
    List head2 = NULL;

    int flag = 0;
    //Finding greater number with size and comparing bits of the list

    if(sizeOfList2 > sizeOfList1){
        //negative answer
         flag = 2;
        head1 = L2.num;
        head2 = L1.num;
    }
    else if(sizeOfList1 > sizeOfList2){
        flag = 1;
        head1 = L1.num;         // Indicates List 1 is greater
        head2 = L2.num;
    }
    else{

        List temporary1 = L1.num;
        List temporary2 = L2.num; 

        while(temporary1 && temporary2){
            
            if(temporary1 -> data > temporary2 -> data){
                    flag = 1;           // Indicates List 1 is greater
                    break;
            }
            else if(temporary2 -> data > temporary1 -> data){
                    flag = 2;           // Indicates List 2 is greater so the answer is negative
                    break;
            }
        
            temporary1 = temporary1 -> next;
            temporary2 = temporary2 -> next;
        }
        
        //By getting values of flag setting list 1 as greatest 
        if(flag == 1){
            head1 = L1.num;
            head2 = L2.num;
        }
        else {
            head2 = L1.num;
            head1 = L2.num;
        }
    }
    
    reverse(&head1);
    reverse(&head2);

    int borrow = 0 ;
    int diff = 0 ;

    while(head1 || head2 || borrow ){       //Loop will run until we list1 or list2 or borrow is present

    int val1 = 0 , val2 = 0 ;               //I have tried to write generic code for lists which would reduce my code
        if(head1)
            val1 = head1 -> data;
        if(head2)
            val2 = head2 -> data;
        diff = (val1 - val2 - borrow);

        int temp = borrow;
        
        if(borrow == 1)         //Borrow is present so reset it to zero and add it to number
        borrow = 0;

        if(diff < 0){
            val1 = val1 + 10;               //Borrow req hence add 10 
            diff = (val1 - val2 - temp);
            borrow = 1;
        }
        // if(isEmptyLinkedList(L3)){
            // append(&L3,diff%10);
        // }
        // else{
            append(&L3.num,diff%10);
        // }

        if(head1)
            (head1)= (head1) -> next;
        if(head2)
            (head2) = (head2) -> next;
      }

      reverse(&L3.num);

      removePreceedingZeros(&L3.num);             //Removing preeceding zeros and setting sign
      if(flag == 1){
        if(L1.sign == '+'){
            L3.sign = '+';
        }
        else{
            L3.sign = '-';

        }
      }
      else if(flag == 2){
    //   printf("%d",flag);
        //  if(L2.sign == '+'){
            L3.sign = '-';
        // }
        // else{
            // L3.sign = '+';
        // }
      }
      else{
             L3.sign = '+';
      }
      return L3;
}

