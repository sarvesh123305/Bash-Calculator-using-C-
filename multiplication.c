#include "multiplication.h"
#include<stdio.h>
#include<stdlib.h>

Number multiply(Number tempFirst,Number tempSecond){
    Number first = tempFirst;
    Number second = tempSecond;
    reverse(&first.num);
    reverse(&second.num);

    Node* firstNo = first.num;
    Node* secondNo = second.num;            //getting reversed Linked lists


    int n = getSize(secondNo);

    Number answer[n] ;                   //In multiplication we multiply each digit of second  number with first and later we add them
                                        //So here for result of each number we need linked list which I had taken array of list with size of second list
    
    int carry = 0;
    int row = 0;

    while(secondNo){

     firstNo = first.num;                               //Setting firstNo evertime in the loop , as we traverse firstNo so track if lost
     answer[row].num = (Node*)malloc(sizeof(Node));     //Alloting space for rows for multiplication of each digit
        initList(&answer[row].num);
        
     for(int i = 0 ; i < row ;i++){  
         append(&answer[row].num,0);                    //Now in multiplication in 1st row there are no zeros but as we go increasing row we append 
     }                                              // a 0 and keep increasing it as per row i.e I have done with the loop   
   
    while(firstNo){                                 //Keep repeating loop until firstNo exists
        
        int sum = secondNo -> data * firstNo -> data + carry ;
        carry = sum / 10;                                              //Seperating carry and using it for next iteration
        int digit = sum % 10;
        append(&answer[row].num,digit);
        firstNo = firstNo -> next;
    }

    if(carry){
        append(&answer[row].num,carry);                           //If carry exists newnode is created for that
        carry = 0;
    }
    
        row++;
        secondNo = secondNo -> next;

}
     for(int i = 0 ; i < n ; i++){
        reverse(&answer[i].num);                                //Reversing all the rows of answer
     }

Number result ;
initNumber(&result);                                            //Initing result with carry and carry out addition iteratively of rows
append(&result.num,0);

for(int i = 0 ; i < n ; i++){
        result = addTwoLinkedLists(answer[i],result);
}
removePreceedingZeros(&result.num);                                //Removing preeceding zeros and returning the answer
return result;
}