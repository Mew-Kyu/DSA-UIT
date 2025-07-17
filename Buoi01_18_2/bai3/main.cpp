#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

struct NhanVien {
    int maNV;
    string hoTen;
    float luongCB;
    int soNg;
    float luongHT;
};

// Ham khoi tao mang nhan vien voi 5 nhan vien da cho san
void initArrNV(NhanVien arrNV[], int &soNV) {
    soNV = 5;
    arrNV[0] = {1, "Nguyen Hoang Long", 6000000, 22, 0};
    arrNV[1] = {2, "Dang Kien Tuong", 4000000, 24, 0};
    arrNV[2] = {3, "Nguyen Vu Hao", 5500000, 20, 0};
    arrNV[3] = {4, "Nguyen Thai", 5000000, 26, 0};
    arrNV[4] = {5, "Nguyen The Hoa", 4500000, 25, 0};
}

// Ham in danh sach nhan vien
void inArrNV(NhanVien arrNV[], int soNV) {
    cout << left << setw(10) << "MaNV"
         << setw(25) << "Ho ten"
         << setw(15) << "LuongCB"
         << setw(10) << "SoNg"
         << setw(15) << "LuongHT" << endl;
    for (int i = 0; i < soNV; i++) {
        cout << left << setw(10) << arrNV[i].maNV
             << setw(25) << arrNV[i].hoTen
             << setw(15) << arrNV[i].luongCB
             << setw(10) << arrNV[i].soNg
             << setw(15) << arrNV[i].luongHT << endl;
    }
}

// Ham tinh luong hang thang theo cong thuc de bai:
// LuongHT = LuongCB + soNg * 180000
// Neu LuongHT > 8 trieu thi cong bonus 5%
// Neu LuongCB < 5 trieu thi cong phu cap 10%
void tinhLuongHT(NhanVien arrNV[], int soNV) {
    for (int i = 0; i < soNV; i++) {
        arrNV[i].luongHT = arrNV[i].luongCB + arrNV[i].soNg * 180000;
        if (arrNV[i].luongHT > 8000000)
            arrNV[i].luongHT *= 1.05;  // bonus 5%
        if (arrNV[i].luongCB < 5000000)
            arrNV[i].luongHT += arrNV[i].luongCB * 0.1;  // phu cap 10%
    }
}

// Yeu cau 4: Tinh tong luong cong ty phai tra
float tongLuongCongTy(NhanVien arrNV[], int soNV) {
    float tong = 0;
    for (int i = 0; i < soNV; i++) {
        tong += arrNV[i].luongHT;
    }
    return tong;
}

// Yeu cau 5: Tinh tong luong cac nhan vien co luongCB < 5 trieu
float tongLuongNVDuoi5Tr(NhanVien arrNV[], int soNV) {
    float tong = 0;
    for (int i = 0; i < soNV; i++) {
        if (arrNV[i].luongCB < 5000000)
            tong += arrNV[i].luongHT;
    }
    return tong;
}

// Yeu cau 6: Tim nhan vien theo maNV
void timNVTheoMa(NhanVien arrNV[], int soNV) {
    int ma;
    cout << "\nNhap ma nhan vien can tim: ";
    cin >> ma;
    bool timThay = false;
    cout << "\nKet qua tim kiem:\n";
    cout << left << setw(10) << "MaNV"
         << setw(25) << "Ho ten"
         << setw(15) << "LuongCB"
         << setw(10) << "SoNg"
         << setw(15) << "LuongHT" << endl;
    for (int i = 0; i < soNV; i++) {
        if (arrNV[i].maNV == ma) {
            cout << left << setw(10) << arrNV[i].maNV
                 << setw(25) << arrNV[i].hoTen
                 << setw(15) << arrNV[i].luongCB
                 << setw(10) << arrNV[i].soNg
                 << setw(15) << arrNV[i].luongHT << endl;
            timThay = true;
        }
    }
    if (!timThay)
        cout << "Khong tim thay nhan vien co ma " << ma << endl;
}

// Yeu cau 7: Tim nhan vien co luong hang thang thap nhat
void timNVLuongHTThapNhat(NhanVien arrNV[], int soNV) {
    if (soNV == 0) return;
    float minLuong = arrNV[0].luongHT;
    for (int i = 1; i < soNV; i++) {
        if (arrNV[i].luongHT < minLuong)
            minLuong = arrNV[i].luongHT;
    }
    cout << "\nNhan vien co luong hang thang thap nhat (" << minLuong << "):\n";
    cout << left << setw(10) << "MaNV"
         << setw(25) << "Ho ten"
         << setw(15) << "LuongCB"
         << setw(10) << "SoNg"
         << setw(15) << "LuongHT" << endl;
    for (int i = 0; i < soNV; i++) {
        if (arrNV[i].luongHT == minLuong) {
            cout << left << setw(10) << arrNV[i].maNV
                 << setw(25) << arrNV[i].hoTen
                 << setw(15) << arrNV[i].luongCB
                 << setw(10) << arrNV[i].soNg
                 << setw(15) << arrNV[i].luongHT << endl;
        }
    }
}

// Yeu cau 8: Tim nhan vien co luongCB cao nhat
void timNVLuongCBCaoNhat(NhanVien arrNV[], int soNV) {
    if (soNV == 0) return;
    float maxLuong = arrNV[0].luongCB;
    for (int i = 1; i < soNV; i++) {
        if (arrNV[i].luongCB > maxLuong)
            maxLuong = arrNV[i].luongCB;
    }
    cout << "\nNhan vien co luong co ban cao nhat (" << maxLuong << "):\n";
    cout << left << setw(10) << "MaNV"
         << setw(25) << "Ho ten"
         << setw(15) << "LuongCB"
         << setw(10) << "SoNg"
         << setw(15) << "LuongHT" << endl;
    for (int i = 0; i < soNV; i++) {
        if (arrNV[i].luongCB == maxLuong) {
            cout << left << setw(10) << arrNV[i].maNV
                 << setw(25) << arrNV[i].hoTen
                 << setw(15) << arrNV[i].luongCB
                 << setw(10) << arrNV[i].soNg
                 << setw(15) << arrNV[i].luongHT << endl;
        }
    }
}

int main() {
    NhanVien arrNV[100];
    int soNV = 0;

    // Yeu cau 1: Khoi tao du lieu voi 5 nhan vien da cho san
    initArrNV(arrNV, soNV);

    // Yeu cau 2: In danh sach nhan vien ban dau
    cout << "\nDanh sach nhan vien ban dau:\n";
    inArrNV(arrNV, soNV);

    // Yeu cau 3: Tinh luong hang thang va in lai danh sach sau khi tinh luong
    tinhLuongHT(arrNV, soNV);
    cout << "\nDanh sach nhan vien sau khi tinh luong hang thang:\n";
    inArrNV(arrNV, soNV);

    // Yeu cau 4: Tinh tong luong cong ty phai tra
    cout << "\nTong luong cong ty phai tra: " << tongLuongCongTy(arrNV, soNV) << " VND" << endl;

    // Yeu cau 5: Tinh tong luong cac nhan vien co luongCB < 5 trieu
    cout << "\nTong luong cac nhan vien co luongCB < 5 trieu: " << tongLuongNVDuoi5Tr(arrNV, soNV) << " VND" << endl;

    // Yeu cau 6: Tim nhan vien theo maNV
    timNVTheoMa(arrNV, soNV);

    // Yeu cau 7: Tim nhan vien co luong hang thang thap nhat
    timNVLuongHTThapNhat(arrNV, soNV);

    // Yeu cau 8: Tim nhan vien co luongCB cao nhat
    timNVLuongCBCaoNhat(arrNV, soNV);

    return 0;
}
