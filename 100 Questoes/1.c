
/*1. Defina um programa que lê (usando a função scanf uma sequência de números inteiros ter-
minada com o número 0 e imprime no ecran o maior elemento da sequência.*/

#include <stdio.h>

int main ()

{

	int var, maior = 0;

	printf("Intorduza um Numero\n");
	scanf ("%d", &var);

	while (var != 0)
		{
			if (maior < var) 
			maior = var;

			printf("Intorduza um Numero\n");
		    scanf ("%d", &var);
		}

		printf ("%d", maior);
return 0;

}