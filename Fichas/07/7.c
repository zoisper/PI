#include <stdio.h>
#include <stdlib.h>

/*1. Considere a seguinte definição de um tipo para representar listas ligadas de inteiros.*/

typedef struct slist {
int valor;
struct slist * prox;
} Nodo, *LInt;

/*(a) Apresente uma sequência de instruções que coloque na variável a do tipo LInt, uma lista
com 3 elementos: 10, 5 e 15 (por esta ordem).*/

/* Resposta:
    LInt a = malloc (sizeof (Nodo));
    a->valor = 10;
    LInt b = malloc (sizeof (Nodo));
    b->valor = 5;
    LInt c = malloc (sizeof (Nodo));
    c->valor = 15;
    a->prox = b;
    b->prox = c;
    c->prox = NULL;*/

void showL (LInt l) // imprime LInt
{
    if (l)
    {
        printf ("%d ", l->valor);
        showL (l->prox);
    }
}

/*(b) Apresente definições (preferencialmente não recursivas) das seguintes funções sobre listas
ligadas:*/

/*i. LInt cons (LInt l, int x) que acrescenta um elemento no inicio da lista.*/

LInt cons (LInt l, int x)
{
    LInt r = malloc (sizeof (Nodo));
    r->valor = x;
    r->prox = l;
    return r;
}

/*ii. LInt tail (LInt l) que remove o primeiro elemento de uma lista não vazia (liber-
tando o correspondente espaço).*/

LInt tail (LInt l)
{
    LInt r = NULL;
    if (l)
    {
        r = l->prox;
        free (l);
    }
    return r;
}
/*iii. LInt init (LInt l) que remove o último elemento de uma lista não vazia (libertando
o correspondente espaço).*/

LInt init (LInt l)
{
    LInt r = l;
    LInt ant = NULL;
    if (l)
    {
        while (l->prox)
        {
            ant = l;
            l = l->prox;
        }
        free (l);
        if (ant)
            ant->prox = NULL;
        else
            r = NULL;
    }
    return r;
}

/*iv. LInt snoc (LInt l, int x) que acrescenta um elemento no fim da lista.*/

LInt snoc (LInt l, int x)
{
    LInt * ptr = &l;
    while (*ptr)
        ptr = &((*ptr)->prox);
    *ptr = malloc (sizeof (Nodo));
    (*ptr)->valor = x;
    (*ptr)->prox = NULL;
    return l;
}

/*v. LInt concat (LInt a, LInt b) que acrescenta a lista b a a, retornando o inı́cio da
lista resultante).*/

LInt concat (LInt a, LInt b)
{
    LInt * ptr = &a;
    while (*ptr)
        ptr = &((*ptr)->prox);
    *ptr = b;
    return a;
}

/*2. Para gerir a informação sobre os alunos inscritos a uma dada disciplina, é necessário armazenar
os seguintes dados:

• Nome do aluno (string com no máximo 60 caracteres)
• Número do aluno
• Nota*/

/*(a) Defina os tipos Aluno e Turma. Para o efeito considere que a informação referente aos
alunos de uma turma é armazenada numa lista ligada de alunos.*/

typedef struct aluno {
    char * nome;
    int numero;
    int nota;
} Aluno;

typedef struct turma {
    Aluno a;
    struct turma * prox;
} *Turma;

void showA (Aluno a) // imprime aluno
{
    printf ("%s :: %d :: %d\n", a.nome, a.numero, a.nota);
}

void showT (Turma t) // imprime turma
{
    while (t)
    {
        showA (t->a);
        t = t->prox;
    }
}

/*(b) Defina uma função int acrescentaAluno (Turma *t, Aluno a) que acrescenta a in-
formação de um dado aluno a uma turma. A função deverá retornar 0 se a operação
for feita com sucesso.*/

int acrescentaAluno (Turma *t, Aluno a)
{
    int r = 1;
    while (*t)
        t = &((*t)->prox);
    *t = malloc (sizeof (struct turma));
    if (*t)
    {
        (*t)->a = a;
        (*t)->prox = NULL;
        r = 0;
    }
    return r;
}

/*(c) Defina uma função Aluno *procura (Turma t, int numero) que procura o aluno com
um dado número na turma. A função deve retornar NULL se a informação desse aluno não
existir; caso exista deve retornar o endereço onde essa informação se encontra.*/

Aluno *procura (Turma t, int numero)
{
    Aluno * r = NULL;
    while (t && !r)
    {
        if (t->a.numero == numero)
            r = &(t->a);
        else
            t = t->prox;
    }
    return r;
}

/*(d) Defina uma função que determine quantos alunos obtiveram aproveitamento à disciplina
(nota final maior ou igual a 10).*/

int aprovados (Turma t)
{
    int r = 0;
    while (t)
    {
        if (t->a.nota >= 10)
            r++;
        t = t->prox;
    }
    return r;
}

