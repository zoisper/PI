#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*1. Relembre o problema proposto na Ficha ante-rior de calcular a 
palavra mais frequente de umtexto.
Considere ainda que se implementa o tipo Dicionario como uma árvore 
binária deprocura (ordenada pela palavra).

Apresente definições das funções*/

typedef struct dicionario {
char *pal;
int ocorr;
struct dicionario *esq, *dir;
} *Dicionario;

/*• void initDic (Dicionario *d) que inicializa o dicionário a vazio.*/

void initDic (Dicionario *d)
{
    *d = NULL;
}

/*• int acrescenta (Dicionario *d, char *pal) que acrescenta uma ocorrência da palavra
pal ao dicionário *d. A função deverá retornar o número de vezes que a palavra pal passou
a ter após a inserção.*/

void limpa (char * pal) // elimna carateres de pontuação
{
    int i = 0, r = 0;
    while (pal[i])
    {
        if(isalnum(pal[i]) || pal[i] == '-' || pal[i] == '_')
            pal[r++]  = pal[i];
        i++;
    }
    pal[r] = '\0';
}

void maisculas (char * pal) // coloca palavra em maisculas
{
    int i = 0, r = 0;
    while (pal[i])
        pal[r++] = toupper (pal[i++]);
}

int acrescenta (Dicionario *d, char *pal)
{
    int r = 1;
    char * newPal = strdup(pal);
    limpa(newPal);
    maisculas(newPal);
    while (*d && strcmp(newPal, (*d)->pal) != 0)
    {
        if(strcmp(newPal, (*d)->pal) > 0)
            d = &((*d)->dir);
        else
            d = &((*d)->esq);
    }
    if(! *d)
    {
        *d = malloc (sizeof (struct dicionario));
        (*d)->pal = newPal;
        (*d)->ocorr = 1;
        (*d)->dir = NULL;
        (*d)->esq = NULL;
    }
    else
    {
        (*d)->ocorr++;
        r = (*d)->ocorr;
        free(newPal);
    }
    return r;
}

/*• char *maisFreq (Dicionario d, int *c) que calcula a palavra mais frequente de um di-
cionario (retornando ainda em c o número de ocorrências dessa palavra).*/

char *maisFreq (Dicionario d, int *c)
{
    char *r = NULL, *tmp = NULL;;
    int aux = 0;
    if(d)
    {
        r = d->pal;
        *c = d->ocorr;
        tmp = maisFreq (d->esq, &aux);
        if (aux > *c)
        {
            r = tmp;
            *c = aux;
        }
        tmp = maisFreq (d->dir, &aux);
        if (aux > *c)
        {
            r = tmp;
            *c = aux;
        }
    }
    return r;
}

void showDic (Dicionario d) // imprime dicionario
{
    if (d)
    {
        showDic (d->esq);
        printf ("%s :: %d\n", d->pal, d->ocorr);
        showDic (d->dir);
    }
}

/*2. Relembre as definições de listas ligadas e árvores binárias de inteiros.*/

typedef struct abin {
int valor;
struct abin *esq,
*dir;
} *ABin;

typedef struct lista {
int valor;
struct lista *prox;
} *LInt;

/*Defina as seguintes funções de conversão entre estes tipos de dados.*/

/*• ABin fromList (LInt l) que produz uma árvore binária de procura balanceada a partir de
uma lista ordenada.
De forma a tornar essa função mais eficiente pode definir uma função auxiliar Lint fromListN
(LInt l, int N, ABin *a) que produz (em *a) uma árvore binária de procura balanceada
a partir dos N primeiros elementos da lista l, retornando a lista dos restantes elementos.*/

int length (LInt l) // calcula comprimento de LInt
{
    int r= 0;
    while(l)
    {
        l = l->prox;
        r++;
    }
    return r;
}

LInt fromListN (LInt l, int N, ABin *a)
{
    if(N>0)
    {
        *a = malloc (sizeof (struct abin));
        l = fromListN(l, N/2, &((*a)->esq));
        (*a)->valor = l->valor;
        l = l->prox;
        l = fromListN (l, N - N/2 - 1, &((*a)->dir));
       
    }
    else
        *a = NULL;
    return l;  
}

ABin fromList (LInt l)
{
    ABin r = NULL;
    int len = length(l);
    fromListN (l, len, &r);
    return r;
}

/*• LInt inorderL (ABin a) que produz uma lista ligada ordenada a partir de uma árvore
binária de procura.
De forma a tornar essa função mais eficiente pode definir uma função auxiliar LInt inorderLAux
(ABin a, LInt *end) que coloca em *end o endereço do último elemento da lista produzida.*/

LInt inorderLAux (ABin a, LInt *end)
{
    LInt r = NULL, aux = NULL;
    if (a)
    {
        r = inorderLAux (a->esq, &aux);
        LInt new = malloc (sizeof (struct lista));
        new->valor = a->valor;
        new->prox = inorderLAux (a->dir, end);
        if(aux)
            aux->prox = new;
        else
            r = new;
        if(!*end)
            *end = new;
    }
    return r;
}

LInt inorderL (ABin a)
{
    LInt end = NULL;
    return inorderLAux (a, &end);
}


LInt listFromArray (int v[], int N) // cria LInt apartir de array
{
    LInt r = NULL, *ptr = &r;
    int i = 0;
    while (i<N)
    {
        *ptr = malloc (sizeof (struct lista));
        (*ptr)->valor = v[i++];
        (*ptr)->prox = NULL;
        ptr = &((*ptr)->prox);
    }
    return r;
}

void showLInt (LInt l) // imprime LInt
{
    while (l)
    {
        printf ("%d ", l->valor);
        l = l->prox;
    }
}

void showABin (ABin a) // imprime ABin
{
    if (a)
    {
        showABin (a->esq);
        printf ("%d\n", a->valor);
        showABin (a->dir);
    }
}

/*3. Considere o tipo DLInt para representar listas duplamente ligadas 
(em cada célula contem o endereço da próxima e da anterior).*/

typedef struct dlista {
int valor;
struct dlista *prox,
*ant;
} *DLInt;

/*Defina a função DLInt inorderDL (ABin a) que produz uma lista duplamente ligada ordenada a
partir de uma árvore binária de procura (retornando o endereço do menor elemento da lista).*/

DLInt inorderDL (ABin a)
{
    DLInt r = NULL, *ptr = &r;
    if(a)
    {
        *ptr = inorderDL (a->esq);
        DLInt new = malloc (sizeof (struct dlista));
        new->valor = a->valor;
        new->prox = inorderDL (a->dir);
        if (new->prox)
            new->prox->ant = new;
        while (*ptr && (*ptr)->prox)
            ptr = &((*ptr)->prox);
        if(*ptr)
        {
            (*ptr)->prox = new;
            new->ant = *ptr;
        }
        else
            *ptr = new;        
    }
    return r;
}

void showDL (DLInt d) // imprime DLInt
{
    while (d)
    {
        printf ("%d ", d->valor);
        d = d->prox;
    }
}

void showDLrev (DLInt d) // imprime DLInt no sentido inverso
{
    while (d)
    {
        printf ("%d ", d->valor);
        d = d->ant;
    }
}

DLInt lastDL (DLInt d) // devolve o ultimo elemnto da DLInt sem a alterar.
{
    while (d && d->prox)
        d = d->prox;
    return d;
}

