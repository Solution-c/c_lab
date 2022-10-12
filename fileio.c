#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define MAX_SIZE 100

typedef struct book{
    int num;
    char title[300];
    char author[100];
    int ishere;
}book;

void filecheck(FILE *fp);
void render();
void select();
void add();
void load();
void show(int num);
int search();
void borrow();
void breturn();
void repeat();

int sel;
bool isadded;
bool isloaded;
book lib[MAX_SIZE];

int main() {
    render();
    return 0;
}

void filecheck(FILE* fp){
    if (fp==NULL) {
        printf("데이터 로딩 실패\n");
        exit(1);
    }
    else printf("데이터 로딩 성공\n");
}
void render(){

    do{
        printf("---------------------\n");
        printf("1. 검색\n");
        printf("2. 추가\n");
        printf("3. 대출\n");
        printf("4. 반납\n");
        printf("5. 종료\n");
        printf("---------------------\n");
        printf("선택:");
        scanf("%d", &sel);
        }while(sel<1||sel>5);
    select();
}
void load(){
    int n=0;   
    FILE *fp;
    fp = fopen("list.txt","r");
    filecheck(fp);
    while(!feof(fp)){
        fscanf(fp, "%d", &n);
        lib[n].num = n;
        fscanf(fp, ", %[^,]s", lib[n].title);
        fscanf(fp, ", %[^,]s", lib[n].author);
        fgetc(fp);
        fscanf(fp, "%d", &lib[n].ishere);
        fgetc(fp);
    }
    fclose(fp);
    isloaded = true;
    isadded = false;
}

void select(){
    switch(sel){
        case 1: 
            search();
            break;
        case 2:
            add();
            break;
        case 3:
            borrow();
            break;
        case 4:
            breturn();
            break;
        case 5:
            exit(1);
            break;
    }
    repeat();
}

void add(){
    FILE* fp;
    int num=0;
    char title[50]={'\0'};
    char author[15]={'\0'};
    
    fp = fopen("list.txt", "a+");
    filecheck(fp);
    printf("---------------------\n");
    printf("번호 : ");
    scanf("%d", &num);
    getchar();

    printf("제목 : ");
    fgets(title, 50*sizeof(char), stdin);
    title[strlen(title)-1]='\0';
    printf("저자명 : ");
    fgets(author, 15*sizeof(char), stdin);
    printf("---------------------\n");
    author[strlen(author)-1]='\0';

    fprintf(fp, "%04d, %s, %s, 1\n", num, title, author);

    fclose(fp);
    bool isadded = 1;
}

void show(int num){
    if(!isloaded || isadded) load();
    printf("---------------------\n");
    printf("\n num : %04d", lib[num].num);
    printf("\n title : %s", lib[num].title);
    printf("\n author : %s", lib[num].author);
    printf("\n ishere : %d\n", lib[num].ishere);
    printf("---------------------\n");
}

int search(){
    int num;
    char s;

    printf("[검색] 책 번호:");
    scanf("%d", &num);
    getchar();
    show(num);
    return num;
}

void repeat(){
    char c;
    printf("계속합니까?(y/n):");
    scanf("%c", &c);
    getchar();
    switch(c){
        case 'y':
            select();
            break;
        case 'n':
            render();
            break;
        default :
            repeat();
            break;
    }
}

void borrow(){
    int num = search();
    if(lib[num].ishere ==1){
        lib[num].ishere = 0;
        printf("%s 대출 성공\n", lib[num].title);
        show(num);
    }
    else if(lib[num].ishere ==0){
        printf("대출 불가능\n");
    }
}

void breturn(){
    int num = search();
    lib[num].ishere = 1;
    printf("%s 반납 성공\n", lib[num].title);
    show(num);
}