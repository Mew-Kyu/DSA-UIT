#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

// In ra 10% giá trị đầu tiên của mảng
void printArr(double a[], int n)
{
    for(int i = 0; i < n*0.1; i++)
    {
        cout << a[i] << "\n";
    }
    cout << endl << endl;
}

/* Sắp xếp mảng bằng thuật toán chọn trực tiếp
   Input:
       + double a[]: mảng số thực
       + int n: số lượng phần tử mảng
       + bool tang: true nếu sắp xếp tăng dần, false nếu giảm dần
   Output:
       + Không có
*/
void selectionSort(double a[], int n, bool tang)
{
    int m;
    for(int i = 0; i < n - 1; i++)
    {
        m  = i;
        for(int j = i + 1; j < n; j++)
        {
            if((tang && a[j] < a[m]) || (!tang && a[j] > a[m]))
                m = j;
        }
        if(m != i)
            swap(a[m], a[i]);
    }
}

/* Sắp xếp mảng bằng thuật toán chèn trực tiếp
   Input:
       + double a[]: mảng số thực
       + int n: số lượng phần tử mảng
       + bool tang: true nếu sắp xếp tăng dần, false nếu giảm dần
   Output:
       + Không có
*/
void insertionSort(double a[], int n, bool tang)
{
    for (int i = 1; i < n; i++)
    {
        double item = a[i];
        int j;
        for (j = i-1; j >= 0; j--)
        {
            if ((tang && a[j] <= item) || (!tang && a[j] >= item))
                break;

            a[j+1] = a[j];
        }
        a[j+1] = item;
    }
}

/* Đo thời gian thực hiện thuật toán sắp xếp
   Input:
       + double a[]: mảng số thực
       + int n: số lượng phần tử mảng
       + int loai: 1 nếu selection sort, 2 nếu insertion sort
       + bool tang: true nếu sắp xếp tăng dần, false nếu giảm dần
   Output:
       + double: thời gian thực hiện tính bằng giây
*/
double timeSort(double a[], int n, int loai, bool tang)
{
    double s = clock();
    if(loai == 1)
        selectionSort(a, n, tang);
    else if(loai == 2)
        insertionSort(a, n, tang);
    double e = clock();

    return (double)(e - s)/CLOCKS_PER_SEC;
}

/* Khởi tạo mảng với 100000 phần tử số thực ngẫu nhiên
   Input:
       + double a[]: mảng số thực
       + int& n: số lượng phần tử mảng (truyền tham chiếu)
   Output:
       + Không có
*/
void initDataArr100k(double a[], int& n)
{
    n = 100000;
    for (int i = 0; i < n; i++)
    {
        a[i] = (rand() % 100000) / 1000.0;
    }
}

double a[(int)1e6];

int main()
{
    srand(time(0)); // random khác nhau mỗi lần chạy
    int n = 0;

    initDataArr100k(a, n);

    cout << "Mang ban dau:\n";
    printArr(a, n);

    cout << "Sap xep tang dan bang Selection Sort...\n";
    cout << "Thoi gian: " << timeSort(a, n, 1, true) << " giay\n";
    printArr(a, n);

    initDataArr100k(a, n);

    cout << "Sap xep giam dan bang Selection Sort...\n";
    cout << "Thoi gian: " << timeSort(a, n, 1, false) << " giay\n";
    printArr(a, n);

    initDataArr100k(a, n);

    cout << "Sap xep tang dan bang Insertion Sort...\n";
    cout << "Thoi gian: " << timeSort(a, n, 2, true) << " giay\n";
    printArr(a, n);

    initDataArr100k(a, n);

    cout << "Sap xep giam dan bang Insertion Sort...\n";
    cout << "Thoi gian: " << timeSort(a, n, 2, false) << " giay\n";
    printArr(a, n);

    return 0;
}
