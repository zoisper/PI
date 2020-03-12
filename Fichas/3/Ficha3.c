#include <stdio.h>




//Exercicio 1
/*
a)
1, 1, 4  
2, 2, 6	
3, 3, 8
4, 4, 10
5, 5, 12

b) 
13
*/

//Exercicio 2

void e1 ()
{
	printf("\na)\n1 1 4\n2 2 6\n3 3 8\n4 4 10\n5 5 12\n\nb)\n13\n");
}

void swapM (int *x, int *y)
{
	int c;
	c = *x;
	*x = *y;
	*y = c;
}

void e2 ()
{
	int a , b;
	printf("Introduza Um Numero\n");
	scanf ("%d", &a);
	printf("Introduza Um Numero\n");
	scanf ("%d", &b);
	printf("Antes x = %d e y = %d\n",a,b );
	swapM (&a, &b);
	printf ("Depois x = %d y = %d\n", a,b);

}

void swap (int v[], int i, int j)
{
	int c;
	c = v[i];
	v[i] = v[j];
	v[j] = c;

}

void e3()
{
	int n, a, b, i;
	printf("Digite o tamanho do vetor\n");
	scanf ("%d", &n);
	int v[n];
	printf("Coloque %d valores no vetor\n", n );
	for (i=0; i < n; i++)
		scanf("%d", &v[i]);
	printf("Escolha uma posição entre 1 e %d\n",n );
	scanf ("%d", &a);
	printf("Escolha uma posição entre 0 e %d\n",n );
	scanf ("%d", &b);
	a--, b--;
	printf("Antes\n");
	for (i=0; i < n; i++)
		printf("%d\n", v[i]);
	swap (v, a, b);
	printf("Depois da Troca\n");
	for (i=0; i < n; i++)
		printf("%d\n", v[i]);
}

int soma (int v[], int N)
{
	int soma, i;
	soma = 0;
	for (i=0; i<N; i++)
	{
		soma += v[i];
	}
	return soma;
}

void e4 ()
{
	int n, i;
	printf("Digite o tamanho do vetor\n");
	scanf ("%d", &n);
	int v[n];
	printf("Coloque %d valores no vetor\n", n );
	for (i=0; i < n; i++)
		scanf("%d", &v[i]);
	printf("Soma = %d\n", soma(v,n));
}

int maximum (int v[], int N, int *m)
{
	int i, c;
	*m = v[0];
	for (i=1; i<N; i++)
		if (v[i] > *m)
			*m = v[i];
	return 0;
}

void e5 ()
{
	int i, n, m;
	printf("Coloque Um valor em m\n");
	scanf("%d", &m);
	printf("Digite o tamanho do vetor\n");
	scanf ("%d", &n);
	int v[n];
	printf("Coloque %d valores no vetor\n", n );
	for (i=0; i < n; i++)
		scanf("%d", &v[i]);
	maximum (v, n, &m);
	printf("m = %d\n", m);
}

void quadrados (int q[], int N)
{
	int i;
	for(i=1; i<=N; i++)
		q[i-1] = i*i;
} 

void e6()
{
	int i, n;
	printf("Digite um numero Natural\n");
	scanf ("%d", &n);
	int v[n];
	quadrados (v, n);
	printf("\n");
	for(i=0; i<n; i++)
		printf("%d\n", v[i]);
}

void pascal (int v[], int N)
{
	if (N==1)
		v[0] = 1;
	else 
	{
		int i;
		int x[N-1];
		pascal (x, N-1);
		
		for (i=1; i < N-1; i++)
			v[i] = x[i-1] + x[i];
		v[0] = 1;
		v[N-1] = 1;
	}
}

void e7()
{
	int i, n;
	printf("Digite o nº da linha do Triangulo de Pascal\n");
	scanf ("%d", &n);
	int v[n];
	pascal (v, n);
	printf("\n");
	for(i=0; i<n; i++)
		printf("%d ", v[i]);
	printf("\n");	
}


int main ()
{

int option = -1;

do
{
	printf("Escolha Um Exercicio\n");
	scanf ( "%d", &option);
}
while (option <= 0 || option > 7);

switch (option)
{
	case 1 : e1(); break;
	case 2 : e2(); break;
	case 3 : e3(); break;
	case 4 : e4(); break;
	case 5 : e5(); break;
	case 6 : e6(); break;
	case 7 : e7(); break;

}

return 0;


}