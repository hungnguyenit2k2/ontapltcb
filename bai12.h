#include <stdio.h>
#include <myfunctions.h>

void bai12()
{
    int arr[1000] = {0}, n;
    printf("nhap n: ");
    scanf("%d", &n);
    nhapDay(arr, n);
    inDay(arr, n);
    sapXepDay(arr, n);
    inDay(arr, n);

    // 2 ý cuối không hiểu đề hỏi gì luôn :v
}