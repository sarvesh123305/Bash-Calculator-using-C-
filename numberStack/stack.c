#include "stack.h"
#include<stdio.h>
#include<stdlib.h>


void initStackN(Stack* s){
    s -> top = NULL;
}
int isEmptyN(Stack s){
    return s.top == NULL;
}

void displayN(Stack s){
   if(isEmptyN(s))
   return ;

   NodeforStack* temp = s.top;
   printf("%c",temp -> data -> sign);
   while(temp){
    Node* go = temp -> data;
    while(go){
        printf("%d",go -> data);
        // printf("Yes");
        go = go -> next;
    }
    printf("\n");
    temp = temp -> up;
   }
}

Node* getTopN(Stack s){
    Node* newnode = (Node*)malloc(sizeof(Node));
    newnode -> data = -1;
    newnode -> next = NULL;
    if(!s.top)
    return newnode;
    return s.top -> data;
}


void pushN(Stack* s,Node* data){
    

    NodeforStack* newnode = (NodeforStack*)malloc(sizeof(NodeforStack));
    newnode -> data = data;
    newnode -> up = NULL;

    if(isEmptyN(*s))
    {
        s -> top = newnode;
    }
    else
    {
        newnode -> up = s -> top;
        s -> top = newnode;
    }
    return ;
}

Node* popN(Stack *s){
    if(isEmptyN(*s)){
        return NULL;
    }
    NodeforStack* deleteNode = s -> top;
    
    Node* actualList = deleteNode -> data;
    // free(deleteNode);
    // display(actualList);
    s -> top = s -> top -> up;
    return actualList;
}
// Node* top(Stack);

int getSizeOfStackN(Stack s){
    if(isEmptyN(s))
    return 0;
    int ct = 0;
    NodeforStack* temp = s.top;
    while(temp){
        ct++;
        temp = temp -> up;
    }
    return ct;
}