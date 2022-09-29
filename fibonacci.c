#include <stdio.h>
int fib(int n);

int main() {
    printf("%d\n",fib(10));
    return 0;
}

int fib(int n){
    switch(n){
        case 0 :
            return 0;
        case 1 :
            return 1;
        default :
            return fib(n-1)+fib(n-2);
    }
}