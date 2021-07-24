#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int wordsStartWithLetter(char str[])
{
    for (int i = strlen(str); i >= 1; i--)
        str[i] = str[i - 1];
    str[0] = 32;
    int count = 0;
    for (int i = 1; i < strlen(str); i++)
        if ((str[i] != 32 && str[i - 1] == 32))
        {
            if ((str[i] >= 65 && str[i] <= 90) || (str[i] >= 97 && str[i] <= 122))
                count++;
        }
    return count;
}

void bai17()
{
    FILE *fInput = fopen("demtu.inp", "r");
    if (!fInput)
    {
        printf("File not exist!");
    }
    else
    {
        int n;
        fscanf(fInput, "%d\n", &n);
        int count = 0;
        for (int i = 1; i <= n; i++)
        {
            char str[50];
            fscanf(fInput, "%[^\n]\n", str);
            count += wordsStartWithLetter(str);
        }
        FILE *fOuput = fopen("demtu.out", "w");
        fprintf(fOuput, "%d", count);
    }
}

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void inDay(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d, ", arr[i]);
    }
    printf("\n");
}

void delete (int *arr, int *n, int index)
{
    for (int i = index; i < *n; i++)
    {
        arr[i] = arr[i + 1];
    }
    *n -= 1;
}

void bai18()
{
    FILE *fin = fopen("songuyen.inp", "r");
    int c, arr[50] = {0}, arrLenght = 0;
    ;
    while (!feof(fin))
    {
        fscanf(fin, "%d", &arr[arrLenght++]);
    }

    for (int i = 0; i < arrLenght; i++)
    {
        for (int j = arrLenght - 1; j > i; j--)
        {
            if (arr[i] == arr[j])
            {
                delete (arr, &arrLenght, j);
                j++;
            }
        }
    }

    int sortedArray[50] = {0};
    int countEven = 0, countOdd = arrLenght - 1;
    for (int i = 0; i < arrLenght; i++)
    {
        if (arr[i] % 2 == 0)
            sortedArray[countEven++] = arr[i];
        else
            sortedArray[countOdd--] = arr[i];
    }

    FILE* fout = fopen("songuyen.out", "w");
    for (int i=0; i<countEven; i++) {
        fprintf(fout, "%d ", arr[i]);
    }
    fprintf(fout, "\n");

    for (int i=countEven; i<arrLenght; i++) {
        fprintf(fout, "%d ", arr[i]);
    }
}
