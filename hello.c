#include <stdio.h>

int main() {
    float x;
    float y;

    x = 300000.000000;
    y = 149600000.000000;

    printf("빛의 속도는 : %f km/s \n", x);
    printf("지구와의 거리는 : %f km \n", y);
    printf("도달시간은 %f 분.", y/x/60);
    return 0;
    }