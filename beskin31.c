#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    // ���� ����
    int nos =31;

    //���� ����    
    int x, y, winner;

    do {
        printf("���� ��ƽ�� ���� : %d \n", nos);
        if(nos==1){
            printf("������ �� �ִ� ��ƽ�� ������ 1���ۿ� ���� �ʾҽ��ϴ�.\n");
            winner=2;
            break;
        }
        do{
            winner = 1;
            printf("������ ��ƽ�� ������ �Է��ϼ��� (1~3��):\n");
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
                    printf("������ �� �ִ� ��ƽ�� ������ 1���ۿ� ���� �ʾҽ��ϴ�.\n");
                    winner=1;
                    break;
                }
                else {
                    y = nos-1;
                }
             }

                printf("**��ǻ�ʹ� %d���� ��ƽ�� ���������ϴ�. ** \n\n",y);
                nos = nos -y;   
        }
        else {
            break;
        }
    } while (nos>0) ;
    printf("!!��ƽ�� ������ 0�� �Ǿ����ϴ�!! \n");
    printf("���ڴ� %s �Դϴ�. \n", winner==1? "�÷��̾�":"��ǻ��");
    return 0;


}