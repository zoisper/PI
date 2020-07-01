#include <stdio.h>
#include <string.h>
#include <ctype.h>


/*1. Defina uma função int minusculas (char s[]) que substitui na string s todas as
letras maiúsculas pela correspondente letra minúscula.
A função deverá retornar quantas substituições foram efectuadas.*/

int minusculas (char s[])
{
    int i = 0, r = 0;
    while (s[i])
    {
        if (isalpha (s[i]) && isupper (s[i]))
            {
                s[i] = tolower (s[i]);
                r++;
            }
        i++;
    }    
    return r;
}

/*2. Defina uma função int contalinhas (char s[]) que calcula quantas linhas tem uma
string (assuma que o caracter que separa duas linhas é ’\n’).*/

int contalinhas (char s[])
{
    int i = 0, r = 1;
    while (s[i])
    {
        if (s[i] == '\n')
            r++;
        i++;
    }
    return r;
}

/*3. Defina uma função int contaPal (char s[]) que calcula quantas palavras tem uma
string. Assuma que uma palavra é um conjunto de caracteres não brancos terminada
por um caracter branco. Use para isso a função standard (ctype.h) int isspace(int
c).*/

int contaPal (char s[])
{
    int i = 0, r = 0;
    while (s[i])
    {
        if((!isspace (s[i]) && s[i]!= '\n') && (isspace (s[i+1]) || s[i+1] == '\n' || s[i+1] == '\0'))
            r++;
        i++;
    }
    return r;
}

/*4. Defina uma função int procura (char *p, char *ps[], int N) que procura uma
string p num array de strings ps).*/

int procura (char *p, char *ps[], int N)
{
    int i=0, r = -1;

    while (i<N && r < 0)
    {
        if (strcmp (ps[i], p) == 0)
            r = i+1;
        else
            i++;
    }
    return r;
}

/*5. Considere o seguinte tipo para representar stacks de números inteiros.*/

#define MAX 100
typedef struct stack {
int sp;
int valores [MAX];
} STACK;

/*Defina as seguintes funções sobre este tipo:*/

/*(a) void initStack (STACK *s) que inicializa uma stack (passa a representar uma
stack vazia)*/

void initStack (STACK *s)
{
    s->sp = 0;
}

/*(b) int isEmptyS (STACK *s) que testa se uma stack é vazia*/

int isEmptyS (STACK *s) 
{
    return s->sp == 0;
}

/*(c) int push (STACK *s, int x) que acrescenta x ao topo de s; a função deve re-
tornar 0 se a operação fôr feita com sucesso (i.e., se a stack ainda não estiver cheia)
e 1 se a operação não fôr possı́vel (i.e., se a stack estiver cheia).*/

int push (STACK *s, int x) 
{
    int r = 1;
    if (s->sp >= 0 && s->sp < MAX)
    {
        s->valores[s->sp] = x;
        s->sp++;
        r = 0;
    }
    return r;
}

/*(d) int pop (STACK *s, int *x) que remove de uma stack o elemento que está no
topo. A função deverá colocar no endereço x o elemento removido. A função
deverá retornar 0 se a operação for possı́vel (i.e. a stack não está vazia) e 1 em
caso de erro (stack vazia).*/

int pop (STACK *s, int *x)
{
    int r = 1;
    if (s->sp > 0)
    {
        s->sp--;
        *x = s->valores[s->sp];
        r = 0;
    }
    return r;
}

/*(e) int top (STACK *s, int *x) que coloca no endereço x o elemento que está no
topo da stack (sem modificar a stack). A função deverá retornar 0 se a operação
for possı́vel (i.e. a stack não está vazia) e 1 em caso de erro (stack vazia).*/

int top (STACK *s, int *x)
{
    int r = 1;
    if (s->sp > 0)
    {
        *x = s->valores[s->sp -1];
        r = 0;
    }
    return r;
}

