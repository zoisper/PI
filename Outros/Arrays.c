#include <stdio.h>

void swap (int * a, int * b)
{
    int aux;
    aux = *a;
    *a = *b;
    *b = aux;
}

void quickSort (int v[], int N)
{
    int i = 0, j = N-1;
    if (N>0)
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
            swap (v, v+j);
            quickSort (v, j);
            quickSort (v+j+1, N-j-1);
    }   
}

void showArray (int v[], int N)
{
    int i;
    for (i=0; i<N; i++)
        printf ("%d ", v[i]);
}

int main ()
{
    int v[5] = {1,7,-1,4,-3};
    showArray (v,5);
    putchar ('\n');
    quickSort (v,5);
    showArray (v,5);
    putchar ('\n');

    return 0;
}