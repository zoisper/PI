
#include <stdio.h>
#include <stdlib.h>
#include "llint.h"


int main()
{

	int i;
	LInt lista, aux;
	lista = (LInt) malloc (sizeof (Nodo));
	lista->valor = 15;
	lista->prox = NULL;
	
	aux = (LInt) malloc (sizeof (Nodo));
	aux->valor = 5;
	aux->prox = lista;

	lista = (LInt) malloc (sizeof (Nodo));
	lista->valor = 10;
	lista->prox = aux;
showLInt (lista);
showLIntRec(lista);

for(i=0;i<=10;i++)
	lista = cons(lista,i);
showLInt (lista);

for(i=0;i<=10;i++)
	lista = tail (lista);
showLInt (lista);

for(i=0;i<=5;i++)
	lista = snoc (lista,i);
showLInt (lista);

LInt l1, l2;
for(i=1; i<=10; i++)
	l1 = snoc(l1,i);

for(i=1; i<=10; i++)
	l1 = cons(l1,2*i);
showLInt (l1);
showLInt (l2);


	

	return 0;
}