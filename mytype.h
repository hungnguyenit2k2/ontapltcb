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

typedef struct sinhvien
{
    char name[50], nativeVillage[50];
    float gpa1, gpa2;
    Date DOB;
} Sinhvien;

