#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    int isbn;
    char author[12];
    char* title;
    bool ishere;
} book;

void render_menu();
void add(book b);
book retrieve_by_isbn(int n);
book retrieve_by_author(char a[]);
book retrieve_by_title(char* t);

book library[];
char* menu[5]={
    "1. 도서 번호로 책 찾기", 
    "2. 저자이름으로 책 찾기", 
    "3. 제목으로 책 찾기", 
    "4. 새로운 책 추가", 
    "5. 도서관이 소장한 도서의 수 표시"};

int main(){

}

void render_menu() {
    printf("==========================\n");
    for(int i=0; i<5; i++){
        printf("%s \n", menu[i]);
    }
    printf("==========================\n");
}

int select(int *n){
    
}

void add(book b){

}

book retrieve_by_isbn(int n){

}

book retrieve_by_author(char a[]){

}

book retrieve_by_title(char *t){

}