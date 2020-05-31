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


void imprimeDic (Dicionario d)
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



LInt inorderLAux (ABin a, LInt *end){
    
    LInt res, aux, novo;
    
    if (a == NULL) { // caso de paragem
       res = NULL;
       *end = NULL;
    }
    else {
       novo = malloc (sizeof (struct slista));
       novo->valor = a->valor;
       novo->prox = inorderLAux(a->dir, end);
    
    res = inorderLAux (a->esq, &aux);

    if (res==NULL)
    	res = novo;
   	
   	else
   		aux->prox = novo;
   	
   	if (*end == NULL)
   		*end = novo;


          }
    return res;
}

LInt parteAmeio (LInt l, LInt *dest )
{
	int len = 0;
	//LInt r = l;
	LInt aux = l;
	LInt ant = NULL;

	while (aux)
	{
		aux = aux->prox;
		len++;
	}
	
	aux = l;
	len /= 2;

	while (len > 0)
		{
			ant = aux;
			aux = aux->prox;
			len--;
		}

	*dest = aux;
	
	if (ant) 
    	ant->prox = NULL;
    
    else 
    	l = NULL;
 

	return l;

}




ABin fromList (LInt l)
{
	ABin r = NULL;
	LInt ini = NULL;
	LInt fim = NULL;

	if (l)
	{
		ini = parteAmeio (l, & fim);
		r = malloc (sizeof (struct abin));
		r->valor = fim->valor;
		r->esq = fromList (ini);
		r->dir = fromList (fim->prox);

	}

	return r;
}

LInt fromArray (int *v, int N)
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


void showL (LInt l)
{
	while (l)
	{
		printf("%d\n", l->valor);
		l = l->prox;
	}
}

void showABin (ABin a)
{
	if (a)
	{
		showABin (a->esq);
		printf ("%d\n", a->valor);
		showABin (a->dir);
	}
}



int main ()
{
	
	int c=0;
	char * mf = NULL;
	
	Dicionario d; 
	initDic(&d);
	acrescenta (&d, "Ola");
	acrescenta(&d, "Mundo");
	acrescenta(&d, "Mundo");
	acrescenta (&d, "Ola");
	acrescenta (&d, "Ola");

	//imprimeDic (d);

	mf = maisFreq (d, &c);
	//printf("%s %d\n",mf, c );

	int v[5] = {1,2,3,4,5};
	LInt l = fromArray(v,5);
	showL (l);
	putchar ('\n');
	
	ABin a = fromList(l);

	showABin(a);



	//LInt aux = parteAmeio (&l);
	//showL(aux);
	//putchar ('\n');
	//showL(l);

	 

	return 0;
}