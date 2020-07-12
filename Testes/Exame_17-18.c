
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

void showPal (Palavras p)  ////////// imprime Palavras
{
	while (p)
	{
		char s[p->comp+1]; 
		strcpy(s, (p->palavra));
		s[p->comp] = '\0';
		printf ("%s\n", s);
		printf("comprimento: %d\n",p->comp);
		p = p->prox;
	}
}


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

/*2. Usando a função referida na alı́nea anterior defina agora uma função Palavras words (char *texto)
que, a partir de um texto, constrói a lista das palavras desse texto.
A função em questão não precisa de alocar espaço para armazenar cada uma das palavras (o campo
palavra de cada célula), nem precisa de terminar essas strings com o caracter ’\0’. Em vez disso deve
ser armazenado o endereço onde a palavra se inı́cia no texto dado, bem como o comprimento da palavra.*/


Palavras words (char *texto) 
{
	int i = 0;
	Palavras pal = NULL;
	Palavras *ptr = &pal;
	int len = 0,e = 0;

	while (*texto)
	{
		len = daPalavra (texto, &e);
		*ptr = malloc (sizeof (struct celula));
		(*ptr)->palavra = (texto+e);
		(*ptr)->comp = len;
		(*ptr)->prox = NULL;
		ptr = &((*ptr)->prox);
		texto += e+len;
	}

	return pal;

}

/*3. Defina uma função Palavras daLinha (Palavras t, int n) que dada uma lista de palavras t e um
tamanho de linha n, remove dessa lista o maior número de palavras que possam ser escritas numa linha
desse comprimento. A função deve deixar em t a lista com as palavras que compõe a primeira linha e
retornar a lista com apenas as restantes.
Esta função reorganiza a lista recebida sem alocar memória adicional.*/

Palavras daLinha (Palavras t, int n)
{
	Palavras r = NULL;
	Palavras prev = NULL;
	
	if(t)
	{
		if (t->comp >= n)
		{
			r = t->prox;
			t->prox = NULL;	
		}		
		
		else
		{
			
			while (t && n>0 && t->comp <= n)
			{
				n -= t->comp+1;
				prev = t;
				t = t->prox;
			}
			r = t;
			prev->prox = NULL;
		}
	}
	
	return r;
}/*

Palavras daLinha (Palavras t, int n) {
    int len = 0;
    Palavras prev;
    for(;len < n && t;t = t->prox) {
        len += t->comp + 1;
        if(len > n) break;
        prev = t;
    }
    t = prev->prox;
    prev->prox = NULL;
    return t;
}*/


/*4. Defina uma função void escreveLinha (Palavras p, int n) que recebe uma lista de palavras e a
escreve no ecran (stdout) numa linha com n caracteres, correctamente justificada de ambos os lados.
Assuma que a menos que se trate de uma única palavra com mais do que n caracteres, as palavras e os
espaços para as separar podem ser escritas com esse número de caracteres. No caso de se tratar de uma
linha só com uma palavra maior do que a largura pretendida, deve ser escrita toda a palavra.*/

void escreveLinha (Palavras p, int n)
{
	Palavras aux = p;
	int len = 0, numP=0, i=0, j=0, k=0, acc=0;
	if(p)
	{
		if (p->comp >=n)
		{
			for (i=0; i< p->comp; i++)
				putchar (p->palavra[i]);
		}
		else
		{
			
			while (aux && len-1 <= n)
			{
				
				acc = aux->comp+1;
				len += acc;
				numP++;
				aux = aux->prox;
					
			}

			if (len-1>n)
			{
				numP--;
				len -= acc;	
			}
			
		
			int space = (n-len);
			
			
			for (i=0; i<numP; i++)
			{
				space -= k;
			

				for (j=0; j< p->comp; j++)
					putchar (p->palavra[j]);

				if (i<numP-1);
					putchar (' ');
				
				for(k=0; k<(space/(numP-i)); k++)
					putchar (' ');
				p= p->prox;

			}	

		}
		putchar ('\n');		
	}

}

/*5. Usando, entre outras, as funções referidas nas alı́neas anteriores defina uma função void formata (char
texto[], int largura) que escreve no ecran o texto formatado com a largura especificada.
Note que a sua solução deve garantir que é libertada toda a memória alocada.*/

void formata (char texto[], int largura)
{
	Palavras pal = words (texto);
	Palavras aux = NULL;

	while (pal)
	{
		aux = daLinha (pal, largura);
		escreveLinha (pal, largura);
		free (pal);
		pal = aux;
	}
	

}

