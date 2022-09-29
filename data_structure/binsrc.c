#include <stdio.h>
#include <stdbool.h>
#define cmp(x,y) ((x==y)? 0:((x>y)? 1:-1))

typedef struct {
    double coef[50];
    int exp[50];
} polynomial;




int binsrc(int a[], int size, int key);
int modify(int a);

int main() {
    polynomial p = {{0},{0}};
    setPolynomial(&p, 0, 2, 2.0);
    printf("%lf", p.coef[0]);

}



int binsrc(int a[], int size, int key){
    int init=0, term=size-1;
    while(init<=term){
        int mid = (init+term)/2;
        switch(cmp(a[mid], key)){
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
        return false;
    }
}
}

int modify(int a) {
    *(&a) = 999;
}