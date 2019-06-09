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
        inserido = inserido->getLeft();
    }
    else if((inserido == inserido->getFather()->getLeft())&&(inserido->getFather()==inserido->grandFather()->getRight()))
    {
        this->rotacaoDireita(inserido->getFather());
        inserido = inserido->getRight();
    }
    //agr vamos verificar a necessidade de se fazer uma rotação dupla
    //se chegamos até aqui podemos assumir como necessário esse passo
    inserido->getFather()->setColor('b');
    inserido->grandFather()->setColor('r');
    if((inserido == inserido->getFather()->getLeft())&&(inserido->getFather()==inserido->grandFather()->getLeft()))
    {
        this->rotacaoDireita(inserido->grandFather());
    }
    else
    {
        this->rotacaoEsquerda(inserido->grandFather());
    }
    this->metodoValidacao(inserido->grandFather());
}
//Rotacao direita
void RubroNegra::rotacaoDireita(Node* node)
{

    Node* aux2 = node->getFather();
    Node* aux3 = node->getLeft();
    //setando o pai de node
    if(aux2==nullptr)
    {
        this->setRoot(aux3);
    }
    else if(aux2->getRight()==node)
    {
        aux2->setRight(aux3);
    }
    else
    {
        aux2->setLeft(aux3);
    }
    //setando o pai do node filho
    aux3->setFather(aux2);
    //setar a esquerda do node e o father
    node->setLeft(aux3->getRight());
    node->setFather(aux3);
    //setar a esquerda do node filho
    aux3->setRight(node);
}
//recebendo node pai vamos rotaciona o mesmo a esquerda
void RubroNegra::rotacaoEsquerda(Node* node)
{
    Node* aux2 = node->getFather();
    Node* aux3 = node->getRight();
    //setando o pai de node
    if(aux2==nullptr)
    {
        this->setRoot(aux3);
    }
    else if(aux2->getRight() == node)
    {
        aux2->setRight(aux3);
    }
    else
    {
        aux2->setLeft(aux3);
    }
    //setando pai do node filho
    aux3->setFather(aux2);
    //setar a direita do node e o father
    node->setRight(aux3->getLeft());
    node->setFather(aux3);
    //setar a esquerda do node filho
    aux3->setLeft(node);
}
void RubroNegra::simetrica(Node* a)
{
    if(a->getExterno()!=true)
    {
        cout<<a->getValor()<<" ";
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
