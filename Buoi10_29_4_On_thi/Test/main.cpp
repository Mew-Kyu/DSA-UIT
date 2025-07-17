#include <iostream>
#include <stack>
using namespace std;

//Họ và tên: Nguyễn Hoàng Long
//Mã sinh viên: 24410186
//Đề: 6 % 3 = 0 => Làm đề 1


//Bước 1: Định nghĩa cấu trúc Node
struct Node
{
    double data;
    Node* pLeft;
    Node* pRight;
};

//Bước 2: Cấp phát động Node để lưu giá trị cần lưu
Node* initNode(double value)
{
    Node* p = new Node;
    p->data = value;
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

/*1. Hàm chèn node chứa giá trị double vào cây
Input:
    + Tree t
    + double value
Output:
    + -1 nếu chèn thành công
    + 1 nếu chèn thất bại (giá trị đã tồn tại)
*/
int addValue(Tree& t, double value)
{
    // Kiểm tra giá trị đã tồn tại chưa
    Node* pCheck = t.pRoot;
    while(pCheck != NULL)
    {
        if(value == pCheck->data)
            return 1; // Giá trị đã tồn tại, trả về 1

        if(value < pCheck->data)
            pCheck = pCheck->pLeft;
        else
            pCheck = pCheck->pRight;
    }

    // Tạo node mới
    Node* p = initNode(value);

    if(t.pRoot == NULL)
    {
        t.pRoot = p;
        return -1; // Chèn thành công
    }

    // Cây không rỗng
    Node* pGoto = t.pRoot;
    Node* pLoca = NULL;
    while(pGoto != NULL) // Đi tìm Node thích hợp
    {
        pLoca = pGoto;
        if(p->data < pGoto->data)
            pGoto = pGoto->pLeft;
        else if(p->data > pGoto->data)
            pGoto = pGoto->pRight;
    }

    // Gắn p vào pLoca
    if(p->data < pLoca->data)
        pLoca->pLeft = p;
    else if(p->data > pLoca->data)
        pLoca->pRight = p;

    return -1; // Chèn thành công
}

/*2. Hàm khởi tạo dữ liệu cho cây từ mảng 1 chiều
Input:
    + Tree t
    + double arr[] - mảng chứa các giá trị
    + int n - số phần tử của mảng
Output:
    + số lượng phần tử đã thêm thành công vào cây
*/
int initDataTreeFromArray(Tree& t, double arr[], int n)
{
    int count = 0;
    for(int i = 0; i < n; i++)
    {
        if(addValue(t, arr[i]) == -1)
            count++;
    }
    return count;
}

//3. Hàm in các giá trị (tăng dần) có trong cây
void printTreeInOrder(Tree t)
{
    stack<Node*> s;
    Node* p = t.pRoot;
    while(p != NULL || s.empty() == false)
    {
        // Left liên tục
        while(p != NULL)
        {
            s.push(p);
            p = p->pLeft;
        }

        // Xử lý Node
        p = s.top();
        s.pop();
        cout << p->data << "   ";

        // Chuyển qua Right
        p = p->pRight;
    }
    cout << endl;
}

/*4. Hàm tìm kiếm node giá trị X trong cây
Input:
    + Tree t
    + double x: giá trị cần tìm
Output:
    + -1 (tìm thấy)
    + 1 (không tìm thấy)
*/
int findValue(Tree t, double x)
{
    Node* p = t.pRoot;

    while(p != NULL)
    {
        if(x == p->data)
            return -1; // Tìm thấy

        if(x < p->data)
            p = p->pLeft;
        else
            p = p->pRight;
    }
    return 1; // Không tìm thấy
}

/*5. Hàm tính tổng các node lá của cây
Input:
    + Tree t
Output:
    + doubleL: Tổng các node lá
*/
double sumLeafNodes(Tree t)
{
    double sum = 0;
    stack<Node*> s;
    Node* p = t.pRoot;

    if(p == NULL)
        return 0;

    while(p != NULL || !s.empty())
    {
        while(p != NULL)
        {
            s.push(p);
            p = p->pLeft;
        }

        p = s.top();
        s.pop();

        // Nếu là node lá (không có con trái và con phải)
        if(p->pLeft == NULL && p->pRight == NULL)
            sum += p->data;

        p = p->pRight;
    }

    return sum;
}

/*6. Hàm đếm các node chỉ có 1 nhánh con
Input:
    + Tree t
Output:
    + int: Số lượng node chỉ có 1 nhánh con
*/
int countNodesWithOneChild(Tree t)
{
    int count = 0;
    stack<Node*> s;
    Node* p = t.pRoot;

    if(p == NULL)
        return 0;

    while(p != NULL || !s.empty())
    {
        while(p != NULL)
        {
            s.push(p);
            p = p->pLeft;
        }

        p = s.top();
        s.pop();

        // Node chỉ có 1 nhánh con
        if((p->pLeft != NULL && p->pRight == NULL) ||
           (p->pLeft == NULL && p->pRight != NULL))
            count++;

        p = p->pRight;
    }

    return count;
}

/*7. Hàm tìm giá trị lớn nhất và giá trị nhỏ nhất trong cây
Input:
    + Tree t
    + double &min
    + double &max
Output:
    + 0 (cây rỗng)
    + 1 (thành công)
*/
int findMinMax(Tree t, double &min, double &max)
{
    if(t.pRoot == NULL)
        return 0; // Cây rỗng

    // Tìm min (giá trị nhỏ nhất nằm ở node trái nhất)
    Node* pMin = t.pRoot;
    while(pMin->pLeft != NULL)
        pMin = pMin->pLeft;
    min = pMin->data;

    // Tìm max (giá trị lớn nhất nằm ở node phải nhất)
    Node* pMax = t.pRoot;
    while(pMax->pRight != NULL)
        pMax = pMax->pRight;
    max = pMax->data;

    return 1;
}

/*8. Hàm tính giá trị trung bình các node trong cây
Input:
    + Tree t
Output:
    + double: Giá trị trung bình của các node
*/
double averageValue(Tree t)
{
    double sum = 0;
    int count = 0;
    stack<Node*> s;
    Node* p = t.pRoot;

    if(p == NULL)
        return 0;

    while(p != NULL || !s.empty())
    {
        while(p != NULL)
        {
            s.push(p);
            p = p->pLeft;
        }

        p = s.top();
        s.pop();

        // Cộng giá trị node hiện tại
        sum += p->data;
        count++;

        p = p->pRight;
    }

    return (count > 0) ? sum / count : 0;
}

/*9. Hàm khởi tạo 2 cây nhị phân tìm kiếm mới
Input:
    + Tree t - cây ban đầu
    + Tree &leftTree - cây được tạo từ nhánh trái
    + Tree &rightTree - cây được tạo từ nhánh phải
Output:
    + 0: cây rỗng
    + 1: (thành công)
*/
int createLeftRightTrees(Tree t, Tree &leftTree, Tree &rightTree)
{
    if(t.pRoot == NULL)
        return 0; // Cây rỗng

    // Khởi tạo cây trái và phải
    initTree(leftTree);
    initTree(rightTree);

    // Xây dựng cây từ nhánh trái
    if(t.pRoot->pLeft != NULL)
    {
        stack<Node*> s;
        Node* p = t.pRoot->pLeft;

        while(p != NULL || !s.empty())
        {
            while(p != NULL)
            {
                s.push(p);
                p = p->pLeft;
            }

            p = s.top();
            s.pop();

            // Thêm node vào cây trái
            addValue(leftTree, p->data);

            p = p->pRight;
        }
    }

    // Xây dựng cây từ nhánh phải
    if(t.pRoot->pRight != NULL)
    {
        stack<Node*> s;
        Node* p = t.pRoot->pRight;

        while(p != NULL || !s.empty())
        {
            while(p != NULL)
            {
                s.push(p);
                p = p->pLeft;
            }

            p = s.top();
            s.pop();

            // Thêm node vào cây phải
            addValue(rightTree, p->data);

            p = p->pRight;
        }
    }

    return 1;
}

int main()
{
    Tree t;
    initTree(t); // Khởi tạo cây rỗng

    // Câu 1
    cout << "Cau 1: Them gia tri vao cay moi" << endl;
    Tree t1;
    initTree(t1); // Khởi tạo cây mới
    double valueX = 45.6;
    int res1 = addValue(t1, valueX);
    cout << "Cay t1 sau khi them:" << endl;
    printTreeInOrder(t1);

    // Câu 2
    double arr[] = {50.1, 70.1, 60.2, 30.4, 70.7, 90.5, 75.2, 25.3, 30.4, 10.5, 90.5};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "\nCau 2: Khoi tao cay tu mang" << endl;
    int added = initDataTreeFromArray(t, arr, n);
    cout << "So phan tu da them vao cay: " << added << endl; //9, do 30.4 và 90.5 trùng

    // Câu 3
    cout << "\nCau 3: Cac gia tri trong cay theo thu tu tang dan:" << endl;
    printTreeInOrder(t);

    // Câu 4
    cout << "\nCau 4: Tim kiem gia tri trong cay:" << endl;
    double searchValue1 = 60.2;
    double searchValue2 = 100.0;
    cout << "Tim " << searchValue1 << " (ton tai): " << findValue(t, searchValue1) << endl;
    cout << "Tim " << searchValue2 << " (khong ton tai): " << findValue(t, searchValue2) << endl;

    // Câu 5
    cout << "\nCau 5: Tong cac node la: " << sumLeafNodes(t) << endl;

    // Câu 6
    cout << "\nCau 6: So node chi co 1 nhanh con: " << countNodesWithOneChild(t) << endl;

    // Câu 7
    double minValue, maxValue;
    cout << "\nCau 7: Tim gia tri lon nhat va nho nhat trong cay:" << endl;
    if(findMinMax(t, minValue, maxValue))
        cout << "Min: " << minValue << ", Max: " << maxValue << endl;
    else
        cout << "Cay rong" << endl;

    // Câu 8
    cout << "\nCau 8: Gia tri trung binh cac node: " << averageValue(t) << endl;

    // Câu 9
    Tree leftTree, rightTree;
    cout << "\nCau 9: Tao 2 cay tu nhanh trai va phai:" << endl;
    if(createLeftRightTrees(t, leftTree, rightTree))
    {
        cout << "Cay con ben trai:" << endl;
        printTreeInOrder(leftTree);

        cout << "Cay con ben phai:" << endl;
        printTreeInOrder(rightTree);
    }
    else
        cout << "Cay rong" << endl;

    return 0;
}
