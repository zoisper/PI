# include <stdio.h>

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