#include <stdio.h>
#define SIZE 

void modify(int *ptr){
    *ptr = 99;
}

int main() {
    int a[] = {10, 20, 30, 40, 50};
    int *p;
    p = a;
    printf("%d", a[6]);
    
}