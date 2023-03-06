#include<stdio.h>
#include "characterStack/stack.h"
#include "numberStack/stack.h"
#include "multiplication.h"

int isNumber(char ch);
int precedence(char symb);
Number applyOperand(Number,Number, char);
void infixEvaluation(char*);
int isCharacter(char);