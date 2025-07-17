#include <iostream>
#include <time.h>
using namespace std;

void printArr(double a[], int n)
{
    for(int i = 0; i < n*0.1; i++)
    {
        cout << a[i] << "\n";
    }
    cout << endl << endl;
}

void selectionSort(double a[], int n)
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

void insertionSort(double a[], int n)
{
    for (int i = 1; i < n; i++)
    {
        double item = a[i];
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

double timeSort(double a[], int n, int loai)
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

void initDataArr100k(double a[], int& n)
{
    n = 100000;
    for (int i = 1; i < n; i++)
    {
        a[i] = rand() + (rand()%1001)/1000.0;
    }
}

double a[(int)1e6];
int main()
{
    int n = 0;

    initDataArr100k(a, n);

    //printArr(a, n);

    //selectionSort(a, n);
    //insertionSort(a, n);

    cout << "Time: " << timeSort(a, n, 1) << endl;
    //printArr(a, n);

    return 0;
}
