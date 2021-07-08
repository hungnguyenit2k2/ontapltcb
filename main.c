#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <conio.h>
#include <stdbool.h>

float tong1deni(int i)
{
    float s = 0;
    for (int j = 1; j <= i; j++)
    {
        s += j;
    }
    return s;
}

void convertToBinary(int n)
{
    if (n)
    {
        convertToBinary(n / 2);
        printf("%d", n % 2);
    }
}

void inDay(int *day, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d", day[i]);
    }
    printf("\n");
}

bool isPrime(int n)
{
    if (n <= 1)
        return false;
    if (n == 2 || n == 3)
        return true;
    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

bool isSymetric(int n)
{
    int n2 = 0, n3 = n;
    while (n3)
    {
        n2 = n2 * 10 + n3 % 10;
        n3 /= 10;
    }
    if (n2 == n)
        return true;
    else
        return false;
}

bool isSquare(int n)
{
    if (n == 1)
        return true; // thêm dòng này
    int i = 1;
    while (i <= n / 2) // sửa từ < thành <=
    {
        if (i * i == n)
            return true;
        i++;
    }
    return false;
}

bool isAmstrong(int n)
{
    int arr[10] = {0};
    int n2 = n, count = 0;
    while (n2)
    {
        arr[count] = n2 % 10;
        count++;
        n2 /= 10;
    }
    int sum = 0;
    for (int i = 0; i < count; i++)
    {
        sum += pow(arr[i], count);
    }
    if (sum == n)
        return true;
    else
        return false;
}

void nhapDay(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
}

void sapXepDay(int *arr, int n)
{
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (arr[i] > arr[j])
            {
                int tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
}

int isInString(char chr, char str[])
{
    if (str[0] == '\0')
        return 0;
    else
        for (int i = 0; i < strlen(str); i++)
        {
            if (str[i] == chr)
                return 1;
        }
    return 0;
}

typedef struct Date
{
    int day, month, year;
} Date;

typedef struct Book
{
    char name[50], author[50], publisher[50];
    Date DOP;
    int amount, price;
} Book;

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

typedef struct sinhvien
{
    char name[50], nativeVillage[50];
    float gpa1, gpa2;
    Date DOB;
} Sinhvien;

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

void inSinhVien(Sinhvien *sinhviens, int n, char type[])
{
    system("cls");
    if (n == 0)
        printf("NONE");
    else
    {
        printf("THONG KE SINH VIEN (%s)\n");
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
bool compareDOB(Sinhvien sv1, Sinhvien sv2)
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

// Sắp xếp sinh viên theo hàm callback
// type: Tiêu đề sẽ hiện trên bảng khi in ra
// reverse = true: sắp xếp ngược
void sort(Sinhvien *sinhviens, int n, bool (*callback)(Sinhvien, Sinhvien), char type[], bool reverse)
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

void bai2()
{
    int n;
    printf("nhap n: ");
    scanf("%d", &n);
    int count = 0;
    for (int m = 13; m <= n; m++)
    {
        int k = m;
        int max = k % 10, min = k % 10;
        while (k != 0)
        {
            if (min > k % 10)
                min = k % 10;
            if (max < k % 10)
                max = k % 10;
            k /= 10;
        }
        if ((max - min) == 2)
        {
            printf("%d\n", m);
            count++;
        };
    }
    printf("co %d so", count);
}

void bai3()
{
    int n;
    printf("nhap n: ");
    scanf("%d", &n);
    convertToBinary(n);
}

void bai4()
{
    int n;
    printf("Nhap n: ");
    scanf("%d", &n);
    float s1 = 0, s2 = 0;
    ;
    for (int i = 1; i <= n; i++)
    {
        s1 += 1 / (float)(i * (i + 1));
        s2 += 1 / tong1deni(i);
    }
    printf("tong 1: %f \ntong 2: %f", s1, s2);
}

void bai5()
{
    int n;
    float x;
    float s1 = 0, s2 = 0;
    printf("nhap n va x: ");
    scanf("%d %f", &n, &x);
    for (int i = 1; i <= 2 * n + 1; i++)
        if (i % 2 == 0)
            s1 += pow(x, i);
        else
            s2 += pow(x, i);
    printf("s1 = %f, s2 = %f", s1, s2);
}

void bai6()
{
    int m, y;
    printf("nhap m/y: ");
    scanf("%d/%d", &m, &y);
    int result;
    switch (m)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        result = 31;
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        result = 30;
        break;
    case 2:
        result = (y % 100 == 0) ? (y % 400 == 0 ? 29 : 28) : ((y % 4 == 0) ? 29 : 28);
        break;
    default:
        printf("nhap sai");
    }
    printf("%d ngay", result);
}

void bai7()
{
    float a, b, c;
    printf("nhap a, b, c: ");
    scanf("%f %f %f", &a, &b, &c);
    if (a == 0)
    {
        if (b == 0)
        {
            if (c == 0)
                printf("Phuong trinh vo so nghiem");
            else
                printf("Phuong trinh vo nghiem");
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

void tryNextArray(int *day, int n, int index)
{
    for (int i = 0; i <= 1; i++)
    {
        day[index] = i;
        if (index == n - 1)
        {
            inDay(day, n);
        }
        else
        {
            tryNextArray(day, n, index + 1);
        }
    }
}

void bai8()
{
    int arr[20] = {0};
    int n;
    printf("nhap n: ");
    scanf("%d", &n);
    tryNextArray(arr, n, 0);
}

void bai9()
{
    int n;
    printf("nhap n: ");
    scanf("%d", &n);
    if (isSquare(n))
        printf("La so chinh phuong\n");
    else
        printf("Khong la so chinh phuong\n");
    if (isPrime(n))
        printf("La so nguyen to\n");
    else
        printf("Khong la so nguyen to\n");
    if (isSymetric(n))
        printf("La so doi xung\n");
    else
        printf("Khong la so doi xung\n");
}

void bai10()
{
    int n;
    printf("nhap n: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        if (isAmstrong(i))
            printf("%d la so Amstrong\n", i);
    }
}

void bai11()
{
    float arr[1000] = {0};
    int n;
    printf("nhap so phan tu: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%f", &arr[i]);
    float max = arr[0], min = arr[0];
    int indexMax = 0, indexMin = 0;
    for (int i = 1; i < n; i++)
    {
        if (max < arr[i])
        {
            max = arr[i];
            indexMax = i;
        }
        if (min > arr[i])
        {
            min = arr[i];
            indexMin = i;
        }
    }
    // tìm giá trị gần giá trị trung bình nhất
    float arrSum = 0;
    for (int i = 0; i < n; i++)
    {
        arrSum += arr[i];
    }
    float average = arrSum / n;
    float nearAverage = fabs(arr[0] - average);
    int indexNearAverage = 0;
    for (int i = 1; i < n; i++)
    {
        if (fabs(arr[i] - average) < nearAverage)
        {
            nearAverage = fabs(arr[i] - average);
            indexNearAverage = i;
        }
    };
    int segMax = ceil(max), segMin;
    // tìm segMin
    if (min >= 0)
        if (ceil(min) == min)
            segMin = ceil(min);
        else
            segMin = ceil(min) - 1;
    else if (ceil(min) == min)
        segMin = ceil(min);
    else
        segMin = ceil(min) - 1;

    printf("vi tri dau tien cua phan tu nho nhat: %d\n", indexMin);
    printf("vi tri dau tien cua phan tu lon nhat: %d\n", indexMax);
    printf("phan tu gan gia tri trung binh nhat: %3.2f\n", arr[indexNearAverage]);
    printf("Cac phan tu nam trong doan [%d,%d]\n", segMin, segMax);
}

void bai12()
{
    int arr[1000] = {0}, n;
    printf("nhap n: ");
    scanf("%d", &n);
    nhapDay(arr, n);
    inDay(arr, n);
    sapXepDay(arr, n);
    inDay(arr, n);

    // 2 ý cuối không hiểu đề hỏi gì luôn :v
}

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
            system("pause");
            break;
        }
    }
    free(books);
}

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
        printf("7. In sinh vien theo GPA ki 1 tang dan\n");
        printf("8. In sinh vien theo ngay sinh tang dan\n");
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
            sort(sinhviens, n, compareAverageGpa, "Sap xep theo GPA trung binh", false);
            break;
        case 7:
            sort(sinhviens, n, compareGpa1, "Sap xep thep GPA ki 1", false);
            break;
        case 8:
            sort(sinhviens, n, compareDOB, "Sap xep theo ngay sinh", false);
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
}

int main()
{
    // cần chạy bài nào thì gọi hàm ra nhé
    // ví dụ cần bài 1 thì gọi bai1
    bai1();
}
