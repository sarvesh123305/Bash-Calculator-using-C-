#include<stdio.h>
#include<stdlib.h>
#include "subtraction.h"

void removePreceedingZeros(List *L){
    if(!(*L))
    return ;

    Node* temp = *L;

    //Checking for preeceding zeros and removing it Eg : 0012 -> 12
    //This would make our subtraction task easy

    while(temp -> next){
        if(temp -> data == 0)
        {
            Node* deleteNode = temp;
            temp = temp -> next;
            free(deleteNode);
        }
        else{
            break;  // Break the loop when there are no preceding zeros
        }
    }
    *L = temp;

    return ;
}


List subtractTwoLinkedLists(List L1,List L2){

    List L3;
    initList(&L3);
    // L3 -> sign = '-';

    //My Function is implemented with always subtracting smaller no from bigger no
    //So if first no is smaller we would swap nos 

    int sizeOfList1 = getSize(L1);
    int sizeOfList2 = getSize(L2);

    Node* head1 = NULL;
    Node* head2 = NULL;

    //Finding greater number with size and comparing bits of the list

    if(sizeOfList2 > sizeOfList1){
        //negative answer
        L3 -> sign = '-';
        head1 = L2;
        head2 = L1;
    }
    else if(sizeOfList1 > sizeOfList2){
        head1 = L1;
        head2 = L2;
    }
    else{

        Node* temporary1 = L1;
        Node* temporary2 = L2;

        int flag = 0;

        while(temporary1 && temporary2){
            
            if(temporary1 -> data > temporary2 -> data){
                    flag = 1;           // Indicates List 1 is greater// Indicates List 1 is greater
                    break;
            }
            else if(temporary2 -> data > temporary2 -> data){
                    // L3 -> sign = '-';
                    flag = 2;           // Indicates List 2 is greater
                    break;
            }
        
            temporary1 = temporary1 -> next;
            temporary2 = temporary2 -> next;
        }

        if(flag == 1){
            head1 = L1;
            head2 = L2;
        }
        else {
            head2 = L1;
            head1 = L2;
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
            val1 = val1 + 10;       //Borrow req hence add 10 
            diff = (val1 - val2 - temp);
            borrow = 1;
        }

        append(&L3,diff%10);

        if(head1)
            head1 = head1 -> next;
        if(head2)
            head2 = head2 -> next;
      } 
      reverse(&L3);
      removePreceedingZeros(&L3);
      return L3;
}

