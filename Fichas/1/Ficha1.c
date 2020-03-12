#include <stdio.h>
#define SML '#'

void quadrado (int v )

{

int i, n;
for (i = 0; i < v; i++)
	{	
		for ( n = 0; n < v; n++)
		putchar (SML);

		putchar ('\n');
	}
}

void xadrez (int v)
{

int i, n;
char s = '#';
for (i = 0; i < v; i++)
	{	
		for ( n = 0; n < v; n++)
			{
				putchar (s);
				s = (s == '#') ? '_' : '#';  
			}		
		putchar ('\n');
	} 
}



void main ()
{

int tamanho;
printf("Insira um numero\n");
scanf ("%d", &tamanho);

quadrado (tamanho);
putchar ('\n');
xadrez (tamanho);


}