#include <stdio.h>
#include <stdlib.h>

//Parte A

typedef struct slist {
int valor;
struct slist *prox;
} *LInt;


/*1. Defina uma função int bitsUm (unsigned int n) que calcula o número de bits iguais a 1 usados na
representação binária de um dado número n.*/

int bitsUm (unsigned int x)
{
    int r=0;
    while (x>0)
    {
        if(x%2 == 1 )
            r++;
        x /= 2;
    }
    return r;
}

/*2. Defina uma função int limpaEspacos (char t[]) que elimina repetições sucessivas de espaços por
um único espaço. A função deve retornar o comprimento da string resultante.*/

int limpaEspacos (char texto[]) 
{
    int i, r;
    
    for(i=0, r=0; texto[i]; i++)
        if (texto[i]!= ' ' || texto[i+1]!= ' ')
            texto[r++] = texto[i];
            
        texto[r]= '\0';
    
    return r;
}

/*3. Defina uma função int dumpL (LInt l, int v[], int N) que, dada uma lista l, preenche o array v
com os elementos da lista. A função deverá preencher no máximo N elementos e retornar o número de
elementos preenchidos.*/

int dumpL (LInt l, int v[], int N)
{
    int r = 0;
   
    if (l && N>0)
    {
        *v = l->valor;
        r++;
        
        l = l->prox;
        r += dumpL (l, v+1, N-1);        
    }   
    return r;
}

/*4. Defina uma função LInt parte (LInt l) que parte uma lista l em duas: na lista l ficam apenas os
elementos das posições ı́mpares; na lista resultante ficam os restantes elementos.
Assim, se a lista x tiver os elementos {12,22,32,42,52,62} a chamada y = parte (x), coloca na lista
y os elementos {22,42,62} ficando em x apenas os elementos {12,32,52}.*/

LInt parte (LInt l)
{
    LInt r = NULL, aux = l;
    LInt * ptr = &r;
    
    while (aux)
    {
        *ptr = aux->prox;
        
        if (*ptr)
            {
                aux->prox = (*ptr)->prox;
                (*ptr)->prox = NULL;
                ptr = &((*ptr)->prox);
            }
        
        aux = aux->prox;
    }       
    return r;
}
