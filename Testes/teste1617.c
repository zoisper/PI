#include <stdio.h>
#include <stdlib.h>

typedef struct slist {
int valor;
struct slist *prox;
} *LInt;

typedef struct nodo {
int valor;
struct nodo *esq, *dir;
} *ABin;

// Parte A

/*1. Defina uma função int limpaEspacos (char t[]) que elimina repetições sucessivas de espaços
por um único espaço. A função deve retornar o comprimento da string resultante.*/

int limpaEspacos (char texto[]) 
{
    int i, j=0;
    
    for (i=0,j=0; texto[i]; i++)
    {
        if (texto[i] != ' ' || texto[i+1]!= ' ')
            texto[j++] = texto[i];
    }
    texto[j] = '\0';
    
    return j;
}

/*2. Defina uma função void transposta (int N, float m [N][N]) que transforma uma matriz
na sua transposta.*/

void transposta (int N, float m [N][N]) 
{
	float aux ;
    int i ,j ;
    for (i=0; i<N; i++)
        for (j=0; j<i; j++)
        {
            aux = m[i][j];
            m[i][j] = m[j][i];
            m[j][i] = aux;
        }
}

