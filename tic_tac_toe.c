#include <stdio.h>
#include <stdbool.h>

int main() {
    int board[3][3]={{0,0,0},{0,0,0},{0,0,0}};
    int x, y, i , j;
    bool player = true;
    int round = 1;

    for(round; round<10; round ++){
        do{
            printf("좌표를 입력하세요:");
            scanf("%d %d", &x, &y);
            } while((board[x-1][y-1]==1)||(board[x-1][y-1]==2));
        if(player){
            board[x-1][y-1] = 1;
        }
        else {
            board[x-1][y-1] =2;
        }
        player = !player;
        printf("---|---|---\n");
        for(i=0;i<3;i++){
            for(j=0;j<3;j++){
                switch (board[i][j]){
                case 1:
                    printf(" X ");
                    break;
                case 2:
                    printf(" O ");
                    break;
                default:
                    printf("   ");
                    break;
                }
                if(j==2){
                    printf("\n");
                }
                else{
                    printf("|");
                }
            }
            printf("---|---|---\n");
        }

    }
    return 0;
}