#include <iostream>

using namespace std;

int main()
{
    int x;
    int y;

    cout << x << y << endl;

    int* p1 = NULL;

    cout << p1 << endl;

    p1 = &y;

    return 0;
}
