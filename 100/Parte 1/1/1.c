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