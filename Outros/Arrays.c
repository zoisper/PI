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
    int i, j, k, r = N-1;
    if (N>0)
    {
        
    
        quickSort (v, r);
        quickSort (v+r+1, N-r-1);
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
    int v[12] = {2,5,1,7,6, 13, 0, 11, 12, 15, 100, 7};
    showArray (v, 7);
    putchar ('\n');
    quickSort (v,7);
    showArray (v, 7);
    putchar ('\n');

    return 0;
}