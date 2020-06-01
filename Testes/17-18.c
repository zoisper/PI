#include <stdio.h>
#include <stdlib.h>

typedef struct slist {
int valor;
struct slist *prox;
} *LInt;

typedef struct nodo {
int valor;
struct nodo *esq, *dir;
} *ABin;


// Parte A


/*1. Defina uma função int retiraNeg (int v[], int N) que retira os números negativos de
um vector com N inteiros. A função deve retornar o número de elementos que não foram
retirados.*/

int retiraNeg (int v[], int N)
{

	for(int i=0; i<N; i++)
		if (v[i]<0)
		{
			
			for(int j=i; j<N-1; j++)
				v[j] = v[j+1]; 
			
			N--;
			i--;
		}

	return N;
}

/*2. Defina uma função int difConsecutivos (char s[]) que, dada uma string s calcula o
comprimento da maior sub-string com caracteres diferentes. Por exemplo, difConsecutivos
("aabcccaac") deve dar como resultado 3, correspondendo à string "abc".*/

int isDif (char s[], int N)  ////// função auxilar
{
	int r = 1;

	for (int i=0; i<N ; i++)
		if (s[i] == s[N])
			r = 0;

	return r;

}

int difConsecutivos (char s[])
{
	int i=0, j=0, r=0;

	for (i=0; s[i]; i++)
		{
			for (j=0; isDif (s+i, j) && s[i+j]; j++);

			if (j> r)
					r = j;
		}
	return r;
}




void showL (LInt l)  //////// imprime lista ligada
{
	while (l)
	{
		printf("%d\n", l->valor);
		l = l->prox;
	}
}

/*3. Defina uma função int maximo (LInt l) que calcula qual o maior valor armazenado numa
lista não vazia.*/

int maximo (LInt l)
{
	int r = l->valor;

	while (l)
	{
		if (l->valor > r)
			r = l->valor;
		l = l->prox;
	}

	return r;
}

/*4. Apresente uma definição não recursiva da função int removeAll (LInt *, int) que remove
todas as ocorrências de um dado inteiro de uma lista, retornando o número de células removi-
das.*/

int removeAll (LInt *l, int x)
{
	int r = 0;
	while (*l)
	{
		if ((*l)->valor == x)
			{
				(*l) = (*l)->prox;
				r++;
			}
		else
			l = &((*l)->prox);	
	}
	return r;
}

/*5. Defina uma função LInt arrayToList (int v[], int N) que constrói uma lista com os
elementos de um array, pela mesma ordem em que aparecem no array.*/

LInt arrayToList (int v[], int N)
{
	LInt r = NULL;
	LInt *ptr = &r;
	int i = 0;
	while (i<N)
	{
		(*ptr) = malloc (sizeof (struct slist));
		(*ptr)->valor = v[i];
		(*ptr)->prox = NULL;
		ptr = &((*ptr)->prox);
		i++;
	}
	return r;

}

// Parte B

void showABin (ABin a)
{
	if (a)
	{
		printf("%d\n",a->valor );
		showABin (a->esq);
		showABin (a->dir);
	}
}

ABin arrayToABin (int v[], int N)  ////////////// constroi ABin de array começando no elemento do meio
{
	ABin r = NULL;

	if (N>0)
	{
		r = malloc (sizeof (struct nodo));
		r->valor = v[N/2];
		r->esq = arrayToABin (v, N/2);
		r->dir = arrayToABin (v + 1 + N/2 , N - 1 - N/2 );
	}



	return r;
}

ABin arrayToABinOrd (int v[], int N)  ////////////// constroi ABin de array começando no primeiro elemento
{
	ABin r = NULL;

	if (N>0)
	{
		r=malloc (sizeof (struct nodo));
		r->valor = v[0];
		r->esq = arrayToABinOrd (v+1, N/2);
		r->dir = arrayToABinOrd (v+ N/2 + 1, N - 1 - N/2);
	}

	return r;
}

/*1. Defina uma função int minheapOK (ABin a) que testa se uma árvore binária é uma min-
heap.*/

int minheapOK (ABin a)
{
	int r = 1;
	if (a)
	{
		ABin esq = a->esq;
		ABin dir = a->dir;

		if (esq && dir && a->valor  < dir->valor  && a->valor < esq->valor )
			r = (minheapOK (esq) && minheapOK (dir));
		else
			if (!esq && dir && a->valor < dir->valor)
				r = minheapOK (dir);
			else
				if (!dir && esq && a->valor < esq->valor)
					r = minheapOK (esq);
			else
				if (esq || dir )
					r = 0;
	}


	return r;
}



int main ()
{
	int v[8] = {1,2,0,4,6,9,7,8};

	ABin a = arrayToABinOrd (v, 3);
	showABin (a);
	putchar ('\n');

	int r = minheapOK (a);
	printf("%d\n",r );



	return 0;
}