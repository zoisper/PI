#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct abin {
int valor;
struct abin *esq,
*dir;
} *ABin;


ABin fromArray (int v[], int N)  //////////////////////// constroi abin de array
{
	ABin esq = NULL;
	ABin dir = NULL;
	ABin r = NULL;
	
	if (N>0)
	{

		esq = fromArray (v, N/2 );
		r = malloc (sizeof (struct abin));
		r->valor = v[N/2];
		dir = fromArray (v + N/2 +1 , N  - 1 - N/2);

		r->esq = esq;
		r->dir = dir;

	}

	return r;
}

void ABintoDL (ABin *a)   /////////////////////////////////// converte ABin em lista duplamente ligada sem malloc
{

	if (*a)
	{
		ABintoDL (&((*a)->esq));
		ABintoDL (&((*a)->dir));

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





void showABin (ABin a)  /////////////////////// imprime ABin
{
	if (a)
	{
		showABin (a->esq);
		printf("%d\n",a->valor );
		showABin (a->dir);

	}
}

void showABinDL (ABin a)  //////////  imprime ABin convertida em DLint sem malloc
{
	while (a)
	{
		printf("%d\n", a->valor);
		a = a->dir;
	}
}

void showABinDLBack (ABin a)  /////////////  imprime ABin convertida em DLInt sem malloc ao contrario
{
	while (a && a->dir)
		a = a->dir;
	while (a)
	{
		printf("%d\n", a->valor );
		a = a->esq;
	}
}


