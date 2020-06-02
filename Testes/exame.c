#include <stdio.h>
#include <stdlib.h>

typedef struct posicao {
int x, y;
} Posicao;

typedef struct slist {
int valor;
struct slist *prox;
} *LInt;

typedef struct nodo {
int valor;
struct nodo *esq, *dir;
} *ABin;



// Parte A

/*1. Apresente uma definição da função pré-definida em C char *strstr (char s1[], char s2[]) que de-
termina a posição onde a string s2 ocorre em s1. A função deverá retornar NULL caso s2 não ocorra em
s1.*/

char * mystrstr (char s1[], char s2[])
{
	int i, j;
	char * r = NULL;
    
    if (s2[0] == '\0')
    	r = s1;
    else
    {
    	for (i=0; s1[i] && !r; i++ )
			for (j=0; s2[j] == s1[i+j] ; j++ )
				if (s2[j+1] == '\0')
			    	r = s1+i;
    }
    			
	return r;
}


/*2. Defina uma função void truncW (char t[], int n) que dado um texto t com várias palavras (as
palavras estão separadas em t por um ou mais espaços) e um inteiro n, trunca todas as palavras de
forma a terem no máximo n caracteres. Por exemplo, se a string txt contiver "liberdade, igualdade
e fraternidade", a invocação de truncW (txt, 4) deve fazer com que passe a estar lá armazenada a
string "libe igua e frat".*/

void mytruncW (char t[], int n)
{
	int i,j=0, controlo = 0;
	
	for (i=0; t[i]; i++)
	{
		if (t[i]!= ' ')
			controlo++;
		else
			controlo = 0;
		
		if (controlo <= n)
			{
			    t[j] = t[i];
			    j++;
			    
			}
		
	}
    t[j] = '\0';

}


/*3. Defina a função int maisCentral (Posicao pos[], int N) que, dado um array com N posições, de-
termina o ı́ndice da posição que está mais perto da origem (note que as coordenadas de cada ponto são
números inteiros).*/

int maisCentral (Posicao pos[], int N)
{
	int r = 0;
    int i;
	
	for(i=0; i<N; i++)
		if (pos[i].x * pos[i].x + pos[i].y * pos[i].y < pos[r].x * pos[r].x + pos[r].y * pos[r].y)
			r = i;

	return r;
}

/*4. Defina uma função LInt somasAcL (LInt l) que, dada uma lista de inteiros, constrói uma nova lista de
inteiros contendo as somas acumuladas da lista original (que deverá permanecer inalterada).
Por exemplo, se a lista l tiver os valores [1,2,3,4] a lista contruı́da pela invocação de somasAcL (l)
deverá conter os valores [1,3,6,10].*/

LInt somasAcL (LInt l)
{
	LInt r = NULL;
	LInt *ptr = &r;
	int acc = 0;
	while (l)
	{
		acc += l->valor;
		*ptr = malloc (sizeof(struct slist));
		(*ptr)->valor = acc;
		(*ptr)->prox = NULL;
	    ptr = &((*ptr)->prox);
		l = l->prox;
	}

	return r;
}

/*
5. Apresente uma definição não recursiva da função int addOrd (ABin *a, int x) que adiciona um ele-
mento a uma árvore binária de procura. A função deverá retornar 1 se o elemento a inserir já existir na
árvore ou 0 no outro caso.*/

int addOrd (ABin *a, int x)
{
	int r = 0;
	if(!*a)
	{
		(*a) = malloc (sizeof (struct nodo));
		(*a)->valor = x;
		(*a)->esq = NULL;
		(*a)->dir = NULL;
	}
	else
		if ((*a)->valor == x)
			r = 1;
		else
			if ((*a)->valor > x)
				r = addOrd ((&(*a)->esq), x);
			else
				r = addOrd ((&(*a)->dir),x);

	return r;

}

// Parte B


typedef struct celula {
char *palavra;
int comp;
struct celula *prox;
} *Palavras;


/*1. Defina uma função int daPalavra (char *s, int *e) que calcula o comprimento da primeira palavra
dessa string (retorna 0 se não houver palavras). Adicionalmente a função deve colocar no endereço e o
número de espaços que antecedem essa palavra.
Use a função int isspace (char c) que testa se um caracter é um espaço.
Por exemplo, a invocação x=daPalavra(" roda nas trevas", &y) deve colocar na variável x o valor 4
(comprimento de "roda") e na variável y o valor 1 (pois há um espaço no inı́cio).*/

int daPalavra (char *s, int *e)
{
	int i, r = 0;
	*e = 0;

	for(i=0; s[i] && s[i]==' '; i++)
		(*e)++;
	if(s[i])
	{
		while(s[i] && s[i]!= ' ')
		{
			r++;
			i++;
		}

	}

	return r;
	


}



int main ()
{
	char t[17] = " roda nas trevas";

	int e, d;

	d=daPalavra(t, &e);

	printf("%d %d\n",d,e );


}