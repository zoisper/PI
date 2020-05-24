/*2. Defina um programa que lê (usando a função scanf uma sequência de números inteiros ter-
minada com o número 0 e imprime no ecran a média da sequência.*/

#include <stdio.h>

int main ()

{

int var, n ;
float  ac;

scanf ("%d", &var);

ac = var*1.0;
n = 0;

while ( var != 0)
	{	
		scanf ("%d", &var);
		
		n++;

		ac = (ac + var);
			
	 }

printf ("%.1f", (ac/n));

return 0;

}