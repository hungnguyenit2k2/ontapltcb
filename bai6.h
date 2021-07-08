#include <stdio.h>

void bai6()
{
    int m, y;
    printf("nhap m/y: ");
    scanf("%d/%d", &m, &y);
    int result;
    switch (m)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        result = 31;
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        result = 30;
        break;
    case 2:
        result = (y % 100 == 0) ? (y % 400 == 0 ? 29 : 28) : ((y % 4 == 0) ? 29 : 28);
        break;
    default:
        printf("nhap sai");
    }
    printf("%d ngay", result);
}