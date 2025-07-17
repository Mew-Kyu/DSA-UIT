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

    Node* pGoto = t.pRoot;
    Node* pLoca = NULL;
    while(pGoto != NULL)
    {
        pLoca = pGoto;
        if(p->data < pGoto->data)
            pGoto = pGoto->pLeft;
        else if(p->data > pGoto->data)
            pGoto = pGoto->pRight;
    }

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

    Node* pGoto = t.pRoot;
    Node* pLoca = NULL;
    while(pGoto != NULL)
    {
        pLoca = pGoto;
        if(p->data < pGoto->data)
            pGoto = pGoto->pLeft;
        else if(p->data > pGoto->data)
            pGoto = pGoto->pRight;
    }

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

void printTree(Tree t)
{
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
        cout << p->data << "   ";

        p = p->pRight;
    }
    cout << endl;
}

/*8. Tìm giá trị trong cây
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

/*9. Hàm đếm toàn bộ số node của cây
   Input:
       + Tree t
   Output:
       + return int
*/
int countNodes(Tree t)
{
    int count = 0;
    stack<Node*> s;
    Node* p = t.pRoot;
    while(p != NULL || !s.empty())
    {
        while(p != NULL)
        {
            s.push(p);
            p = p->pLeft;
        }
        p = s.top();
        s.pop();
        count++;
        p = p->pRight;
    }
    return count;
}

/*10. Hàm đếm số node lá của cây
   Input:
       + Tree t
   Output:
       + return int
*/
int countLeafNodes(Tree t)
{
    int count = 0;
    stack<Node*> s;
    Node* p = t.pRoot;
    while(p != NULL || !s.empty())
    {
        while(p != NULL)
        {
            s.push(p);
            p = p->pLeft;
        }
        p = s.top();
        s.pop();
        if(p->pLeft == NULL && p->pRight == NULL)
            count++;
        p = p->pRight;
    }
    return count;
}

//11. Hàm in ra nhánh (LNR) của một node.
void printLNR(Node* p)
{
    if(p == NULL)
        return;
    printLNR(p->pLeft);
    cout << p->data << "   ";
    printLNR(p->pRight);
}

/*12. Hàm đếm số node có giá trị nhỏ hơn X.
   Input:
       + Tree t
       + int x
   Output:
       + return int
*/
int countLessThanX(Tree t, int x)
{
    int count = 0;
    stack<Node*> s;
    Node* p = t.pRoot;
    while(p != NULL || !s.empty())
    {
        while(p != NULL)
        {
            s.push(p);
            p = p->pLeft;
        }
        p = s.top();
        s.pop();
        if(p->data < x)
            count++;
        p = p->pRight;
    }
    return count;
}

/*13. Tính tổng các Node trong cây
Input:
    + Tree t

Output:
    + return int
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

        tong = tong + p->data;

        p = p->pRight;
    }
    return tong;
}

/*14. Hàm tính tổng các node chẵn trong cây
   Input:
       + Tree t
   Output:
       + return int
*/
int sumEvenNodes(Tree t)
{
    int sum = 0;
    stack<Node*> s;
    Node* p = t.pRoot;
    while(p != NULL || !s.empty())
    {
        while(p != NULL)
        {
            s.push(p);
            p = p->pLeft;
        }
        p = s.top();
        s.pop();
        if(p->data % 2 == 0)
            sum += p->data;
        p = p->pRight;
    }
    return sum;
}

/*15. Hàm tìm node có giá trị lớn nhất và nhỏ nhất trong cây
   Input:
       + Tree t
       + int minVal&, maxVal&
   Output:
       + int minVal&, maxVal&
*/
void findMinMax(Tree t, int& minVal, int& maxVal)
{
    if(t.pRoot == NULL)
    {
        // Nếu cây rỗng thì gán giá trị đặc biệt
        minVal = maxVal = 0;
        return;
    }

    // Tìm node nhỏ nhất: duyệt về bên trái của cây
    Node* pMin = t.pRoot;
    while(pMin->pLeft != NULL)
    {
        pMin = pMin->pLeft;
    }
    minVal = pMin->data;

    // Tìm node lớn nhất: duyệt về bên phải của cây
    Node* pMax = t.pRoot;
    while(pMax->pRight != NULL)
    {
        pMax = pMax->pRight;
    }
    maxVal = pMax->data;
}

int main()
{
    Tree t;
    initTree(t);

    cout << "Test: Tao du lieu cho cay: " << endl;
    cout << "\t + Ket qua = " << initDataTree(t) << endl;

    cout << "\nTest: Print tree LNR:" << endl;
    printTree(t);

    cout << "\nTest 8: Tim gia tri:" << endl;
    cout << "\t+ Tim 66(1) = " << timGiaTri(t, 66) << endl;
    cout << "\t+ Tim 89(0) = " << timGiaTri(t, 89) << endl;

    cout << "\nTest 9: Dem toan bo so node cua cay:" << endl;
    cout << "\t+ So node = " << countNodes(t) << endl;

    cout << "\nTest 10: Dem so node la cua cay:" << endl;
    cout << "\t+ So node la = " << countLeafNodes(t) << endl;

    cout << "\nTest 11: In ra nhanh (LNR) cua mot node" << endl;
    cout << "\t+ In nhanh cua node goc: ";
    printLNR(t.pRoot);
    cout << endl;

    cout << "\nTest 12: Dem so node co gia tri nho hon X" << endl;
    cout << "\t+ So node co gia tri nho hon 60" << " = " << countLessThanX(t, 60) << endl;

    cout << "\nTest 13: Tong cac gia tri trong cay la: " << tong(t) << endl;

    cout << "\nTest 14: Tong cac node chan trong cay la:" << sumEvenNodes(t) << endl;

    int minVal, maxVal;
    findMinMax(t, minVal, maxVal);
    cout << "\nTest 15: Tim node nho nhat va lon nhat trong cay:" << endl;
    cout << "\t+ Node nho nhat = " << minVal << endl;
    cout << "\t+ Node lon nhat = " << maxVal << endl;

    return 0;
}
