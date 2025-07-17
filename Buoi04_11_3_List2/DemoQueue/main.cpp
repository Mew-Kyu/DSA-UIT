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

// Bước 3: Định nghĩa cấu trúc Queue
struct Queue
{
    Node* pFront;
    Node* pRear;
};

// Bước 4: Khởi tạo hàng đợi
void initQueue(Queue& q)
{
    q.pFront = NULL;
    q.pRear = NULL;
}

void enQueue(Queue& q, Node* p)
{
    if(q.pFront == NULL)
    {
        q.pFront = p;
        q.pRear = p;
    }
    else
    {
        q.pRear->pNext = p;
        q.pRear = p;
    }
}

bool deQueue(Queue& q)
{
    if(q.pFront == NULL)
        return false;

    Node* p = q.pFront;
    q.pFront = q.pFront->pNext;
    delete p;

    if(q.pFront == NULL)
        q.pRear = NULL;

    return true;
}

void printQueue(Queue q)
{
    cout << "<<Front<< ";
    for(Node* p = q.pFront; p != NULL; p = p->pNext)
    {
        cout << p->data << " ";
    }
    cout << "<<Rear<<" << endl << endl;
}

int main()
{
    Queue q;
    initQueue(q);

    enQueue(q, initNode(45));
    enQueue(q, initNode(32));
    enQueue(q, initNode(79));

    printQueue(q);

    deQueue(q);
    printQueue(q);

    return 0;
}
