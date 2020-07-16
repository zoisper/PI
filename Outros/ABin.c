#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct abin {
int valor;
struct abin *esq,
*dir;
} *ABin;

ABin ABinFromArray (int v[], int N)  // cria arvore binaria apartir de array
{

	ABin r = NULL;
	if(N>0)
	{
		r = malloc (sizeof (struct abin));
 		r->valor = v[N/2];
 		r->esq = ABinFromArray (v, N/2);
 		r->dir = ABinFromArray (v+ N/2 +1, N - N/2 - 1);
	}
return r;
}

void showABin (ABin a)  // imprime ABin
{
	if (a)
	{
		showABin (a->esq);
		printf("%d\n",a->valor );
		showABin (a->dir);
	}
}


void showPathsAux (ABin a, char *c) // função auxiliar para imprimir caminhos de arvore binaria
{
	if(a)
	{
		printf("%s%d\n",c, a->valor );
		int len = strlen (c);
		char e[len+1] , d[len+1];
		strcpy (e, c);
		strcpy (d, c);
		strcat (e, "<");
		strcat (d, ">");
		showPathsAux (a->esq, e);
		showPathsAux (a->dir, d);
	}
} 

void showPaths (ABin a)  // imprime caminhos de arvore binaria
{
	if (a)
	showPathsAux (a,"");
}


void DLFromAbin (ABin *a)   // converte ABin em lista duplamente ligada sem malloc
{

	if (*a)
	{
		DLFromAbin (&((*a)->esq));
		DLFromAbin (&((*a)->dir));
		if ((*a)->dir)
			(*a)->dir->esq = (*a);
		if ((*a)->esq)
		{
			ABin aux = ((*a)->esq);
			ABin r = ((*a)->esq);	
			while (aux->dir)
				aux = aux->dir;	
			aux->dir = (*a);
			(*a)->esq = aux;
			while (r->esq)
				r = r->esq;
			(*a) = r;
		}	
	}
}

int lenDL (ABin a) // calcula comprimento de lista duplamente ligada
{
    int r = 0;
    while (a)
    {
        r++;
        a = a->dir;
    }
    return r;
}

void ABinFromDL (ABin *a) // converte lista duplamente ligada em ABin sem malloc
{
    ABin raiz = *a, e = NULL;
    if (*a)
    {
        int len = lenDL (*a);
        len /= 2;
        while (len > 0)
        {
            raiz = raiz->dir;
            len--;
        }
        *a = raiz;
        e = (*a)->esq;
        if (e)
        {
            e->dir = NULL;
            while (e->esq)
                e = e->esq;
            (*a)->esq = e;
        }
        if ((*a)->dir)
            (*a)->dir->esq = NULL;
        
        ABinFromDL(&((*a)->esq));
        ABinFromDL(&((*a)->dir));
    }
}

void showDL (ABin a)  // imprime ABin convertida em lista duplamente ligada
{
	while (a)
	{
		printf("%d ", a->valor);
		a = a->dir;
	}
}

void showDLBack (ABin a)  // imprime ABin convertida em em lista duplamente ligada ao contrario (para testar se a conversão foi bem sucedida)
{
	while (a && a->dir)
		a = a->dir;
	while (a)
	{
		printf("%d ", a->valor );
		a = a->esq;
	}
}
