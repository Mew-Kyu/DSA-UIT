#include <iostream>

using namespace std;

//Bước 1: Định nghĩa cấu trúc Node
struct Node
{
    int data;
    Node* pPre;
    Node* pNext;
};

//Bước 2: Cấp phát động Node để lưu giá trị
Node* initNode(int value)
{
    Node* p = new Node;

    if(p == NULL)
        return NULL;

    p->data = value;
    p->pNext = NULL;
    p->pPre = NULL;

    return p;
}

//Bước 3: Định nghĩa List
struct List
{
    Node* pHead;
    Node* pTail;
};

//Bước 4: Khởi tạo List
void initList(List& l)
{
    l.pHead = NULL;
    l.pTail = NULL;
}

void pushHead(List& l, Node* p)
{
    if(l.pHead == NULL)
    {
        l.pHead = p;
        l.pTail = p;
    }
    else
    {
        p->pNext = l.pHead;
        l.pHead->pPre = p;
        l.pHead = p;
    }
}

void pushTail(List& l, Node* p)
{
    if(l.pHead == NULL)
    {
        l.pHead = p;
        l.pTail = p;
    }
    else
    {
        l.pTail->pNext = p;
        p->pPre = l.pTail;
        l.pTail = p;
    }
}

void printfList(List l)
{
    cout << endl << "In tu pHead den pTail:" << endl;
    for(Node* p = l.pHead; p != NULL; p = p->pNext)
    {
        cout << p->data << " ";
    }

    cout << endl << "In tu pTail den pHead:" << endl;
    for(Node* p = l.pTail; p != NULL; p = p->pPre)
    {
        cout << p->data << " ";
    }
}

int main()
{
    //10    79  39
    Node* p1 = initNode(10);
    Node* p2 = initNode(79);
    Node* p3 = initNode(39);

    List l;
    initList(l);    //Danh sách l rỗng

    pushHead(l, p1);
    pushTail(l, p2);
    pushTail(l, p3);

    pushHead(l, initNode(50));
    pushTail(l, initNode(26));

    //50  10  79  39  26
    printfList(l);

    return 0;
}
