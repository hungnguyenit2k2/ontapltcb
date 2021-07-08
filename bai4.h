#include <stdio.h>
#include "myfunctions.h"
void bai4()
{
    int n;
    printf("Nhap n: ");
    scanf("%d", &n);
    float s1 = 0, s2 = 0;
    ;
    for (int i = 1; i <= n; i++)
    {
        s1 += 1 / (float)(i * (i + 1));
        s2 += 1 / tong1deni(i);
    }
    printf("tong 1: %f \ntong 2: %f", s1, s2);
}