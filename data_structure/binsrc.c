#include <stdio.h>
#include <stdbool.h>
#define cmp(x,y) ((x==y)? 0:((x>y)? 1:-1))


int binsrc(int a[], int size, int key);
int modify(int a);

int main() {
    printf(" %d ", cmp(1,2));
    printf(" %d ", cmp(3,3));
    printf(" %d ", cmp(2,1));

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