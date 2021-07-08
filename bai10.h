#include <stdio.h>
#include <myfunctions.h>

void bai10()
{
    int n;
    printf("nhap n: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        if (isAmstrong(i))
            printf("%d la so Amstrong\n", i);
    }
}