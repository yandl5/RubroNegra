#include <iostream>
#include "node.h"
#include "RubroNegra.h"
using namespace std;

int main()
{
    RubroNegra* a = new RubroNegra();
    a->inserir(10);
    a->inserir(15);
    a->inserir(12);
    a->inserir(25);
    a->inserir(31);
    a->inserir(33);
    a->inserir(41);
    a->inserir(45);
    cout<<a->heightTree(a->getRoot());
    return 0;
}
