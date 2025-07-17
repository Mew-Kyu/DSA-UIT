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
    cout << "[" << sv.maSV << ", " << sv.hoTen << ", "
         << sv.diemTB << ", " << sv.xepLoai << "]" << endl;
}

//Bước 1: Định nghĩa cấu trúc Node
struct Node
{
    SinhVien data;
    Node* pPre;
    Node* pNext;
};

//Bước 2: Cấp phát động Node để lưu giá trị
Node* initNode(SinhVien value)
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

/* 4. Viết hàm thêm sinh viên vào đầu danh sách
Input:
    + l: List&
    + p: Node*
Output:
    + l: List&
*/
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

/* 5. Viết hàm thêm sinh viên vào cuối danh sách
Input:
    + l: List&
    + p: Node*
Output:
    + l: List&
*/
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

//6. Viết hàm khởi tạo dữ liệu cho danh sách sinh viên
int initDataListSV(List& dsSV)
{
    SinhVien sv1 = {123, "Nguyen Van A", 9.1, ""};
    SinhVien sv2 = {124, "Nguyen Van B", 8.8, ""};
    SinhVien sv3 = {125, "Nguyen Van C", 9.1, ""};
    SinhVien sv4 = {126, "Nguyen Van D", 2.1, ""};
    SinhVien sv5 = {127, "Nguyen Van F", 9.7, ""};
    SinhVien sv6 = {128, "Nguyen Van G", 4.1, ""};
    SinhVien sv7 = {129, "Nguyen Van H", 8.3, ""};

    pushHead(dsSV, initNode(sv1));
    pushHead(dsSV, initNode(sv2));
    pushHead(dsSV, initNode(sv3));
    pushHead(dsSV, initNode(sv4));
    pushTail(dsSV, initNode(sv5));
    pushTail(dsSV, initNode(sv6));
    pushTail(dsSV, initNode(sv7));

    pushTail(dsSV, initNode({130, "Nguyen Van K", 7.9, ""}));

    return 8;
}

//7. In danh sách sinh viên
void printfList(List l)
{
    cout << endl << "In tu pHead den pTail:" << endl;
    for(Node* p = l.pHead; p != NULL; p = p->pNext)
    {
        inSV(p->data);
    }

    cout << endl << "In tu pTail den pHead:" << endl;
    for(Node* p = l.pTail; p != NULL; p = p->pPre)
    {
        inSV(p->data);
    }
}


/* 8. Viết hàm cập nhật xếp loại học lực
Input:
    + dsSV: List&
Output:
    + dsSV: List&
*/
void xepLoai(List& dsSV)
{
    for(Node* p = dsSV.pTail; p != NULL; p = p->pPre)
    {
        float d = p->data.diemTB;
        if(d >= 9)
            p->data.xepLoai = "Xuat Sac";
        else if (d >= 8)
            p->data.xepLoai = "Gioi";
        else if (d >= 7)
            p->data.xepLoai = "Kha";
        else if (d >= 6)
            p->data.xepLoai = "Trung binh kha";
        else if (d >= 5)
            p->data.xepLoai = "Trung binh";
        else
            p->data.xepLoai = "Hoc lai";
    }
}

/* 9. Viết hàm tìm điểm trung bình cao nhất
Input:
    + dsSV: List
Output
    + dtb: float
*/
float timMax(List dsSV)
{
    float dtb = dsSV.pHead->data.diemTB;
    for(Node* p = dsSV.pHead; p != NULL; p = p->pNext)
    {
        if(p->data.diemTB > dtb)
           dtb = p->data.diemTB;
    }
    return dtb;
}

/* 10. viết hàm tìm kiếm sinh viên theo mã sinh viên
Input:
    + dsSV: List
    + value: int
Output
    + SinhVien
*/
void timSV(List dsSV, int value)
{
    for(Node* p = dsSV.pHead; p != NULL; p = p->pNext)
    {
        if(p->data.maSV == value)
            inSV(p->data);
    }
    cout << endl << endl;
}

/* 11. viết hàm tìm kiếm sinh viên có điểm trung bình cao nhất
Input:
    + dsSV: List
Output
    + SinhVien
*/
void svMax(List dsSV)
{
    float dtb = timMax(dsSV);
    for(Node* p = dsSV.pHead; p != NULL; p = p->pNext)
    {
        if(p->data.diemTB == dtb)
            inSV(p->data);
    }
    cout << endl << endl;
}

/* 12. viết hàm tìm kiếm sinh viên có điểm trung bình thấp nhất
Input:
    + dsSV: List
Output
    + SinhVien
*/
void svMin(List dsSV)
{
    SinhVien sv = dsSV.pHead->data;
    float dtb = dsSV.pHead->data.diemTB;
    for(Node* p = dsSV.pHead; p != NULL; p = p->pNext)
    {
        if(p->data.diemTB < dtb)
            dtb = p->data.diemTB;
    }
    for(Node* p = dsSV.pHead; p != NULL; p = p->pNext)
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
    cout << "Test: 6. Khoi tao du lieu danh sach sinh vien: " << endl;
    int siSo = initDataListSV(dsSV);
    cout << siSo << "sinh vien." << endl;

    //7
    cout << "\nTest: 7. In danh sach sinh vien: " << endl;
    printfList(dsSV);

    //8
    cout << "\nTest: 8. Cap nhat xep loai hoc luc:" << endl;
    xepLoai(dsSV);
    printfList(dsSV);

    //9
    cout << "\nTest: 9. Diem trung binh cao nhat la: " << timMax(dsSV) << endl;

    //10
    cout << "\nTest: 10. Sinh vien co ma sinh vien 125 la: " << endl;
    timSV(dsSV, 125);

    //11
    cout << "\nTest: 11. Sinh vien co diem trung binh cao nhat la: " << endl;
    svMax(dsSV);

    //12
    cout << "\nTest: 12. Sinh vien co diem trung binh thap nhat la: " << endl;
    svMin(dsSV);

    return 0;
}
