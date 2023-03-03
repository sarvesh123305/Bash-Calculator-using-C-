#include "linkedList.h"
#include<stdio.h>
#include<stdlib.h>

void initList(List* l){
    *l = NULL;
    return ;
}

void append(List* head,int data){
    Node* newnode = (Node*)malloc(sizeof(Node));
    
    if(!newnode)
    return ;

    newnode -> data = data;
    newnode -> next = NULL;
    if(!(*head)){
        *head = newnode;
        return ;
    }

    Node* temp = *head;
    while(temp -> next){
        temp = temp -> next;
    }
    temp -> next = newnode ;
}

void reverse(List *L1){
    if(!(*L1))
    return ;

    Node* prev = NULL;
    Node* curr = *L1;
    Node* next = NULL;

    while(curr){
        next = curr -> next;
        curr -> next = prev;
        prev  = curr;
        curr = next;
    }
    *L1 = prev;
    return;
    //0 - 3
    //0<-3
}


void displayList(List head){
    if(!head){
        return ;
    }
    printf("%d",head -> data);
    displayList(head -> next);
}
void display(Number head){
    if(!head.num)
    return ;
    Number temp = head;
    printf("= %c",temp.sign);
    displayList(temp.num);
    printf("\n");
}


int getSize(List head){
    List temp = head;
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

int isEmptyLinkedList(List head){
    return head == NULL;
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
    number -> num = NULL;
}

void freeList(List* numberList){
    while(numberList){
        List* freeNode = numberList;
        *(numberList) = (*numberList)-> next;
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