#include <stdio.h>
#define SIZE 10



int main() {
    int price[SIZE] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int i,j,k;
    int box;

    for(j=0;j<SIZE-1;j++){
        for(i=0;i<SIZE;i++){
            for(k=0;k<price[i];k++){
                printf("*");
            }
            printf("\n");
        }
        printf("\n");
        for(i=0;i<SIZE-j-1;i++){
            if(price[i]<price[i+1]){
                
            }
            else{
                box = price[i+1];
                price[i+1]=price[i];
                price[i]=box;
            }
    
        }
        
    }
     
    for(i=0;i<SIZE;i++){
            for(k=0;k<price[i];k++){
                printf("*");
            }
            printf("\n");
        }
    return 0;
}
