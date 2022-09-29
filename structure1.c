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

    printf("정답을 입력하세요 : ");
    scanf("%d", a);
    getchar();
}

bool check(struct question q){
    printf("입력답 : %d, 정답 : %d, %s \n",  q.stdasnwer, q.ranswer,q.stdasnwer==q.ranswer?"정답입니다.":"틀렸습니다." ); 
    return q.stdasnwer==q.ranswer? true:false;
}


int main(void){
    struct question qlist[2]={
        { "임베디드 장치에 가장 적합한 프로그래밍 언어는?", 
    {{1, "Python"}, {2, "Java"}, {3, "C"}, {4, "JavaScript"}}, 0, 3},
     { "서로 다른 자료형을 모을 수 있는 구조는?", 
    {{1, "배열"}, {2, "포인터"}, {3, "구조체"}, {4, "변수"}}, 0, 3}
    };
        for(int i=0; i<2; i++){
            printf("[%d] ", i+1);
            render(qlist[i]);
            get_stdanswer(&qlist[i].stdasnwer);
            check(qlist[i]);
           
    }
    printf("아무 키나 입력하시면 종료됩니다.");
    _getch();

    return 0;
}

