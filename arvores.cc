#include <stdlib.h>
#include <stdio.h>
typedef int Item;
typedef struct arv {
    struct arv *esq;
    Item item;
    struct arv *dir;
} Arv;

Arv* arv(Arv *e, Item x, Arv *d) {
    Arv *n = (Arv *)malloc(1 * sizeof(struct arv));
    n->esq = e;
    n->item = x;
    n->dir = d;
    return n;
};

void arv_imprime (Arv* a)
    {
        printf("%c ", a->item);
        arv_imprime(a->esq);
        arv_imprime(a->dir);
    };


main() {
    arv(NULL, 1, NULL);
    
    Arv *R = arv(arv(arv(NULL,4,NULL),2,arv(NULL,5,NULL)),1,arv(NULL,3,arv(NULL,6,NULL)));

    arv_imprime(R);

};