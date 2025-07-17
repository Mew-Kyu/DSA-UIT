#include <iostream>
#include <time.h>
using namespace std;

void printArr(int a[], int n)
{
    for(int i = 0; i < n; i++)
    {
        cout << a[i] << "\t";
    }
    cout << endl << endl;
}

void selectionSort(int a[], int n)
{
    int m;
    for(int i = 0; i < n - 1; i++)
    {
        m  = i;
        for(int j = i + 1; j < n; j++)
        {
            if(a[j] < a[m])
                m = j;
        }
        if(m != i)
            swap(a[m], a[i]);
    }
}

void insertionSort(int a[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int item = a[i];
        int j;
        for (j = i-1; j >= 0; j--)
        {
            if (a[j] < item)
                break;

            a[j+1] = a[j];
        }
        a[j+1] = item;
    }
}

double timeSort(int a[], int n, int loai)
{
    if(loai == 1)
    {
        double s = clock();
        selectionSort(a, n);
        double e = clock();

        return (double)(e - s)/CLOCKS_PER_SEC;
    }
    else if(loai == 2)
    {
        double s = clock();
        insertionSort(a, n);
        double e = clock();

        return (double)(e - s)/CLOCKS_PER_SEC;
    }
}

int main()
{
    int a[100] = {12, 90, 50, 28, 45, 68};
    int n = 6;

    printArr(a, n);

    //selectionSort(a, n);
    //insertionSort(a, n);

    cout << "Time: " << timeSort(a, n, 1) << endl;

    printArr(a, n);
    return 0;
}
