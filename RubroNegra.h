#ifndef RUBRONEGRA
#define RUBRONEGRA
#include "node.h"
class RubroNegra
{
private:
    Node* root;
    int quantidadeElementos;
public:
    RubroNegra();

    //gets ands sets
    Node* getRoot();
    int getQuantidadeElementos();
    void setRoot(Node* node);
    void setQuantidadeElementos(int quantidadeElementos);

    //método de busca

    //método de inserção
    void inserir(int valor);
    void rotacaoDireita(Node* node);
    void rotacaoEsquerda(Node* node);
    void metodoValidacao(Node* &inserido);
    //método de remorção

    //método de visita simetrica
    void simetrica(Node* a);
    //altura arvore
    int heightTree(Node* r);
};

#endif // RUBRONEGRA
