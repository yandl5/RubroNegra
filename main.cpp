#include <iostream>
#include "node.h"
using namespace std;

int main()
{
    Node* a = new Node(15);
    if(a->getLeft()->getExterno()==false)
    {
        cout<<"eh externo jao";
    }
    return 0;
}
