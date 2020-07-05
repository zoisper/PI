#include <stdio.h>
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
    int i = 0, j = 0;
    while (pal[i])
    {
        if (isalnum(pal[i]) || pal[i] == '-' || pal[i] == '_' )
            pal[j++] = pal[i];
        i++;
    }
}

void maisculas (char * pal) // coloca palavra em maisculas
{
    int i = 0;
    while (pal[i])
    {
        pal[i] = toupper (pal[i]);
        i++;
    }
}

int acrescenta (Dicionario *d, char *pal)
{
    int r = 1;
    char * palN = strdup (pal);
    limpa (palN);
    maisculas (palN);
    if (*d)
    {
        int controlo = strcmp ((*d)->pal, palN);
            if (controlo == 0)
            {
                r = (*d)->ocorr++;
                free (palN);
            }
            else
                if (controlo > 0)
                {
                    r = acrescenta (&((*d)->esq), pal);
                    free (palN);
                }
                    
                else
                {
                    r = acrescenta (&((*d)->dir), pal);
                    free (palN);
                }
    }
    else
    {
        *d = malloc (sizeof (struct dicionario));
        (*d)->pal = palN;
        (*d)->ocorr = 1;
        (*d)->esq = NULL;
        (*d)->dir = NULL;
    }    
    return r;
}

/*• char *maisFreq (Dicionario d, int *c) que calcula a palavra mais frequente de um di-
cionario (retornando ainda em c o número de ocorrências dessa palavra).*/

char *maisFreq (Dicionario d, int *c)
{
    char * r = NULL, * temp = NULL;
    int aux = 0;
    *c = 0;
    
    if (d)
    {
        *c = d->ocorr;
        r = d->pal;
        temp = maisFreq (d->esq, &aux);
        if (aux > *c)
        {
            *c = aux;
            r = temp; 
        }
        temp = maisFreq (d->dir, &aux);
        if (aux > *c)
        {
            *c = aux;
            r = temp; 
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

int compList (LInt l) // calcula comprimento LInt
{
    int r = 0;
    while (l)
    {
        r++;
        l = l->prox;
    }
    return r;
} 

ABin fromListAux (LInt l, int len)
{
    ABin r = NULL;
    int m = 0;
    if (len>0)
    {
        r = malloc (sizeof (struct abin));
        r->esq = fromListAux (l, len/2);
        while (m < len/2)
        {
            l = l->prox;
            m++;
        }
        r->valor = l->valor;
        r->dir = fromListAux (l->prox, len - len/2 -1 );             
    }
    return r;
}

ABin fromList (LInt l) 
{
    int len = compList (l);
    return fromListAux (l, len);
}

/*• LInt inorderL (ABin a) que produz uma lista ligada ordenada a partir de uma árvore
binária de procura.
De forma a tornar essa função mais eficiente pode definir uma função auxiliar LInt inorderLAux
(ABin a, LInt *end) que coloca em *end o endereço do último elemento da lista produzida.*/


LInt inorderLAux (ABin a, LInt *end)
{
    LInt novo = NULL, r = NULL, aux = NULL;
    *end = NULL;
    if (a)
    {
        novo = malloc (sizeof (struct lista));
        novo->valor = a->valor;
        novo->prox = inorderLAux (a->dir, end);
        r = inorderLAux (a->esq, &aux);
        if (!*end)
            *end = novo;
        if (r)
            aux->prox = novo;
        else
            r = novo;
    }
    return r;
}


LInt inorderL (ABin a) 
{
    LInt end = NULL;
    return inorderLAux(a, &end);
}

/*Alternativamente pode definir uma função LInt inorderLAcc (ABin a, LInt l) que acres-
centa no final da lista l o resultado de percorrer a árvore.*/

LInt inorderLAcc (ABin a, LInt l)
{
    LInt *ptr =  &l;
    if (a)
    {
        l = inorderLAcc (a->esq, l);
        while (*ptr)
            ptr = &((*ptr)->prox);
        *ptr = malloc (sizeof (struct lista));
        (*ptr)->valor = a->valor;
        (*ptr)->prox = NULL;
        l = inorderLAcc (a->dir, l);
    }
    return l;
}

LInt inorderLAlt (ABin a)
{
    return inorderLAcc (a, NULL);
}


LInt ListfromArray (int v[], int N) // cria LInt apartir de array
{
    LInt r = NULL;
    LInt * ptr = &r;
    int i = 0;
    while (i<N)
    {
        *ptr = malloc (sizeof (struct lista));
        (*ptr)->valor = v[i];
        (*ptr)->prox = NULL;
        ptr = &((*ptr)->prox);
        i++;
    }
    return r;
}

void showL (LInt l) // imprime LInt
{
    while (l)
    {
        printf ("%d ", l->valor);
        l = l->prox;
    }
}

void showAB (ABin a) // imprime ABin
{
    if (a)
    {
        showAB (a->esq);
        printf ("%d ", a->valor);
        showAB (a->dir);
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
    DLInt aux = NULL, novo = NULL, r = NULL;
    if (a)
    {
        aux = inorderDL (a->dir);
        novo = malloc (sizeof (struct dlista));
        novo->valor = a->valor;
        novo->prox = aux;
        novo->ant = NULL;
        if (aux)
            aux->ant = novo;
        r = inorderDL (a->esq);
        if (r)
        {
            aux = r;
            while (aux->prox)
                aux = aux->prox;
            aux->prox = novo;
            novo->ant = aux;
        }
        else
            r = novo;     
    }
    return r;
}

void showDL (DLInt d)
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

