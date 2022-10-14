#include <stdio.h>
#include <stdbool.h>

typedef struct position{
    int row;
    int col;
}position;

typedef struct mindex{
    int index;
    bool exist;
} mindex;

typedef struct matrix {
    int offset[3];
    position pos[50];
    int value[50];
} matrix;

matrix zero={{0, 0, 0}, {0,0}, {0}};
void setOffset(matrix* A, int * offset);
void printOffset(matrix A);
matrix remIndex(matrix A, int index);
mindex findex(matrix A, position pos);
void printMI(matrix A, position pos);
void printMat(matrix A);
matrix setValue(matrix A, position pos, int value);

int main(){
    matrix A={{6, 6, 8},
    {{1, 1}, {1, 4}, {1, 6}, {2, 2}, {2, 3}, {3, 4}, {5, 1}, {6, 3}},
    {15, 22, -15, 11, 3, -6, 91, 28}};
    matrix B;
    printf("%d %d", A.pos[8].row, A.pos[8].col);
}


void setOffset(matrix* A, int * offset){
    for(int i=0; i<3; i++) A->offset[i]=offset[i];
}

void printOffset(matrix A){
    printf("{%d, %d, %d}\n", A.offset[0], A.offset[1], A.offset[2]);
}

void printMat(matrix A){
    for(int i=0;i<A.offset[2];i++){
    printf("(%d, %d) %d \n",A.pos[i].row, A.pos[i].col, A.value[i]);
    }
}

matrix remIndex(matrix A, int index){
    matrix B=zero;
    B.offset[0]=A.offset[0];
    B.offset[1]=A.offset[1];
    B.offset[2]=A.offset[2]-1;
    for(int j=index; j<A.offset[2];j++){
        B.pos[j].row = A.pos[j+1].row;
        B.pos[j].col = A.pos[j+1].col;
        B.value[j] = A.value[j+1];
    }
   return B;
}

mindex findex(matrix A, position pos){
    int p=0;
    while(A.pos[0].row<pos.row){
        A=remIndex(A,0);
        p++;
    }
    if (A.pos[0].row==pos.row){
        while(A.pos[0].col<pos.col){
        A=remIndex(A,0);
        p++;
        }
        if(A.pos[0].col==pos.col) return (mindex){p, true};
        else return (mindex){p, false};
    }
    else return (mindex){p, false};
}

void printMI(matrix A, position pos){
    printf("%d %d\n", findex(A, pos).index, findex(A, pos).exist);
}


matrix setValue(matrix A, position pos, int value){
    matrix B=zero;
    int i=0, j=0;
    B.offset[0]=A.offset[0];
    B.offset[1]=A.offset[1];
    B.offset[2]=A.offset[2]+1;

    }
