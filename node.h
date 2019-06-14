#ifndef NODE
#define NODE
#include <iostream>
using namespace std;
class Node
{
private:
    int valor;
    Node* right;
    Node* left;
    Node* father;
    char color; //r ou b
    //construtor de nodes externos
    Node();
    bool externo;
public:
    //construtor padr�o
    Node(int valor);
    //metodos gets and seters
    int getValor();
    Node* getRight();
    Node* getLeft();
    Node* getFather();
    char getColor();
    bool getExterno();
    void setValor(int valor);
    void setRight(Node* node);
    void setLeft(Node* node);
    void setFather(Node* node);
    void setColor(char color);
    void setExterno(bool externo);

    //Fun��es av� e tio do node em quest�o
    Node* grandFather();
    Node* uncle();
    //sobrecarga do igual '='
    Node& operator=(Node const &t);
};

#endif // NODE
