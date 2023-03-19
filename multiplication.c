#include "multiplication.h"
#include<stdio.h>
#include<stdlib.h>

Number multiply(Number first,Number secondNo){

    Node* firstNo = first.num;           //getting  Linked lists


    int n = getSize(secondNo.num);

    Number answer[n] ;                   //In multiplication we multiply each digit of second  number with first and later we add them
                                        //So here for result of each number we need linked list which I had taken array of list with size of second list
    
    int carry = 0;
    int row = 0;

    while(secondNo.num){

     firstNo = first.num;                               //Setting firstNo evertime in the loop , as we traverse firstNo so track if lost
     answer[row].num = (Node*)malloc(sizeof(Node));     //Alloting space for rows for multiplication of each digit
        initNumber(&answer[row]);
        
     for(int i = 0 ; i < row ;i++){  
        append(&answer[row].num,0);                    //Now in multiplication in 1st row there are no zeros but as we go increasing row we append 
        answer[row].count++;                                // a 0 and keep increasing it as per row i.e I have done with the loop  
        answer[row].decimal++;

     }                                              

    while(firstNo){                                 //Keep repeating loop until firstNo exists
        
        int sum = secondNo.num -> data * firstNo -> data + carry ;
        carry = sum / 10;                                              //Seperating carry and using it for next iteration
        int digit = sum % 10;
        append(&answer[row].num,digit);
         answer[row].count++;
         answer[row].decimal++;
        firstNo = firstNo -> next;
    }
 
    if(carry){
        append(&answer[row].num,carry);                           //If carry exists newnode is created for that
        answer[row].count++;
        answer[row].decimal++;
        carry = 0;
    }
          
        row++;
        secondNo.num = secondNo.num -> next;

}

Number result ;
initNumber(&result);                                            //Initing result for iterative addition of rows
insertFront(&result.num,0);
result.count = 1;
result.decimal = 1;


for(int i = 0 ; i < n ; i++){

        result = addTwoLinkedLists(answer[i],result);       //Adding all the rows of multiplication together
        freeNumber(&answer[i]);                              //Free the number 
}

reverse(&result.num);
removeZerosFromFront(&result);                  //Free the number
reverse(&result.num);
                          //Removing preeceding zeros and returning the answer
    int ct = (first.count - first.decimal ) + (secondNo.count - secondNo.decimal);
 
result.decimal = result.count - ct;
int getMax = max((first.count - first.decimal ),(secondNo.count - secondNo.decimal));
ct = ct - getMax;
 while(result.num && ct-- ){
    result.num = result.num -> next;
}

return result;
}
