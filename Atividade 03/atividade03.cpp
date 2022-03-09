#include <iostream>
#include <stdlib.h>
#include <stack>
using namespace std;

class No{
    public:
        char nome;
        No *left;
        No *right;
        No(char n){
            nome = n;
            left = NULL;
            right = NULL;
        }
};

class Arvore{
    public:
        No *raiz;

    Arvore(){
        raiz = NULL;
    }

    int isEmpty(){
        return(raiz==NULL);
    }


    void cria_No(char nov){
    No *novo=new No(nov);
    raiz=novo;
    }

    void cria_No(char nov, int lado, char pai){
    No *novo=new No(nov);
    insere(raiz,novo,lado,pai);
    }

    void imprime(No* n){
        if(n != NULL) {
            cout<<"<"<<n->nome;
            imprime(n->left);
            imprime(n->right);
            cout<<">";
        }
        else
        cout<<"<>";
    }

    void preOrdem(){
        
        stack<No*> pilha;
        No *p = raiz;
        if (p != 0){
            pilha.push(p);
            while (!pilha.empty()) {
                p=pilha.top();
                cout<<pilha.top()->nome<<endl;
                pilha.pop();
                if (p->left != 0)
                    pilha.push(p->left);
                if (p->right != 0)
                    pilha.push(p->right);
            }
        }
    };

    void posOrdem(){
        stack<No*> pilha;
        No *p = raiz;
        if (p != 0){
            if (p->left != 0)
                pilha.push(p->left);
            if (p->right != 0)
                pilha.push(p->right);
            pilha.push(p);
            while (!pilha.empty()) {
                p=pilha.top();
                cout<<pilha.top()->nome<<endl;
                pilha.pop();
        }   
        }
    }

    void inOrdem(){
        stack<No*> pilha;
        No *p = raiz;
        if(p != 0){
            if (p->left != 0)
                pilha.push(p->left);
            pilha.push(p);
            while (!pilha.empty()) {
                p=pilha.top();
                cout<<pilha.top()->nome<<endl;
                pilha.pop();
            }
            if (p->right != 0)
                pilha.push(p->right);
        }
    }


    void insere(No *arv, No *novo, int lado, char pai){
    if (arv!=NULL){
        if(arv->nome==pai){
            if(lado==1)
                if(arv->left==NULL)
                arv->left = novo;
            else
                cout<<"\n ERRO - ja existe um no nessa posicao!\n";
            if (lado==2)
                if(arv->right==NULL)
                    arv->right = novo;
            else
                cout<<"\n ERRO - ja existe um no nessa posicao!\n";
        }else{
            insere(arv->right,novo,lado,pai);
            insere(arv->left,novo,lado,pai);
        }
    }
}
};


main(){
    Arvore *arv = new Arvore();
    arv->cria_No('A');
    arv->cria_No('B',1,'A');
    arv->cria_No('D',2,'B');
    arv->cria_No('T',2,'B');
    arv->cria_No('C',2,'A');
    //arv->preOrdem();
    //arv->posOrdem();
    //arv->inOrdem();
    //arv->imprime(arv->raiz);
}

/*
Questão 02
Apos checar as duas formas de execução do algoritmo, é possivel perceber
que a versão que utiliza a pilha, parece sem mais rapida. Então sim, existe
melhoria na eficiencia do algoritmo.
*/