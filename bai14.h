#include <stdio.h>
#include "myfunctions.h"

void bai14()
{
    // khai báo hai xâu str1 và str2
    char str1[20], str2[20]; 
    // nhập xâu str1
    fflush(stdin);
    gets(str1);
    // nhập xâu str2
    fflush(stdin);
    gets(str2);
    // tạo biến đêm
    int count = 0;
    // duyệt qua các phần tử của xâu 1
    for (int i = 0; i < strlen(str1); i++)
        // nếu phần tử str1[i] không nằm trong xâu str2 thì tăng biến đếm lên 1
        // hàm isInString trả về true nếu str[i] nằm trong xâu str2
        // nên thêm ! ở trước để đảo kết quả
        if (!isInString(str1[i], str2))
        {
            count++;
        }
    // duyệt qua các phần tử của xâu 2
    for (int i = 0; i < strlen(str2); i++)
        // nếu phần tử str2[i] không nằm trong xâu str1 thì tăng biến đếm lên 1
        if (!isInString(str2[i], str1))
        {
            count++;
        }
    // in kết quả
    printf("%d", count);
}