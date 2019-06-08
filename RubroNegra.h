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
    void rotacaoDuplaD(Node* node);
    void rotacaoDuplaE(Node* node);
    void metodoValidacao(Node* inserido);
    //método de remorção

};

#endif // RUBRONEGRA
