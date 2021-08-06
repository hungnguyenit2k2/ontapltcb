#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// định nghĩa STR_MAX là độ dài tối đa của tên, quê quán, chức vụ, vị trí,...
#define STR_MAX 50
// định nghĩa PHONE_MAX là độ dài tối đa của SĐT
#define PHONE_MAX 10
// định nghĩa NOT_FOUND là giá trị -1 trả về khi không tìm thấy node nào trong danh sách
#define NOT_FOUND -1

// Định nghĩa struct tên là NodeType, lúc làm thật phải thay hết NodeType thành kiểu như đề bài yêu cầu
// Thay hết newNode thành new + kiểu mới, vd newSinhVien, newNhanVien,...
// Thay hết newNodeData thành new + kiểu mới, vd newSinhVienData, newNhanVienData,...
typedef struct {
    // những thành phần trong này tự thay đổi theo yêu cầu của đề bài
    char name[STR_MAX], position[STR_MAX], nvil[STR_MAX], phone[PHONE_MAX];
    int age, id;
    float gpa1, gpa2, aGpa;
    int dg, sl, tt;
} NodeType;

// định nghĩa kiểu node, là kiểu con trỏ, trỏ vào vùng nhớ có kiểu cấu trúc NodeType
typedef struct LinkedList {
    NodeType data;
    struct LinkedList *next;
} * node;

// PHẦN TIỀN KHAI BÁO HÀM
// phần này để tránh trường hợp hàm đứng trước gọi hàm đứng sau, gây ra lỗi
// tất cả các hàm từ createNode đếm deleteAt PHẢI ĐỂ LẠI
// những hàm còn lại đề yêu cầu hàm nào thì để hàm đó lại, còn lại xoá hết
// XOÁ CẢ PHẦN ĐỊNH NGHĨA BÊN DƯỚI
node createNode(NodeType newNodeData);
void swapNodeData(node a, node b);
void addHead(node *head, NodeType newNodeData);
void addTail(node *head, NodeType newNodeData);
void addAt(node *head, NodeType newNodeData, int pos);
void deleteHead(node *head);
void deleteTail(node *head);
void deleteAt(node *head, int pos);
void inputLK(node *head);
void printLK(node *head, char* type);
int listLength(node *head);
int firtIndexOf(node* head, void *newNodeData,  int (*key)(const void*, const void*));
void replaceByPos(node* head, int pos, NodeType* newNode);
void deleteBy(node *head, void *newNodeData, int (*key)(const void*, const void *));
void addBefore(node *head, void *newNodeData, int (*key)(const void*, const void *));

// PHẦN ĐỊNH NGHĨA HÀM

/** Hàm tạo node, hàm này nhận vào một đối số có kiểu NodeType
 * thực thi việc tạo một vùng nhớ chứa dữ liệu của đối số
 * và trả về địa chỉ của vùng nhớ đó
 * */
node createNode(NodeType newNodeData) {
    // cấp phát một vùng nhớ kiểu NodeType, tạo một node tmp trỏ vào vùng nhớ đó
    node tmp = (node)malloc(sizeof(struct LinkedList));
    // gán dữ liệu từ newNodeData vào data của node tmp
    tmp->data = newNodeData;
    // gán dữ cho next của node tmp = NULL để tránh nó trỏ đi linh tinh
    tmp->next = NULL;
    // trả về node tmp
    return tmp;
}

/** Hàm tráo đổi dữ liệu của 2 node
 * Thực thi việc đổi dữ liệu của hai node cho nhau
 * */
void swapNodeData(node a, node b) {
    NodeType tmp = a->data;
    a->data = b->data;
    b->data = tmp;
}

/** Hàm thêm một node vào đầu DSLK
 * hàm nhận vào 2 đối số là địa chỉ của đầu DSLK và dữ liệu của node mới
 * Lưu ý, lí do phải khai báo node *head là bởi vì ta định nghĩa node là một kiểu con trỏ,
 * cũng như một kiểu dữ liệu thông thường như số nguyên, số thập phân,...
 * nên nếu khai báo node head thì head chỉ là tham số hình thức, nên không thay đổi đầu DSLK mà ta truyền vào
 * gây ra lỗi, thay vào đó ta khai báo node *head và truyền tham chiếu của đầu DSLK (&head) vào
 * */
void addHead(node *head, NodeType newNodeData) {
    // tạo một node trung gian tmp
    node tmp = createNode(newNodeData);
    // nếu *head == NULL tức là head rỗng, cho head = tmp luôn
    if (*head == NULL) *head = tmp;
    // ngược lại nếu *head != NULL tức là head đã có node rồi
    else {
        // cho next của tmp trỏ đến head
        tmp->next = *head;
        // cho head = tmp để tmp làm đầu DS
        *head = tmp;
    }
}

/** Hàm thêm một node vào đuôi DSLK
 * hàm nhận vào 2 đối số là địa chỉ của đầu DSLK và dữ liệu của node mới
 * Lưu ý, lí do phải khai báo node *head là bởi vì ta định nghĩa node là một kiểu con trỏ,
 * cũng như một kiểu dữ liệu thông thường như số nguyên, số thập phân,...
 * nên nếu khai báo node head thì head chỉ là tham số hình thức, nên không thay đổi đầu DSLK mà ta truyền vào
 * gây ra lỗi, thay vào đó ta khai báo node *head và truyền tham chiếu của đầu DSLK (&head) vào
 * */
void addTail(node *head, NodeType newNodeData) {
    // nếu head = NULL tức là DS trống, addHead luôn
    if (*head == NULL) addHead(head, newNodeData);
    // ngược lại, nếu DS không rỗng
    else {
        // tạo một node tmp
        node tmp = createNode(newNodeData);
        // tạo node p trỏ đến head
        node p = *head;
        // duyệt qua từng node, chừng nào mà next của node đó trỏ đến NULL, tức là đã ở cuối DS
        while (p->next != NULL) p = p->next;
        // thì cho next của node đó = tmp;
        p->next = tmp;
    }
}

/** Hàm thêm một node vào vị trí bất kì trong DSLK
 * Vị trí của các node được đánh số từ 0
 * hàm nhận vào 3 đối số là địa chỉ của đầu DSLK (node* head), dữ liệu của node mới (NodeType newNodeData) và vị trí cần chèn (int pos);
 * Lưu ý, lí do phải khai báo node *head là bởi vì ta định nghĩa node là một kiểu con trỏ,
 * cũng như một kiểu dữ liệu thông thường như số nguyên, số thập phân,...
 * nên nếu khai báo node head thì head chỉ là tham số hình thức, nên không thay đổi đầu DSLK mà ta truyền vào
 * gây ra lỗi, thay vào đó ta khai báo node *head và truyền tham chiếu của đầu DSLK (&head) vào
 * */
void addAt(node *head, NodeType newNodeData, int pos) {
    // nếu vị trí nhập vào <= 0 thì thêm vào đầu dslk
    if (pos <= 0 || *head == NULL) addHead(head, newNodeData);
    else {
        // duyệt qua các node đồng thời đếm thứ tự của chúng
        // lí do khai báo k = 1 là vì việc chèn vào vị trí 0 đã đc làm ở if bên trên rồi
        // nên duyệt từ vị trí 1
        int k = 1;
        // tạo node p = *head để bắt đầu duyệt
        node p = *head;
        // chừng nào k!=pos (chưa duyệt đến vị trí cần chèn)
        // hoặc pos->next != NULL (chưa duyệt đến node cuối cùng)
        // thì tăng k lên 1, cho p = p->next
        // điều kiện thoát vòng lặp là k đã đến vị trí cần chèn
        // hoặc p đã trỏ đến cuối ds
        while (k != pos && p->next != NULL) {
            k++;
            p = p->next;
        }
        // nếu đã duyệt đến node cuối cùng mà k vẫn chưa đến pos
        // tức là pos nằm ngoài vị trí cuối cùng
        // thì thêm node mới vào đuôi DSLK luôn
        if (k != pos) addTail(head, newNodeData);
        // ngược lại k đã đến pos thì
        else {
            // tạo node mới
            node tmp = createNode(newNodeData);
            // cho tmp->next = p->next
            // và p->next = tmp
            // cái này lên gg mà xem ảnh minh hoạ cho dễ hiểu
            tmp->next = p->next;
            p->next = tmp;
        }
    }
}

/** Hàm xoá node đầu tiên của DSLK
 * Vị trí của các node được đánh số từ 0
 * Lưu ý, lí do phải khai báo node *head là bởi vì ta định nghĩa node là một kiểu con trỏ,
 * cũng như một kiểu dữ liệu thông thường như số nguyên, số thập phân,...
 * nên nếu khai báo node head thì head chỉ là tham số hình thức, nên không thay đổi đầu DSLK mà ta truyền vào
 * gây ra lỗi, thay vào đó ta khai báo node *head và truyền tham chiếu của đầu DSLK (&head) vào
 * */
void deleteHead(node *head) {
    // nếu *head == NULL, dslk rỗng thì thông báo
    if (*head == NULL) printf("Nothing to delete\n");
    // ngược lại cho head = head->next luôn là xong
    // lên gg mà xem hình minh hoạ
    else *head = (*head)->next;
}

/** Hàm xoá node cuối cùng của DSLK
 * Vị trí của các node được đánh số từ 0
 * Lưu ý, lí do phải khai báo node *head là bởi vì ta định nghĩa node là một kiểu con trỏ,
 * cũng như một kiểu dữ liệu thông thường như số nguyên, số thập phân,...
 * nên nếu khai báo node head thì head chỉ là tham số hình thức, nên không thay đổi đầu DSLK mà ta truyền vào
 * gây ra lỗi, thay vào đó ta khai báo node *head và truyền tham chiếu của đầu DSLK (&head) vào
 * */
void deleteTail(node *head) {
    // nếu *head == NULL, dslk rỗng thì xoá đầu luôn
    // hoặc *head->next == NULL, dslk chỉ có 1 node, xoá đầu luôn
    if (*head == NULL || (*head)->next == NULL) deleteHead(head);
    // ngược lại
    else {
        // tạo node p trỏ đến *head
        node p = *head;
        // duyệt đến node đứng trước node cuối cùng của dslk
        // vì node cuối cùng thì next = NULL nên mình sẽ duyệt đến thằng đứng trc nó
        // nên mới có điều kiện p->next->next != NULL
        while (p->next->next != NULL) p = p->next;
        p->next = NULL;
    }
}

/** Hàm xoá node tại vị trí pos của DSLK
 * Vị trí của các node được đánh số từ 0
 * hàm nhận vào 2 đối số là địa chỉ của đầu DSLK và dữ liệu của node mới
 * Lưu ý, lí do phải khai báo node *head là bởi vì ta định nghĩa node là một kiểu con trỏ,
 * cũng như một kiểu dữ liệu thông thường như số nguyên, số thập phân,...
 * nên nếu khai báo node head thì head chỉ là tham số hình thức, nên không thay đổi đầu DSLK mà ta truyền vào
 * gây ra lỗi, thay vào đó ta khai báo node *head và truyền tham chiếu của đầu DSLK (&head) vào
 * */
void deleteAt(node *head, int pos) {
    if (pos <= 0 || *head == NULL || (*head)->next == NULL) deleteHead(head);
    else {
        int k = 1;
        node p = *head;
        while (k != pos && p->next->next != NULL) {
            k++;
            p = p->next;
        }
        if (k != pos) deleteTail(head);
        else p->next = p->next->next;
    }
}

void inputLK(node *head) {
//    int stt = listLength(head) + 1;
    NodeType newNode;
    do {
        printf("name: "); fflush(stdin); gets(newNode.name);
        if (strlen(newNode.name) == 0) break;
        addTail(head, newNode);
    } while (1);
}

void printLK(node *head, char* type) {
    printf("Danh sach (%s)\n", type);
    node p = *head;
    while (p != NULL) {
        // Print node data here
        printf("%s ", p->data.name);
        p = p->next;
    }
    printf("\n");
}

int listLength(node *head) {
    int length = 0;
    if (*head == NULL) return length;
    else {
        node p = *head;
        do {
            length++;
            p = p->next;
        } while (p->next != NULL);
    }
    return length;
}

int searchByName(const void* itemNode, void *newNodeData) {
    return !strcmp(((node)itemNode)->data.name, (char *)newNodeData);
}

int firstIndexOf(node *head, void *newNodeData, int (*key)(const void*, const void *)) {
    if (*head == NULL) return NOT_FOUND;
    node p = *head;
    int index = 0;
    while (p != NULL) {
        if (key(p, newNodeData)) return index;
        index++;
        p = p->next;
    }
    return NOT_FOUND;
}

void addBefore(node *head, void *newNodeData, int (*key)(const void*, const void *)) {
    int pos = firstIndexOf(head, newNodeData, key);
    if (pos == NOT_FOUND) printf("Khong tim thay\n");
    else {
        printf("Them vao truoc vi tri %d\n", pos + 1);
        NodeType newNode;
        // get the newNode data here
        addAt(head, newNode, pos);
    }
}

void deleteBy(node *head, void *newNodeData, int (*key)(const void*, const void *)) {
    int pos = firstIndexOf(head, newNodeData, key);
    if (pos == NOT_FOUND) printf("khong tim thay de xoa\n");
    else deleteAt(head, pos);
}

void replaceByPos(node* head, int pos, NodeType* newNode) {
    if (*head == NULL) printf("Danh sach trong, khong the thay the\n");
    else if (pos < 0) printf("Ngoai khoang tim kiem, khong the thay the\n");
    else {
        int k = 0; node p = *head;
        while (k != pos && p->next != NULL) {
            p = p->next;
            k++;
        }
        if (k != pos) printf("Ngoai khoang tim kiem, khong the thay the\n");
        else p->data = *newNode;
    }
}

int sortName(const void* p1, const void* p2) {
    puts(((node)p1)->data.name);
    return strcmp(((node)p1)->data.name, ((node)p2)->data.name) <= 0;
}

void sortLK(node* head, int (*key)(const void*, const void*)) {
    if (*head == NULL) return;
    else {
        node p1 = *head;
        while (p1->next!=NULL) {
            node p2 = p1->next;
            while (p2!=NULL) {
                if (key(p1, p2)) swapNodeData(p1, p2);
                printLK(head, "Sap xep");
                p2 = p2->next;
            }
            p1 = p1->next;
        }
    }
}

void inputLKFromFile(node* head) {
    FILE* f = fopen("file.inp", "rb+");
    NodeType newNode;
    while (fread(&newNode, sizeof(NodeType), 1, f)) addTail(head, newNode);
}

void writeLKOnFile(node* head) {
    FILE* f = fopen("file.inp", "rb+");
    node p = *head;
    while (p!=NULL) {
        fwrite(&(p->data), sizeof(NodeType), 1, f);
        p=p->next;
    }
}

int main() {
    node head = NULL;
    inputLK(&head);
    writeLKOnFile(&head);
//    inputLKFromFile(&head);
    printLK(&head, "Tu tep");
}
