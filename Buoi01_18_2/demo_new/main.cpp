#include <iostream>

using namespace std;

int main()
{
    int* p = new int;

    *p = 10;

    cout << "1. Dia chi " << p << endl;
    cout << "1. Dia chi " << *p << endl;

    delete p;
    p = NULL

    cout << "2. Dia chi " << p << endl;
    //cout << "2. Dia chi " << *p << endl;

    return 0;
}
