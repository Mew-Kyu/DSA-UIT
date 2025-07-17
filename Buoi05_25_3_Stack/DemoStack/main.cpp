#include <iostream>

using namespace std;

//Bước 1: Định nghĩa cấu trúc Node
struct Node
{
    int data;
    Node* pNext;
};

//Bước 2: Cấp phát Node để lưu giá trị cần lưu
Node* initNode(int value)
{
    Node* p = new Node;

    if(p == NULL)
        return NULL;

    //p->data = value;
    (*p).data = value;
    p->pNext = NULL;

    return p;
}

//Bước 3: Định nghĩa cấu trúc Stack
struct Stack
{
    Node* pTop;
};

//Bước 4: Khởi tạo Stack
void initStack(Stack& s)
{
    s.pTop = NULL;
}

void push(Stack& s, Node* p)
{
    if(s.pTop == NULL)
    {
        s.pTop = p;
    }
    else
    {
        p->pNext = s.pTop;
        s.pTop = p;
    }
}

void push(Stack& s, int value)
{
    Node* p = initNode(value);
    if(s.pTop == NULL)
    {
        s.pTop = p;
    }
    else
    {
        p->pNext = s.pTop;
        s.pTop = p;
    }
}

void printStack(Stack s)
{
    cout << "Stack s = Top <<  ";
    for(Node* p = s.pTop; p != NULL; p = p->pNext)
    {
        cout << p->data << "  ";
    }
    cout << ">>" << endl;
}

void pop(Stack& s)
{
    if(s.pTop == NULL)
        return;

    Node* p = s.pTop;
    s.pTop = s.pTop->pNext;
    delete p;
}

int getTop(Stack s)
{
    return s.pTop->data;
}

void convert10_2(int n, Stack& s)
{
    for(; n != 0; n = n/2)
    {
        push(s, n%2);
    }
}

int main()
{
    Stack s;
    initStack(s); //s rỗng

    Node* p1 = initNode(10);
    Node* p2 = initNode(79);
    Node* p3 = initNode(39);

    push(s, p1);
    push(s, p2);
    push(s, p3);
    push(s, 26);

    //Top <<  26  39  79  10  >>
    printStack(s);

    pop(s);
    printStack(s);

    pop(s);
    printStack(s);

    pop(s);
    printStack(s);

    pop(s);
    printStack(s);

    pop(s);
    printStack(s);

    Stack s2;
    initStack(s2);

    convert10_2(13, s2);
    printStack(s2);


    return 0;
}
