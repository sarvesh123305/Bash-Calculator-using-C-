#include "binaryCalculator.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


char** convertCharArray(char *expression){
    
    int count1 = 0 ;
    int flag = 1;
    char ch;
    for(int i = 0 ; expression[i] != '\0' ;i++){
         ch = expression[i];
        if(ch == '+' || ch == '-' || ch == '*' || ch == '/'||ch == '(' || ch == ')'){
            
            if(flag){
                count1 += 2;
            }
            else{
                count1++;
            }
            flag = 0;
        }
        else{
            flag = 1;
        }


    }
    if(ch != '(' || ch != ')')
    ++count1;

    printf("\n%d\n",count1);
    char **ans = (char**)malloc(sizeof(char*)*count1)  ;
    int space = 0;
    char *str = (char*)malloc(sizeof(char)*space) ;
    int k = 0, a = 0;
    strcpy(str,"");
     for(int i = 0 ; expression[i] != '\0' ; i++){
        char ch = expression[i];
        // if(ch == ' ')
        // continue;
        if(ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '(' || ch == ')'){
            ans[k] = (char*)malloc(sizeof(str));
            strcpy(ans[k++],str);
            a = 0;
            space = 1;
            str = realloc(str, space); // allocate new space
            strcpy(str," ");

        
            char operator[1] ;
            operator[0] = ch;
            ans[k] = (char*)malloc(sizeof(1)); 
            strcpy(ans[k++],operator);
            

        }
        else{
            str[a++] = (char)(ch);
            space++;              
            str = realloc(str, space); // allocate new space
        }
     }
            ans[k] = (char*)malloc(sizeof(str)); 
            strcpy(ans[k++],str);

    for(int i = 0 ; i < count1 ; i++){
        printf("%s\t",ans[i]);
    }
      return ans;
}
int precendence(char ch){  
    if(ch == '(')
    return 0;
   
    if(ch == '+' || ch == '-')
    return 1;

     if(ch == '*' || ch == '/')
    return 2;

    return 0;
}


void convertToPostfix(char **expression,int n){
     charStack s;
    //  initStackC(&s,n);
     initStackC(&s,10);


     char **ans = (char**)malloc(sizeof(char*)*n);
// //priority () * / + - 
      int k = 0;
      printf("\n");
    for(int i = 0 ; i <= n ; i++){
        char *ch = expression[i];
    //    printf("%s",ch);

         if((strcmp("+",ch) && strcmp("-",ch) && strcmp("/",ch) && strcmp("*",ch) && strcmp("(",ch) && strcmp(")",ch)  )  )
         {
            ans[k] = (char*)malloc(sizeof(ch));
            strcpy(ans[k++],ch);
         }
           if(strcmp("(",ch))
           {
               
                pushC(&s,'(');   
         }
           else if(!strcmp(")",ch))
            {
                 while( topC(s) !=  ' ' && topC(s) != '(')
                 {
                char temp = topC(s);
                char temp1[1] ;
                 temp1[0] = temp;
                 ans[k] = (char*)malloc(sizeof(temp));
                strcpy(ans[k++],temp1);
                popC(&s);
              }
               popC(&s);
            }
            else{
            char abc = ch[0];
            // printf("%c\t",abc);
                while(topC(s) != ' ' &&  precendence(topC(s)) >= precendence(abc)){
                    ans[k] = (char*)malloc(sizeof(topC(s)));
                    char temp[1] ;
                    temp[0] = topC(s);
                    strcpy(ans[k++],temp);
                    popC(&s);
                }
                pushC(&s,abc);
    }
    
    for(int i = 0 ; i <= n ;i++){
                // printf("Yes");

        printf("%s\n",ans[i]);
        // printf("\n");
    }

}
 while(!isEmptyC(s)){
        char ch = topC(s);
        ans[k] = (char*)malloc(sizeof(topC(s)));
        char temp[1] ;
        temp[0] = topC(s);
        strcpy(ans[k++],temp);
        popC(&s);
    }


}

void controlEverything(){
    // char* expression = inputExpression();
        // convertCharArray(expression);
    char **temp = convertCharArray("2+3*1");
    // printf("\n%s",temp[0]);
    // printf("\n%s",temp[1]);
    // printf("\n%s",temp[2]);
    // printf("\n%s",temp[3]);
    // printf("\n%s",temp[4]);
  
     convertToPostfix(temp,4);

}


char* inputExpression(){

    printf("\nEnter a expression : ");
    
    char *expression = NULL;
    scanf ("%m[^\n]%*c", &expression);
    printf ("\n str: %s\n\n", expression);
    return expression;
}




void initStack(Stack* s){
    s -> top = NULL;
}
int isEmpty(Stack s){
    return s.top == NULL;
}

void displayS(Stack s){
   if(isEmpty(s))
   return ;

   NodeforStack* temp = s.top;
   while(temp){
    Node* go = temp -> data;
    while(go){
        printf("%d",go -> data);
        go = go -> next;
    }
    printf("\n");
    temp = temp -> up;
   }
}

Node* top(Stack s){
    Node* newnode = (Node*)malloc(sizeof(Node));
    newnode -> data = -1;
    newnode -> next = NULL;
    if(!s.top)
    return newnode;
    return s.top -> data;
}


void push(Stack* s,Node* data){
    

    NodeforStack* abc = (NodeforStack*)malloc(sizeof(NodeforStack));
    abc -> data = data;
    abc -> up = NULL;

    if(isEmpty(*s))
    {
        s -> top = abc;
    }
    else
    {
        s -> top -> up = abc;
        s -> top = abc;
    }
     displayS(*s);
}

// Node* pop(Stack*);
// Node* top(Stack);