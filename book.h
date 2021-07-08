#include <stdio.h>
#include "mytype.h"
#include <stdlib.h>
#include <string.h>

void inputBooks(Book *books, int n)
{
    if (n == 0)
    {
        printf("NONE\n");
        system("pause");
    }
    for (int i = 0; i < n; i++)
    {
        system("cls");
        printf("Quyen sach thu %d\n", i);
        printf("Ten sach         : ");
        fflush(stdin);
        gets(books[i].name);
        printf("Tac gia          : ");
        fflush(stdin);
        gets(books[i].author);
        printf("Nam XB (D/M/Y)   : ");
        scanf("%d/%d/%d", &(books[i].DOP.day), &(books[i].DOP.month), &(books[i].DOP.year));
        printf("Nha XB           : ");
        fflush(stdin);
        gets(books[i].publisher);
        printf("So luong         : ");
        scanf("%d", &(books[i].amount));
        printf("Gia              : ");
        scanf("%d", &(books[i].price));
    }
}

void printBooks(Book *books, int n, char type[])
{
    system("cls");
    printf("BANG THONG KE SACH (%s)\n", type);

    if (n == 0)
        printf("NONE\n");
    else
    {
        printf("| STT | Ten sach                      | Tac gia   | Nha XB    | Nam XB | SL | Gia     |\n");
        printf("|-------------------------------------------------------------------------------------|\n");
        for (int i = 0; i < n; i++)
        {
            printf("| %d   ", i);
            printf("| %-30s", books[i].name);
            printf("| %-10s", books[i].author);
            printf("| %-10s", books[i].publisher);
            printf("| %7d", books[i].DOP.year);
            printf("| %3d", books[i].amount);
            printf("| %8d|\n", books[i].price);
            printf("|-------------------------------------------------------------------------------------|\n");
        }
    }

    system("pause");
}

bool isSpringer(Book book)
{
    return strcmp(strupr(book.publisher), "SPRINGER") == 0;
}

bool isLessThan10k(Book book)
{
    return book.price < 10000;
}

void filterBooks(Book *books, int n, bool (*callback)(Book), char type[])
{
    Book result[50];
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (callback(books[i]))
        {
            result[count] = books[i];
            count++;
        }
    }
    printBooks(result, count, type);
}

void cheapExpensive(Book *books, int n)
{
    if (n == 1 || n == 0)
    {
        printBooks(books, n, "Dat nhat va re nhat");
    }
    else
    {
        Book result[2];
        result[0] = books[0];
        result[1] = books[0];
        for (int i = 1; i < n; i++)
        {
            if (result[0].price < books[i].price)
                result[0] = books[i];
            if (result[1].price > books[i].price)
                result[1] = books[i];
        }
        printBooks(result, 2, "Dat nhat va re nhat");
    }
}