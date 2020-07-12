#include <stdio.h>
#include <stdlib.h>
#define MAX 100

/*1. Considere o seguinte tipo para representar queues de números inteiros.*/

typedef struct squeue {
int inicio, tamanho;
int valores [MAX];
} SQUEUE;

/*Defina as seguintes funções sobre este tipo:*/

/*(a) void initSQueue (SQUEUE *q) que inicializa uma queue (passa a representar uma queue
vazia)*/

void initSQueue (SQUEUE *q)
{
    q->inicio = 0;
    q->tamanho = 0;
}

/*(b) int isEmptySQ (SQUEUE *q) que testa se uma queue é vazia*/

int isEmptySQ (SQUEUE *q)
{
    return q->tamanho == 0;
}

/*(c) int ensqueue (SQUEUE *q, int x) que acrescenta x ao fim de q; a função deve retornar
0 se a operação fôr feita com sucesso (i.e., se a queue ainda não estiver cheia) e 1 se a
operação não fôr possı́vel (i.e., se a queue estiver cheia).*/

int ensqueue (SQUEUE *q, int x)
{
    int i, r = 1;
    if (q->tamanho < MAX)
    {
        i = (q->inicio + q->tamanho) % MAX;
        q->valores[i] = x;
        q->tamanho++;
        r = 0; 
    }
    return r;
}

/*(d) int desqueue (SQUEUE *q, int *x) que remove de uma queue o elemento que está no
inı́cio. A função deverá colocar no endereço x o elemento removido. A função deverá
retornar 0 se a operação for possı́vel (i.e. a queue não está vazia) e 1 em caso de erro
(queue vazia).*/

int desqueue (SQUEUE *q, int *x)
{
    int r = 1;
    if (q->tamanho > 0)
    {
        *x = q->valores[q->inicio];
        q->tamanho--;
        q->inicio = (q->inicio + 1) % MAX; 
        r = 0;
    }
    return r;
}

/*(e) int frontS (SQUEUE *q, int *x) que coloca no endereço x o elemento que está no inı́cio
da squeue (sem modificar a squeue). A função deverá retornar 0 se a operação for possı́vel
(i.e. a queue não está vazia) e 1 em caso de erro (queue vazia).*/

int frontS (SQUEUE *q, int *x)
{
    int r = 1;
    if(q->tamanho > 0)
    {
        *x = q->valores[q->inicio];
        r = 0;
    }   
    return r;
}

/*2. Na representação de queues sugerida na alı́nea anterior o array de valores tem um tamanho
fixo (definido pela constante MAX). Uma consequência dessa definição é o facto de a função de
inserção (enqueue) poder não ser executada por se ter excedido a capacidade da estruturas.
Uma definição alternativa consiste em não ter um array com tamanho fixo e sempre que seja
preciso mais espaço, realocar o array para um de tamanho superior (normalmente duplica-se o
tamanho do array).
Considere então a seguinte definição alternativa e adapte as funções definidas atrás para esta
nova representação.*/

typedef struct dqueue {
int size; // guarda o tamanho do array valores
int inicio, tamanho;
int *valores;
} DQUEUE;

/*Use as funções malloc e free cujo tipo está definido em stdlib.h.*/

/*(a) void initDQueue (DQUEUE *q) que inicializa uma queue (passa a representar uma queue
vazia)*/

void initDQueue (DQUEUE *q)
{
    q->size = MAX;  // valor aleatório.
    q->inicio = 0;
    q->tamanho = 0;
    q->valores = malloc (q->size * sizeof (int));
}

/*(b) int isEmptyDQ (DQUEUE *q) que testa se uma queue é vazia*/

int isEmptyDQ (DQUEUE *q)
{
    return q->tamanho == 0;
}

/*(c) int endqueue (DQUEUE *q, int x) que acrescenta x ao fim de q; a função deve retornar
0 se a operação fôr feita com sucesso (i.e., se houver memoria disponivel) e 1 se a
operação não fôr possı́vel (i.e., se não for possivel alocar mais memoria).*/

int dupDQ (DQUEUE *q) // duplica o tamanho da DQUEUE 
{
    int i, r = 1;
    int * t = malloc (2 * q->size  * sizeof (int));
    if (t)
    {
        for (i=0; i<q->size; i++)
            t[i] = q->valores[i];
        free (q->valores);
        q->valores = t;
        q->size *= 2;
        r = 0;
    }
    return r;
}

int endqueue (DQUEUE *q, int x)
{
    int i, r = 0;
    if (q->tamanho == q->size)
        r = dupDQ (q);   
    if (r == 0)
    {
        i = (q->inicio + q->tamanho % q->size);
        q->valores[i] = x;
        q->tamanho++;
    }
    return r;    
}

/*(d) int dedqueue (DQUEUE *q, int *x) que remove de uma queue o elemento que está no
inı́cio. A função deverá colocar no endereço x o elemento removido. A função deverá
retornar 0 se a operação for possı́vel (i.e. a queue não está vazia) e 1 em caso de erro
(queue vazia).*/

int dedqueue (DQUEUE *q, int *x)
{
    int r = 1;
    if (q->tamanho > 0)
    {
        *x = q->valores[q->inicio];
        q->inicio = (q->inicio + 1) % q->size;
        q->tamanho--;
        r = 0;
    }
    return r;
}

/*(e) int frontD (DQUEUE *q, int *x) que coloca no endereço x o elemento que está no inı́cio
da squeue (sem modificar a squeue). A função deverá retornar 0 se a operação for possı́vel
(i.e. a queue não está vazia) e 1 em caso de erro (queue vazia).*/

int frontD (DQUEUE *q, int *x)
{
    int r = 1;
    if (q->tamanho > 0)
    {
        *x = q->valores[q->inicio];
        r = 0;
    }
    return r;
}

