#include <iostream>

using namespace std;

int main()
{
    int x = 10;

    int* p = &x;

    *p = 30;

    cout << x << endl;
    cout << *p << endl;

    return 0;
}
