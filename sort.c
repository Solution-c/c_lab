#include <stdio.h>
#define SIZE 10



int main() {
    int price[SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int i,j,k, check, count=0;
    int box;

    for(j=0;j<SIZE-1;j++){
        check = 0;
        for(i=0;i<SIZE-j-1;i++){
            
            if(price[i]<price[i+1]){
                
            }
            else{
                box = price[i+1];
                price[i+1]=price[i];
                price[i]=box;
                check++;
                count++;
                
            }
        }

        if(check==0){
                printf("%d번 교환의 결과 배열이 완료되었습니다.\n", count);
                break;
        }

    }
     

    return 0;
}
