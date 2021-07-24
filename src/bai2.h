#include <stdio.h>

void bai2()
{
    int n;
    printf("nhap n: ");
    scanf("%d", &n);
    int count = 0;
    for (int m = 13; m <= n; m++)
    {
        int k = m;
        int max = k % 10, min = k % 10;
        while (k != 0)
        {
            if (min > k % 10)
                min = k % 10;
            if (max < k % 10)
                max = k % 10;
            k /= 10;
        }
        if ((max - min) == 2)
        {
            printf("%d\n", m);
            count++;
        };
    }
    printf("co %d so", count);
}