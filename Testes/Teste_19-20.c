#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*1 Defina uma função:

int verifica(int s[], int N)
que verifica se os números armazenados num array s são os primeiros N números de uma progressão
geométrica (exponencial), ou seja, existem números inteiros a e b (positivo) tal que
s[i] == a * b^i para todo o 0 <= i < N.

Por exemplo, 

verifica ({2,6,18,54}, 4) deve retornar 1 (True) (a=2, b=3), enquanto que 

verifica ({1,4,8,13,19}, 5) deve retornar 0 (False).*/

int verifica(int s[], int N)
{
	int r = 1;
	if (N>1)
	{
		int controlo = s[1]/s[0];
		for (int i=1; i<N; i++)
			if (s[i]/s[i-1] != controlo)
				r=0;
	}
	
	return r;
}


/*2 Considere o tipo LInt para representar listas de inteiros.*/

typedef struct slist{
	int valor;
	struct slist *prox;
} *LInt;

/*Defina uma função:

void gera(LInt *l, int N)
que cria uma lista com os primeiros N factoriais (1,1,2,6,24,...) */

int fact (int n)
{
	if (n<=1) 
		return 1;
	else
		return n * fact(n-1);
}

void gera(LInt *l, int N)
{
	int i = 1;
	*l = NULL;
	while (i<=N)
	{
		(*l) = malloc (sizeof(struct slist));
		(*l)->valor = fact(i);
		(*l)->prox = NULL;
		l = &((*l)->prox); 
		i++;
	}
}

void showLInt (LInt a)
{
	while (a)
	{
		printf("%d\n", a->valor);
		a = a->prox;
	}
}





/*3 Considere o tipo LInt para representar listas de inteiros.


Defina uma função:

int tamanho(LInt l)
que calcula o tamanho de uma lista ligada circular
(i.e., uma lista em que o campo prox do último elemento tem o valor do endereço do primeiro).*/

int tamanho(LInt l) 
{
	int r = 0;
	if (l)
	{
		r++;
		int controlo = l->valor;
		l = l->prox;
		
		while (l && l->valor != controlo)
		{
			l = l->prox;
			r++;
		}
	}


	return r;

}

LInt fromArray (int v[], int N) //// controi lista ligada de array
{
	int i = 0;
	LInt r = NULL;
	LInt *ptr = & r;
	while (i<N)
	{
		*ptr = malloc (sizeof (struct slist));
		(*ptr)->valor = v[i];
		(*ptr)->prox = NULL;
		ptr = &((*ptr)->prox);
		i++;
	}
	return r;
}

void liga (LInt *l) /// liga o ulitimo elemnto da lista ao primeiro
{
	if (*l)
	{
		LInt inicio = *l;
		while ((*l)->prox)
			l = &((*l)->prox);
		
		(*l)->prox = inicio;
	}
}







/*4 Considere o seguinte tipo para listas duplamente ligadas onde são guardados o apontador
para o primeiro e último nó.*/

 
typedef struct dlist{
	int valor;
	struct dlist *ant, *prox;
} NodoD;

typedef struct{
	NodoD *front, *last;
} DLint;

/*Defina uma função:

int capicua(DLint l)
que testa se uma destas listas tem a mesma sequência de valores quando percorrida nos dois sentidos. */

int length(NodoD *n)   //// calcula o tamnho da lista duplamente ligada
{
	int r = 0;
	while (n)
	{
		n = n->prox;
		r++;
	}
	return r;
}


int capicua(DLint l) 
{
	int len = length (l.front);
	int r = 1;
	int i = 0;
	NodoD *f = l.front;
	NodoD *u = l.last;

	while (i<len)
	{
		if (f->valor != u->valor)
			r=0;
		f = f->prox;
		u = u->ant;
		i++;
		len--;
	}
		
	
	return r; 
}

void reverse (DLint *l)
{
	if (l)
	{
		NodoD * aux = NULL;
		l->last = l->front;
		
		while (l->front)
		{
			aux = l->front->ant;
			l->front->ant = l->front->prox;
			l->front->prox = aux;
			aux = l->front;
			l->front = l->front->ant;
			
		}
		l->front = aux;
	}
}

DLint DLfromArray(int v[], int N)   //// constoi lista duplamente ligada apartir de array
{
	DLint r;
	r.front = NULL;
	r.last = NULL;
	NodoD **ptr = &(r.front);
	NodoD *prev = NULL;
	int i = 0;
	
	while (i<N)
	{
		(*ptr) = malloc (sizeof (struct dlist));
		(*ptr)->valor = v[i];
		(*ptr)->prox = NULL;
		(*ptr)->ant = prev;
		prev = *ptr;
		ptr = &((*ptr)->prox);
		i++;
	}
	r.last = prev;


	return r;
} 

void showDL (DLint l)  /// imprime lista duplamente ligada
{
	while (l.front)
	{
		printf ("%d\n", l.front->valor);
		l.front = l.front->prox;
	}
}



/*5 Defina uma função:
void imprime(ABin t)
que dada uma árvore binária imprime segundo uma travessia posorder os
valores da árvore, um por linha, precedidos do caminho para chegar a esse valor
(no caminho um caracter ‘<’ representa uma ida para a esquerda e o
caracter ‘>’ para a direita).*/ 


typedef struct abin {
int valor;
struct abin *esq,
*dir;
} *ABin;

/*Por exemplo, a árvore 

..4

./.\

1...6

.../.\

..5...8

deveria ser impressa como:

<1

><5

>>8

>6

4
*/

ABin ABfromArray (int v[], int n)  /// cria arvore binaria de array
{
	ABin r = NULL;
	if(n>0)
	{
		r = malloc (sizeof (struct abin));
 		r->valor = v[n/2];
 		r->esq = ABfromArray (v, n/2);
 		r->dir = ABfromArray (v+(n/2)+1, n - n/2 -1);
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

void imprimeAux (ABin a, char *c)
{
	if(a)
	{
		printf("%s%d\n\n",c, a->valor );
		int len = strlen (c);
		char e[len+1] , d[len+1];
		strcpy (e, c);
		strcpy (d, c);
		strcat (e, "<");
		strcat (d, ">");
		imprimeAux (a->esq, e);
		imprimeAux (a->dir, d);
	}
} 

void imprime(ABin a)  
{
	if (a)
	imprimeAux (a,"");
}

/*6 Defina uma função:
void pad (char *texto, int p, int N)
que recebe um texto com p palavras e acrescenta N espaços entre cada uma das palavras do texto. 

Por exemplo, se o array t contiver “teste de Programacao Imperativa”, a chamada pad (t,4,2)
deve fazer com que o array t passe a ter “teste   de   Programacao   Imperativa”.

Assuma que o array recebido como argumento tem espaço suficiente para alojar os caracteres adicionais.*/

void pad (char *texto, int p, int N)
{
	int i, j, k, len, numPal;
	len = strlen (texto);
	for (i=0, numPal=1; texto[i] && numPal<p; i++)
	{
		if (texto[i] == ' ' && texto[i+1] != ' ' && texto[i+1] != '\0' )
		{
			for (j=0; j<N; j++)
			{
				for(k=len; k>i; k--)
					texto[k+1] = texto[k];
				
				texto[i+1] = ' ';
				len++;				
			}
			numPal++;
			i += N;				
		}
	}
}

/*7 Considere o seguinte tipo de dados para armazenar (por ordem alfabética) um conjunto de palavras.*/

typedef struct nodo {
	char *raiz;
	int quantos;
	struct nodo *esq, *dir;
} *Palavras;

/*No campo quantos será armazenado o número de elementos  da sub-árvore esquerda.

Defina uma função:

int calculaQuantos (Palavras p)
que preenche o campo quantos de cada nodo da árvore. 

Diga ainda qual o significado do valor de retorno da função que definir.

Serão valorizadas respostas que obtenham o resultado pretendido percorrendo a árvore uma única vez.*/

// a função retorna o numero de elementos da arvore.

int calculaQuantos (Palavras p)
{
	int r = 0;
	if (p)
	{
		int e = 0, d =  0;
		e = calculaQuantos (p->esq);
		d = calculaQuantos (p->dir);	
		p->quantos = e;
		r = 1 + e + d;
	}
	return r;
}

/*8 Defina uma função:

int acrescenta (Palavras *e, char *p)
que recebe uma destas árvores em *e e uma palavra p e a insere no conjunto das palavras.
Note que essa inserção vai alterar o campo quantos de alguns (não necessariamente todos) nodos da árvore.

A função deverá retornar 0 se a inserção for bem sucedida ou um valor diferente de zero se
não houver memória disponível ou a palavra a inserir já se encontrar no conjunto.*/

int acrescenta (Palavras *e, char *p)
{
	int r = 1;
	int controlo = 0;
	if (!*e)
	{
		*e = malloc (sizeof (struct nodo));
		if (*e)
		{
			(*e)->raiz = strdup (p);
			r = 0;
		}	
	}
	else
	{
		controlo = strcmp ((*e)->raiz, p);
		if (controlo == 0)
			r = 0;
		else
			if (controlo < 0)
				r = acrescenta (&(*e)->dir, p);
			else 
			{
				(*e)->quantos++;
				r = acrescenta (&(*e)->esq, p);
			}
	}
	return r;
}

void showPal (Palavras p) // imprime estrutura Palavras
{
	if (p)
	{
		showPal (p->esq);
		printf("%s %d\n", p->raiz, p->quantos);
		showPal (p->dir);
	}
}

/* 9 Defina uma função:

char *atRank (Palavras p, int k)
que, recebendo um conjunto de palavras nesta representação
(e com o campo quantos de cada nodo correctamente calculado) calcula a palavra que
se encontra na posição k (isto é, a palavra para a qual existem exactamente k palavras menores do que ela).  

No caso de k ser superior ao número de palavras do conjunto a função deverá retornar NULL.*/

char *atRank (Palavras p, int k)
{
	char *r = NULL;
	if (p && k>=0)
	{
		if (k == p->quantos)
			r = p->raiz;
		else
			if (k < p->quantos)
				r = atRank (p->esq, k);
			else
				r = atRank (p->dir, k - 1 - p->quantos);				
	}
	return r;
}

