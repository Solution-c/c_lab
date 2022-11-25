#include <stdio.h>
#include <stdlib.h>

void convert(int val, int *a);

int main(){
    int a = 1;
    convert(2, &a);
    printf("%d", a);

}

void convert(int val, int *a){
    *a = val;
}

