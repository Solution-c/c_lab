#include <stdio.h>

int main() {
    float x;
    float y;

    x = 300000.000000;
    y = 149600000.000000;

    printf("���� �ӵ��� : %f km/s \n", x);
    printf("�������� �Ÿ��� : %f km \n", y);
    printf("���޽ð��� %f ��.", y/x/60);
    return 0;
    }