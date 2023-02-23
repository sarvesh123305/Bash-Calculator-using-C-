#include "addition.h"
#include<stdio.h>

List addTwoLinkedLists(List L1,List L2){
    List L3;
    initList(&L3);

    Node* head1 = L1;
    Node* head2 = L2;

    reverse(&head1);
    reverse(&head2);
    
    int carry = 0 ;
    int sum = 0 ;

    while(head1 || head2 || carry ){

    int val1 = 0 , val2 = 0 ;
        if(head1)
            val1 = head1 -> data;
        if(head2)
            val2 = head2 -> data;
        
        sum = val1 + val2 + carry;
        
        append(&L3,sum%10);
        carry = sum / 10 ;

        if(head1)
            head1 = head1 -> next;
        if(head2)
            head2 = head2 -> next;
      } 
      reverse(&L3);
      return L3;
}

