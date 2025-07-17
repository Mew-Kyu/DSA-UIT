#include <iostream>

using namespace std;

// Bước 1: Tạo cấu trúc Node
struct Node
{
    int data;
    Node* pNext; // Lưu địa chỉ Node phía sau
};

// Bước 2: Khởi tạo Node để lưu giá trị
Node* initNode(int value)
{
    Node* p = new Node;
    p->data = value;
    p->pNext = NULL;

    return p;
}

// Bước 3: Định nghĩa cấu trúc List
struct List
{
    Node* pHead;
    Node* pTail;
};

// Bước 4: Khởi tạo danh sách
void initList(List& l)
{
    l.pHead = NULL;
    l.pTail = NULL;
}

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

// Bước 5: In danh sách
void printListFor(List l)
{         //start            stop       step
    for(Node* p = l.pHead; p != NULL; p = p->pNext)
    {
        cout << p->data << " ";
    }
    cout << endl << endl;
}

void printListWhile(List l)
{
    Node* p = l.pHead;
    while(p != NULL)
    {
        cout << p->data << " ";
        p = p->pNext;
    }
    cout << endl << endl;
}


/* Yêu cầu: Viết hàm tìm kiếm một giá trị có trong List hay không?
Input:
    + l: List (hoặc List l)
    + value: int
Output
    + true/ false = > return bool
*/
bool timGiaTri(List l, int value)
{
    for(Node* p = l.pHead; p != NULL; p = p->pNext)
    {
        if(p->data == value)
            return true;
    }
    return false;
}

/* Yêu cầu: Viết hàm tìm giá trị node kế cuối?
Input:
    + l: List
Output
    + return bool
    + x: int&
*/
bool giaTriNodeKeCuoi(List l, int& x)
{
    return false;
}

int main()
{
    Node* p1 = initNode(10);
    Node* p2 = initNode(79);
    Node* p3 = initNode(39);

    List l;
    initList(l); // Có thể gọi nó là danh sách rỗng

    addHead(l, p1);
    addHead(l, p2);
    addTail(l, p3);

    // 79 10 39
    printListFor(l);
    printListWhile(l);

    cout << "Test: Tim 10(1): " << timGiaTri(l, 10) << endl;
    cout << "Test: Tim 35(0): " << timGiaTri(l, 35) << endl;

    int x;
    if(timGiaTri(l, x))
    {
        cout << "" << x;
    }
    else
    {

    }

    return 0;
}
