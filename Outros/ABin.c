#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct abin {
int valor;
struct abin *esq,
*dir;
} *ABin;

ABin fromArray (int v[], int n)  /// cria arvore binaria de array
{

	ABin r = NULL;
	if(n>0)
	{
		r = malloc (sizeof (struct abin));
 		r->valor = v[n/2];
 		r->esq = fromArray (v, n/2);
 		r->dir = fromArray (v+(n/2)+1, n - n/2 -1);
	}

return r;

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


void showPathsAux (ABin a, char *c)
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

void showPaths (ABin a)  //// imprime caminhos de arvore binaria
{
	if (a)
	showPathsAux (a,"");
}


void ABintoDL (ABin *a)   ////converte ABin em lista duplamente ligada sem malloc
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
