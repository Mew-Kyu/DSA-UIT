#include <iostream>

using namespace std;

struct SinhVien
{
    int maSV;
    string hoTen;
    float diemTB;
    string xepLoai;
};

void inSV(SinhVien sv)
{
    cout << "Thong tin sinh vien: " << endl;
    cout << "\t+ Ma SV   : " << sv.maSV << endl;
    cout << "\t+ Ho ten  : " << sv.hoTen << endl;
    cout << "\t+ Diem TB : " << sv.diemTB << endl;
    cout << "\t+ Xep loai: " << sv.xepLoai << endl;
}

// Bước 1: Tạo cấu trúc Node
struct Node
{
    SinhVien data;
    Node* pNext; // Lưu địa chỉ Node phía sau
};

// Bước 2: Khởi tạo Node để lưu giá trị
Node* initNode(SinhVien value)
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

//6. Viết hàm khởi tạo dữ liệu cho danh sách sinh viên
void initDataListSV(List& dsSV)
{
    SinhVien sv1 = {123, "Nguyen Van A", 9.1, ""};
    SinhVien sv2 = {124, "Nguyen Van B", 8.8, ""};
    SinhVien sv3 = {125, "Nguyen Van C", 9.1, ""};
    SinhVien sv4 = {126, "Nguyen Van D", 2.1, ""};
    SinhVien sv5 = {127, "Nguyen Van F", 9.7, ""};
    SinhVien sv6 = {128, "Nguyen Van G", 4.1, ""};
    SinhVien sv7 = {129, "Nguyen Van H", 8.3, ""};

    addHead(dsSV, initNode(sv1));
    addHead(dsSV, initNode(sv2));
    addHead(dsSV, initNode(sv3));
    addHead(dsSV, initNode(sv4));
    addHead(dsSV, initNode(sv5));
    addHead(dsSV, initNode(sv6));
    addHead(dsSV, initNode(sv7));

    addTail(dsSV, initNode({130, "Nguyen Van K", 7.9, ""}));
}

//7. In danh sách sinh viên
void printDSSV(List l)
{
    if(l.pHead == NULL)
    {
        cout << "Danh sach rong..." << endl;
        return;
    }
          //start            stop       step
    for(Node* p = l.pHead; p != NULL; p = p->pNext)
    {
        inSV(p->data);
    }
    cout << endl << endl;
}

/* 8. Viết hàm tìm điểm trung bình cao nhất
Input:
    + l: List
Output
    + dtb: float
*/
float timMax(List l)
{
    float dtb = l.pHead->data.diemTB;
    for(Node* p = l.pHead; p != NULL; p = p->pNext)
    {
        if(p->data.diemTB > dtb)
           dtb = p->data.diemTB;
    }
    return dtb;
}

/* 9. viết hàm tìm kiếm sinh viên theo mã sinh viên
Input:
    + l: List
    + value: int
Output
    + SinhVien
*/
void timSV(List l, int value)
{
    for(Node* p = l.pHead; p != NULL; p = p->pNext)
    {
        if(p->data.maSV == value)
            inSV(p->data);
    }
    cout << endl << endl;
}

/* 10. viết hàm tìm kiếm sinh viên có trung bình cao nhất
Input:
    + l: List
Output
    + SinhVien
*/
void svMax(List l)
{
    float dtb = timMax(l);
    for(Node* p = l.pHead; p != NULL; p = p->pNext)
    {
        if(p->data.diemTB == dtb)
            inSV(p->data);
    }
    cout << endl << endl;
}

/* 11. viết hàm tìm kiếm sinh viên có điểm trung bình thấp nhất
Input:
    + l: List
Output
    + SinhVien
*/
void svMin(List l)
{
    SinhVien sv = l.pHead->data;
    float dtb = l.pHead->data.diemTB;
    for(Node* p = l.pHead; p != NULL; p = p->pNext)
    {
        if(p->data.diemTB < dtb)
            dtb = p->data.diemTB;
    }
    for(Node* p = l.pHead; p != NULL; p = p->pNext)
    {
        if(p->data.diemTB == dtb)
            inSV(p->data);
    }
    cout << endl << endl;
}

int main()
{
    List dsSV;
    initList(dsSV);

    //6
    cout << "Test: 6. Khoi data cho ds sv:" << endl;
    initDataListSV(dsSV);

    //7
    cout << "\nTest: 7. In ds sv:" << endl;
    printDSSV(dsSV);

    //8
    cout << "\nTest: 8. Diem trung binh cao nhat la: " << timMax(dsSV) << endl;

    //9
    cout << "\nTest: 9. Sinh vien co ma sinh vien 125 la: " << endl;
    timSV(dsSV, 125);

    //10
    cout << "\nTest: 10. Sinh vien co trung binh cao nhat la: " << endl;
    svMax(dsSV);

    //11
    cout << "\nTest: 11. Sinh vien co diem trung binh thap nhat la: " << endl;
    svMin(dsSV);

    return 0;
}
