#ifndef LINKEDLIST_H
#define LINKEDLIST_H


typedef struct Node{
    int data;
    struct Node *next;
}Node;

typedef Node* List;

typedef struct Number{    
    char sign;
    List num;
}Number;

void initNumber(Number*);

void initList(List* l);
void append(List* head,int data);
void reverse(List *L1);
void display(Number head);
int getSize(List head);
Node* top(List head);
int isEmptyLinkedList(List);
void removePreceedingZeros(List*);

int compareLinkedLists(List,List);
  
#endif



