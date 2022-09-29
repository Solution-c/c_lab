#include <stdio.h>
#define SIZE 10
int find_smllst(int A[], int i);
void print_array(int A[]);


int main() {
    int i, j, t;
    int A[]= {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    
    for(i=0;i<SIZE;i++){
    j = find_smllst(A, i);
    t = A[i]; A[i]=A[j]; A[j]=t;
    print_array(A);
    }
    
    print_array(A);
}

// array A와 찾기 시작하고자 하는 위치를 입력받아 최솟값의 위치 반환
int find_smllst(int A[], int i) {
    int s=i, j;
    for(j=i+1;j<SIZE;j++){
        if(A[j]<A[s]){
            s = j;
        }
    }
    return s;
}

//
void print_array(int A[]){
    int i;

    printf("[");
    for(i=0;i<SIZE;i++){
        printf("%d ", A[i]);
    }
    printf("]\n");
}

