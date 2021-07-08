#include "myfunctions.h"
#include <stdio.h>
#include <math.h>

void bai1()
{
    int count = 0;
    for (int i=1; i<=9; i++){
        for (int j=1; j<=9; j++) {
            if (isSquare(i*j)) count++;
        }
    }
    int sum = count * pow(10, 5);
    printf("%d", sum);
}