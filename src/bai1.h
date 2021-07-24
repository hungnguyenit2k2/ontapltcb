#include "myfunctions.h"
#include <stdio.h>
#include <math.h>
#include <unistd.h>

void bai1()
{
    // khai báo biếm đếm
    int count = 0;
    // duyệt qua các cặp số từ 1-9
    for (int i=1000000; i<=9999999; i++) {
        if (isSquare(getFirstXLast(i))) {
            printf("%d\n", i);
            sleep(1);
            count++;
        }

    }
    // số có 7 chữ số mà đã có số lượng truòng hợp cho chữ số đầu và cuối
    // nên chỉ cần * với các trường hợp của 5 chữ số còn lại
    printf("%d", count);
}