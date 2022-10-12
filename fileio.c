#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define MAX_SIZE 100

typedef struct book{
    int num;
    char title[50];
    char author[50];
    int ishere;
}book;

void filecheck(FILE *fp);
bool isadded;
void add();
void load();
void show(int num);
bool isloaded;
book lib[MAX_SIZE];

int main() {
    int sel;
    do{
        printf("----------------------------------\n");
        printf("1. 책 번호로 검색\n");
        printf("2. 책 정보 추가");
        printf("3. 대출");
        printf("----------------------------------\n");
        scanf("%d", &sel);
        }while(0<sel&&sel<5);
    return 0;
}

void filecheck(FILE* fp){
    if (fp==NULL) {
        printf("파일 로딩 실패");
        exit(1);
    }
    else printf("파일 로딩 성공");
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

void add(){
    FILE* fp;
    int num;
    char title[50];
    char author[15];
    
    fp = fopen("list.txt", "a+");
    filecheck(fp);

    printf("\n번호 : ");
    scanf("%d", &num);
    getchar();

    printf("제목 : ");
    fgets(title, 50*sizeof(char), stdin);
    title[strlen(title)-1]='\0';
    printf("저자명 : ");
    fgets(author, 15*sizeof(char), stdin);
    author[strlen(author)-1]='\0';

    fprintf(fp, "%04d, %s, %s, 1\n", num, title, author);

    fclose(fp);
    bool isadded = 1;
}

void show(int num){
    if(!isloaded || isadded) load();
    printf("\n num : %04d", lib[num].num);
    printf("\n title : %s", lib[num].title);
    printf("\n author : %s", lib[num].author);
    printf("\n ishere : %d\n", lib[num].ishere);
}
