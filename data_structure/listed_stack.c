#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *link;
};

typedef struct node stack;
stack *top=NULL;

void push();
int pop();

int main(){
    push(1);
    push(2);
    push(3);
    printf(" %d ", pop());
    printf(" %d ", pop());
    printf(" %d ", pop());
    printf(" %d ", pop());
}

void push(int item){
    stack *tmp = (stack *)malloc(sizeof(stack));
    if(tmp == NULL) {
        fprintf(stderr, "The memory is full\n");
        exit(1);
    }
    tmp->data = item;
    tmp->link = top;
    top = tmp;
}

int pop(){
    stack *tmp = top;
    int item;
    if (tmp == NULL) {
        fprintf(stderr, "The stack is empty\n");
        exit(1);
    }
    item = tmp->data;
    top = tmp->link;
    free(tmp);
    return item;
}