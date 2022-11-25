#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node* link;
}listnode;

listnode* create2();
void printlist(listnode* list);
void insert(int item,listnode** first, listnode* x);
void delete(listnode** first, listnode* x);

int main(){
    listnode *first=NULL;
    first = create2();
    insert(30, &first, first->link);
    printlist(first);
    listnode *second=NULL;
    insert(50, &second, second);
    printlist(second);
    delete(&first, first);
    printlist(first);
}

listnode* create2(){
    listnode *first, *second;
    first = malloc(sizeof(listnode));
    second = malloc(sizeof(listnode));
    second->link = NULL;
    second->data = 20;
    first->link = second;
    first->data = 10;
    return first;
}

void printlist(listnode* list){
    listnode *ptr = list;
    for(ptr; ptr!=NULL; ptr=ptr->link){
        printf(" %d ", ptr->data);
    }
    printf("\n");
}

void insert(int item, listnode** first, listnode* x){
    listnode* tmp;
    tmp=malloc(sizeof(listnode));
    tmp->data = item;
    if(*first){
        tmp->link = x->link;
        x->link = tmp;
    }
    else{
        tmp->link = NULL;
        *first = tmp;
    }
}

void delete(listnode** first, listnode* x){
    listnode* tmp =*first;
    if(tmp==x){
        *first=tmp->link;
        tmp=NULL;
        free(tmp);
    }
    else{
        if(tmp==NULL) printf("err : the list is empty\n");
        while((tmp->link)!=x && (tmp->link)!=NULL){ /* ptr을 x전 또는 끝까지 이동*/
            tmp=tmp->link;
        }
        if(tmp->link==x){
            tmp->link=x->link;
            free(x);
        }
        else printf("err : no such x in the list\n");
    }
}