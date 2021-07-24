#include <stdio.h>
#include <math.h>

void bai5()
{
    // khai báo n và x, s1, s2
    int n;
    float x;
    float s1 = 0, s2 = 0;
    printf("nhap n va x: ");
    scanf("%d %f", &n, &x);
    // duyệt i từ 1 đến 2n+1
    for (int i = 1; i <= 2 * n + 1; i++)
        if (i % 2 == 0) // nếu i chẵn thì nhân s + với x^i
            s1 += pow(x, i);
        else
            s2 += pow(x, i); // nếu i chẵn thì nhân s + với x^i
    // in s1 với s2
    printf("s1 = %f, s2 = %f", s1, s2);
}