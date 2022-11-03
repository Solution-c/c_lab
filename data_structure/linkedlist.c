#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *link;
};

typedef struct node node;

node *A, *B;

int main() {
    A = (node *)malloc(sizeof(node));
    A-> data = 10;
    B = (node *)malloc(sizeof(node));
    B-> data = 20;
    A-> link =B;
    B-> link = NULL;
    node *ptr;
    int length = 0;

    for(ptr=A; ptr!=NULL; ptr = ptr->link) {
        length++;
    }
    printf(" # of nodes :%d \n", length);

    free(A); free(B);
}