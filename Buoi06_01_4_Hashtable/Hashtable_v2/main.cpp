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

//Bước 3: Định nghĩa cấu trúc Hashtable
const int Size = 5;
struct Hashtable
{
    struct Bucket
    {
        Node* pHead;
        Node* pTail;
    };

    Bucket buckets[Size];
};

typedef Hashtable HT;

//Bước 4: Khởi tạo hashtable
void initHashtable(Hashtable& h)
{
    for(int i = 0; i < Size; i++)
    {
        h.buckets[i].pHead = NULL;
        h.buckets[i].pTail = NULL;
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

void add(Hashtable& h, Node* p)
{
    //B1: Tính vị trí bucket
    int viTri = hashFunc(p);

    //B2: Push vào bucket đã xác định
    //Cách gọi h.buckets[viTri]

    if(h.buckets[viTri].pHead == NULL)
    {
        h.buckets[viTri].pHead = p;
        h.buckets[viTri].pTail = p;
    }
    else
    {
        h.buckets[viTri].pTail->pNext = p;
        h.buckets[viTri].pTail = p;
    }
}

void add(Hashtable& h, int value)
{
    //B1: Tính vị trí bucket
    int viTri = hashFunc(value);

    //B2: Push vào bucket đã xác định
    //Cách gọi h.buckets[viTri]
    Node* p = initNode(value);
    if(h.buckets[viTri].pHead == NULL)
    {
        h.buckets[viTri].pHead = p;
        h.buckets[viTri].pTail = p;
    }
    else
    {
        h.buckets[viTri].pTail->pNext = p;
        h.buckets[viTri].pTail = p;
    }
}

//1. Tạo dữ liệu cho bảng băm
int initDataHashtable(Hashtable& h)
{
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

    return 10;
}

//2. In bảng băm
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

/* 3. Viết hàm tạo dữ liệu cho bảng băm từ mảng 1 chiều
Input:
    + HT h
    + int a[]
    + int n
Output:
    + HT& h
*/
void initDataHTArr(HT& h, int a[], int n)
{
    for(int i = 0; i < n; i++)
    {
        add(h, a[i]);
    }
}

/* 5. Viết hàm tìm một giá trị trong bảng băm
Input:
    + HT h
    + int value
Output:
    + return bool
*/
bool timGiaTri(HT h, int value)
{
    //1. Tìm vị trí BK có khả năng
    int vt = hashFunc(value);

    //2. Tìm trên BK đó
    for(Node* p = h.buckets[vt].pHead; p != NULL; p=p->pNext)
    {
        if(p->data == value)
            return true;
    }
    return false;
}

/* 6. Viết hàm xóa giá trị trong bảng băm
Input:
    + HT h
    + int value
Output:
    + return bool
*/
bool xoaGiaTri(HT& h, int value)
{
    // 1. Tìm vị trí BK có khả năng
    int vt = hashFunc(value);
    Node* p = h.buckets[vt].pHead;
    Node* prev = NULL;

    // 2. Duyệt trên BK đó để tìm giá trị cần xóa
    while(p != NULL)
    {
        if(p->data == value)
        {
            // Nếu p là phần tử đầu tiên
            if(prev == NULL)
            {
                h.buckets[vt].pHead = p->pNext;
                // Nếu p cũng là phần tử cuối cùng
                if(p == h.buckets[vt].pTail)
                    h.buckets[vt].pTail = NULL;
            }
            else
            {
                prev->pNext = p->pNext;
                // Nếu p là phần tử cuối cùng
                if(p == h.buckets[vt].pTail)
                    h.buckets[vt].pTail = prev;
            }
            delete p;
            return true;
        }
        prev = p;
        p = p->pNext;
    }
    return false;
}

/* 7. Viết hàm tính tổng các giá trị lẻ trong bảng băm
Input:
    + HT h
Output:
    + return int
*/
int tongGiaTriLe(HT h)
{
    int tong = 0;
    for (int i = 0; i < Size; i++)
    {
        for (Node* p = h.buckets[i].pHead; p != NULL; p = p->pNext)
        {
            if(p->data % 2 != 0)
                tong += p->data;
        }
    }
    return tong;
}

/* 8. Viết hàm kiểm tra bảng băm có rỗng không
Input:
    + HT h
Output:
    + return bool
*/
bool isEmpty(HT h)
{
    for (int i = 0; i < Size; i++)
    {
        if(h.buckets[i].pHead != NULL)
            return false;
    }
    return true;
}

/* 9. Viết hàm xử lý bảng băm theo một điều kiện kiểm tra số nguyên tố
Input:
    + int n
Output:
    + return bool
*/
bool isPrime(int n)
{
    if(n < 2) return false;
    for(int i = 2; i * i <= n; i++)
    {
        if(n % i == 0)
            return false;
    }
    return true;
}
// Hàm in số nguyên tố
void inSoNguyenTo(HT h)
{
    cout << "Cac so nguyen to trong Hashtable: ";
    for (int i = 0; i < Size; i++)
    {
        for (Node* p = h.buckets[i].pHead; p != NULL; p = p->pNext)
        {
            if(isPrime(p->data))
                cout << p->data << "\t";
        }
    }
    cout << endl;
}

int main()
{
    //Hashtable h2;
    //initHashtable(8);

    Hashtable h;
    initHashtable(h);

    cout << "Test: 1. Tao du lieu: " << endl;
    int soLuong = initDataHashtable(h);
    cout << "\t+ Ket qua: " << soLuong << endl;

    cout << "\nTest: 2. In bang bam: " << endl;
    printHashTable(h);

    cout << "\nTest: 3. Tao du lieu tu mang 1 chieu: " << endl;
    int a[] = {1, 7, 90, 56, 23, 78};
    int n = 6;
    initDataHTArr(h, a, n);
    printHashTable(h);

    cout << "\nTest: 5. Tim gia tri: " << endl;
    cout << "\t+ Ket qua tim 53(1) = " << timGiaTri(h, 53) << endl;
    cout << "\t+ Ket qua tim 91(0) = " << timGiaTri(h, 91) << endl;

    cout << "\nTest: 6. Xoa gia tri (xoa 36): " << endl;
    bool kqXoa = xoaGiaTri(h, 36);
    cout << "\t+ Ket qua xoa 36(" << (kqXoa ? 1 : 0) << ") = " << kqXoa << endl;
    printHashTable(h);

    cout << "\nTest: 7. Tinh tong cac gia tri le: " << endl;
    int tongLe = tongGiaTriLe(h);
    cout << "\t+ Tong cac gia tri le = " << tongLe << endl;

    cout << "\nTest: 8. Kiem tra bang bam co rong khong: " << endl;
    cout << "\t+ Kiem tra rong (" << (isEmpty(h) ? 1 : 0) << ") = " << isEmpty(h) << endl;

    cout << "\nTest: 9. Xuat cac so nguyen to trong bang bam: " << endl;
    inSoNguyenTo(h);

    return 0;
}
