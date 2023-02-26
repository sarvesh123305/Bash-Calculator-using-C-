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
        newnode -> sign = '+';
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


void display(List head){
    if(!head)
    return ;
    printf("\n");
    Node* temp = head;
    printf("%c",head -> sign);
    while(temp){
        printf("%d",temp -> data);
        temp = temp -> next;
    }
    printf("\n");

}


int getSize(List head){
    if(!head){
        return 0;
    }
    int ct = 0;
    while(head){
        ct++;
        head = head -> next;
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
