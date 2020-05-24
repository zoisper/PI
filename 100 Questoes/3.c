
/*3. Defina um programa que lê (usando a função scanf uma sequência de números inteiros ter-
minada com o número 0 e imprime no ecran o segundo maior elemento.*/

#include <stdio.h>

int main ()

{


int maior = 0, segundo = 0, var;


while (maior == 0)

	scanf ("%d", & maior);

while (segundo == 0)

{
	scanf ("%d", &segundo);
	
	if (segundo > maior)

		{
			var = maior;
			maior = segundo;
			segundo = var;
		}

	else segundo = var;

}



while (var !=0 )

{

	scanf ("%d", &var);
	
	if (var > maior)

		{
			segundo = maior;
			maior = var;
		}

	else 

		if (segundo < var)

			segundo = var;



}

printf("%d\n", segundo );

return 0;

}
