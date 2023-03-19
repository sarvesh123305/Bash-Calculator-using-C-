#include "linkedList.h"
#include<stdio.h>
#include<stdlib.h>

int abs(int n){
    if(n < 0){
        n*=-1;          //Gives absolute values
    }
    return n;
}
int max(int a,int b){
    if(a > b){
        return a;          //Gives max number from two
    }
    return b;
}

void initList(List* l){
    *l = NULL;          //Initing the list
    return ;
}

void append(List* head,int data){        //Appends number to last of list
    Node* newnode = (Node*)malloc(sizeof(Node));
    
    if(!newnode)
    return ;

    newnode -> data = data;
    newnode -> next = NULL;

    if(!(*head)){
        *head = newnode;        //If list is null newnode is the head
        return ;
    }

    Node* temp = *head;         //otherwise go to end of list and append the number to last
    while(temp -> next){
        temp = temp -> next;
    }
    temp -> next = newnode ;
}


void insertFront(List* head,int data){ //Appends number to first of list
    Node* newnode = (Node*)malloc(sizeof(Node));
    if(!newnode)
    return ;
    newnode -> data = data;
    newnode -> next = NULL;


    if(!(*head)){
        *head = newnode;//If list is null newnode is the head
        return;
    }

    newnode -> next = *head;        //otherwise join the list to next of newnode and make newnode as head
    *head = newnode;
}

void reverse(List *L1){
    if(!(*L1))
    return ;

    Node* prev = NULL;
    Node* curr = *L1;           //Take 3 pointers
    Node* next = NULL;

    while(curr){
        next = curr -> next;        //Store next element of current
        curr -> next = prev;        //Change the pointer of current number to previous
        prev  = curr;               //Increment pointers
        curr = next;
    }
    *L1 = prev;             //Now the changes are saved in the prev as it contain head, so make l1 = head
    return;
}

List reverseList(List L1){
      if(!(L1))
    return NULL;

    Node* prev = NULL;  
    Node* curr = L1;        //Same as above just returns list
    Node* next = NULL;

    while(curr){
        next = curr -> next;
        curr -> next = prev;
        prev  = curr;
        curr = next;
    }
    return prev;
}

void displayList(Number head){  //Displaying list using recursion
    if(!head.num){          //Base case if head == NULL return;
        return ;
    }

    int data = head.num -> data;
    head.decimal = head.decimal + 1;        //increment decimal for setting the decimal point
    head.num = head.num -> next;            //Increment list and recursive call for the same
    displayList(head);
     if(head.count == head.decimal ){       //When decimal == count i.e there lies decimal point , Just print it 
        printf(".");
    }
    printf("%d",data);
}
void display(Number head){
    if(!head.num)
    return ;
    Number temp = head;


    if(isTheNumberZero(head)){  // if Answer is 0 then set always set it as positive because 0 is never negative
        temp.sign = '+';
    }
    
    printf("= ");           
    if(temp.sign == '-')            //Print sign only if its negative
    printf(" %c",temp.sign);
    
    displayList(temp);
    printf("\n");
}

void AddingFrontAndBackDecimalsTillPoints(Number* head1,Number* head2)
{
  
    int list1Decimal = (*head1).decimal;
    int list2Decimal = (*head2).decimal;
 
    int list1Points = (*head1).count - list1Decimal;        //Getting no of decimal points in both numbers
    int list2Points = (*head2).count - list2Decimal;

    int countNormal = abs(list1Decimal - list2Decimal);     //Getting absolute value of decimals in both numbers
    int countDecimal = abs(list1Points - list2Points);

    
    if(list1Decimal > list2Decimal){
        //add in list2
        while(countNormal--) {
            append(&((*head2).num),0);
            (*head2).count += 1;
            (*head2).decimal +=1;

        }
    }
    else{
            //add in list1
         while(countNormal--) {
            append(&((*head1).num),0);
            (*head1).decimal +=1;
            (*head1).count += 1;
        }
    }
   
    if(list1Points > list2Points){
         //add in list2
         while(countDecimal--) {
            insertFront(&((*head2).num),0);
            (*head2).count += 1;
        }
    }
    else{
            //add in list1
        while(countDecimal--) {
            insertFront(&((*head1).num),0);
            (*head1).count += 1;
        }

    }
        return ;
}

int getSize(List head){
    List temp = head;               //Traverse whole the list and just increment count and return it
    if(!temp){
        return 0;
    }
    int ct = 0;
    while(temp){
        ct++;
        temp = temp -> next;
    }
    return ct;
}



void removePreceedingZeros(List *L){
    if(!(*L))
    return ;

    Node* temp = *L;

    //Checking for preeceding zeros and removing it Eg : 0012 -> 12
    //This would make our subtraction task easy

    while(temp -> next){
        if(temp -> data == 0)
        {
            Node* deleteNode = temp;
            temp = temp -> next;
            free(deleteNode);
        }
        else{
            break;  // Break the loop when there are no preceding zeros
        }
    }
    *L = temp;

    return ;
}

void removeZerosFromFront(Number* L){
 if(!(*L).num)
    return ;

    Number temp = *L;

    //Checking for preeceding zeros and removing it Eg : 0012 -> 12
    //This would make our task easy and remove redundant zeros too

    while(temp.num -> next){
        if(temp.num -> data == 0 && temp.decimal != 1)
        {
            temp.count--;               //Decrementing count and decimal too
            temp.decimal--;
            Node* deleteNode = temp.num;
            temp.num = temp.num -> next;
            free(deleteNode);
        }
        else{
            break;  // Break the loop when there are no preceding zeros
        }
    }
    *L = temp;
}

Number reverseNumber(Number number){
    reverse(&number.num);           //Reversing the number
    return number;
}


int compareLinkedLists(List mulResult,List Number){
   
    removePreceedingZeros(&mulResult);
    removePreceedingZeros(&Number);

    int size1 = getSize(mulResult);
    int size2 = getSize(Number);

    if(size1 > size2){
        return 0;                //Answer would be 0 as number is lesser
    }
    
    else{
        if(size1 == size2){
            Node* temporary1 = mulResult;
            Node* temporary2 = Number;

            int flag = 1;
            while(temporary1 && temporary2){
                if(temporary1 -> data > temporary2 -> data){
                    flag = 11;   //break kro kuch nahi ho sakta ab
                    break;
                }
                else if(temporary2 -> data > temporary1 -> data){
                    flag = 22;   //if list 1 is bigger return 2
                    break;      //Answer nahi aya abhi tak bhago answer ki taraf as like pointer 
                }
                
                temporary1 = temporary1 -> next;
                temporary2 = temporary2 -> next;

            }

            if(flag == 11){
                return 11;       //temporary Answer
            }
            else if(flag == 22){
                return 22;     //Exceeding answer 
            }
            else
            return 1;       //indicates numbers are equal i.e answer is got perfectly
                
        }else{
            return 22;       //try karte raho
        }
    }
}

void initNumber(Number* number){
    number -> sign = '+';
    number -> num = NULL;           //Initialize number with positive sign
    number -> decimal = 0;
    number -> count = 0;
}

void freeList(List* numberList){
    while(numberList){
        List* freeNode = numberList;
        *(numberList) = (*numberList)-> next;           //Freeing up the space 
        free(freeNode);
    }
}
void freeNumber(Number* freenum){
      List temp = freenum -> num;

      while(temp){
        List deleteNode = temp;
        temp = temp -> next;
        free(deleteNode);
      }
}


Number copyNumber(Number num1){
        Number num3;
        initNumber(&num3);

        while(num1.num){
            append(&num3.num,num1.num -> data);
            num1.num = num1.num -> next;
        }
        return num3;
}

void setDecimalToResult(Number L1,Number L2,Number *L3){
    int difference =  max(L1.count - L1.decimal , L2.count - L2.decimal);
        if(L1.decimal == L1.count && L2.decimal == L2.count){
                    (*L3).decimal = (*L3).count;
            }
            else{
                    (*L3).decimal = (*L3).count - difference;
            }
}

int isTheNumberZero(Number y){//Check if number is 0 

    reverse(&y.num);
    removeZerosFromFront(&y);  //Reverse the list and remove redundant zeros , again make the list as it was and return 
                            
    reverse(&y.num);

    if(y.num && !y.num -> next && y.num -> data == 0){
        return 1;
    }
    return 0;
}
