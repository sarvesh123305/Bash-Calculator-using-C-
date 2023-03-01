#include "addition.h"
#include<stdio.h>
#include<stdlib.h>
Number addTwoLinkedLists(Number L1,Number L2){
    Number L3;
    initNumber(&L3);

    Number head1 = L1;
    Number head2 = L2;

    reverse(&head1.num);
    reverse(&head2.num);
    
    int carry = 0 ;
    int sum = 0 ;

    while(head1.num || head2.num || carry ){

    int val1 = 0 , val2 = 0 ;
        if(head1.num)
            val1 = head1.num -> data;
        if(head2.num)
            val2 = head2.num -> data;
        
        sum = val1 + val2 + carry;
        
        append(&L3.num,sum%10);
        carry = sum / 10 ;

        if(head1.num)
            head1.num = head1.num -> next;
        if(head2.num)
            head2.num = head2.num -> next;
      } 
      reverse(&L3.num);
      return L3;
}

