#include <iostream>

using namespace std;

/* Yêu cầu 1: Xây dựng cấu trúc node và cấu trúc danh sách liên kết đơn. */
struct Node
{
    int data;
    Node* pNext; // Lưu địa chỉ Node phía sau
};

/* Định nghĩa cấu trúc danh sách liên kết đơn */
struct List
{
    Node* pHead;
    Node* pTail;
};
/* Yêu cầu 2: Viết hàm khởi tạo danh sách liên kết đơn và hàm khởi tạo địa chỉ node từ một số nguyên.
Input:
    + value: int
Output:
    + Node*
*/
Node* initNode(int value)
{
    Node* p = new Node;
    p->data = value;
    p->pNext = NULL;

    return p;
}
/* Khởi tạo danh sách liên kết đơn. */
void initList(List& l)
{
    l.pHead = NULL;
    l.pTail = NULL;
}

/* Yêu cầu 3: Viết hàm thêm Node vào đầu
Input:
    + l: List&
    + p: Node*
Output
    + L: List&
*/
void addHead(List& l, Node* p)
{
    if(l.pHead == NULL)
    {
        l.pHead = p;
        l.pTail = p;
    }
    else
    {
        p->pNext = l.pHead;
        l.pHead = p;
    }
}

/* Yêu cầu 4: Viết hàm thêm Node vào cuối
Input:
    + l: List&
    + p: Node*
Output
    + L: List&
*/
void addTail(List& l, Node* p)
{
    if(l.pHead == NULL)
    {
        l.pHead = p;
        l.pTail = p;
    }
    else
    {
        l.pTail->pNext = p;
        l.pTail = p;
    }
}

/* Yêu cầu 5: Viết hàm khởi tạo giá trị cho danh sách từ mảng một chiều
Input:
    + l: List&
    + a[]: int
    + n: int
Output
    + l: List&
*/
void addValueArray(List& l, int a[], int n)
{
    for(int i = 0; i < n; i++)
    {
        Node* p = initNode(a[i]); // Khởi tạo node với giá trị từ mảng
        addTail(l, p); // Thêm node vào cuối danh sách
    }
}

// Yêu cầu 6. Viết hàm in giá trị danh sách
void printListFor(List l)
{         //start            stop       step
    for(Node* p = l.pHead; p != NULL; p = p->pNext)
    {
        cout << p->data << " ";
    }
    cout << endl << endl;
}

/* Yêu cầu 7: In giá trị kèm địa chỉ của từng node trong danh sách.
Input:
    + l: List
Output:
    + Xuất ra màn hình giá trị và địa chỉ của từng node
*/
void printListWithAddress(List l)
{
    for(Node* p = l.pHead; p != NULL; p = p->pNext)
    {
        cout << "Giá trị: " << p->data << ", Địa chỉ: " << p << endl;
    }
    cout << endl;
}

/* Yêu cầu 8: Kiểm tra danh sách có rỗng hay không
Input:
    + l: List
Output:
    + true/ false
*/
bool isListEmpty(List l)
{
    return l.pHead == NULL;
}

/* Yêu cầu 9: Viết hàm trả về node thứ n trong danh sách.
Input:
    + l: List
    + n: int
Output:
    + Node*
*/
Node* getNodeAt(List l, int n)
{
    Node* p = l.pHead;
    for(int i = 0; p != NULL && i < n; i++)
    {
        p = p->pNext;
    }
    return p;
}

/* Yêu cầu 10: Viết hàm tìm kiếm một node có giá trị X trong danh sách.
Input:
    + l: List
    + x: int
Output:
    + Node*
*/
Node* findNode(List l, int x)
{
    for(Node* p = l.pHead; p != NULL; p = p->pNext)
    {
        if(p->data == x)
            return p;
    }
    return NULL;
}

/* Yêu cầu 11: Viết hàm tìm kiếm các địa chỉ node có giá trị X trong danh sách.
Input:
    + l: List
    + x: int
Output:
    + Xuất ra màn hình các địa chỉ node chứa giá trị X
*/
void findAllNodes(List l, int x)
{
    for(Node* p = l.pHead; p != NULL; p = p->pNext)
    {
        if(p->data == x)
            cout << "Địa chỉ: " << p << endl;
    }
}

/* Yêu cầu 12: Viết hàm đếm số lượng các node có giá trị âm, dương.
Input:
    + l: List
Output:
    + pos: int& (số node có giá trị dương)
    + neg: int& (số node có giá trị âm)
*/
void countPositiveNegative(List l, int& pos, int& neg)
{
    pos = neg = 0;
    for(Node* p = l.pHead; p != NULL; p = p->pNext)
    {
        if(p->data > 0) pos++;
        else if(p->data < 0) neg++;
    }
}

/* Yêu cầu 13: Viết hàm tìm node có giá trị âm lớn nhất, tìm node có giá trị lẻ nhỏ nhất trong danh sách.
Input:
    + l: List
Output:
    + Node* (node âm lớn nhất hoặc node lẻ nhỏ nhất)
*/
Node* findMaxNegative(List l)
{
    Node* maxNeg = NULL;
    for(Node* p = l.pHead; p != NULL; p = p->pNext)
    {
        if(p->data < 0 && (maxNeg == NULL || p->data > maxNeg->data))
            maxNeg = p;
    }
    return maxNeg;
}

Node* findMinOdd(List l)
{
    Node* minOdd = NULL;
    for(Node* p = l.pHead; p != NULL; p = p->pNext)
    {
        if(p->data % 2 != 0 && (minOdd == NULL || p->data < minOdd->data))
            minOdd = p;
    }
    return minOdd;
}

/* Yêu cầu 14: Viết hàm cập nhật giá trị cho một node có giá trị là X bằng giá trị Y mới.
Input:
    + l: List&
    + x: int
    + y: int
Output:
    + Cập nhật giá trị X thành Y trong danh sách
*/
void updateNodeValue(List& l, int x, int y)
{
    for(Node* p = l.pHead; p != NULL; p = p->pNext)
    {
        if(p->data == x)
            p->data = y;
    }
}

/* Yêu cầu 15: Viết hàm copy danh sách.
Input:
    + l: List
Output:
    + List (danh sách mới sao chép từ danh sách gốc)
*/
List copyList(List l)
{
    List newList;
    initList(newList);
    for(Node* p = l.pHead; p != NULL; p = p->pNext)
    {
        Node* newNode = initNode(p->data);
        addTail(newList, newNode);
    }
    return newList;
}

int main()
{
    List l;
    initList(l); // Có thể gọi nó là danh sách rỗng

    // Test Yêu cầu 3 & 4: Thêm Node vào đầu và cuối
    Node* p1 = initNode(10);
    Node* p2 = initNode(79);
    Node* p3 = initNode(39);
    addHead(l, p1);
    addHead(l, p2);
    addTail(l, p3);

    // 79 10 39
    cout << "Test: Yeu cau 6. In danh sach lien ket don: " << endl;
    printListFor(l);

    // Test Yêu cầu 5: Khởi tạo danh sách từ mảng
    int a[] = { -5, 0, 3, -2, 7, 10, 7 };
    int n = sizeof(a) / sizeof(a[0]);
    List l2;
    initList(l2);
    addValueArray(l2, a, n);
    cout << "Test Yeu cau 5: Danh sach tu mang:" << endl;
    printListFor(l2);

    // Test lại Yeu cau 8: Kiểm tra danh sách có rỗng
    cout << "Test: Yeu cau 8. Danh sach rong(1): " << isListEmpty(l) << endl;

    // Test Yeu cau 9: Lấy node thứ n (ví dụ: node thứ 3)
    Node* nodeAt3 = getNodeAt(l2, 3);
    if (nodeAt3 != NULL)
        cout << "Test Yeu cau 9: Node tai vi tri 3 co gia tri: " << nodeAt3->data << endl;
    else
        cout << "Test Yeu cau 9: Node tai vi tri 3 khong ton tai" << endl;

    // Test Yeu cau 10: Tìm kiếm một node có giá trị X (ví dụ: 7)
    Node* foundNode = findNode(l2, 7);
    if (foundNode != NULL)
        cout << "Test Yeu cau 10: Tim thay node co gia tri 7: " << foundNode->data
             << ", dia chi: " << foundNode << endl;
    else
        cout << "Test Yeu cau 10: Khong tim thay node co gia tri 7" << endl;

    // Test Yeu cau 11: Tìm kiếm tất cả các node có giá trị X (ví dụ: 7)
    cout << "\nTest Yeu cau 11: Tim tat ca node co gia tri 7:" << endl;
    findAllNodes(l2, 7);

    // Test Yeu cau 12: Đếm số lượng node có giá trị dương và âm
    int pos, neg;
    countPositiveNegative(l2, pos, neg);
    cout << "\nTest Yeu cau 12: So luong so duong: " << pos << ", so am: " << neg << endl;

    // Test Yeu cau 13: Tìm node có giá trị âm lớn nhất và node có giá trị lẻ nhỏ nhất
    Node* maxNeg = findMaxNegative(l2);
    if (maxNeg != NULL)
        cout << "Test Yeu cau 13: Node am lon nhat co gia tri: " << maxNeg->data << endl;
    else
        cout << "Test Yeu cau 13: Khong co node am trong danh sach" << endl;

    Node* minOdd = findMinOdd(l2);
    if (minOdd != NULL)
        cout << "Test Yeu cau 13: Node le nho nhat co gia tri: " << minOdd->data << endl;
    else
        cout << "Test Yeu cau 13: Khong co node le trong danh sach" << endl;

    // Test Yeu cau 14: Cập nhật giá trị cho node (update các node có giá trị 7 thành 100)
    updateNodeValue(l2, 7, 100);
    cout << "\nTest Yeu cau 14: Danh sach sau khi cap nhat (7 -> 100):" << endl;
    printListFor(l2);

    // Test Yeu cau 15: Copy danh sách
    List lCopy = copyList(l2);
    cout << "Test Yeu cau 15: Danh sach copy:" << endl;
    printListFor(lCopy);

    return 0;
}
