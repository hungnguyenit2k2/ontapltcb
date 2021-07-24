#include <stdio.h>
#include <string.h>
#include "mytype.h"
#include <stdlib.h>
#include <stdbool.h>

void nhapSinhVien(Sinhvien *sinhviens, int n)
{
    if (n == 0)
        printf("NONE");
    for (int i = 0; i < n; i++)
    {
        system("cls");
        printf("---------------------------\n");
        printf("Sinh vien %d\n", i + 1);
        printf("Ho ten           : ");
        fflush(stdin);
        gets(sinhviens[i].name);
        printf("Ngay sinh (D/M/Y): ");
        scanf("%d/%d/%d", &(sinhviens[i].DOB.day), &(sinhviens[i].DOB.month), &(sinhviens[i].DOB.year));
        printf("Que quan:        : ");
        fflush(stdin);
        gets(sinhviens[i].nativeVillage);
        printf("Diem HK 1        : ");
        scanf("%f", &(sinhviens[i].gpa1));
        printf("Diem HK 2        : ");
        scanf("%f", &(sinhviens[i].gpa2));
    }
}

void inSinhVien(Sinhvien *sinhviens, int n, char* type)
{
    system("cls");
    if (n == 0)
        printf("NONE");
    else
    {
        printf("THONG KE SINH VIEN (%s)\n", type);
        printf("| STT | Ho Ten              | Ngay sinh  | Que quan   | TB K1 | TB K2 |\n");
        for (int i = 0; i < n; i++)
        {
            printf("| %3d |", i + 1);
            printf(" %-20s|", sinhviens[i].name);
            printf(" %-2d/%-2d/%-4d |", sinhviens[i].DOB.day, sinhviens[i].DOB.month, sinhviens[i].DOB.year);
            printf(" %-11s|", sinhviens[i].nativeVillage);
            printf(" %-6.2f|", sinhviens[i].gpa1);
            printf(" %-6.2f|\n", sinhviens[i].gpa2);
        }
        printf("| tong so: %d sinh vien                                                 |\n", n);
    }
    system("pause");
}

bool isHaTinhNgheAn8(Sinhvien sv)
{
    return ((sv.gpa1 + sv.gpa2) / 2 >= 8) && (strcmp(sv.nativeVillage, "Nghe An") == 0 || strcmp(sv.nativeVillage, "Ha Tinh") == 0);
}

bool bornIn1990(Sinhvien sv)
{
    return sv.DOB.year == 1990;
}

bool gpaOver9(Sinhvien sv)
{
    return (sv.gpa1 + sv.gpa2) / 2 > 9;
}

// Lọc ra các sinh viên theo tiêu chí của hàm callback
// type: Tên hiển thị trên bảng thống kê
void filterSinhviens(Sinhvien *sinhviens, int n, bool (*callback)(Sinhvien), char type[])
{
    Sinhvien result[50];
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (callback(sinhviens[i]))
        {
            result[count] = sinhviens[i];
            count++;
        }
    }
    inSinhVien(result, count, type);
}

void swap(Sinhvien *sv1, Sinhvien *sv2)
{
    Sinhvien tmp = *sv1;
    *sv1 = *sv2;
    *sv2 = tmp;
}

bool compareGpa1(Sinhvien sv1, Sinhvien sv2)
{
    return sv1.gpa1 > sv2.gpa1;
}

bool compareGpa2(Sinhvien sv1, Sinhvien sv2)
{
    return sv1.gpa2 > sv2.gpa2;
}

bool compareAverageGpa(Sinhvien sv1, Sinhvien sv2)
{
    return ((sv1.gpa1 + sv1.gpa2) / 2) > ((sv2.gpa1 + sv2.gpa2) / 2);
}

bool compareName(Sinhvien sv1, Sinhvien sv2)
{
    return (strcmp(sv1.name, sv2.name) >= 0);
}

// So sánh năm sinh -> tháng sinh -> ngày sinh
bool compareDate(Sinhvien sv1, Sinhvien sv2)
{
    if (sv1.DOB.year == sv2.DOB.year)
    {
        if (sv1.DOB.month == sv2.DOB.month)
        {
            if (sv1.DOB.day == sv2.DOB.day)
            {
                return false;
            }
            else
                return (sv1.DOB.day > sv2.DOB.day);
        }
        else
            return sv1.DOB.month > sv2.DOB.month;
    }
    else
        return sv1.DOB.year > sv2.DOB.year;
}

void sortSinhVien(Sinhvien *sinhviens, int n, bool (*callback)(Sinhvien, Sinhvien), char* type, bool reverse)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (reverse == false ? callback(sinhviens[i], sinhviens[j]) : !callback(sinhviens[i], sinhviens[j]))
            {
                swap(&sinhviens[i], &sinhviens[j]);
            }
        }
    }
    inSinhVien(sinhviens, n, type);
}
