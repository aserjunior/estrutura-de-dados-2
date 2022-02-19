#include <iostream>
using namespace std;

struct noDaArvore{
    int valor;
    struct noDaArvore* esquerda;
    struct noDaArvore* direita;
};

typedef struct noDaArvore no;

no* inserirNo(int valor, no* esq, no* dir);
void imprimirPreOrdem(no* n);
void imprimirEmOrdem(no* n);
void imprimirPosOrdem(no* n);


no* inserirNo(int valor, no* esq, no* dir){
    no* n = (no*) malloc(sizeof(no));

    if (n==NULL){
        exit(1);
    }else{

        n->valor = valor;
        n->esquerda = esq;
        n->direita = dir;
    }



    return n;
}



void imprimirPreOrdem(no* n){

    if(n != NULL){
        cout<<"<"<<n->valor;
        imprimirPreOrdem(n->esquerda);
        imprimirPreOrdem(n->direita);
        cout<<">";
    }
    else
    cout<<"<>";
}

void imprimirEmOrdem(no* n){

    if(n != NULL){
        imprimirEmOrdem(n->esquerda);
        cout<<"<"<<n->valor;
        imprimirEmOrdem(n->direita);
        cout<<">";
    }
    else
    cout<<"<>";
}

void imprimirPosOrdem(no* n){

    if(n != NULL){
        imprimirPosOrdem(n->esquerda);
        imprimirPosOrdem(n->direita);
        cout<<"<"<<n->valor;
        cout<<">";
    }
    else
    cout<<"<>";
}

main(){

    no* n = inserirNo(15, inserirNo(10,NULL,NULL), inserirNo(50, inserirNo(20,NULL,NULL), NULL));

    //imprimirPreOrdem(n);
    //imprimirEmOrdem(n);
    imprimirPosOrdem(n);
}
