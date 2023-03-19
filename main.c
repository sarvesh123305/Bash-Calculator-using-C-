#include<stdio.h>
#include "infixEvaluation.h"
#include<stdlib.h>
#include<string.h>

#define MAX 2048

void displayInformation(){
printf("\nBC 1.21  SARVESH KULKARNI - 142203012");
    printf("\nCopyright 2022 , Free Software Foundation under GNU");
    printf("\nThis is a free and open source software with ABSOLUTELY NO WARRANTY");
    printf("\nOperations Supported - (+  -  /  * %% ^)\n");
    printf("Use 'info' for more information\n");

}
int main(){
    system("clear");
    displayInformation();

    //  char str[MAX] = "12.21^12";
    //  printf("\n%s\n",str);
        // infixEvaluation(str);
// exit(0);

    char str[MAX] = "";
    //  char str[MAX] = "809318230981+514513451*15441251312455315413/23412";


    int i = 0 ;
     

    while(1){
       
        fgets(str,MAX,stdin);

    int len = strlen(str);

    if(len > 0 && str[len-1] == '\n'){
        str[len-1] = '\0';
    }

    if(strcmp(str,"quit")== 0|| strcmp(str,"exit") == 0)
            break;

    else if(strcmp(str,"clear") ==  0){
             system("clear");
            displayInformation();
    }

    else if(strcmp(str,"info") ==  0){
        printf("\nThis is a Binary Calculator which can add very large numbers ");
        printf("Everything is represented via linked lists so it has the ability to perform operation like addition , subtraction ,multiplication,modulus and division of large number\n");
        printf("For more help you can use ");
        printf("\n1)clear - clearing the screen \n2)quit/exit/Ctrl+C - quitting the bc\n\n");
        continue;
    }

    else{
        for(int i = 0 ; str[i] != '\0' ; i++){
            if(isCharacter(str[i]))
             {
                   printf("Invalid Expression\n");
                    exit(0);
             }
         } 
        } 
        infixEvaluation(str);
        
    }
    return 0;
}
