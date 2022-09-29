#include <stdio.h>
#include <conio.h>
#include <windows.h>
void get_dir();
static int xpos=0, ypos=1;

int main(){
    char board[10][10]={
        {'#','#','#','#','#','.','.','.', '.','.'},
        {'.','.','.','.','.','#','.','.', '.','.'},
        {'#','#','#','#','.','.','#','.', '.','.'},
        {'.','.','.','.','#','.','.','#', '.','.'},
        {'.','.','.','.','.','#','.','#', '.','.'},
        {'.','.','.','.','.','#','.','#', '.','.'},
        {'.','.','.','.','.','#','.','#', '.','.'},
        {'.','.','.','.','.','#','.','#', '#','#'},
        {'.','.','.','.','.','#','.','.', '.','.'},
        {'.','.','.','.','.','#','#','#', '#','#'}
    };
    //시작위치 표시
    board[ypos][xpos]='@';

    while(1){
        system("cls");
        // 보드 출력
        for(int y=0;y<10;y++){
            for(int x=0;x<10;x++){
                printf("%c", board[y][x]);    
            }
            printf("\n");
        }
        board[ypos][xpos]='.';
        get_dir();
        board[ypos][xpos]='@';
        }
    return 0;
}

void get_dir(){
    // 이동방향 입력 
    char dir = _getch();
    switch(dir){
        case 'K':
            xpos--;
            break;
        case 'M':
            xpos++;
            break;
        case 'H':
            ypos--;
            break;
        case 'P':
            ypos++;
            break;
    }
}