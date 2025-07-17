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

    p->data = value;
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

/*Hàm kiểm tra Stack có rỗng hay không
Input:
    + s: Stack&

Output:
    + return: bool
*/
bool isEmpty(Stack s)
{
    return (s.pTop == NULL);
}

/*Hàm đẩy một phần tử vào đỉnh Stack
Input:
    + s: Stack&
    + p: Node*

Output:
    + s: Stack&
*/
void push(Stack& s, Node* p)
{
    if(p == NULL)
        return;

    p->pNext = s.pTop;
    s.pTop = p;
}

/*Hàm lấy phần tử ở đỉnh Stack ra
Input:
    + s: Stack&

Output:
    + return: int
*/
int pop(Stack& s)
{
    if(isEmpty(s))
        return -1; // Trả về -1 nếu Stack rỗng

    Node* p = s.pTop;
    int value = p->data;
    s.pTop = s.pTop->pNext;

    delete p;
    return value;
}

//Hàm in trạng thái của các cột
void printStacks(Stack A, Stack B, Stack C)
{
    cout << "Cot A: ";
    for(Node* p = A.pTop; p != NULL; p = p->pNext) cout << p->data << " ";
    cout << "\nCot B: ";
    for(Node* p = B.pTop; p != NULL; p = p->pNext) cout << p->data << " ";
    cout << "\nCot C: ";
    for(Node* p = C.pTop; p != NULL; p = p->pNext) cout << p->data << " ";
    cout << "\n\n";
}

int main()
{
    Stack A, B, C;
    initStack(A);
    initStack(B);
    initStack(C);

    int n = 3; // Số đĩa cần chuyển
    int moves = 0;

    for(int i = n; i >= 1; --i)
    {
        push(A, initNode(i));
    }

    int choice;
    do {
        printStacks(A, B, C);

        cout << "Chon nuoc di:\n1. A -> B\n2. A -> C\n3. B -> A\n4. B -> C\n5. C -> A\n6. C -> B\n0. Thoat\n";
        cout << "Chon so tuong ung: ";
        cin >> choice;

        Stack *from, *to;
        switch(choice) {
            case 1: from = &A; to = &B; break;
            case 2: from = &A; to = &C; break;
            case 3: from = &B; to = &A; break;
            case 4: from = &B; to = &C; break;
            case 5: from = &C; to = &A; break;
            case 6: from = &C; to = &B; break;
            case 0: return 0;
            default: cout << "Lua chon khong hop le.\n"; continue;
        }

        int disk = pop(*from);

        if(disk == -1 || (!isEmpty(*to) && disk > to->pTop->data)) {
            cout << "Nuoc di khong hop le!\n";
            if(disk != -1) push(*from, initNode(disk));
        } else {
            push(*to, initNode(disk));
            moves++;
        }

        cout << "So buoc da di chuyen: " << moves << "\n\n";
    } while(true);

    return 0;
}
