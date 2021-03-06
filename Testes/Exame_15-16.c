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
	int i = 0, j = 0, controlo =0;
	while (p[i] && ! isalnum (p[i]))
		i++;
	
	while (p[i] && (isalnum (p[i]) || (p[i] == '-' && controlo < 2)))
	{
		if (p[i] == '-')
			controlo++;
			
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

char *remMaisFreq(Hist *h, int *count)
{
	char *r = NULL;
	*count = 0;
	Hist *aux = NULL;
	Hist freeD = NULL;

	if (*h)
	{
		aux = h;
		*count = (*aux)->cont;
		
		while (*aux)
		{
			if ((*aux)->cont > *count)
			{
				*count = (*aux)->cont;
				h = aux;
			}
			aux = &((*aux)->prox);

		} 
		r = (*h)->pal;
		freeD = *h;
		(*h) = (*h)->prox;
		free (freeD);
	}





	return r;
}



 Hist HistFromStr (char *s)   /// cria uma listaP apartir de uma string
{
	Hist h = NULL;
	char buff[100];
	int jump = 0;
	while (*s)
		{
			jump = primeiraPal (s, buff);
			inc (&h, buff);
			int len = strlen (buff);
			s += len+jump;
		}



	return h;
}

void showHist (Hist h)   //// imprime listaP
{
	while (h)
	{
		printf ("%s\n", h->pal);
		printf("%d\n",h->cont );
		h = h->prox;
	}
} 

/*3. Escreva um programa C que, utilizando os tipos e as funções definidas, leia um texto (de stdin)
e imprima (em stdout) as 10 palavras mais frequentes com mais de três caracteres (e a respectiva
contagem). Deve atender aos seguintes aspectos:
• Pode considerar que o tamanho máximo das palavras que ocorrem no texto é 60;
• As palavras devem passar por um processo de filtagem onde se removem todos os caracteres que
não letras e se convertem para maiúsculas (e.g. "gato22,", "GaTo" ou "Gato,,,"" devem ser
consideradas a mesma palavra: "GATO").
• Toda a memória alocada pelo programa deve explicitamente libertada.
• Utilize as funções definidas nas bibliotecas standard do C (em particular as de manipulação de
strings e caracteres disponibilizadas em string.h e ctype.h).*/

void freeHist (Hist *h)
{
	Hist *aux = NULL;
	while (*h)
	{
		aux = h;
		h = &((*h)->prox);
		free(*aux);
		*aux = NULL;
	}

}

int main (int argc , char *argv[] )
{

	FILE *input = NULL;  
	char buff[1024]; 
	Hist h = NULL;
	int i = 0, x = 0;
	int r = 1;
	
	if (argc == 2)
		input = fopen (argv[1], "r");
	else
		input = stdin;

	if (input)
	
	{
		while (fscanf(input,"%s", buff )==1)
		{
			limapaPal (buff);
			maiusculas (buff);
			if (strlen (buff) > 3)
				inc (&h, buff);
		}


		while (i<3)
		{
			char *temp = remMaisFreq (&h, &x );
			printf("%s %d\n",temp, x);
			i++;
		}
		freeHist (&h);
		r=0;
	} 


	return r;
}