#include <stdio.h>
#include "myfunctions.h"

void bai9()
{
    int n;
    printf("nhap n: "); scanf("%d", &n);
    printf("%sLa so chinh phuong\n", isSquare(n) ? "" : "Khong ");
    printf("%sLa so nguyen to\n", isPrime(n) ? "" : "Khong ");
    printf("%sLa so doi xung\n", isSymetric(n) ? "" : "Khong");
}