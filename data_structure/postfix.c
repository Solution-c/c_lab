#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX_SIZE 50

char stack[MAX_SIZE];
int top=0;
void push(char item);
char pop();
int eval(char *postfix);
int priority(char operator);
char* postfix(char* infix);
int isp(char c){
    switch (c){
        case '(': return 0;
        case '+':
        case '-': return 12;
        case '*':
        case '/':
        case '%': return 13;
    }
}
int icp(char c){
    switch (c){
        case '(': return 20;
        case '+':
        case '-': return 12;
        case '*':
        case '/':
        case '%': return 13;
    }
}

int main() {
    char *x;
    x=postfix("(1+2)*3");
    printf("%d\n", eval(x));
}

int eval(char *postfix){
    char *p=postfix;
    for(p; *p!='\0'; p++){
        if(isdigit(*p)){
            push(*p-'0');
        }
        else{
            int x, y;
            y = pop();
            x = pop();            
            switch (*p){
                case '+':
                    push(x+y);
                    break;
                case '-':
                    push(x-y);
                    break;
                case '*':
                    push(x*y);
                    break;
                case '/':
                    push(x/y);
                    break;
                case '%':
                    push(x%y);
                    break;
                default:
                    break;
                }
        }
    }
    return pop();
}

void push(char item){
    stack[++top] = item;
}

char pop(){
    return stack[top--];
}

char* postfix(char* infix){
    char *x, *ptr;
    x=malloc(sizeof(*infix));
    ptr = x;
    push('\0');
    for(infix;*infix!='\0';infix++){
        if(isdigit(*infix)) {*x=*infix; x=x+1;}
        else if(*infix==')'){
            while(stack[top]!='('){
                *(x++) = pop();
            }
            pop();
        }
        else{
            while(isp(stack[top])>=icp(*infix)){
                *(x++) = pop();
            }
            push(*infix);
        }
    }
    while(stack[top]!='\0'){
        *(x++) = pop();
    }
    *x='\0';
    return ptr;
}