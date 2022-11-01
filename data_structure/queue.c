#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 6 

typedef struct queue{
    int front;
    int rear;
    int item[MAX_SIZE];
}queue;

queue create = {0, 0, '\0'};
bool isempt(queue q);
void add(int i, queue* q);
int c(int i);
int del(queue* q);
void printQ(queue q);

int main() {
    queue q = create;
    add(1, &q);
    add(2, &q);
    add(3, &q);
    add(4, &q);
    add(5, &q);
    add(6, &q);
    del(&q);
    add(7, &q);
    add(8, &q);
    printQ(q);
}

bool isempt(queue q){
    if(q.front == q.rear) return true;
    else return false;
}

int c(int i){
    return i%(MAX_SIZE);
}

void add(int i, queue* q){
    if((q->rear)-(q->front)==MAX_SIZE) printf("falied : queue_full\n");
    else q->item[c(++(q->rear))]=i;
}

int del(queue* q){
    if(isempt(*q)) printf("failed : queue_empty\n");
    else {
        return q->item[c(++(q->front))]; 
    }
}   

void printQ(queue q){
    for(int i=(q.front)+1; i<=q.rear; i++) printf("----");
    printf("\n");
    for(int i=(q.front)+1; i<=q.rear; i++) printf(" %2d ", q.item[c(i)]);
    printf("\n");
    for(int i=(q.front)+1; i<=q.rear; i++) printf("----");
    printf("\n total : %d  front : %d  rear : %d  \n\n",(q.rear)-(q.front), q.front, q.rear); 
}