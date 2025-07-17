#include <iostream>
using namespace std;


struct Node
{
    Node* pNext;
    float data;
};

int main() {
    Node* p = new Node({NULL, 1.5});
    p->pNext = new Node({NULL, 30.4});
    p->data += p->pNext->data;
    cout << (*p->pNext).data;
    return 0;
}
