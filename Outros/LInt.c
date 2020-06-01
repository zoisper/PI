#include <stdio.h>
#include <stdlib.h>

typedef struct nodo {
    int valor;
    struct nodo * prox;
} Nodo, *LInt;

LInt cons (int x, LInt xs){
    LInt r = malloc (sizeof (Nodo));
    r->valor = x; r->prox = xs;

    return r;
}

LInt fromArray (int v[], int N) {
    int i; LInt r = NULL;

    for (i=N-1; i>=0; i--)
        r = cons (v[i], r);
    return r;
}



LInt mergeL (LInt a, LInt b) {
     LInt r,      // lista resultado
          * sitio; 
     
     sitio = & r ; // primeira a ser alterada
     
     
     while (a != NULL && b != NULL) {
        if (a->valor <= b->valor) {
          // acrescentar a a r
          (*sitio)  = a;
          // avancar a e r
          a = a->prox; 
        }
        else {
          // acrescentar b a r
          *sitio = b;
          // avancar b e r
          b=b->prox; 
        }
        sitio = &((*sitio)->prox);
     }
     
     if (a == NULL) 
          *sitio=b;
     else *sitio=a;
     
     
     return r;
}

int length (LInt l){
    // calcula o comprimento da lista 
    int r = 0;
    while (l!=NULL) {
      r++; l=l->prox;
    }
    return r;
}

LInt splitAt (LInt l, int n) {
   // deixa n elementos em l e retorna o resto da lista
   LInt r;
   while (n>1 && l != NULL) {
     n--; l=l->prox;
   }
   
   r       = l->prox;
   l->prox = NULL;
   return r;
}


LInt mergeSortAux (LInt l, int cl) {
  LInt lAux;
  if (l!=NULL && l->prox != NULL) {
    lAux = splitAt (l, cl/2);
    l    = mergeSortAux (l, cl/2);
    lAux = mergeSortAux (lAux, cl - (cl/2));
    
    l = mergeL (l, lAux);
  }
  return l;
}

LInt mergeSort (LInt l) {
  return (mergeSortAux (l, length (l)));
}

int main () {

    int a[10] = {10, 2, 130, -40, 55, 5, 15, 17, 23, 25};

    LInt l1 = fromArray (a,5);

    l1 = mergeSort (l1);

    return 0;
}
