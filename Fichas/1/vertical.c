
#include <stdio.h>
#define SPACE ' '
#define SML '*'

void main ()
{

int tamanho;
printf("Insira um numero\n");
scanf ("%d", &tamanho);

for (int a = 0; a < tamanho; a++ )
	{
		for ( int b = a; b >= 0; b--)
			
			putchar (SML);
			
		putchar ('\n');
	}

for (tamanho; tamanho > 1; tamanho--)
	{
		for (int c = tamanho - 1; c > 0; c--)

			putchar (SML);

		putchar ('\n');

	}

}