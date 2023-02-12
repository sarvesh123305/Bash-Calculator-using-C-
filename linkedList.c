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
}


void display(List head){
    if(!head)
    return ;
    Node* temp = head;
    while(temp){
        printf("%d\t",temp -> data);
        temp = temp -> next;
    }
}
