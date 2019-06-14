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
    while(aux->getExterno()!= true)
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
void RubroNegra::metodoValidacao(Node* &inserido)
{
    while(inserido->getFather()->getColor()=='r')
    {
        Node* avo = inserido->grandFather();
        Node* tio = inserido->uncle();
        //O tio direito é rubro
        if(inserido->getFather()==avo->getLeft())
        {
            if(tio->getColor()=='r')
            {
                inserido->getFather()->setColor('b');
                tio->setColor('b');
                avo->setColor('r');
                Node* inserido = avo;
            }
            else
            {
                if(inserido==inserido->getFather()->getRight())
                {
                    inserido = inserido->getFather();
                    this->rotacaoEsquerda(inserido);
                }
                inserido->getFather()->setColor('b');
                avo->setColor('r');
                this->rotacaoDireita(inserido->grandFather());
            }
        }
        else
        {
            if(tio->getColor()=='r')
            {
                inserido->getFather()->setColor('b');
                tio->setColor('b');
                avo->setColor('r');
                Node* inserido = avo;
            }
            else
            {
                if(inserido ==inserido->getFather()->getLeft())
                {
                    inserido = inserido->getFather();
                    this->rotacaoDireita(inserido);
                }
                inserido->getFather()->setColor('b');
                avo->setColor('r');
                this->rotacaoEsquerda(inserido->grandFather());
            }
        }
    }
    this->getRoot()->setColor('b');
}
//Rotacao direita
void RubroNegra::rotacaoDireita(Node* node)
{
    Node* aux = node->getLeft();
    node->setLeft(aux->getRight());
    if(aux->getRight()->getExterno()!=true)
    {
        aux->getRight()->setFather(node);
    }
    aux->setFather(node->getFather());
    if(node->getFather()==nullptr)
    {
        this->setRoot(aux);
    }
    else if(node==node->getFather()->getRight())
    {
        node->getFather()->setRight(aux);
    }
    else
    {
        node->getFather()->setLeft(aux);
    }
    aux->setRight(node);
    node->setFather(aux);

}
//recebendo node pai vamos rotaciona o mesmo a esquerda
void RubroNegra::rotacaoEsquerda(Node* node)
{
    Node* aux = node->getRight();
    node->setRight(aux->getLeft());
    if(aux->getLeft()->getExterno()!=true)
    {
        aux->getLeft()->setFather(node);
    }
    aux->setFather(node->getFather());
    if(node->getFather()==nullptr)
    {
        this->setRoot(aux);
    }
    else if(node==node->getFather()->getLeft())
    {
        node->getFather()->setLeft(aux);
    }
    else
    {
        node->getFather()->setRight(aux);
    }
    aux->setLeft(node);
    node->setFather(aux);
}
void RubroNegra::simetrica(Node* a)
{
    if(a->getExterno()!=true)
    {
        cout<<a->getValor()<<" "<<a->getColor()<<"-";
        simetrica(a->getLeft());
        simetrica(a->getRight());
    }
}
int RubroNegra::heightTree(Node* r)
{
    if(r != NULL)
    {
        int heightLeft = heightTree(r->getLeft());
        int heightRight = heightTree(r->getRight());
        if (heightLeft < heightRight)
        {
            return heightRight + 1;
        }
        else
        {
            return heightLeft + 1;
        }
    }
    else
    {
       return 0;
    }
}
