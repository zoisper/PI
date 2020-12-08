#include <stdio.h>

void swap (int * a, int * b) // troca o valor entre dois inteiros
{
    int aux;
    aux = *a;
    *a = *b;
    *b = aux;
}

void quickSort (int v[], int N)
{
    int i = 1, j = N-1;
    if (N>1)
    {
        while (i<j)
        {
            while (v[i]<v[0])
                i++;
            while (v[j] > v[0])
                j--;
            if (i<j)
                swap (v+i, v+j);
        }
            if (v[j] < v[0])
                swap (v, v+j);
            quickSort (v, j);
            quickSort (v+j+1, N-j-1);
    }   
}

void merge (int r[], int a[], int b[], int na,  int nb)  // faz merge entre dois arrays ordenados
{
    int i = 0, j = 0, k = 0;
    while (k < na + nb)
    {
        if (i >= na)
            r[k++] = b[j++];
        else 
            if (j >= nb)
                r[k++] = a[i++];
            else 
                if (a[i] > b[j])
                    r[k++] = b[j++];
                else
                    r[k++] = a[i++];             
    }    
}

void parte (int v[], int N, int a [], int b[]) // parte o array em dois arrays passados por parametro
{
    int i = 0, j = 0;
    while (i < N/2)
    {
        a[i] = v[i];
        i++;
    }
    while (i<N)
        b[j++] = v[i++];
}

void mergeSort (int v[], int N)
{
    if (N>1)
    {
        int a[N/2];
        int b[N - N/2];
        parte (v, N, a, b);
        mergeSort (a, N/2);
        mergeSort (b, N - N/2);
        merge (v, a, b,  N/2, N - N/2);
    }
}

void showArray (int v[], int N) // imprime array
{
    int i;
    for (i=0; i<N; i++)
        printf ("%d ", v[i]);
}
