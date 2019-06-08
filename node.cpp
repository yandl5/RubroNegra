#include "node.h"
//node externo.
Node::Node()
{
    this->setRight(nullptr);
    this->setLeft(nullptr);
    this->setColor('b');
    this->setExterno(true);
}
//construtor node normal
Node::Node(int valor)
{
    Node* externoUm = new Node();
    externoUm->setFather(this);
    Node* externoDois = new Node();
    externoDois->setFather(this);
    this->valor = valor;
    this->setRight(externoUm);
    this->setLeft(externoDois);
    this->setExterno(false);
    this->setFather(nullptr);
    this->color = 'r';
}
Node* Node::getRight()
{
    return this->right;
}
Node* Node::getLeft()
{
    return this->left;
}
Node* Node::getFather()
{
    return this->father;
}
int Node::getValor()
{
    return this->valor;
}
char Node::getColor()
{
    return this->color;
}
bool Node::getExterno()
{
    return this->externo;
}
void Node::setLeft(Node* node)
{
    this->left = node;
}
void Node::setRight(Node* node)
{
    this->right = node;
}
void Node::setFather(Node* node)
{
    this->father = node;
}
void Node::setValor(int valor)
{
    this->valor = valor;
}
void Node::setColor(char color)
{
    this->color = color;
}
void Node::setExterno(bool externo)
{
    this->externo = externo;
}
Node* Node::grandFather()
{
    if(this->getFather()!=nullptr)
    {
        if(this->getFather()->getFather()!=nullptr)
        {
            return this->getFather()->getFather();
        }
        else
        {
            return nullptr;
        }
    }
}
Node* Node::uncle()
{
    Node* aux = this->grandFather();
    if(aux==nullptr)
    {
        return nullptr;
    }
    if(this->getFather()==aux->getLeft())
    {
        return aux->getRight();
    }
    else
    {
        return aux->getLeft();
    }
}

