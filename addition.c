#include "addition.h"
#include<stdio.h>
#include<stdlib.h>

Number addTwoLinkedLists(Number head1,Number head2){
    Number L3;
    initNumber(&L3);

    int carry = 0 ;
    int sum = 0 ;
 
    if(head1.count != head1.decimal || head2.count != head2.decimal){
        AddingFrontAndBackDecimalsTillPoints(&head1,&head2);
    }
    while(head1.num || head2.num || carry ){

    int val1 = 0 , val2 = 0 ;
        if(head1.num)
            val1 = head1.num -> data;
        if(head2.num)
            val2 = head2.num -> data;
        
        sum = val1 + val2 + carry;
        
        insertFront(&L3.num,sum%10);
        L3.count++;
        L3.decimal++;
        carry = sum / 10 ;

        if(head1.num)
            head1.num = head1.num -> next;
        if(head2.num)
            head2.num = head2.num -> next;
      } 

    setDecimalToResult(head1,head2,&L3);
    removeZerosFromFront(&L3);
    reverse(&L3.num);
      return L3;
}

