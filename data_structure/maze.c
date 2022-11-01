#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_STACK_SIZE 100 //m*p

typedef struct {
    short int x;
    short int y;
} offsets;
offsets move[8] = {{-1,0}, {-1,1}, {0,1}, {1,1}, {1, 0}, {1,-1}, {0,-1}, {-1,-1}};

typedef struct {
    short int row;
    short int col;
    short int dir;
} element;

element stack[MAX_STACK_SIZE];
void add(element e);
element pop();
int maze[13][17];
int top=0;
void load_maze();
void set_dir();


int main() {
    load_maze();
    add((element){1, 0, 0});
    for(int i = 0; i<13; i++){
        for(int j=0; j<17; j++){
            printf(" %d ", maze[i][j]);
        }
        printf("\n");
    }
    while(stack[top].row != 11 || stack[top].col!= 15){
        set_dir();
    }
}

void add(element e){
    top++;
    stack[top].row = e.row;
    stack[top].col = e.col;
    stack[top].dir = e.dir;
}

element pop(){
    return stack[top--];
}

void load_maze(){
    FILE* fp;
    fp = fopen("maze.txt", "r");
    for(int i=0;i<17;i++){
        maze[0][i]=1;
        maze[12][i]=1;
    }
    for(int j=1; j<12; j++){
        maze[j][0] =1; maze[j][16]=1;
        for(int i=1; i<16; i++){
            fscanf(fp, "%d", &maze[j][i]);

        }
    }
    fclose(fp);
}

void set_dir(){
    printf("%d %d %d \n", stack[top].row, stack[top].col, stack[top].dir);
    int i=stack[top].dir;
    bool set=false;
    element e;
    int r, c;
    for(i; i<stack[top].dir+8;i++){
        r = stack[top].row;
        c = stack[top].col;
        r = r+move[i%8].x;
        c = c+move[i%8].y;
        if(maze[r][c]==0) {
            e.row = r; e.col = c; e.dir = i%8;
            add(e);
            maze[r][c]=1;
            set = true;
            break;
        }
    }
    if(!set) {
        pop();
    }
    set = false;
}