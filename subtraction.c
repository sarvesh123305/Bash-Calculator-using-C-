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

    Node* head1 = L1;
    Node* head2 = L2;

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

