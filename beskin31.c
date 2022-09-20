#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    // 개수 세팅
    int nos =31;

    //변수 선언    
    int x, y, winner;

    do {
        printf("현재 스틱의 개수 : %d \n", nos);
        if(nos==1){
            printf("가져올 수 있는 스틱의 개수가 1개밖에 남지 않았습니다.\n");
            winner=2;
            break;
        }
        do{
            winner = 1;
            printf("가져올 스틱의 개수를 입력하세요 (1~3개):\n");
            scanf("%d",&x);
            if(nos==x) {
            winner=2;
            break;
            }
            } while (!((x<=nos)&&(x>0)&&(x<4)));
         nos = nos - x;
         
        if(nos>0) {
             winner = 2;
             if(nos>3){
                do {
                    srand(time(NULL));
                    y = rand()%3 + 1;
                } while (x>nos);
             }
             else {
                if(nos ==1){
                    printf("가져올 수 있는 스틱의 개수가 1개밖에 남지 않았습니다.\n");
                    winner=1;
                    break;
                }
                else {
                    y = nos-1;
                }
             }

                printf("**컴퓨터는 %d개의 스틱을 가져갔습니다. ** \n\n",y);
                nos = nos -y;   
        }
        else {
            break;
        }
    } while (nos>0) ;
    printf("!!스틱의 개수가 0이 되었습니다!! \n");
    printf("승자는 %s 입니다. \n", winner==1? "플레이어":"컴퓨터");
    return 0;


}