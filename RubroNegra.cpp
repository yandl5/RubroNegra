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
    //chamaremos o metodo de validacao para testar se essa insercao eh valida
    this->metodoValidacao(inserir);
}
void RubroNegra::metodoValidacao(Node* inserido)
{
    //agora é importante testarmos se a árvore ficou balanceada de fato
    //já que o novo node é rubro, o pai deve ser negro, iremos testar
    if(inserido->getFather()->getColor()=='b')
    {
        return;
    }
    //agora verificamos se o o tio e o pai tem cor rubra, caso verdade, basta alterarmos
    //a cor dos dois para preto e a cor do avô para rubro
    else if(inserido->uncle()!=nullptr && inserido->uncle()->getColor()=='r')
    {
        inserido->getFather()->setColor('b');
        inserido->uncle()->setColor('b');
        if(inserido->grandFather()==this->root)
        {
            inserido->grandFather()->setColor('b');
        }
        else
        {
            inserido->grandFather()->setColor('r');
        }
        return;
    }
    //Caso não seja possível nenhuma das opções acima, se faz necessário o uso de rotações
    //nos casos seguintes
    if((inserido == inserido->getFather()->getRight())&&(inserido->getFather()==inserido->grandFather()->getLeft()))
    {
        this->rotacaoEsquerda(inserido->getFather());

    }


}
void RubroNegra::rotacaoDireita(Node* node)
{

}
void RubroNegra::rotacaoEsquerda(Node* node)
{

}
void RubroNegra::rotacaoDuplaD(Node* node)
{

}
void RubroNegra::rotacaoDuplaE(Node* node)
{

}
