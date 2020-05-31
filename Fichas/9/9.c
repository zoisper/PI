#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct dic {
char *pal;
int ocorr;
struct dic *esq, *dir;
} *Dicionario;

typedef struct abin {
int valor;
struct abin *esq,
*dir;
} *ABin;


typedef struct slista {
int valor;
struct slista *prox;
} *LInt;

typedef struct dlista {
int valor;
struct dlista *prox, *ant;
} *DLInt;


void imprimeDic (Dicionario d)   ///////////////// Imprime dicionario
{
	if (d)
	{
		imprimeDic(d->esq);
		printf("%s %d\n", d->pal, d->ocorr );
		imprimeDic(d->dir);
	}
}


void initDic (Dicionario *d)
{
	*d = NULL;
}


int acrescenta (Dicionario *d, char *pal)
{
	int r=1;
	int controlo;

	while (*d && (controlo = strcmp ((*d)->pal, pal)) !=0 )
	{
		if (controlo > 0)
			d = &((*d)->esq);
		else
			d = &((*d)->dir);

	}

	if (*d)
		{
		 (*d)->ocorr ++;
		 r = (*d)->ocorr;
		}
	else
	{
		*d = malloc (sizeof (struct dic ));
		(*d)->pal = pal;
		(*d)->ocorr = 1;
		(*d)->esq = NULL;
		(*d)->dir = NULL;

		
	}
	


	return r;

}

char *maisFreq (Dicionario d, int *c)
{
	*c = 0;
	char * mf = NULL;
	
	if (d)
	{
		int fdir = 0, fesq = 0;
		char * direita = maisFreq (d->dir, &fdir );
		char * esquerda = maisFreq (d->esq, &fesq);	
	

		if (fesq >= fdir && fesq >= d->ocorr )
		{
			*c = fesq;
			mf = esquerda;
		}	

		else
			if (fdir > d->ocorr)
			{
				*c = fdir;
				mf = direita;
			}
			else
			{	
				*c = d->ocorr;
				mf = d->pal;
			}	
	}
	
	return mf;

}
////////////////////////////////////////////////////////////////////////////////


void showL (LInt l) /////// Imprime lista ligada
{
	while (l)
	{
		printf("%d\n", l->valor);
		l = l->prox;
	}
}


LInt fromArray (int *v, int N)  /////////////// Constroi lista apartir de array
{
	LInt r=NULL;
	LInt *ptr = &r;
	int i = 0;
	
	while (i < N)
	{
		*ptr = malloc (sizeof (struct slista));
		(*ptr)->valor = v[i];
		(*ptr)->prox = NULL;
		ptr = &((*ptr)->prox);

		i++;
	}
	return r;

}

/////////////////////////////////////////////////////////////////////////////////



void showABin (ABin a) /////////////////////////// Imprime ABin
{
	if (a)
	{
		showABin (a->esq);
		printf ("%d\n", a->valor);
		showABin (a->dir);
	}
}


ABin fromListAux (LInt l, int N) 
{
	ABin r = NULL;
	LInt meio = l;
	
	if (N>0 && l)
	{
		int i = N/2;
		
		while (i)
		{
			meio = meio->prox;
			i--;
		}

		r = malloc (sizeof (struct abin));
		r-> valor = meio->valor;
		r->esq = fromListAux (l, N/2);
		if (meio)
		r->dir = fromListAux (meio->prox, N - N/2 -1);


	}

	return r;
}


ABin fromList (LInt l)  
{
	
	LInt aux = l;
	int len = 0;
	
	while (aux)
	{
		aux = aux->prox;
		len++;
	}


	ABin r = fromListAux (l, len);

	return r; 
}

LInt inorderL (ABin a)
{
	LInt r = NULL;
	if (a)
	{
		LInt dir = inorderL (a->dir);
		r = malloc (sizeof (struct slista));
		r->valor = a->valor;
		r->prox = dir;
		LInt esq = inorderL (a->esq);

		if (esq)
		{
			LInt aux = esq;
			while (aux->prox)
				aux = aux->prox;
			aux->prox = r;
			r = esq;
		}
		
	}

	return r;
}

LInt inorderLAux (ABin a, LInt *end)
{
	LInt r = NULL;
	LInt new = NULL;
	LInt aux = NULL;

	*end = NULL;
	
	if (a)
	{
		new = malloc (sizeof (struct slista));
		new->valor = a->valor;
		new->prox = inorderLAux (a->dir, end);
		r = inorderLAux (a->esq, &aux);

		if (*end==NULL)
			*end = new;
	
		if (r)
			aux->prox = new;
		else
			r = new;
	}

	return r;




}

LInt inorderL2 (ABin a)
{
	LInt end = NULL;
	LInt r = inorderLAux (a, &end);

	return r;
}

////////////////////////////////////////////////////


void showDL (DLInt dl)  ///////////////////// imprime lista duplamente ligada
{
	while (dl)
	{
		
		printf("%d\n",dl->valor);
		dl = dl->prox;
	}
}

void showDLrec (DLInt dl)   ////////////////// imprime lista duplamente ligada recursivamente
{
	if (dl)
	{
		printf("%d\n", dl->valor );
		showDLrec (dl->prox);
	}
}

void showDLback (DLInt dl)   /////////////////// imprime lista duplamente liga ao contrario
{
	while (dl && dl->prox)
		dl = dl->prox;
	
	while (dl)
	{
		printf("%d\n",dl->valor );
		dl = dl->ant;
	}
}

DLInt inorderDL (ABin a)
{
	DLInt new = NULL;
	DLInt d = NULL;
	DLInt e = NULL;
	DLInt r = NULL;

	if (a)
	{
		d = inorderDL (a->dir);
		e = inorderDL (a->esq);
		
		new = malloc (sizeof (struct dlista));
		new->valor = a->valor;
		new->prox = d;

		if (d)
			d->ant = new;
		
		if (e)
		{
			r=e;
			
			while (e->prox)
				e = e->prox;

			e->prox = new;
			new->ant = e;
			
		}

		else
		{
			new->ant = NULL;
			r=new;

		}


	}

	
	return r;

}

