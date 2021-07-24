#include <stdio.h>
#include "sinhvien.h"

void bai16()
{
    Sinhvien *sinhviens = (Sinhvien *)malloc(50 * sizeof(Sinhvien));
    int option = -1;
    while (1)
    {
        system("cls");
        printf("MENU\n");
        printf("1. Nhap sinh vien\n");
        printf("2. In sinh vien\n");
        printf("3. In sinh vien TB>9\n");
        printf("4. In sinh vien sinh nam 1990\n");
        printf("5. In sinh vien o Ha Tinh hoac NA TB >8\n");
        printf("6. In sinh vien theo GPA trung binh tang dan\n");
        printf("0. Thoat\n");
        printf("Lua chon: ");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            system("cls");
            int n;
            printf("nhap so sinh vien: ");
            scanf("%d", &n);
            nhapSinhVien(sinhviens, n);
            break;
        case 2:
            inSinhVien(sinhviens, n, "Tat ca");
            break;
        case 3:
            filterSinhviens(sinhviens, n, gpaOver9, "GPA > 9");
            break;
        case 4:
            filterSinhviens(sinhviens, n, bornIn1990, "Sinh nam 1990");
            break;
        case 5:
            filterSinhviens(sinhviens, n, isHaTinhNgheAn8, "Nghe An, Ha Tinh, GPA > 8");
            break;
        case 6:
            sortSinhVien(sinhviens, n, compareAverageGpa, "Sap xep theo GPA trung binh", false);
            break;
        case 7:
            sortSinhVien(sinhviens, n, compareGpa1, "Sap xep thep GPA ki 1", false);
            break;
        case 8:
            sortSinhVien(sinhviens, n, compareDate, "Sap xep theo ngay sinh", false);
            break;
        case 0:
            exit(0);
            break;
        default:
            printf("Nhap sai, nhap lai");
            system("pause");
            break;
        }
    }
    free(sinhviens);
}
