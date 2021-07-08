#include <stdio.h>
#include <myfunctions.h>

void bai14()
{
    char str1[20], str2[20];
    fflush(stdin);
    gets(str1);
    fflush(stdin);
    gets(str2);
    int count = 0;
    for (int i = 0; i < strlen(str1); i++)
        if (!isInString(str1[i], str2))
        {
            count++;
        }
    for (int i = 0; i < strlen(str2); i++)
        if (!isInString(str2[i], str1))
        {
            count++;
        }
    printf("%d", count);
}