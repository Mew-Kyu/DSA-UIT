#include <iostream>
#include <stack>
using namespace std;

//Bước 1: Định nghĩa cấu trúc Node
struct Node
{
    int data;
    Node* pLeft;
    Node* pRight;
};

//Bước 2: Cấp phát động Node để lưu giá trị cần lưu
Node* initNode(int value)
{
    Node* p = new Node;
    p->data = value;
    //(*p).data = value;
    p->pLeft = NULL;
    p->pRight = NULL;

    return p;
}

//Bước 3: Định nghĩa cấu trúc cây
struct Tree
{
    Node* pRoot;
};

//Bước 4: Khởi tạo cây
void initTree(Tree& t)
{
    t.pRoot = NULL;
}

void addNode(Tree& t, Node* p)
{
    if(t.pRoot == NULL)
    {
        t.pRoot = p;
        return;
    }

    //Cây không rỗng
    Node* pGoto = t.pRoot;
    Node* pLoca = NULL;
    while(pGoto != NULL) //Đi tìm Node thích hợp
    {
        pLoca = pGoto;
        if(p->data < pGoto->data)
            pGoto = pGoto->pLeft;
        else if(p->data > pGoto->data)
            pGoto = pGoto->pRight;
    }

    //Gắn p vào pLoca
    if(p->data < pLoca->data)
        pLoca->pLeft = p;
    else if(p->data > pLoca->data)
        pLoca->pRight = p;
}

void addValue(Tree& t, int value)
{
    Node* p = initNode(value);

    if(t.pRoot == NULL)
    {
        t.pRoot = p;
        return;
    }

    //Cây không rỗng
    Node* pGoto = t.pRoot;
    Node* pLoca = NULL;
    while(pGoto != NULL) //Đi tìm Node thích hợp
    {
        pLoca = pGoto;
        if(p->data < pGoto->data)
            pGoto = pGoto->pLeft;
        else if(p->data > pGoto->data)
            pGoto = pGoto->pRight;
    }

    //Gắn p vào pLoca
    if(p->data < pLoca->data)
        pLoca->pLeft = p;
    else if(p->data > pLoca->data)
        pLoca->pRight = p;
}

int initDataTree(Tree& t)
{
    //50    26  73  66  88  61
    Node* p1 = initNode(50);
    Node* p2 = initNode(26);
    Node* p3 = initNode(73);
    Node* p4 = initNode(66);
    Node* p5 = initNode(88);
    Node* p6 = initNode(61);

    addNode(t, p1);
    addNode(t, p2);
    addNode(t, p3);
    addNode(t, p4);
    addNode(t, p5);
    addNode(t, p6);
    addNode(t, initNode(79));

    addValue(t, 90);
    return 8;
}

void printTree(Tree t) //LNR
{
    stack<Node*> s;
    Node* p = t.pRoot;
    while(p != NULL || s.empty() == false)
    {
        //Left liên tục
        while(p != NULL)
        {
            s.push(p);
            p = p->pLeft;
        }

        //Xử lý Node
        p = s.top();
        s.pop();
        cout << p->data << "   ";

        //Chuyển qua Right
        p = p->pRight;
    }
    cout << endl;
}

/* Tìm giá trị x?
Input:
    + Tree t
    + int x

Output:
    + return bool
*/
bool timGiaTri(Tree t, int x)
{
    Node* p = t.pRoot;

    while(p != NULL)
    {
        if(x == p->data)
            return true;

        if(x < p->data)
            p = p->pLeft;
        else if(x > p->data)
            p = p->pRight;
    }
    return false;
}

/* Tính tổng các giá trị có trong cây
Input:
    + Tree t

Output:
    + return tong
*/
int tong(Tree t)
{
    int tong = 0;
    stack<Node*> s;
    Node* p = t.pRoot;
    while(p != NULL || s.empty() == false)
    {
        while(p != NULL)
        {
            s.push(p);
            p = p->pLeft;
        }

        p = s.top();
        s.pop();

        //xử lý tình huống
        tong = tong + p->data;

        p = p->pRight;
    }
    return tong;
}

/*
Input:
    +
    +

Output:
    +
    +
*/

int main()
{
    Tree t;
    initTree(t); //Cây rỗng

    cout << "Test: Tao du lieu cho cay: " << endl;
    cout << "\t + Ket qua = " << initDataTree(t) << endl;

    cout << "\nTest: Print tree LNR:" << endl;
    printTree(t);

    cout << "\nTest: Tim gia tri:" << endl;
    cout << "\t+ Tim 66(1) = " << timGiaTri(t, 66) << endl;
    cout << "\t+ Tim 89(0) = " << timGiaTri(t, 89) << endl;

    cout << "\nTest: Tong cac gia tri trong cay: " << tong(t) << endl;

    return 0;
}
