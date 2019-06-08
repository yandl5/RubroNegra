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
//M�todo de inser��o
void RubroNegra::inserir(int valor)
{
    Node* inserir = new Node(valor);
    //inser��o na raiz da �rvore
    if(this->quantidadeElementos==0)
    {
        this->root = inserir;
        inserir->setColor('b');
        this->quantidadeElementos++;
        return;
    }
    //� feita a busca para se inserir na posi��o correta da �rvore
    //Criamos um n� auxiliar e percorremos a �rvore
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
        //valor j� existe na �rvore
        else
        {
            cout<<"O valor j� existe na �rvore"<<endl;
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
        //aumentar quantidade de elementos da �rvore
        this->quantidadeElementos++;
    }
    //aux � esquerda
    else
    {
         //setar node pai do inserir
        inserir->setFather(aux->getFather());
        //setar o pai para receber o node inserir
        aux->getFather()->setLeft(inserir);
        //aumentar quantidade de elementos da �rvore
        this->quantidadeElementos++;
    }
    //chamaremos o metodo de validacao para testar se essa insercao eh valida
    this->metodoValidacao(inserir);
}
void RubroNegra::metodoValidacao(Node* inserido)
{
    //agora � importante testarmos se a �rvore ficou balanceada de fato
    //j� que o novo node � rubro, o pai deve ser negro, iremos testar
    if(inserido->getFather()->getColor()=='b')
    {
        return;
    }
    //agora verificamos se o o tio e o pai tem cor rubra, caso verdade, basta alterarmos
    //a cor dos dois para preto e a cor do av� para rubro
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
    //Caso n�o seja poss�vel nenhuma das op��es acima, se faz necess�rio o uso de rota��es
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
