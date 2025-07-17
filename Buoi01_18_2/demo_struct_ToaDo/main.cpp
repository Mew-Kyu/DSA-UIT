#include <iostream>

using namespace std;

struct ToaDo
{
    float x;
    float y;
};

void inToaDo(ToaDo a)
{
    cout << "{" << a.x << ";" << a.y << "}" << endl;
}

int main()
{
    int x = 8;
    cout << x << endl;

    ToaDo a = {1, 2};
    //cout << a << endl;
    inToaDo(a);

    ToaDo* p = new ToaDo;

    // Cach 1:
    //p->x = 3;
    //p->y = 4;

    // Cach 2:
    //*p = {3, 4};

    // Cach 3:
    (*p).x = 3;
    (*p).y = 4;

    inToaDo(*p);

    return 0;
}
