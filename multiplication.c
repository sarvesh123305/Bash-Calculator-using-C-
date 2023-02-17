#include "multiplication.h"
#include<stdio.h>
#include<stdlib.h>
// #include "addition.h"
// #include "subtract.h"


Node* multiply(Node* first,Node* second){

reverse(&first);
reverse(&second);
Node* firstNo = first;
Node* secondNo = second;

// display(first);
// display(second);


int n = getSize(secondNo);
// printf("\nsize = %d\n",n);

Node* answer[n] ;



    int carry = 0;
// generic linked list  
// List ans1;
// initList(&ans1);

int row = 0;
while(secondNo){
    firstNo = first;
     answer[row] = (Node*)malloc(sizeof(Node));
        initList(&answer[row]);
        
     for(int i = 0 ; i < row ;i++){  
         append(&answer[row],0);
     }
   
    while(firstNo){
        
        int sum = secondNo -> data * firstNo -> data + carry ;
        carry = sum / 10;
        int digit = sum % 10;
        append(&answer[row],digit);
        firstNo = firstNo -> next;
    }
   
   
    
    if(carry){
        append(&answer[row],carry);
        carry = 0;
    }
    
        row++;
 
        secondNo = secondNo -> next;

}
     for(int i = 0 ; i < n ; i++){
        reverse(&answer[i]);
     }
    // reverse(&answer[0]);
    //  display(answer[0]);
    //  display(answer[1]);

List result ;
initList(&result);
append(&result,0);
    // printf("sadasdasda %d\n",n);


for(int i = 0 ; i < n ; i++){
    // printf("sadasdasda\n");
    // display(answer[i]);
    printf("\n");
    // if(i == 0){
    //     result = addTwoLinkedLists(answer[i],answer[i-1]);
    // //     // i++;
    // }else{
        result = addTwoLinkedLists(answer[i],result);
    // }
}
// printf("****");
// display(result);
// printf("****");

return result;
}