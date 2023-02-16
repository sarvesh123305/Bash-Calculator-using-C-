#include "multiplication.h"
#include<stdio.h>
void multiply(Node* first,Node* second){

    //84 
    //26
    //5 0 4
  //1 6 8 0
//  2 1 8 4
// reverse(first);
// reverse(second);
Node* firstNo = first;
Node* secondNo = second;

    int carry = 0;
// List ans1;
// initList(&ans1);
// int row = 0;
while(secondNo){
    // printf("%d ",firstNo -> data , secondNo -> data);
    firstNo = first;
     // for(int i = 0 ; i < row ;i++){
        
    // append(&ans,0);
    // 
    // }

    while(firstNo){
        int sum = secondNo -> data * firstNo -> data + carry ;
        carry = sum / 10;
        int digit = sum % 10;
        printf("%d ",digit); 
        // append(&ans1,digit);
        firstNo = firstNo -> next;
    }    
    if(carry){
        printf("%d ",carry);       
        carry = 0;
    }
   
    // break;
    // row++;
        secondNo = secondNo -> next;

}
}