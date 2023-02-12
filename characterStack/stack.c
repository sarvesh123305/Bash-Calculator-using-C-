#include<stdio.h>
#include "stack.h"
#include<stdlib.h>
#include<string.h>

void initStackC(charStack* s,int size){
     s -> arr = (char*)malloc(sizeof(char)*size);
     s -> top = -1;
     s -> size = size;
     return ;
}

int isFullC(charStack s){
    return s.top >=  s.size - 1;
}

void pushC(charStack *s,char data){
  
  if(isFullC(*s)){
        return;
  }
   s -> top++;
   s -> arr[s -> top] = data;
   return ;
}

void displayC(charStack s){

    if(s.top == -1 )
    return ;
    printf("\n");
    for(int i = s.size ; i >= 0 ; i--){
    printf("%c ",s.arr[i]);
    }

}
int isEmptyC(charStack s){
    return s.top == -1;
}
void insertIntoStackC(charStack* s,char* data)
{
    
    for(int i = 0 ; i < data[i] != '\0'; i++){
         if(i >= s -> size)
             return ;

        pushC(s,data[i]);
    }
    return ;
}
int popC(charStack *s){
    if(isEmptyC(*s))
    return 0;

    int element = s -> arr[s->top];
    s -> top--;
    return element;
}


char topC(charStack s){
    if(isEmptyC(s)){
        char c = ' ';
        return c;
    }
    return s.arr[s.top];
}
