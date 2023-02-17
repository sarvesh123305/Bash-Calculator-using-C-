#include<stdio.h>
#include<stdlib.h>
#include "subtraction.h"

void removePreceedingZeros(List *L){
    if(!(*L))
    return ;
    Node* temp = *L;
    while(temp -> next){
        if(temp -> data == 0)
        {
            Node* deleteNode = temp;
            temp = temp -> next;
            free(deleteNode);

        }
        else
        break;
    }
    *L = temp;
    // printf("Enter");
    return ;
}


List subtractTwoLinkedLists(List L1,List L2){
    List L3;
    initList(&L3);

    int sizeOfList1 = getSize(L1);
    int sizeOfList2 = getSize(L2);

    // printf("%d",sizeOfList2);
    Node* head1 = NULL;
    Node* head2 = NULL;
    if(sizeOfList2 > sizeOfList1){
        //negative answer
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
        while(temporary1 -> data > temporary2 -> data){
            temporary1 = temporary1 -> next;
            temporary2 = temporary2 -> next;
        }
        

    }
    reverse(&head1);
    reverse(&head2);

    int borrow = 0 ;
    int diff = 0 ;

    while(head1 || head2 || borrow ){

    int val1 = 0 , val2 = 0 ;
        if(head1)
            val1 = head1 -> data;
        if(head2)
            val2 = head2 -> data;
        diff = (val1 - val2 - borrow);
    printf("val1: %d val2 : %d borrow : %d\t",val1 , val2,borrow);

    printf("\n");
        int temp = borrow;
        
        if(borrow == 1)
        borrow = 0;

        if(diff < 0){
            val1 = val1 + 10;
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
      display(L3);
    
      return L3;
}

