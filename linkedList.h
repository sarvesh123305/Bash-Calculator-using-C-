#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct Node{
    short int data;
    struct Node *next;
}Node;

typedef Node* List;

typedef struct Number{    
    char sign;
    int decimal,count;
    List num;
}Number;

void initNumber(Number*);
void initList(List* l);
int getSize(List head);
void append(List* head,int data);
void reverse(List *L1);
void display(Number head);
void removeZerosFromFront(Number*);
void insertFront(List* head,int data);
int compareLinkedLists(List,List);
void freeNumber(Number*);
Number copyNumber(Number num1);
void AddingFrontAndBackDecimalsTillPoints(Number*,Number*);
List reverseList(List L1);
Number reverseNumber(Number number);
void setDecimalToResult(Number L1,Number L2,Number *L3);
int max(int a,int b);
int isTheNumberZero(Number y);

#endif



