#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct slist *LInt;

typedef struct slist {
    int valor;
    //typedef struct *prox;
    LInt prox;
} Nodo;


LInt p1a() {
    Nodo *n1 = (Nodo *)malloc(sizeof(Nodo));
    n1->valor = 10;
    Nodo *n2 = (Nodo *)malloc(sizeof(Nodo));
    n2->valor = 5;
    Nodo *n3 = (Nodo *)malloc(sizeof(Nodo));
    n3->valor = 15;

    n1->prox = n2;
    n2->prox = n3;
    n3->prox = NULL;

    return n1;
}

LInt cons (LInt l, int x) {
    //LInt l2 = l;
    Nodo *n = (Nodo *)malloc(sizeof(Nodo));
    n->valor = x;
    n->prox = l;

    /*
    if (!l2) { // if (l2 == NULL)
        l = n;
    }
    else {
        n->prox = l2;
        l = n;
    }
    */
    

    return n;
}


LInt tail(LInt a) {
    LInt a1 = a->prox;
    free(a);
    return a1;
}


LInt init(LInt a) {
    LInt a2 = a, ant = NULL;
    while(a->prox) {
        ant = a;
        a = a->prox;
    }
    free(a);
    if (ant) {
        ant->prox = NULL;
    }
    else {
        a2 = NULL;
    }

    return a2;
}

LInt concat(LInt a, LInt b) {
    LInt a2 = a;

    while(a->prox) {
        a = a->prox;
    }
    a->prox = b;

    return a2;
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
    printl(a);
    //printl(a);

    LInt b = NULL;
    b = cons(b, 1);
    //printl(b);
    b = cons(b, 2);
    b = cons(b, 3);
    printl(b);
    
    //b = init(b);
    //printl(b);
    //b = init(b);
    a = concat(a, b);
    printl(a);


    return 1;
}





