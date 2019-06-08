#ifndef NODE
#define NODE
using namespace std;
class Node
{
private:
    int valor;
    Node* right;
    Node* left;
    Node* father;
    char color; //r ou b
    Node();
    bool externo;
public:
    Node(int valor);
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
};

#endif // NODE
