#include <iostream>

using namespace std;

//Bước 1: Định nghĩa cấu trúc Node
struct Node
{
    int data;
    Node* pNext;
};

//Bước 2: Cấp phát động Node để lưu giá trị cần lưu
Node* initNode(int value)
{
    Node* p = new Node;

    p->data = value;
    p->pNext = NULL;

    return p;
}

//Bước 3: Định nghĩa Bucket
struct Bucket
{
    Node* pHead;
    Node* pTail;
};

//Bước 4: Khởi tạo Bucket
void initBucket(Bucket& bk)
{
    bk.pHead = NULL;
    bk.pTail = NULL;
}

//Bước 5: Định nghĩa kiểu Hashtable
const int Size = 5;
struct Hashtable
{
    Bucket buckets[Size];
};

//Bước 6: Khởi tạo Hashtable
void initHashtable(Hashtable& h)
{
    for(int i = 0; i < Size; i++)
    {
        initBucket(h.buckets[i]);
    }
}

int hashFunc(int value)
{
    return value % Size;
}

int hashFunc(Node* p)
{
    return p->data % Size;
}

void push(Bucket& bk, Node* p) //Tương tự addTail trong list
{
    if(bk.pHead == NULL)
    {
        bk.pHead = p;
        bk.pTail = p;
    }
    else
    {
        bk.pTail->pNext = p;
        bk.pTail = p;
    }
}

void add(Hashtable& h, Node* p)
{
    //B1: Tính vị trí bucket
    int viTri = hashFunc(p);

    //B2: Push vào bucket đã xác định
    //Cách gọi h.buckets[viTri]
    push(h.buckets[viTri], p);
    /*
    if(h.buckets[viTri].pHead == NULL)
    {
        h.buckets[viTri].pHead = p;
        h.buckets[viTri].pTail = p;
    }
    */
}

void add(Hashtable& h, int value)
{
    //B1: Tính vị trí bucket
    int viTri = hashFunc(value);

    //B2: Push vào bucket đã xác định
    //Cách gọi h.buckets[viTri]
    push(h.buckets[viTri], initNode(value));
}

void printHashTable(Hashtable h)
{
    cout << "Size of Hashtable: " << Size << endl;
    for(int i = 0; i < Size; i++)
    {
        cout << "Bucket[" << i << "]: ";
        for(Node* p = h.buckets[i].pHead; p != NULL; p=p->pNext)
        {
            cout << p->data << "\t";
        }
        cout << endl;
    }
}

int main()
{
    Hashtable h;
    initHashtable(h);

    //50    73  35  36  64  28  90  21  53  13
    Node* p1 = initNode(50);
    Node* p2 = initNode(73);
    Node* p3 = initNode(35);
    Node* p4 = initNode(36);
    Node* p5 = initNode(64);
    add(h, p1);
    add(h, p2);
    add(h, p3);
    add(h, p4);
    add(h, p5);
    add(h, initNode(28));
    add(h, 90);
    add(h, 21);
    add(h, 53);
    add(h, 13);

    printHashTable(h);

    return 0;
}
