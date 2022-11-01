#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define MAX_SIZE 6 // MAX_SIZE(+1) ex. input 6 for max 5 items

typedef struct stack{
    int top;
    int item[MAX_SIZE]; 
}stack;

stack create = { 0, '\0'};
void push(int i, stack* s);
int pop(stack* s);
void printS(stack s);
bool isempt(stack s);

int main() {
    stack s = create;
    push(1, &s);
    push(2, &s);
    pop(&s);
    pop(&s);
    pop(&s);
    printS(s);
}

void printS(stack s){
    for(int i = 0; i<s.top; i++) printf("----");
    printf("\n");
    printf("|");
    for(int i = 1; i<s.top+1; i++){
        printf(" %2d ", s.item[i]);
    }
    printf("\n");
    for(int i = 0; i<s.top; i++) printf("----");
    char tf[6]="false";
    if(isempt(s)) strcpy(tf, "true");
    printf("\n total : %d, isempt: %s \n\n", s.top, tf);
}

void push(int i, stack* s){
    if(s->top>=MAX_SIZE) printf("failed : stack_full");
    else s->item[++(s->top)] =i;
}

int pop(stack* s){
    if(isempt(*s)) printf("failed : stack_empty");
    else return s->item[(s->top)--];
}

bool isempt(stack s){
    if(s.top==0) return true;
    else return false;
}