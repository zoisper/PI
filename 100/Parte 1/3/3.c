# include <stdio.h>

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
