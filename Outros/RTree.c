#include <stdio.h>
#include <stdlib.h>

typedef struct listaA {
  struct nodo * x;
  struct listaA *prox;
} *ListaArv;


typedef struct nodo {
  int valor;
  ListaArv descendentes;
} *RTree;

int main () {
  
  int arr [5] = {1,3,5,7,2};
  
  RTree t, t2, t3;
  
 
  t2 = malloc (sizeof (struct nodo));
  t2->valor = 5;
  t2->descendentes = NULL; // sem descendentes

  t3 = malloc (sizeof (struct nodo));
  t3->valor = 15;
  t3->descendentes = NULL; // sem descendentes
  
  t = malloc (sizeof (struct nodo));
  t->valor = 10;
  
  t->descendentes = malloc (sizeof (struct listaA));
  t->descendentes->x = t2;
  t->descendentes->prox->x = t3//=NULL;
  
  return 0;
  
}