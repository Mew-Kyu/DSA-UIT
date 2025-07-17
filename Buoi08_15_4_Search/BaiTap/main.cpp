#include <iostream>
#include <time.h>
using namespace std;

/*Viết hàm nhập giá trị tự động cho mảng,
các giá trị thuộc [100; 999],
số lượng phần tử thuộc [30; 50].
*/
void initDataAuto1(int a[], int& n)
{
    n = 30 + rand()%21; //[30; 50] = 30 + [0; 20]
    for(int i = 0; i < n; i++)
    {
        a[i] = 100 + rand()%900; //[100; 999] = 100 + [0;899]
    }
}

/*Viết hàm nhập giá trị tự động tăng dần cho mảng,
phần tử đầu tiên <= 130,
các phần từ kề nhau không quá 15,
các giá trị thuộc [100; 999],
số lượng phần tử thuộc [30; 50].

n => [30; 50]               50

a[0] = [100; 130]           130

a[1] = a[0] + [0; 15]       145
a[2] = a[1] + [0; 15]       160

a[i] = a[i-1] + [0; 15]

a[49]                       ???
*/
void initDataAuto2(int a[], int& n)
{
    n = 30 + rand()%21; //[30; 50] = 30 + [0; 20]
    a[0] = 100 + rand()%31;
    for(int i = 0; i < n; i++)
    {
        a[i] = a[i - 1] + rand()%16;
    }
}

//Hàm xuất mảng
void printArr(int a[], int n)
{
    cout << "Number: " << n << endl;
    for(int i = 0; i < n; i++)
    {
        cout << a[i] << "   ";
    }
    cout << endl;
}

/*Viết hàm tìm kiếm một phần tử trong mảng bằng tìm kiếm tuyến tính.
   Input:
       + int a[]
       + int n
       + int x
       + int &count
   Output:
       + return int
*/
int linearSearch(int a[], int n, int x, int &count) {
    count = 0;
    for (int i = 0; i < n; i++) {
        count++;
        if (a[i] == x) return i;
    }
    return -1;
}

/*Viết hàm tìm kiếm một phần tử trong mảng bằng tìm kiếm nhị phân.
   Input:
       + int a[]: mảng đã sắp xếp tăng dần
       + int n: số phần tử mảng
       + int x: giá trị cần tìm
       + int &count: số lần kiểm tra
   Output:
       + return vị trí tìm được, hoặc -1 nếu không tìm thấy
*/
int binarySearch(int a[], int n, int x, int &count) {
    count = 0;
    int left = 0, right = n - 1;
    while (left <= right) {
        count++;
        int mid = (left + right) / 2;
        if (a[mid] == x) return mid;
        else if (a[mid] < x) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

/*Viết hàm tìm kiếm một phần tử trong mảng bằng tìm kiếm nội suy.
   Input:
       + int a[]
       + int n
       + int x
       + int &count
   Output:
       + return int
*/
int interpolationSearch(int a[], int n, int x, int &count) {
    count = 0;
    int low = 0, high = n - 1;
    while (low <= high && x >= a[low] && x <= a[high]) {
        count++;
        if (a[high] == a[low]) break; // tránh chia cho 0

        int pos = low + ((double)(high - low) / (a[high] - a[low])) * (x - a[low]);

        if (pos < low || pos > high) break;

        if (a[pos] == x) return pos;
        if (a[pos] < x) low = pos + 1;
        else high = pos - 1;
    }
    return -1;
}

/* 4. So sánh số lần thực hiện tìm kiếm giữa 3 thuật toán
   Input:
       + int a[]
       + int n
       + int x
       + int &count1: số lần kiểm tra tìm kiếm tuyến tính
       + int &count2: số lần kiểm tra tìm kiếm nhị phân
       + int &count3: số lần kiểm tra tìm kiếm nội suy
   Output:
       + return int
*/
int compareSearchAlgorithms(int a[], int n, int x, int &count1, int &count2, int &count3) {
    int res1 = linearSearch(a, n, x, count1);
    int res2 = binarySearch(a, n, x, count2);
    int res3 = interpolationSearch(a, n, x, count3);

    if (res1 == res2 && res2 == res3)
        return res1;
    return -1;
}

int main()
{
    //int* a = new int[100];

    srand(time(0));
    int a[100];
    int n = 0;

    initDataAuto1(a, n);
    printArr(a, n);

    //InitDataAuto2
    initDataAuto2(a, n);
    printArr(a, n);

    //Linear Search
    cout << "\nTest: Linear search:" << endl;
    int count;
    cout << "\t + Ket qua tim " << a[0] << " (0) = " << linearSearch(a, n, a[0], count) << endl;
    cout << "\t + Ket qua tim " << a[1] << " (1) = " << linearSearch(a, n, a[1], count) << endl;
    cout << "\t + Ket qua tim 9999 (-1) = " << linearSearch(a, n, 9999, count) << endl;

    //Binary Search
    cout << "\nTest: Binary search:" << endl;
    cout << "\t + Ket qua tim " << a[0] << " (0) = " << binarySearch(a, n, a[0], count) << endl;
    cout << "\t + Ket qua tim " << a[1] << " (1) = " << binarySearch(a, n, a[1], count) << endl;
    cout << "\t + Ket qua tim 9999 (-1) = " << binarySearch(a, n, 9999, count) << endl;

    //Interpolation Search
    cout << "\nTest: Interpolation search:" << endl;
    cout << "\t + Ket qua tim " << a[0] << " (0) = " << interpolationSearch(a, n, a[0], count) << endl;
    cout << "\t + Ket qua tim " << a[1] << " (1) = " << interpolationSearch(a, n, a[1], count) << endl;
    cout << "\t + Ket qua tim 9999 (-1) = " << interpolationSearch(a, n, 9999, count) << endl;

    //Compare Algorithms
    cout << "\nTest: Compare search algorithms:" << endl;
    int count1, count2, count3;
    int x = a[2]; // chọn giá trị có thật để so sánh
    int pos = compareSearchAlgorithms(a, n, x, count1, count2, count3);

    cout << "\t + Gia tri can tim: " << x << endl;
    cout << "\t + Linear     - So lan kiem tra: " << count1 << endl;
    cout << "\t + Binary     - So lan kiem tra: " << count2 << endl;
    cout << "\t + Interpol   - So lan kiem tra: " << count3 << endl;
    cout << "\t + Vi tri tim thay (neu cac thuat toan cung ket qua): " << pos << endl;

    return 0;
}
