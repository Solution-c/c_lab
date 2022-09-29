#include <stdio.h>
#include <stdbool.h>
#define cmp(x,y) ((x==y)? 0:((x>y)? 1:-1))

typedef struct {
    double coef[50];
    int exp[50];
} polynomial;

polynomial zero = {{0},{0}};
int binsrc(int a[], int size, int key);
bool iszero(polynomial p);
int countTerm(polynomial p);
polynomial retrieve(polynomial p, int i);
void setPoly(polynomial* p, int i, int j, double a);
void printPoly(polynomial p);
polynomial rem(polynomial* p, int i);
polynomial attach(polynomial* p, int i, double key);
polynomial padd(polynomial* p, polynomial* q);
int print_array(int A[], int size);


int main() {
    polynomial p = {{2,3,4,5}, {5,4,3,1}};
    polynomial q=zero;
    attach(&p, 3, 1);
    attach(&p, 0, 1);
    attach(&p, 0, 2);
    rem(&p, 4);
    printPoly(p);
}

int binsrc(int a[], int size, int key){
    int init=0, term=size-1;
    while(init<=term){
        int mid = (init+term)/2;
        switch(cmp(key, a[mid])){
            case 0:
                return mid;
                break;
            case 1:
                term = mid-1;
                break;
            case -1:
                init = mid+1;
                break;
    }
    if(init>term){
        return -1;
    }
}
}

bool iszero(polynomial p){
    if(p.coef[0]==0 && p.exp[0]==0){
        return true;
    }
    else return false;
}

int countTerm(polynomial p){
    int count = 0;
    for(int i=0; i<p.exp[0]+1; i++){
        if(p.coef[i]>0){
            count++;
        }
    }
    return count;
}

polynomial retrieve(polynomial p, int i){
    for(int j=0;j<countTerm(p);j++){
        if(p.exp[j]==i){
            return (polynomial){{p.coef[j]},{p.exp[j]}}; 
            break;
        }
    }
    return zero;
}

void setPoly(polynomial* p, int i, int j, double a){
    p->exp[i] = j;
    p->coef[i]= a;
}

void printPoly(polynomial p){
    int n=countTerm(p), i;
    printf("\n");
    for(i=0;i<n;i++){
        if(p.exp[i]==0){
            break;
        }
        else{
            if(i==0) printf("%6d", p.exp[i]);
            else printf("%8d", p.exp[i]);
        }
    }
    printf("\n");
    for(i=0;i<n;i++){
        if(i==n-1&&p.exp[i]!=0){
            printf("%2.1lf x", p.coef[i]);
            }
        else if(p.exp[i]==0) printf("%2.1f", p.coef[i]);
        else printf("%2.1lf x + ", p.coef[i]);
    }
    printf("\n");
}

polynomial attach(polynomial *p, int i, double a){
    if(a==0) return *p;
    int n=iszero(*p)?1:countTerm(*p);
    if(!iszero(retrieve(*p, i))){
        int j = binsrc(p->exp,countTerm(*p),i);
     setPoly(p, j, i, a);
    }
    else if(i ==0) setPoly(p, n, i, a);
    else {
        for(int j=0;j<n;j++){
            if(p->exp[j]<i){
                for(int k=n; k>=j;k--){
                 setPoly(p, k+1, p->exp[k], p->coef[k]);
                }
             setPoly(p, j, i, a);
                break;
            }
    }
    }
}


polynomial rem(polynomial* p, int i){
    if(!iszero(retrieve(*p,i))){
        for(int j=binsrc(p->exp,countTerm(*p),i)+1;j<countTerm(*p)+1;j++){
            setPoly(p,j-1, p->exp[j], p->coef[j]);
        }
    }
    else return *p;
}


polynomial padd(polynomial* p, polynomial* q) {
    polynomial r;
    while(!iszero(*p)&& !iszero(*q)){
        switch(cmp(p->exp[0], q->exp[0])){
            case 1: 
                attach(&r, p->exp[0], p->coef[0]);
                rem(p, 0);
            case 0:
                attach(&r, p->exp[0], p->coef[0]+q->coef[0]);
                rem(p,0); rem(q,0);
            case -1:
                attach(&r, q->exp[0], q->coef[0]);
                rem(q, 0);
        }
    }
    return r;
}

int print_array(int A[], int size){
    int i;
    printf("[");
    for(i=0;i<size;i++){
        printf("%d ", A[i]);
    }
    printf("]\n");
}