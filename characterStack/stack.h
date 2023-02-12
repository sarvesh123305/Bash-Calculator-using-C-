typedef struct charStack{
    char *arr;
    int top;
    int size;
}charStack;


void initStackC(charStack*,int);
void pushC(charStack*,char);
void displayC(charStack);
int isFullC(charStack);
int isEmptyC(charStack);
void insertIntoStackC(charStack*,char*);

int popC(charStack*);

char topC(charStack);
