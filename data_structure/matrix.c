#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct matrix{
    int row[50];
    int col[50];
    int val[50];
} matrix;

matrix zero = {{0, 0, 0},'\0', '\0'};
bool iszero(matrix A);
bool nzero(matrix A, int row, int col);
int getRMid(matrix A, int row, int col);
int getCMid(matrix A, int row, int col);
matrix tp(matrix A);
void printM(matrix X);
int getVal(matrix A, int row, int col);
int storesum(matrix A, matrix B, int row, int col);
matrix Mmult(matrix A, matrix B);

int main() {
    matrix A = {{6, 1, 1, 1, 2, 2, 3, 5, 6}, 
                {6, 1, 4, 6, 2, 3, 5, 1, 3}, 
                {8, 15, 22, -15, 11, 3, -6, 91, 28}
    };
    matrix B, C;
    B = tp(A);
    printM(B);
    C = Mmult(A, B);
    printM(C);

}
bool iszero(matrix A){
    if(A.val[0]==0) return true;
    else return false;
}

int getRMid(matrix A, int row, int col){
    int *s= malloc(sizeof(int)*(A.row[0]+1));
    int *t= malloc(sizeof(int)*(A.row[0]+1));
    for(int i=0; i<A.row[0]+1; i++) s[i]=0;
    for(int i=1; i<A.val[0]+1; i++) {
        s[A.row[i]]=s[A.row[i]]+1;
    }
    t[0]=0; t[1]=1;
    for(int i=2; i<A.row[0]+1;i++){
        t[i]=t[i-1]+s[i-1];
    }
    int index = t[row];
    for(int i=0; i<s[row]; i++){
        if(A.col[t[row]+i]<col){
            index++;
        }
    }
    free(s); free(t);
    return index;
}

int getCMid(matrix A, int row, int col){
    int *s = malloc(sizeof(int)*(A.col[0]+1));
    int *t = malloc(sizeof(int)*(A.col[0]+1));
    for(int i=0; i<A.col[0]+1; i++) s[i]=0;
    for(int i=1; i<A.val[0]+1; i++) {
        s[A.col[i]]=s[A.col[i]]+1;
    }
    t[0]=0; t[1]=1;
    for(int i=2; i<A.col[0]+1;i++){
        t[i]=t[i-1]+s[i-1];
    }
    int index = t[col];
    for(int i=0; i<s[col]; i++){
        if(A.row[t[col]+i]<row){
            index++;
        }
    }
    free(s); free(t);
    return index;
}


int getVal(matrix A, int row, int col){
    int n = getRMid(A, row, col);
    return A.val[n];
}

bool nzero(matrix A, int row, int col){
    int n = getRMid(A, row, col);
    if(A.row[n]==row && A.col[n]==col) return true;
    else return false;
}

matrix tp(matrix A){
    matrix B;
    B.row[0] = A.col[0];
    B.col[0] = A.row[0];
    B.val[0] = A.val[0];
    if(iszero(A)) return A;
    int *s = malloc(sizeof(int)*(A.col[0]+1));
    int *t = malloc(sizeof(int)*(A.col[0]+1));
    for(int i=0; i<A.col[0]+1; i++) s[i]=0;
    for(int i=1; i<A.val[0]+1; i++) {
        s[A.col[i]]=s[A.col[i]]+1;
    } 
    t[0]=0; t[1]=1;
    for(int i=2; i<A.col[0]+1; i++){
        t[i]=t[i-1]+s[i-1];
    }
    for(int i=1; i<B.val[0]+1; i++){
        B.row[t[A.col[i]]] = A.col[i];
        B.col[t[A.col[i]]] = A.row[i];
        B.val[t[A.col[i]]] = A.val[i];
        t[A.col[i]]++;
    }
    free(s); free(t);
    return B;
}

void printM(matrix A){
    printf("\n");
    for(int i=1; i<A.row[0]+1; i++){
        printf("[");
        for(int j=1; j<A.col[0]+1; j++){
            if (nzero(A, i, j)) {
                printf(" %4d ", getVal(A, i, j));
            }
            else printf(" %4d ",0);
        }
        printf("]\n");
    }
}

int storesum(matrix A, matrix B, int row, int col){
    int m = A.col[0], n = B.row[0];
    if(m!=n) {
        printf("invalid inner product");
        return false;
    }
    else{
        int sum = 0;
        for(int i=1; i<m+1; i++){
            if(nzero(A, row, i) && nzero(B, i, col))
                sum = sum + getVal(A, row, i)*getVal(B, i, col);
        }
        return sum;
    }
}

matrix Mmult(matrix A, matrix B){
    matrix C;
    C.row[0] = A.row[0];
    C.col[0] = B.col[0];
    int id =0;
    for(int i=1; i<C.row[0]+1; i++){
        for(int j=1; j<C.col[0]+1; j++){
            int vsum = storesum(A, B, i, j);
            if (vsum !=0){
                id++;
                C.row[id] = i;
                C.col[id] = j;
                C.val[id] = vsum;
            }
        }
    }
    C.val[0] = id;
    return C;
}