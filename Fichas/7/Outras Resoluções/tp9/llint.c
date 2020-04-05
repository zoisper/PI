#include "llint.h"
#include <stdio.h>
#include <stdlib.h>

void showLInt(LInt l)
{
	while (l)
	{
		printf("%d ",l->valor );
		l = l->prox;
	}
	printf("\n");
}

void showLIntRec(LInt l)
{
	if (l)
	{
		printf ("%d ", l->valor);
		showLIntRec (l->prox);
	}
	else 
		printf("\n");
}

LInt cons (LInt l, int x)
{
		LInt novo = (LInt)malloc(sizeof(Nodo));
		novo -> valor = x;
		novo->prox = l;
		return novo;
}
LInt tail (LInt l)
{
	LInt r = NULL;
	if (l)
	
	{
		r = l->prox;
		free(l);
	}
	return r;
}

LInt init (LInt l)
{
	LInt r = l, ant;
	while (l && l->prox)
	{
		ant = l;
		l = l->prox;
	}
	if (l)
	{
		ant -> prox = NULL;
		free(l);
	}
	return r;

}

LInt snoc (LInt l, int x)
{
	LInt novoNodo = malloc (sizeof(Nodo));
	LInt pt;

	novoNodo->valor = x;
	novoNodo->prox = NULL;

	for(pt = l; pt && pt->prox; pt = pt->prox);
		if (!pt)
			l = novoNodo;
		else 
			pt->prox = novoNodo;
	return l;	
}

LInt concat (LInt a, LInt b)
{
	LInt pt;
	for(pt = a; pt && pt ->prox; pt = pt->prox);
	if (!pt)
		a = b;
	else 
		pt->prox = b;
	return a;

}