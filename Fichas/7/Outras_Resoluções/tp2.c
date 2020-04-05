#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Nodo == struct slist
// LInt == struct slist* = Nodo*
typedef struct slist *LInt;

typedef struct slist {
    int valor;
    //typedef struct *prox;
    LInt prox;
} Nodo;

LInt p1a() {
    LInt a = NULL;

    Nodo * n1 = (Nodo *)malloc(sizeof(Nodo));
    n1->valor = 10;
    Nodo * n2 = (Nodo *)malloc(sizeof(Nodo));
    n2->valor = 5;
    Nodo * n3 = (Nodo *)malloc(sizeof(Nodo));
    n3->valor = 15;

    n1->prox = n2;
    n2->prox = n3;
    n3->prox = NULL;

    a = n1;

    // return n1;
    return a;
}

LInt cons (LInt l, int x){
    Nodo *n = (Nodo *)malloc(sizeof(Nodo));
    n->valor = x;
    n->prox = l;

    return n;
}

LInt tail (LInt l) {
    LInt r = l->prox;
    free(l);
    return r;
}

LInt concat (LInt a, LInt b) {
    LInt r = a;
    while ( a -> prox != NULL ) {
        a = a -> prox ;
    }
    a -> prox = b ;
    //printf("a valor %d\n", a->valor);

    return r ;
}


LInt init(LInt l) {
    LInt r = l, ant = NULL;
    while(l->prox) {
        ant = l;
        l = l->prox;
    }
    if (ant == NULL) {
        free(l);
        r = NULL;
    }
    else {
        ant->prox = NULL;
        free(l);
    }
    return r;
}

void printl2(LInt a) {
    while(a != NULL) { //while(a)
        printf("%d, ", a->valor);
        a = a->prox;
    }
    printf("\n");
}


void printl(LInt b) {
    LInt a = b;
    while (a != NULL) {
        printf("v: %d -> ", a->valor);
        a = a->prox;
    }
    printf("\n");
}



int main(){
    LInt a = p1a();
    printl2(a);
    //printl2(a);

    LInt b = NULL;
    b = cons(b, 1);
    b = cons(b, 2);
    printl2(b);

    a = concat(a,b);
    printl2(a);

/*
    a = cons(a, 25);
    printl2(a);
    a = cons(a, 35);
    printl2(a);

    LInt b = NULL;
    b = cons(b, 1);
    printl2(b);
    b = cons(b, 2);
    printl2(b);




    b = init(b);
    printl2(b);
    b = init(b);
    printl2(b);
*/
    return 1;
}





