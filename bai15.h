#include <stdio.h>
#include <stdlib.h>
#include "book.h"
#include <stdbool.h>

void bai15()
{
    int n = 0;
    Book *books = (Book *)malloc(5 * sizeof(Book));
    int option = -1;
    while (true)
    {
        system("cls");
        printf("MENU\n");
        printf("1. Nhap sach\n");
        printf("2. In tat ca sach\n");
        printf("3. In sach do Springer xuat ban\n");
        printf("4. In sach re hon 10k\n");
        printf("5. In sach dat nhat va re nhat\n");
        printf("0. Thoat\n");
        printf("Lua chon: ");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            printf("Nhap so sach: ");
            scanf("%d", &n);
            inputBooks(books, n);
            break;
        case 2:
            printBooks(books, n, "Tat ca");
            break;
        case 3:
            filterBooks(books, n, isSpringer, "Springer");
            break;
        case 4:
            filterBooks(books, n, isLessThan10k, "Re hon 10k");
            break;
        case 5:
            cheapExpensive(books, n);
            break;
        case 0:
            exit(0);
            break;
        default:
            printf("Nhap sai, nhap lai");
            break;
        }
    }
    free(books);
}
