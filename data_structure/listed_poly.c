#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
//#define DEBUG

typedef struct polynode{
    int coef;
    int exp;
    struct polynode* link;
}polynode;
typedef polynode* polyPointer;
typedef struct node{
    int data;
    struct node* link;
}stack;

int ipow(int a, int n){ /* power function for integer (a^n) */
    if(n==0) return 1;
    int result=a;
    for(n;n!=1;n--){
        result = result*a;
    }
    return result;
}

polyPointer create();
void attach(int coef, int exp, polyPointer* rear);
void printStack();
polyPointer getNode();
polyPointer avail=NULL;
stack *top=NULL; void push(int item); int pop();
int n=0; /* stack item 개수 카운터 */
void retNode(polyPointer* node);
polyPointer smult(int coef, int exp, polyPointer polynomial);

/* example function defined*/
polyPointer pread(char* polyexpr);
void pwrite(polyPointer polynomial);
polyPointer padd(polyPointer polynomial1, polyPointer polynomial2);
polyPointer psub(polyPointer polynomial1, polyPointer polynomial2);
polyPointer pmult(polyPointer polynomial1, polyPointer polynomial2);
int eval(polyPointer polynomial, int a);
void perase(polyPointer* polynomial);

int main() {
    polyPointer p, q, r;
    p = pread("x^2+1");
    q = pread("x-1");
    r = pmult(p, q);
    pwrite(r);

    int i = eval(p,2);
    printf("%d\n", i);

    perase(&r);
}

polyPointer create(){
    polyPointer empty;
    empty = getNode();
    empty->coef = 0;
    empty->exp = -1;
    empty->link =empty;
    return empty;
}

void attach(int coef, int exp, polyPointer* rear){
    if(coef){
        polyPointer ptr, tmp;
        ptr = getNode();
        ptr->coef = coef;
        ptr-> exp  = exp;
        tmp = (*rear)->link;
        (*rear)->link = ptr;
        ptr->link = tmp;
        (*rear) = ptr;
    }
}

polyPointer getNode(){
    polyPointer loc,tmp;
    if(avail!=NULL){
        tmp = avail->link;
        loc = avail;
        avail = tmp;
    }
    else loc = malloc(sizeof(polynode));
    return loc;
}

void retNode(polyPointer* node){
    (*node)->link = avail;
    avail = *node; 
}

void push(int item){
    stack* tmp;
    tmp = malloc(sizeof(struct node));
    tmp->data = item;
    if(top!=NULL){
        tmp->link = top;
        top = tmp;
    }
    else{
        tmp->link = NULL;
        top = tmp;
    }
    n++;
}

int pop(){
    stack* tmp=top;
    if(top==NULL) {printf("err: stack empty");return 0;}
    else{
        int item = top->data;
        top = tmp->link;
        free(tmp);
        n--;
        return item;
    }
}

void printStack(){
    printf("num of items : %d \n", n);
    stack *ptr=top;
    for(;ptr;ptr=ptr->link){
        printf(" %d ", ptr->data);
    }
    printf("\n");
}

polyPointer pread(char* polyexpr){
    char* p=polyexpr; /* 문자열 포인터 */
    bool positive=true; /* 계수의 부호 저장*/
    bool lastx=false; /* 마지막 x 유무 */
    int coef=0, exp=0;
    polyPointer result=create(), ptr;
    ptr = result;
    if(*p=='-') {positive=false; p++;} /*첫 - 처리*/
    for(p;*p!='\0';p++){
        if(isdigit(*p)) {
            push(*p-'0');
        }
        else switch(*p){
            case 'x':
                lastx=true;
                if(n==0) coef=1;
                else for(int k=0;n!=0;k++) {coef = coef+(pop()*(ipow(10,k)));}
                if(!positive) {
                    coef = coef*(-1);
                    positive = true;
                }
                break;
            case '^' : break;
            case '+' :
                if(n==0) exp=1;
                else for(int k=0;n!=0;k++){exp = exp+(pop()*(ipow(10,n)));}
                attach(coef, exp, &ptr);
                coef=0;exp=0; lastx=false;
                break;
            case '-' : 
                positive = false;
                if(n==0) exp=1;
                else for(int k=0;n!=0;k++) {exp = exp+(pop()*(ipow(10,n)));}
                attach(coef, exp, &ptr);
                coef=0;exp=0; lastx=false;
                break;
        }
    }
    if(coef==0 && n!=0) { /* +3 과 같이 상수로 끝난경우 (stack에 저장되어있으나 coef에 저장되지 않음)*/
        for(int k=0;n!=0;k++) {coef = coef+(pop()*(ipow(10,k)));}
        if(!positive) coef=coef*(-1);
        exp=0;
    }
    else if(coef!=0){ /* 3x 또는 3x^2와 같이 x가 호출 된 경우*/
        if(n==0){
            if(lastx) exp=1;
            else exp=0;
        }
        else for(int k=0;n!=0;k++) {exp = exp+(pop()*(ipow(10,n)));}
    }
    attach(coef, exp, &ptr);
    return result;
}

void pwrite(polyPointer polynomial){
    polyPointer ptr;
    ptr = polynomial->link; //skip header
    if(polynomial==ptr) {printf("NULL(polynomial)");}
    else{
        printf("%dx^%d", ptr->coef, ptr->exp);
        ptr = ptr->link;
        for(;ptr->exp!=-1;ptr=ptr->link){
            if(ptr->coef<0) printf("%d", ptr->coef);
            else {
                printf("+%d", ptr->coef);
            }
            if(ptr->exp!=0) printf("x^%d", ptr->exp);
        }
    }
    printf("\n");
}

polyPointer padd(polyPointer p1, polyPointer p2){
    polyPointer result=create(), ptr;
    int sum;
    p1=p1->link; p2=p2->link; /*skip header*/
    ptr=result;
    while(((p1->exp)!=-1) && ((p2->exp)!=-1)){
        if(p1->exp > p2->exp){
            #ifdef DEBUG
            printf("case1 p1->coef: %d, p1->exp: %d\n", p1->coef,p1->exp);
            #endif
            attach(p1->coef, p1->exp, &ptr);
            p1=p1->link;
            }
        else if(p1->exp == p2->exp){
            sum = (p1->coef)+(p2->coef);
            #ifdef DEBUG
            printf("case0 sum: %d, p1, p2->exp:%d, %d\n", sum, p1->exp, p2->exp);
            #endif

                attach(sum, p1->exp, &ptr); 
                p1=p1->link; p2=p2->link;
        }
        else if(p2->exp > p1->exp){
            #ifdef DEBUG
            printf("case-1 p2->coef: %d, p2->exp: %d\n", p1->coef,p1->exp);
            #endif
            attach(p2->coef, p2->exp, &ptr);
            p2=p2->link;
            }
        }
    for(;((p1->exp)!=-1);p1=p1->link) { /*copy remain*/
        #ifdef DEBUG
        printf("copy p1->coef: %d, p1->exp: %d\n", p1->coef,p1->exp);
        #endif
        attach(p1->coef,p1->exp,&ptr);
        } 
    for(;((p2->exp)!=-1);p2=p2->link) {
        #ifdef DEBUG
        printf("copy p2->coef: %d, p2->exp: %d\n", p2->coef,p2->exp);
        #endif
        attach(p2->coef,p2->exp,&ptr);
        }
    return result;
}

polyPointer smult(int coef, int exp, polyPointer p){
    polyPointer result=create(), ptr;
    ptr = result;
    p=p->link; /*skip header*/
    if(coef!=0){
        for(;(p->exp)!=-1;p=p->link){
            attach((p->coef)*coef, exp+(p->exp), &ptr);
        }
    }
    return result;
}

polyPointer psub(polyPointer p1, polyPointer p2){
    polyPointer result = create(), p2inv;
    p2inv = smult(-1, 0, p2);
    result = padd(p1, p2inv);
    return result;
}

polyPointer pmult(polyPointer p1, polyPointer p2){
    polyPointer result = create(), ptr;
    p2=p2->link;
    for(; p2->exp!=-1; p2=p2->link){
        result = padd(result, smult(p2->coef, p2->exp, p1));
        #ifdef DEBUG
        pwrite(result);
        #endif
    }
    return result;
}

int eval(polyPointer p, int a){
    int result=0;
    p=p->link;
    for(;p->exp!=-1;p=p->link){
        result = result+(p->coef)*ipow(a,p->exp);
    }
    return result;
}

void perase(polyPointer* p){
    polyPointer tmp = (*p)->link;
    (*p)->link = avail;
    avail = tmp;
}