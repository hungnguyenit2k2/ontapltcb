#include <stdio.h>
#include <math.h>

void bai11()
{
    float arr[1000] = {0};
    int n;
    printf("Nhap so phan tu: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%f", &arr[i]);
    float max = arr[0], min = arr[0];
    int indexMax = 0, indexMin = 0;
    for (int i = 1; i < n; i++)
    {
        if (max < arr[i])
        {
            max = arr[i];
            indexMax = i;
        }
        if (min > arr[i])
        {
            min = arr[i];
            indexMin = i;
        }
    }
    // tìm giá trị gần giá trị trung bình nhất
    float arrSum = 0;
    for (int i = 0; i < n; i++)
    {
        arrSum += arr[i];
    }
    float average = arrSum / n;
    float nearAverage = fabs(arr[0] - average);
    int indexNearAverage = 0;
    for (int i = 1; i < n; i++)
    {
        if (fabs(arr[i] - average) < nearAverage)
        {
            nearAverage = fabs(arr[i] - average);
            indexNearAverage = i;
        }
    };
    int segMax = ceil(max), segMin;
    // tìm segMin
    if (min >= 0)
        if (ceil(min) == min)
            segMin = ceil(min);
        else
            segMin = ceil(min) - 1;
    else if (ceil(min) == min)
        segMin = ceil(min);
    else
        segMin = ceil(min) - 1;

    printf("vi tri dau tien cua phan tu nho nhat: %d\n", indexMin);
    printf("vi tri dau tien cua phan tu lon nhat: %d\n", indexMax);
    printf("phan tu gan gia tri trung binh nhat: %3.2f\n", arr[indexNearAverage]);
    printf("Cac phan tu nam trong doan [%d,%d]\n", segMin, segMax);
}