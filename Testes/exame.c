#include <stdio.h>
#include <stdlib.h>

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


