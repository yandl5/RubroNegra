#include "RubroNegra.h"
RubroNegra::RubroNegra()
{
    this->setRoot(nullptr);
    this->setQuantidadeElementos(0);
}
Node* RubroNegra::getRoot()
{
    return this->root;
}
int RubroNegra::getQuantidadeElementos()
{
    return this->quantidadeElementos;
}
void RubroNegra::setRoot(Node* node)
{
    this->root = node;
}
void RubroNegra::setQuantidadeElementos(int quantidadeElementos)
{
    this->quantidadeElementos = quantidadeElementos;
}
//Método de inserção
void RubroNegra::inserir(int valor)
{
    Node* inserir = new Node(valor);
    //inserção na raiz da árvore
    if(this->quantidadeElementos==0)
    {
        this->root = inserir;
        inserir->setColor('b');
        this->quantidadeElementos++;
        return;
    }
    //é feita a busca para se inserir na posição correta da árvore
    //Criamos um nó auxiliar e percorremos a árvore
    Node* aux = this->root;
    while(aux->getExterno()!=true)
    {
        //indo esquerda
        if(valor<aux->getValor())
        {
            aux = aux->getLeft();
        }
        //indo direita
        else if(valor>aux->getValor())
        {
            aux = aux->getRight();
        }
        //valor já existe na árvore
        else
        {
            cout<<"O valor já existe na árvore"<<endl;
            return;
        }
    }
    //Vamos verificar se aux esta a direita ou esquerda do node father e inserir o mesmo
    if(aux->getFather()->getRight()==aux)
    {
        //setar node pai do inserir
        inserir->setFather(aux->getFather());
        //setar o pai para receber o node inserir
        aux->getFather()->setRight(inserir);
        //aumentar quantidade de elementos da árvore
        this->quantidadeElementos++;
    }
    //aux à esquerda
    else
    {
         //setar node pai do inserir
        inserir->setFather(aux->getFather());
        //setar o pai para receber o node inserir
        aux->getFather()->setLeft(inserir);
        //aumentar quantidade de elementos da árvore
        this->quantidadeElementos++;
    }
    return;
}

