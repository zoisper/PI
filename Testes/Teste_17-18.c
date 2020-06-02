
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

/*2. Defina uma função int maxHeap (ABin a) que determina o maior elemento de uma min-heap
não vazia.*/

int maxHeap (ABin a)
{
	ABin esq = a->esq;
	ABin dir = a->dir;

	if (esq && dir)
	{
		 int e = maxHeap (esq);
		 int d = maxHeap (dir);
		 
		 if ( e > d)
		 	return e;
		 else
		 	return d;
	}
	
	else
		if (!esq && dir)
			return maxHeap (dir);
		else
			if (esq && !dir)
				return maxHeap (esq);
			else
				return a->valor;
}

/*3. Defina uma função void removeMin (ABin *a) que remove o menor elemento de uma min-
heap não vazia (que está necessariamente na raı́z).*/

void removeMin (ABin *a)
{
	ABin aux = NULL;

	if (!(*a)->esq)
	{
		aux  = *a;
		*a = (*a)->dir;
		free (aux);

	}
	else
		if (!(*a)->dir)
		{
			aux = *a;
			*a =(*a)->esq;
			free (aux);

		}	
	else
		if ((*a)->dir->valor > (*a)->esq->valor)
		{
			(*a)->valor = (*a)->esq->valor;
			removeMin (&((*a)->esq));
		}
		else
		{
			(*a)->valor = (*a)->dir->valor;
			removeMin ((&(*a)->dir));
		}
}

/*4. Assumindo que, para além das funções acima, existe definida uma função void add (ABin
*a, int x), defina uma função void heapSort (int v[], int N) que ordena um array us-
ando uma min-heap auxiliar. Começa-se por construir uma min-heap com todos os elementos
do array e de seguida vão-se retirando os elementos para obter o array ordenado.*/

void add (ABin*a, int x)  ////// adiciona elemento a miniheap
{
	ABin new = NULL;
	int aux;
	

	if (!*a)
	{
			new = malloc (sizeof (struct nodo));
			new->valor = x;
			new ->esq = NULL;
			new->dir = NULL;
			*a = new;
	}
	
	else
		if (x > (*a)->valor && !(*a)->esq)
			add ((&(*a)->esq),x);
		else
			if (x > (*a)->valor && !(*a)->dir)
				add ((&(*a)->dir),x);
			else
				if (x > (*a)->valor && (*a)->esq->valor > (*a)->dir->valor)
					add ((&(*a)->esq),x);
				else
					if (x > (*a)->valor && (*a)->dir->valor > (*a)->esq->valor)
						add ((&(*a)->dir),x);
					else
						if (x < (*a)->valor && !(*a)->esq)
						{
							aux = (*a)->valor;
							(*a)->valor = x;
							x = aux;
							add ((&(*a)->esq),x);
						}
						else
							if (x < (*a)->valor && !(*a)->dir)
							{
								aux = (*a)->valor;
								(*a)->valor = x;
								x = aux;
								add ((&(*a)->dir),x);
							}
							else
								if (x < (*a)->valor && (*a)->esq->valor > (*a)->dir->valor)
								{
									aux = (*a)->valor;
									(*a)->valor = x;
									x = aux;
									add ((&(*a)->dir),x);
								}
								else
									{
										aux = (*a)->valor;
										(*a)->valor = x;
										x = aux;
										add ((&(*a)->esq),x);
									}
}

void heapSort (int v[], int N)
{
	int i=0;
	ABin a = NULL;

	for(i=0; i<N; i++)
		add (&a, v[i]);
	
	 for (i=0; i<N; i++)
	{
		v[i] = a->valor;
		removeMin (&a);
	}
}

/*5. Considere o problema de ler uma sequência de números e determinar o k-ésimo maior número
lido.
Por exemplo se forem lidos os números 20, 30, 10, 40, 50, 2, 5, 8, 13, 35, 44
e quisermos determinar o 4 o maior, deve ser produzido o número 35
Uma forma de resolver este problema consiste em guardar apenas os k maiores números lidos
até à altura. No final apenas teremos que devolver/imprimir o menor dos números guardados.
De forma a tornar este processo mais eficiente do que simplesmente guardar os números num
array pode-se usar uma min-heap com os ditos números.
Sempre que já foram lidos pelo menos k números e é lido um número menor do que os
armazenados esse número é ignorado. No entanto, se tal não acontecer, remove-se o menor
elemento da min-heap e acrescenta-se esse novo número.
Use esta estratégia para definir uma função int kMaior (int v[], int N, int k) que de-
termina o k-maior elemento de um array v com N elementos.*/


int kMaior (int v[], int N, int k)
{
	ABin a = NULL;

	for (int i=0; i<N; i++)
	{
		if (i<k)
			add (&a, v[i]);
		else
			if (a->valor < v[i])
			{
				removeMin (&a);
				add(&a, v[i]);
			}
	}

	return a->valor;
}



