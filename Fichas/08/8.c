#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*O programa apresentado em baixo calcula o número de palavras de um texto.
O objectivo das questões abaixo é modificar este programa de forma a calcular a palavra mais fre-
quente de um texto.
Para isso vamos começar por calcular quantas vezes cada palavra existe num texto e de seguida
calcularemos qual a que ocorre mais vezes.
Para isso vamos definir um tipo Dicionario para armazenar, para cada palavra que já apareceu no
texto, o número de vezes que tal aconteceu.*/

/*int main (int argc, char *argv[])
{
    FILE *input;
    int r=0, count=0;
    char word[100];
    if (argc==1) 
        input=stdin;
    else 
        input=fopen(argv[1],"r");
    if (input==NULL)
        r=1;
    else 
    {
        while ((fscanf(input,"%s",word)==1))
            count ++;
        fclose (input);
        printf ("%d palavras\n", count);
    }
    return r;
}*/


typedef struct entrada{
char *palavra;
int ocorr;
struct entrada *prox;
} *Palavras;

typedef Palavras Dicionario;

/*Para cada uma das alternativas que vamos definir para o tipo Dicionario é necessário definir as funções*/

/*• void initDic (Dicionario *d) que inicializa o dicionário a vazio.*/

void initDic (Dicionario *d)
{
    *d = NULL;
}

/*• int acrescenta (Dicionario *d, char *pal) que acrescenta uma ocorrência da palavra pal ao
dicionário *d. A função deverá retornar o número de vezes que a palavra pal passou a ter após a
inserção.*/

void maiusculas (char * t) /// coloca string em maisculas.
{
	int i = 0;
	while (t[i])
	{
		t[i] = toupper(t[i]);
		i++;
	}
}

void limpa (char * pal) // elimina virgulas e sinais de pontuação da string.
{
    int i = 0, j = 0;
    while (pal[i])
    {
        if (isalnum (pal[i]) || pal[i] == '-' || pal[i] == '_')
            pal[j++] = pal[i];
        i++;
    }
    pal[j] = '\0';
}

int acrescenta (Dicionario *d, char *pal)
{
    char * novaPal = strdup (pal);
    limpa (novaPal);
    maiusculas (novaPal);
    while (*d && strcmp ((*d)->palavra, novaPal) != 0)
        d = &((*d)->prox);
    if (*d)
    {
        (*d)->ocorr++;
        free (novaPal);
    }         
    else
    {
        *d = malloc (sizeof (struct entrada));
        (*d)->palavra = novaPal;
        ((*d)->palavra);
        (*d)->ocorr = 1;
        (*d)->prox = NULL;
    }
    return (*d)->ocorr;    
}

/*• char *maisFreq (Dicionario d, int *c) que calcula a palavra mais frequente de um dicionario
(retornando ainda em c o número de ocorrências dessa palavra).*/

char *maisFreq (Dicionario d, int *c)
{
    char * r = NULL;
    *c = 0;
    while (d)
    {
        if (d->ocorr > *c)
        {
            *c = d->ocorr;
            r = d->palavra;
        }
        d = d->prox;
    }
    return r;
}


void showD (Dicionario d) // imprime Dicionario
{
    while (d)
    {
        printf ("%s :: %d\n", d->palavra, d->ocorr);
        d = d->prox;
    }
}

/*1. Usando as funções referidas, altere o programa de forma a escrever no ecran a palavra mais frequente
(e o número de vezes que ocorre).*/

/* Resposta:

int main (int argc, char *argv[])
{
    FILE *input;
    int r=0, count=0;
    char word[100], *mF = NULL;
    Dicionario d;
    if (argc==1) 
        input=stdin;
    else 
        input=fopen(argv[1],"r");
    if (input==NULL)
        r=1;
    else 
    {
        initDic (&d);
        while ((fscanf(input,"%s",word)==1))
            acrescenta (&d, word);
        mF = maisFreq (d, &count);
        fclose (input);
        printf ("Palavra Mais Frequente: %s Ocurrencias: %d\n", mF, count);
    }
    return r;
}*/

/*2. Defina essas funções para as seguintes formas alternativas de implementar o tipo Dicionario.*/

/*(a) A forma mais simples de definir o tipo Dicionario é como uma lista ligada: typedef Palavras
Dicionario;.
A ordem pela qual as palavras são armazenadas pode ser:*/

/*• Por ordem alfabética da palavra*/

int acrescentaOrd (Dicionario *d, char *pal)
{
    Dicionario ant = NULL, novo = NULL;;
    char * novaPal = strdup (pal);
    limpa (novaPal);
    maiusculas (novaPal);
    while (*d && strcmp ((*d)->palavra, novaPal) < 0)
    {
        ant = *d;
        d = &((*d)->prox);
    }    
    if (*d && strcmp ((*d)->palavra, novaPal) == 0)
    {
        (*d)->ocorr++;
        free (novaPal);
    }         
    else
    {
        novo = malloc (sizeof (struct entrada));
        novo->palavra = novaPal;
        novo->ocorr = 1;
        novo->prox = *d;
        if (ant)
        {
            ant->prox = novo;
            *d = ant;
        }
        else
            *d = novo;
    }
    return (*d)->ocorr;    
}

/*• Inserindo as novas palavras no fim (ordem cronológica)*/

// Resposta: definido antes da aliena 1.

/*• Movendo para o inı́cio da lista cada nova actualização.*/

int acrescentaIni (Dicionario *d, char *pal)
{
    Dicionario novo = NULL;
    char * novaPal = strdup (pal);
    limpa (novaPal);
    maiusculas (novaPal);
    while (*d && strcmp ((*d)->palavra, novaPal) != 0)
        d = &((*d)->prox);
    if (*d && strcmp ((*d)->palavra, novaPal) == 0)
    {
        (*d)->ocorr++;
        free (novaPal);
    }         
    else
    {
        novo = malloc (sizeof (struct entrada));
        novo->palavra = novaPal;
        novo->ocorr = 1;
        novo->prox = *d;
        *d = novo;
    }
    return (*d)->ocorr;    
}

/*(b) Quando o número de palavras é muito grande, é costume partir essa lista em várias listas mais pequenas.
Em vez de usarmos uma lista para representar um dicionário usaremos um array de HSIZE listas. 
É necessário definir uma função que, dada uma palavra determine em qual dessas listas essa
palavra está ou será armazenada. Como exemplo apresenta-se uma definição muito simples (da
autoria de Dan Bernstein http://www.cse.yorku.ca/~oz/hash.html).*/

#define HSIZE 1000
typedef Palavras DicionarioH[HSIZE];

unsigned int hash (char *pal, int s)
{
    unsigned int r;
    for (r=5381; *pal != '\0'; pal++)
        r = r*33 + *pal;
    return (r%s);
}

/*• void initDicH (DicionarioH *d) que inicializa o dicionário a vazio.*/

void initDicH (DicionarioH *d)
{
    int i = 0;
    while (i<HSIZE)
    {
        (*d)[i] = NULL;
        i++;
    }
}

/*• int acrescentaH (DicionarioH *d, char *pal) que acrescenta uma ocorrência da palavra pal ao
dicionário *d. A função deverá retornar o número de vezes que a palavra pal passou a ter após a
inserção.*/

int acrescentaH (DicionarioH *d, char *pal)
{
    unsigned int h = hash (pal, HSIZE);
    acrescenta (&((*d)[h]), pal);
}

/*• char *maisFreqH (DicionarioH d, int *c) que calcula a palavra mais frequente de um dicionario
(retornando ainda em c o número de ocorrências dessa palavra).*/

char *maisFreqH (DicionarioH d, int *c)
{
    char * r = NULL, * temp = NULL;
    int aux = 0, i = 0;
    *c = 0;
    while (i<HSIZE)
    {
        temp = maisFreq (d[i], &aux);
        if (aux > *c)
        {
            *c = aux;
            r = temp;
        }
        i++;
    }
    return r;
}

void showDH (DicionarioH d) // imprime DicionarioH
{
    int i = 0;
    while (i<HSIZE)
    {
        showD (d[i]);
        i++;
    }
}

