#include <stdio.h>

int main ()
{

float mymultInt (int n, float m)
{
	int x=0;
	for(;n>0;n--)
		x +=m;
	return x;

}

float r = mymultInt (8,7);

printf("%.1f\n",r);

float mymultInt2 (int n, float m)
{
	int x=0;
	for (; n >1; n/=2)
		{	
			if (n%2 == 1)
				x +=m;
	 		m *= 2;
		}
	return m;
}
	


float z = mymultInt2 (8,7);

printf("%.2f\n",z);



int mymdc (int a, int b)
{
	int r,n;
	
	for (n=1; n<=a || n<=b; n++)
	if (a%n == 0 && b%n ==0)
	 r=n;
	 return r;

}

int l = mymdc (2,10);

printf ("%d\n",l);

int mymdc2 (int a, int b)
{
	
	while (a !=0 && b!=0)
	{
		
		if (a > b)
			a -=b;
		else b -=a;

	}

	if (a == 0)
		return b;
	if (b == 0)
		return a;
}

int j = mymdc2 (10, 2);

printf("%d\n", j);

int mymdc3 (int a, int b)
{
	
	while (a !=0 && b!=0)
	{
		
		if (a > b)
			a %=b;
		else b %=a;

	}

	if (a == 0)
		return b;
	if (b == 0)
		return a;
}

int k = mymdc3 (10, 0);

printf("%d\n", k);




int myfib (int n)
{
	if (n == 2 || n==1)
		return 1;
	if (n==0)
		return 0;
	else return (myfib (n-1) + myfib(n-2));
}

int h = myfib (20);

printf("%d\n",h);


int myfib2 (int n)
{
	int z=1, u=1;
if (n==0)
	return 0;

	while (n > 2)
	{
		if (z > u)
			u +=z;
		else z+=u;
		n--;
	}

if (z > u)
return z;
else return u;

}

int p = myfib2 (3);

printf("%d\n",p);




return 0;
}
