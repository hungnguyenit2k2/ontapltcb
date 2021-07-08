#include <stdio.h>
#include <math.h>

void bai7()
{
    float a, b, c;
    printf("nhap a, b, c: ");
    scanf("%f %f %f", &a, &b, &c);
    if (a == 0)
    {
        if (b == 0)
        {
            printf("%s", c==0 ? "Phuong trinh vo so nghiem" : "Phuong trinh vo nghiem");
        }
        else
            printf("Nghiem duy nhat la %f", -c / b);
    }
    else
    {
        float x1, x2, delta;
        delta = pow(b, 2) - 4 * a * c;
        if (delta == 0)
        {
            printf("nghiem duy nhat la: %f", -b / (2 * a));
        }
        else if (delta < 0)
        {
            printf("Phuong trinh vo nghiem");
        }
        else
        {
            x1 = (-b - sqrt(delta)) / (2 * a);
            x2 = (-b + sqrt(delta)) / (2 * a);
            printf("Phuong trinh co 2 nghiem phan biet: x1 = %f, x2=%f", x1, x2);
        }
    }
}