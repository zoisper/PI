
#include <stdio.h>
#define SPACE ' '
#define SML '*'

void main ()
{

int tamanho;
printf("Insira um numero\n");
scanf ("%d", &tamanho);

int c = 1;
for (int i = 0; i < tamanho; tamanho--)
{
	for (int a = tamanho -1; a > 0; a--)
		putchar (SPACE);
	
	for (int b = 0; b < c; b++)
		putchar ('*');
	c += 2;
	putchar ('\n');
}




}