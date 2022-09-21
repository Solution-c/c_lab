#include <stdio.h>
#define ROWS 3
#define COLS 3

int main() {
    int A[ROWS][COLS]={{1,0,0},{0,1,0},{0,0,1}};
    int B[ROWS][COLS]={{1,0,0},{0,1,0},{0,0,1}};
    int ADD[ROWS][COLS]={0};
    int i, j;
    
    for(i=0;i<ROWS;i++){
        for(j=0;j<COLS;j++){
            ADD[i][j] = A[i][j]+B[i][j];
            printf("%d",ADD[i][j]);
        }
        printf("/");
    }
    return 0;
}