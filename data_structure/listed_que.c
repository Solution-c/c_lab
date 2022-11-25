#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int num;
    int data;
    struct node* link;
}queue;

queue *front=NULL;
queue *q_ptr=NULL;
queue *rear=NULL;

void addq(int item, int num);
void insq(int item, int num);
int len();
int delq();
void printq();


int main() {
    addq(1, 4);
    addq(2, 2);
    addq(3, 0);
    insq(3, 6);
    insq(4, 0);
    insq(3, 3);
    insq(4, 3);
    printq();
}

void addq(int item, int num){
    queue* tmp;
    tmp = malloc(sizeof(queue));
    if(tmp==NULL) {fprintf(stderr, "\nThe queue is full\n"); exit(1);}
    tmp->data = item;
    tmp->num = num;
    tmp->link = NULL;
    if(rear==NULL){
        front=tmp; rear=tmp;
    }
    else{
        rear->link = tmp;
        rear = tmp;
    }
}

void insq(int item, int num){
    if(front==NULL) addq(item, num); /*empty 인 경우 추가*/
    else if(num>front->num) { /*가장 앞인 경우 front 앞에 추가*/
            queue* tmp;
            tmp = malloc(sizeof(queue));
            if(tmp==NULL) {fprintf(stderr, "\nThe queue is full\n"); exit(1);}
            tmp->data = item;
            tmp->num = num;
            tmp->link = front;
            front=tmp;
        }
    else if(num<=rear->num){ /* 가장 뒤인 경우 rear 뒤에 추가 */
        if(num==rear->num) rear->data =item;
        if(num<rear->num) addq(item, num);
    }
    else{
        q_ptr = front; 
        while(num<=((q_ptr->link)->num)){ /* 포인터 위치 찾기 (삽입할 위치 전)*/
            q_ptr = q_ptr->link;
            printf("ptr->link (%d) ", q_ptr->num);
            printf(" %d \n", q_ptr==rear);
        }
        if(num==(q_ptr->num)){ 
            printf("num==q_ptr->num");
            q_ptr->data = item;
        }
        else { 
            printf("insert!");
            queue* tmp;
            tmp = malloc(sizeof(queue));
            if(tmp==NULL) {fprintf(stderr, "\nThe queue is full\n"); exit(1);}
            tmp->data = item;
            tmp->num = num;
            tmp->link = q_ptr->link;
            q_ptr->link = tmp;
            q_ptr = tmp;
        }
    }
}

int delq(){
    queue* tmp = front;
    int item;
    if(front==NULL) {fprintf(stderr, "\nThe queue is empty"); exit(1);}
    else{
        item = tmp->data;
        if(front==rear) {
        front=NULL; rear=NULL;
        }
        else front = tmp->link;
        free(tmp);
        return item;
    }
}

void printq(){
    queue *ptr = front;
    printf("\n");
    while(ptr!=NULL){
        printf("%d. %d \n",ptr->num, ptr->data );
        ptr=ptr->link;
    }
    printf("\n");
}

int len(){
    queue* ptr = front;
    int count=0;
    while((ptr->link)!=NULL){
        count++;
        ptr = ptr->link;
    }
    count++;
    return count;
}