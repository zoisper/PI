#include <stdio.h>

/*1. Defina uma função void insere (int v[], int N, int x) que insere um elemento
(x) num vector ordenado. Assuma que as N primeiras posições do vector estão ordenadas
e que por isso, após a inserção o vector terá as primeiras N+1 posições ordenadas.*/

 void insere (int s[], int N, int x)
 {
    int i,j;
    for(i=0; i<N && s[i]< x; i++);
    for (j=N; j>i; j--)
        s[j] = s[j-1];
    s[i] = x;
}

/*2. A função em baixo usa a função insere para ordenar um vector.

void iSort (int v[], int N) 
{
    int i;
    for (i=1; (i<N); i++)
    insere (v, i, v[i]);
}

Apresente uma definição alternativa deste algoritmo sem usar a função insert.*/

void swap (int v[], int a, int b) // troca dois elementos de um array de inteiros.
{
    int aux = v[a];
    v[a] = v[b];
    v[b] = aux;
}

void iSortAlt (int v[], int N) 
{
    int i, j;
    for (i=0; i<N; i++)
        for (j=i; j<N; j++)
            if (v[j]<v[i])
                swap (v, j, i);    
}

/*3. Defina uma função int maxInd (int v[], int N) que, dado um array com N inteiros,
calcula o ı́ndice onde está o maior desses inteiros.*/

int maxInd (int v[], int N)
{
    int i, r = 0;
    for(i=1; i<N; i++)
    {
        if (v[i] > v[r])
             r = i;
    }
    return r;
}

/*4. Use a função anterior na definição de uma função de ordenação de arrays de inteiros,
que vai repetidamente calculando os maiores elementos e trocando-os com o elemento
que está na última posição.*/

void maxSort (int v[], int N)
{
    int i, j;
    for (i=0; i<N; i++)
    {
        j = maxInd (v, N-i);
        swap (v, j, N-i-1);
    }
}

/*5. Apresente uma definição alternativa do algoritmo da alı́nea anterior sem usar a função
maxInd.*/

void maxSortAlt (int v[], int N)
{
    int i, j;
    for (i=N-1; i>0; i--)
        for (j=0; j<i; j++)
            if (v[j]>v[i])
                swap (v, j, i);
}

/*6. Considere a definição a baixo da função bubble.*/

void bubble (int v[], int N) 
{
    int i;
    for (i=1;(i<N); i++)
        if (v[i-1] > v[i])
            swap (v, i-1, i);
}

/*Ilustre a execução da função com um pequeno exemplo. Verifique que após
terminar, o maior elemento do vector se encontra na última posição.*/

// A função bubble compara dois elementos consecutivos e faz swap se o primeiro for maior que o segundo.
// Ao percorrer o array todo, o maior elemento vai ficar colocado no fim do array.


/*7. Use a função bubble na definição de uma função void bubbleSort (int v[], int N)
que ordena o array v por sucessivas invocações da função bubble.*/

void bubbleSort (int v[], int N)
{
    int i;
    for (i=0; i<N; i++)
        bubble (v, N-i);
}

/*8. Uma optimização frequente da função bubbleSort consiste em detectar se o array já
está ordenado. Para isso basta que uma das passagens pelo array não efectue nenhuma
troca. Nesse caso podemos concluı́r que o array já está ordenado.
Incorpore essa optimização na função anterior.*/

int isOrd (int v[], int N) // verifica se o array esta ordenado.
{
    int r = 1, i, j;
    for(i=0; i<N && r == 1; i++)
        for (j=i+1; j<N & r == 1; j++)
            if (v[i] > v[j])
                r = 0;
    return r;
}

void bubbleSortOpt (int v[], int N)
{
    int i;
    for (i=0; i<N && isOrd(v, N) == 0; i++)
        bubble (v, N-i);
}

