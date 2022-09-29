#include <stdio.h>
#define SIZE 4

int input(char *s);
int get_max(int x, int y);
void swap(int *x1,int *x2);
float get_avg(int A[], int size);
int search(int A[], int size, int x);
void print_array(int A[], int size);

int main() {
    int a[SIZE] = {1, 2, 3, 4};
    float avg;
    avg = get_avg(a, SIZE);
    printf("%.2f \n", avg);

}


int input(char *s) {
    int x;
    printf("%s",s);
    scanf("%d", &x);
    return x;
}

int get_max(int x, int y){
    return (x<y? y:x);
}

void swap(int *x1 , int *x2){
    int tmp;
    tmp = *x2;
    *x2 = *x1;
    *x1 = tmp;
}

float get_avg(int A[], int size){
    int i;
    float sum=0;
    float avg;
    for(i=0;i<size;i++){
        sum=sum+A[i];
    }
    avg = (float)sum/(float)size;
    return avg;
}

void print_array(int A[], int size){
    int i;

    printf("[");
    for(i=0;i<size;i++){
        printf("%d ", A[i]);
    }
    printf("]\n");
}
