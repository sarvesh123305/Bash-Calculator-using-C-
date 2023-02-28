#include "multiplication.h"
#include<stdio.h>
#include<stdlib.h>

Node* multiply(Node* tempFirst,Node* tempSecond){
    Node* first = tempFirst;
    Node* second = tempSecond;
    reverse(&first);
    reverse(&second);

    Node* firstNo = first;
    Node* secondNo = second;            //getting reversed Linked lists


    int n = getSize(secondNo);

    Node* answer[n] ;                   //In multiplication we multiply each digit of second  number with first and later we add them
                                        //So here for result of each number we need linked list which I had taken array of list with size of second list
    
    int carry = 0;
    int row = 0;

    while(secondNo){

     firstNo = first;                               //Setting firstNo evertime in the loop , as we traverse firstNo so track if lost
     answer[row] = (Node*)malloc(sizeof(Node));     //Alloting space for rows for multiplication of each digit
        initList(&answer[row]);
        
     for(int i = 0 ; i < row ;i++){  
         append(&answer[row],0);                    //Now in multiplication in 1st row there are no zeros but as we go increasing row we append 
     }                                              // a 0 and keep increasing it as per row i.e I have done with the loop   
   
    while(firstNo){                                 //Keep repeating loop until firstNo exists
        
        int sum = secondNo -> data * firstNo -> data + carry ;
        carry = sum / 10;                                              //Seperating carry and using it for next iteration
        int digit = sum % 10;
        append(&answer[row],digit);
        firstNo = firstNo -> next;
    }

    if(carry){
        append(&answer[row],carry);                           //If carry exists newnode is created for that
        carry = 0;
    }
    
        row++;
        secondNo = secondNo -> next;

}
     for(int i = 0 ; i < n ; i++){
        reverse(&answer[i]);                                //Reversing all the rows of answer
     }

List result ;
initList(&result);                                            //Initing result with carry and carry out addition iteratively of rows
append(&result,0);


for(int i = 0 ; i < n ; i++){
   
        result = addTwoLinkedLists(answer[i],result);
}
removePreceedingZeros(&result);                                //Removing preeceding zeros and returning the answer
return result;
}