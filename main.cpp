#include <iostream>
#include "node.h"
#include "RubroNegra.h"
using namespace std;

int main()
{
    RubroNegra* a = new RubroNegra();
    a->inserir(10);
    a->inserir(15);
    a->inserir(22);
    a->inserir(25);
    a->inserir(31);
    a->inserir(44);
    a->inserir(55);
    a->inserir(77);
    a->inserir(81);
    a->inserir(90);
    a->inserir(95);
    a->inserir(101);
    a->inserir(103);
    a->inserir(105);
    a->inserir(152);

    a->simetrica(a->getRoot());
    cout<<endl;
    cout<<a->heightTree(a->getRoot())-1;
    return 0;
}
