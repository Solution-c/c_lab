#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <conio.h>

struct student {
    int num;
    char name[10];
    double grade;
};

struct point {
    int x;
    int y;
};

struct select{
    int x;
    char* s;
};

struct question{
    char* question;
    struct select list[4];
    int stdasnwer;
    int ranswer;
};

double distance(struct point p,struct point q){
    return sqrt(pow((double)(p.x-q.x),(double)2) + pow((double)(p.y-q.y),(double)2));
}
void render(struct question q){
    int i;
    printf("%s\n", q.question);
    for(i=0;i<4;i++){
        printf("%d. %s   ", q.list[i].x, q.list[i].s);
    }
}

void get_stdanswer(int *a){

    printf("������ �Է��ϼ��� : ");
    scanf("%d", a);
    getchar();
}

bool check(struct question q){
    printf("�Է´� : %d, ���� : %d, %s \n",  q.stdasnwer, q.ranswer,q.stdasnwer==q.ranswer?"�����Դϴ�.":"Ʋ�Ƚ��ϴ�." ); 
    return q.stdasnwer==q.ranswer? true:false;
}


int main(void){
    struct question qlist[2]={
        { "�Ӻ���� ��ġ�� ���� ������ ���α׷��� ����?", 
    {{1, "Python"}, {2, "Java"}, {3, "C"}, {4, "JavaScript"}}, 0, 3},
     { "���� �ٸ� �ڷ����� ���� �� �ִ� ������?", 
    {{1, "�迭"}, {2, "������"}, {3, "����ü"}, {4, "����"}}, 0, 3}
    };
        for(int i=0; i<2; i++){
            printf("[%d] ", i+1);
            render(qlist[i]);
            get_stdanswer(&qlist[i].stdasnwer);
            check(qlist[i]);
           
    }
    printf("�ƹ� Ű�� �Է��Ͻø� ����˴ϴ�.");
    _getch();

    return 0;
}

