#include <stdio.h>
#include <string.h>

void bai13()
{
    char str[200] = "";
    printf("nhap xau: ");
    fflush(stdin);
    gets(str);
    for (int i = strlen(str); i >= 1; i--)
        str[i] = str[i - 1];
    str[0] = 32;
    int count = 0;
    for (int i = 1; i < strlen(str); i++)
        if (str[i] != 32 && str[i - 1] == 32)
        {
            if (str[i] >= 48 && str[i] <= 57)
                count++;
        }
    printf("so tu bat dau bang chu so: %d", count);
}