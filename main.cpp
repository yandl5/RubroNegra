#include <iostream>
#include "node.h"
#include "RubroNegra.h"
using namespace std;

int main()
{
    RubroNegra* a = new RubroNegra();
    a->inserir(5);
    a->inserir(12);
    a->inserir(3);
    cout<<a->getRoot()->getValor()<<" "<<a->getRoot()->getLeft()->getValor()<<" "<<a->getRoot()->getRight()->getValor()<<endl;
    return 0;
}
