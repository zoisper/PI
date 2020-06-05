#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Parte A

typedef struct nodo {
int valor;
struct nodo *esq, *dir;
} *ABin;

/*1. Apresente uma definição da função pré-definida em C char *strcpy (char *dest, char source[])
que copia a string source para dest retornando o valor desta última.*/

char *mystrcpy(char s1[], const char s2[]) 
{
    int i;
    for(i=0; s1[i]=s2[i] ;i++ );
    
    return s1;
}

/*2. Defina uma função void strnoV (char s[]) que retira todas as vogais de uma string.*/

void strnoV (char t[])
{
   int i,j;
   for(i=0, j=0; t[i]; i++)
   		if (t[i] != 'a' &&  t[i] != 'A' && t[i] != 'e' && t[i] != 'E' && t[i] != 'i' && t[i] != 'I' && t[i] != 'o' && t[i] != 'O' && t[i] != 'u' && t[i] != 'U')
   			t[j++] = t[i];
   
   t[j] = '\0';
}


/*3. Defina uma função int dumpAbin (ABin a, int v[], int N) que dada uma árvore a, 
preenche o array v com os elementos da árvore segundo uma travessia inorder. A função deverá preencher
no máximo N elementos e retornar o número de elementos preenchidos.*/

int dumpAbin (ABin a, int v[], int N) 
{
    int r = 0;
    if (a && N>0)
    {
        r=dumpAbin (a->esq, v, N);
        
        if (r<N)
            v[r++] = a->valor;
            
        r+=dumpAbin(a->dir, v+r, N-r);
    }
    
    return r;
}

/*4. Apresente uma definição não recursiva da função int lookupAB (ABin a, int x) que testa se um
elemento pertence a uma árvore binária de procura.*/

int lookupAB (ABin a, int x) 
{
    int r =0;
    if (a)
    {
        if (a->valor == x)
            r =1;
        else
            if (a->valor > x)
                r = lookupAB (a->esq, x);
            else
                r = lookupAB (a->dir, x);           
    }
    return r;
}


// Parte B

typedef struct listaP{
char *pal;
int cont;
struct listaP *prox;
} Nodo, *Hist;



/*1. Defina a função int inc(Hist *h, char *pal) que incrementa o número de ocorrências da palavra
pal (retornando o novo valor). Considere para o efeito que a lista mantém as palavras ordenadas
lexicograficamente. Note que se a palavra não existir na lista, deve ser criada uma nova entrada.*/

void maiusculas (char * t) /// coloca palavra em maisculas
{
	int i = 0;
	while (t[i])
	{
		t[i] = toupper(t[i]);
		i++;
	}

}

void limapaPal (char *p)  //// limpa carateres de pontuação da palavra
{
	int i = 0, j = 0;
	while (p[i] && ! isalnum (p[i]))
		i++;
	
	while (p[i])
	{
		if (isalnum (p[i]) || p[i] == '-')
			p[j++] = p[i];
		i++;	
	}
	p[j] = '\0';
}

 int primeiraPal (char * t, char * dest)  //// copia a primeira palavra para o array dest e retorna o num espaços/pontos antes da palavra,
 {
 	int i = 0, j=0; 
 	char pal[100] ;
 	int jump = 0;
 	for (i=0; t[i] &&  !isalnum (t[i]) ; i++)
 		;
 	jump = i;
 		
	while (t[i] && isalnum (t[i]) || t[i] == '-' )
	{
		dest[j++] = t[i]; 
		i++;
	}
			dest[j]= '\0';
			
			
	return jump;

 }



int inc(Hist *h, char *pal)
{
	int r = 1;
	Hist ant = NULL;
	maiusculas (pal);
	
	if (strlen(pal)>0)
	{
		while ( *h && strcmp (pal, (*h)->pal)>0)
		{
			ant = *h;
			h = &((*h)->prox);
		}
	
		if (!*h)
		{
			*h = malloc (sizeof (Nodo));
			(*h)->pal = strdup (pal);
			(*h)->cont = 1;

		}
		else
			if (strcmp (pal, (*h)->pal)==0)
			{
				(*h)->cont++;
				r = (*h)->cont;
			}
			else
			{
				Hist new = malloc (sizeof (Nodo));
				new->pal = strdup (pal);
				new->cont = 1;
				new->prox = *h;
				if (ant)
					ant->prox = new;
				else
					*h = new;
			}
		
	}
	

	return r;
}

/*2. Defina a função char *remMaisFreq(Hist *h, int *count) que, dado um histograma h, remova a
entrada correspondente à palavra mais frequente, retornando-a e armazenando a sua contagem na
posição de memória apontada por count. */




 Hist HistFromStr (char *s)   /// cria uma listaP apartir de uma string
{
	Hist h = NULL;
	char buff[100];
	int jump = 0;
	while (*s)
		{
			jump = primeiraPal (s, buff);
			//printf("buff %s\n",buff );
			//printf("size %d\n", size);
			inc (&h, buff);
			int len = strlen (buff);
			//printf("len %d\n",len );
			s += len+jump;
		}



	return h;
}

void showHist (Hist h)   //// imprime listaP
{
	while (h)
	{
		printf ("%s\n", h->pal);
		h = h->prox;
	}
} 

int main ()
{

	/*char texto[100] = ".-.-.-pato-ferro, mundo amigos";
	Hist h = HistFromStr (texto);
	showHist (h);*/



	


	
	



	return 0;
}