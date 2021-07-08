#include <stdio.h>
#include "myfunctions.h"

void bai8()
{
    int arr[20] = {0};
    int n;
    printf("nhap n: ");
    scanf("%d", &n);
    tryNextArray(arr, n, 0);
}