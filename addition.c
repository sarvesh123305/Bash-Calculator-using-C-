#include "addition.h"
#include<stdio.h>

Number addTwoLinkedLists(Number L1,Number L2){
    Number L3;
    initList(&L3.num);

    List head1 = L1.num;
    List head2 = L2.num;

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
        
        append(&L3.num,sum%10);
        carry = sum / 10 ;

        if(head1)
            head1 = head1 -> next;
        if(head2)
            head2 = head2 -> next;
      } 
      reverse(&L3.num);
      return L3;
}

