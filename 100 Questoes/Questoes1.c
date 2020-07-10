/*1. Defina um programa que lê (usando a função scanf uma sequência de números inteiros ter-
minada com o número 0 e imprime no ecran o maior elemento da sequência.*/

#include <stdio.h>

int main ()

{

  int var, maior = 0;

  printf("Introduza um Numero\n");
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

/*2. Defina um programa que lê (usando a função scanf uma sequência de números inteiros ter-
minada com o número 0 e imprime no ecran a média da sequência.*/

#include <stdio.h>

int main ()
{

  int var = 1, n = 0 ;
  float  ac = 0;

  while ( var != 0)
  {
    scanf ("%d", &var);
    
    n++;

    ac = ac + var;
  }
  
  n--;
  ac != n;
  printf ("%.2f", ac);

return 0;

}



/*3. Defina um programa que lê (usando a função scanf uma sequência de números inteiros ter-
minada com o número 0 e imprime no ecran o segundo maior elemento.*/

#include <stdio.h>

int main ()

{
  int maior = 0, segundo = 0, aux=1;

  while (aux != 0)
  {
    scanf ("%d", &aux);
    if (aux > maior)
    {
      segundo = maior;
      maior = aux;
    }
    else
    {
      if (aux > segundo)
        segundo = aux;
  }
}



printf("%d\n", segundo );

return 0;

}


/*4. Defina uma função int bitsUm (unsigned int n) que calcula o número de bits iguais a 1
usados na representação binária de um dado número n. (https://codeboard.io/projects/
13548)*/
int bitsUm (unsigned int x)
{
	int r=0;
    while (x!=0)
    {
    	if (x%2 == 1)
      		r++;
		x /=2;       
    }
    return r;
}

/*5. Defina uma função int trailingZ (unsigned int n) que calcula o número de bits a 0 no
final da representação binária de um número (i.e., o expoente da maior potência de 2 que é
divisor desse número). (https://codeboard.io/projects/13549)*/
int trailingZ (unsigned int n)
 {
	int r;
	if (n==0)
		return 32;
	for(r=0; n%2==0; n/=2 )
    	r++;
	return r;   
}

/*6. Defina uma função int qDig (unsigned int n) que calcula o número de dı́gitos necessários
para escrever o inteiro n em base decimal. Por exemplo, qDig (440) deve retornar 3. (https:
//codeboard.io/projects/13583)*/

int qDig (int n) 
{
	int i ;
	for ( i = 1; n/10 >0; i++)
		n /= 10;
    return i;    
}

/*7. Apresente uma definição da função pré-definida em C char *strcat (char s1[], char
s2[]) que concatena a string s2 a s1 (retornando o endereço da primeira). (https://
codeboard.io/projects/14490)*/

char *mystrcat(char s1[], char s2[]) 
{
   int i,j;
   for (i=0; s1[i] != '\0'; i++)
		;
    for (j=0; s1[i] = s2[j]; i++, j++ )
        ;    
	return s1;
}

/*8. Apresente uma definição da função pré-definida em C char *strcpy (char *dest, char
source[]) que copia a string source para dest retornando o valor desta última. (https:
//codeboard.io/projects/14491)*/

char *mystrcpy(char s1[], char s2[])
{
    int i;
    for (i=0; s1[i]=s2[i]; i++)
            ;
    return s1;
}



/*9. Apresente uma definição da função pré-definida em C int strcmp (char s1[], char s2[])
que compara (lexicograficamente) duas strings. O resultado deverá ser
• 0 se as strings forem iguais
• <0 se s1 < s2
• >0 se s1 > s2
(https://codeboard.io/projects/14492)*/

int mystrcmp(char s1[], char s2[]) 
{
    int i;
    for (i=0; s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0'; i++); 
    
    return s1[i] - s2[i];
}

/*10. Apresente uma definição da função pré-definida em C char *strstr (char s1[], char
s2[]) que determina a posição onde a string s2 ocorre em s1. A função deverá retornar
NULL caso s2 não ocorra em s1. (https://codeboard.io/projects/14493)*/

char *mystrstr (char s1[], char s2[]) 
{
    int i, h, j;
    if (s2[0] == '\0')
    	return s1;
    for (i=0; s1[i] != '\0'; i++ )
        for (j=0, h =i; s2[j] == s1[h]; j++, h++)
            if (s2[j+1] =='\0')
                return (s1+i);
    return NULL;
}

/*11. Defina uma função void strrev (char s[]) que inverte uma string. (https://codeboard.
io/projects/14494)*/

void strrev (char s[]) 
{
	int i, len, c;
    for (len=0; s[len] != '\0'; len++)
            ;
    for (i=0, len--; i < len; i++, len--)
    {              
    	c = s[i];
        s[i] = s[len];
        s[len] = c;
    }
}


/*12. Defina uma função void strnoV (char s[]) que retira todas as vogais de uma string.
(https://codeboard.io/projects/13661)*/

void strnoV (char t[])
{
	int i, h;
    for ( i=0, h=0; t[i] != '\0'; i++)
    {
    	if (t[i] != 'a' && t[i] != 'e' && t[i] != 'i' && t[i] != 'o' && t[i] != 'u' &&
            t[i] != 'A' && t[i] != 'E' && t[i] != 'I' && t[i] != 'O' && t[i] != 'U' )
            t[h++] = t[i];
    }    
    t[h] = '\0';
}


/*13. Defina uma função void truncW (char t[], int n) que dado um texto t com várias palavras
(as palavras estão separadas em t por um ou mais espaços) e um inteiro n, trunca todas as
palavras de forma a terem no máximo n caracteres. Por exemplo, se a string txt contiver
"liberdade, igualdade e fraternidade", a invocação de truncW (txt, 4) deve fazer
com que passe a estar lá armazenada a string "libe igua e frat". (https://codeboard.
io/projects/13659)*/
void truncW (char t[], int n)
{
    int i, j, c;
    c = j = 0;
    for (i=0; t[i] != '\0'; i++)
    {
        if (t[i] == ' ')
            c = 0;
        else 
            c++;
        if (c <= n)
            t[j++] = t[i];               
        }
    
    t[j] = '\0';
}


/*14. Defina uma função char charMaisfreq (char s[]) que determina qual o caracter mais fre-
quente numa string. A função deverá retornar 0 no caso de s ser a string vazia. (https:
//codeboard.io/projects/14577)*/

char charMaisfreq (char s[]) 
{
    int i, j, ac, mf; 
    char letra;
    mf = 0;
    if (s[0] == '\0')
        return 0;
    for (i=0; s[i]!='\0'; i++)
    {
    	for(j=0, ac=0; s[j]!='\0'; j++)
            if (s[j] == s[i])
                ac++;
        if(ac > mf)
        {
            mf = ac;
            letra = s[i];
        }      
    }
     return letra;
}

/*15. Defina uma função int iguaisConsecutivos (char s[]) que, dada uma string s calcula o
comprimento da maior sub-string com caracteres iguais. Por exemplo, iguaisConsecutivos
("aabcccaac") deve dar como resultado 3, correspondendo à repetição "ccc". (https://
codeboard.io/projects/14578)*/

int iguaisConsecutivos (char s[])
{
    int i, j, ac, ic;
    ic = 0;
    for (i=0; s[i]!='\0'; i++)
    {
        for (j=i, ac=0; s[i]==s[j]; ac++, j++)
                ;
        if (ac > ic)
            ic = ac;
    }    
    return ic;
}

/*16. Defina uma função int difConsecutivos (char s[]) que, dada uma string s calcula o
comprimento da maior sub-string com caracteres diferentes. Por exemplo, difConsecutivos
("aabcccaac") deve dar como resultado 3, correspondendo à string "abc". (https://
codeboard.io/projects/14579)*/

int isDif (char s[], int n)
{
    int i, r = 1;
    for(i=0;i<n && r; i++)
        if (s[i]==s[n])
            r=0;
    
    return r;
}

int difConsecutivos(char s[]) 
{
    int i, j, r = 0;
    for (i=0; s[i]; i++)
    {
        for (j=0; s[j+i] && isDif (s+i,j); j++);
            if (j > r)
                r = j;
    }        
 return r;   
}

/*17. Defina uma função int maiorPrefixo (char s1 [], char s2 []) que calcula o compri-
mento do maior prefixo comum entre as duas strings. (https://codeboard.io/projects/
14580)*/
int maiorPrefixo (char s1 [], char s2 []) 
{
    int i;
    for(i=0; s1[i] && s1[i]==s2[i]; i++);
    return i;
}

/*18. Defina uma função int maiorSufixo (char s1 [], char s2 []) que calcula o compri-
mento do maior sufixo comum entre as duas strings. (https://codeboard.io/projects/
14581)*/

int maiorSufixo (char s1 [], char s2 []) 
{
    int i, j, r;
    for (i=0; s1[i]; i++);
    i--;
    for (j=0; s2[j]; j++);
    j--;
    for (r=0; i>=0 && j>=0 && s1[i]==s2[j]; i--, j--)
        r++;
    return r;
}

/*19. Defina a função int sufPref (char s1[], char s2[]) que calcula o tamanho do maior
sufixo de s1 que é um prefixo de s2. Por exemplo sufPref("batota","totalidade") deve
dar como resultado 4, uma vez que a string "tota" é um sufixo de "batota" e um prefixo de
"totalidade". (https://codeboard.io/projects/14582)*/

int sufPref (char s1[], char s2[]) 
{
    int i, j ,r = 0;
    for(i=0; s1[i] && !r; i++)
    {
      for (j=0; s1[i+j] && s2[j] && s1[i+j] == s2[j];j++);
      if (s1[i+j] == '\0' && j>r)
        r = j;      
    }
    return r;
}

/*20. Defina uma função int contaPal (char s[]) que conta as palavras de uma string. Uma
palavra é uma sequência de caracteres (diferentes de espaço) terminada por um ou mais
espaços. Assim se a string p tiver o valor "a a bb a", o resultado de contaPal (p) deve ser
4. (https://codeboard.io/projects/14583)*/

int contaPal (char s[])
{
    int i, r = 0;
    for(i=0; s[i]; i++)
      if(s[i] != ' ' && s[i] != '\n' && (s[i+1] == ' ' || s[i+1] == '\0'))
        r++;
    return r;
}

/*21. Defina uma função int contaVogais (char s[]) que retorna o número de vogais da string
s. Não se esqueça de considerar tanto maiúsculas como minúsculas. (https://codeboard.
io/projects/14585)*/

int contaVogais (char s[])
{
	int i, r = 0;
  	for(i=0; s[i]; i++)
    	if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' ||
        	s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U')
          		r++;
    return r;
}



/*22. Defina uma função int contida (char a[], char b[]) que testa se todos os caracteres da
primeira string também aparecem na segunda. Por exemplo, contida "braga" "bracara
augusta" deve retornar verdadeiro enquanto que contida "braga" "bracarense" deve re-
tornar falso. (https://codeboard.io/projects/14586)*/

int contida (char a[], char b[])
{
  	int i, j, r = 1;
  	for(i=0; a[i] && r; i++)
    	for(j=0, r=0; b[j] && !r; j++)
      		if (a[i] == b[j])
        		r = 1;  
  	return r;
}

/*23. Defina uma função int palindorome (char s[]) que testa se uma palavra é palı́ndrome,
i.e., lê-se de igual forma nos dois sentidos. (https://codeboard.io/projects/14587)*/

int palindroma (char s[])
{
  	int i, j, r = 1;
  	for(i=0; s[i]; i++);
  	i--;
  	for (j=0; j<i && r; j++, i--)
    	if (s[i] != s[j])
      	r=0;
  return r;
}

/*24. Defina uma função int remRep (char x[]) que elimina de uma string todos os caracteres
que se repetem sucessivamente deixando lá apenas uma cópia. A função deverá retornar o
comprimento da string resultante. Assim, por exemplo, ao invocarmos a função com uma
vector contendo "aaabaaabbbaaa", o vector deve passar a conter a string "ababa" e a função
deverá retornar o valor 5. (https://codeboard.io/projects/13663)*/

int remRep (char texto []) 
{
	int i, r = 0;
    for(i=0; texto[i]; i++)
    	if(texto[i] != texto [i+1])
            texto[r++] = texto[i];
    texto[r] = '\0';
    return r;
}

/*25. Defina uma função int limpaEspacos (char t[]) que elimina repetições sucessivas de espaços
por um único espaço. A função deve retornar o comprimento da string resultante. (https:
//codeboard.io/projects/13733)*/

int limpaEspacos (char texto[]) 
{
    int i, r=0;
    for(i=0; texto[i]; i++)
        if (texto [i] != ' ' || texto[i+1] != ' ')
            texto[r++] = texto[i];
    texto[r] = '\0';
    return r;
}

/*26. Defina uma função void insere (int v[], int N, int x) que insere um elemento (x) num
vector ordenado. Assuma que as N primeiras posições do vector estão ordenadas e que por
isso, após a inserção o vector terá as primeiras N+1 posições ordenadas. (https://codeboard.
io/projects/14836)
*/

void insere (int s[], int N, int x)
{
	int i, j;
	for(i=0; i<N && s[i]<x; i++);
	for(j=N; j>i; j--)
		s[j] = s[j-1];
	s[i] = x;
}

/*27.  Defina uma função void merge (int r [], int a[], int b[], int na, int nb) que, da-
dos vectores ordenados a (com na elementos) e b (com nb elementos), preenche o vector r (com
na+nb elementos) com os elementos de a e b ordenados. (https://codeboard.io/projects/
14837)
*/
void merge (int r [], int a[], int b[], int na, int nb)
{
	int i = 0, j = 0;
    while (i + j < na + nb)
    {
    	if (i >= na)
        	r[i+j] = b[j++];
     	else
        	if (j >= nb)
            	r[i+j] = a[i++];
         	else
             	if (a[i] > b[j])
                 	r[i+j] = b[j++];
             	else
                 	r[i+j] = a[i++];
    }
}


/*28. Defina uma função int crescente (int a[], int i, int j) que testa se os elementos do
vector a, entre as posições i e j (inclusivé) estão ordenados por ordem crescente. A função
deve retornar 1 ou 0 consoante o vector esteja ou não ordenado. (https://codeboard.io/
projects/14838)*/

int crescente (int a[], int i, int j)
{
	int r = 1;
    while (i<j && r)
    {
    	if (a[i] > a[i+1])
     		r = 0;
        i++;
    }       
    return r;
}


/*29. Defina uma função int retiraNeg (int v[], int N) que retira os números negativos de
um vector com N inteiros. A função deve retornar o número de elementos que não foram
retirados. (https://codeboard.io/projects/14839)*/

int retiraNeg (int v[], int N)
{
	int i, r=0;
    for(i=0; i<N; i++)
    	if (v[i] >= 0)
        	v[r++] = v[i];
    return r;
}
/*30. Defina uma função int menosFreq (int v[], int N) que recebe um vector v com N ele-
mentos ordenado por ordem crescente e retorna o menos frequente dos elementos do
vector. Se houver mais do que um elemento nessas condições deve retornar o que começa por
aparecer no ı́ndice mais baixo. (https://codeboard.io/projects/14840)*/

int menosFreq (int v[], int N)
{
	int i,j, freq = N, r = v[0];
    for (i = 0; i < N; i += j)
   	{
		for(j = 0; i + j < N && v[i] == v[i+j]; j++);
			if (j < freq)
			{
		    	freq = j;
		    	r = v[i];
			}           
    }
    return r;
}

/*31. Defina uma função int maisFreq (int v[], int N) que recebe um vector v com N elemen-
tos ordenado por ordem crescente e retorna o mais frequente dos elementos do vector.
Se houver mais do que um elemento nessas condições deve retornar o que começa por aparecer
no ı́ndice mais baixo. (https://codeboard.io/projects/14841)*/

 int maisFreq (int v[], int N)
 {
    int i, j, acc = 0, r = v[0];
    for (i=0; i<N; i += j)
    for(j=0; j + i < N && v[i+j] == v[i]; j++)
    	if (j>acc)
        {
            acc = j;
            r = v[i];
        }
    return r;
}


/*32. Defina uma função int maxCresc (int v[], int N) que calcula o comprimento da maior
sequência crescente de elementos consecutivos num vector v com N elementos. Por exemplo,
se o vector contiver 10 elementos pela seguinte ordem: 1, 2, 3, 2, 1, 4, 10, 12, 5, 4, a
função deverá retornar 4, correspondendo ao tamanho da sequência 1, 4, 10, 12. (https:
//codeboard.io/projects/14842)*/

 int maxCresc (int v[], int N) 
 {
    int i, j, r = 0;
    for(i=0; i<N; i+=j)
    {
    	for (j=0; j + i < N && v[j+i] <= v[j+i+1]; j++);
        if (++j > r)
        	r = j;    
    }
    return r;
}

 /*33. Defina uma função int elimRep (int v[], int n) que recebe um vector v com n inteiros e
elimina as repetições. A função deverá retornar o número de elementos do vector resultante.
Por exemplo, se o vector v contiver nas suas primeiras 10 posições os números 
{1, 2, 3, 2, 1, 4, 2, 4, 5, 4} a invocação elimRep (v,10) deverá retornar 5 e colocar nas 
primeiras 5 posições do vector os elementos {1,2,3,4,5}. (https://codeboard.io/projects/14843)*/

int elimRep (int v[], int N) 
{
	int i,j,k;
	for (i=0; i<N; i++)
		for (j=i+1; j<N; j++)
	    	if (v[i]==v[j])
	    	{
	      		for (k=j; k<N-1; k++)
	          		v[k] = v[k+1];
	     		j--;
	      		N--;
	      	}
	    	
	return N;
}

/* 34. Defina uma função int elimRepOrd (int v[], int n) que recebe um vector v com n in-
teiros ordenado por ordem crescente e elimina as repetições. A função deverá retornar o
número de elementos do vector resultante. (https://codeboard.io/projects/14844)*/


int elimRepOrd (int v[], int N) 
{
	int i, j;
	for(i = 0 ; i<N-1; i++)
	if(v[i] == v[i+1])
	{
	    N--;
	    for (j=i+1; j<N; j++)
	    	v[j] = v[j+1];
	    i--;
	}
	return N;
}


/*35. Defina uma função int comunsOrd (int a[], int na, int b[], int nb) que calcula quan-
tos elementos os vectores a (com na elementos) e b (com nb elementos) têm em comum. As-
suma que os vectores a e b estão ordenados por ordem crescente. (https://codeboard.io/
projects/14845)*/

 int comunsOrd (int a[], int na, int b[], int nb)
 {
 	int i=0,j=0, r = 0;
 	while (i < na && j < nb)
 	{
 		if (a[i] == b[j])
 	    {
 	    	r++;
 	    	i++;
 	    	j++;
 	    }
 	    else
 	   		if (a[i] > b[j])
 	        	j++;
 	        else
 	        	i++;
 	}
 	return r;
}

/*36. Defina uma função int comuns (int a[], int na, int b[], int nb) que calcula quantos
elementos os vectores a (com na elementos) e b (com nb elementos) têm em comum. Assuma
que os vectores a e b não estão ordenados e defina a função sem alterar os vectores. (https:
//codeboard.io/projects/14846)*/

int comuns (int a[], int na, int b[], int nb)
{
	int j,i,r=0;
      
    for (i = 0; i < na; i++)
    	for( j = 0; j < nb; j++ )
        	if (a[i] == b [j])
            {
            	r++;
                break;
            }
    return r;
}


/*37. Defina uma função int minInd (int v[], int n) que, dado um vector v com n inteiros,
retorna o ı́ndice do menor elemento do vector. (https://codeboard.io/projects/14847)*/

int minInd (int v[], int n) 
{
	int i, r = 0;
	for (i = 1; i < n; i++)
		if (v[i]<v[r])
     		r = i; 
   return r;
}

/*38. Defina uma função void somasAc (int v[], int Ac [], int N) que preenche o vector
Ac com as somas acumuladas do vector v. Por exemplo, na posição Ac[3] deve ser calcu-
lado como v[0]+v[1]+v[2]+v[3]. (https://codeboard.io/projects/14848)*/

void somasAc (int v[], int Ac [], int N)
{
  int i,j;

	for (i=0; i <N; i++)
	{
		Ac[i] = 0;
		for (j=0; j <=i; j++)
			Ac[i] += v[j];
   }
}

/*39. Defina uma função int triSup (int N, float m [N][N]) que testa se uma matriz quadra-
da é triangular superior, i.e., que todos os elementos abaixo da diagonal são zeros. (https:
//codeboard.io/projects/14849)*/

int triSup (int N, int m [N][N]) 
{
    
int i, j,r;
r=1;

for(i=0; i<N; i++)
	for(j=0; j<i; j++ )
		if (m[i][j] != 0)
			r=0;
return r;
}

/*40. Defina uma função void transposta (int N, float m [N][N]) que transforma uma ma-
triz na sua transposta. (https://codeboard.io/projects/14850)*/

void transposta (int N, float m [N][N])
{
    int i, j, float ac;
    for (i=0; i<N ;i++)
    	for (j=0; j<i; j++)
    	{
    		ac = m[i][j];
    		m[i][j] = m[j][i];
    		m[j][i] =ac;
    	}
}

/*41. Defina uma função void addTo (int N, int M, int a [N][M], int b[N][M]) que adi-
ciona a segunda matriz à primeira. (https://codeboard.io/projects/14851)*/

void addTo(int N, int M, int a [N][M], int b[N][M]) 
{
	int i, j;
	for (i = 0; i < N; i++)
		for (j=0; j<M; j++)
			a[i][j] += b[i][j];			
}		

/*42. Uma forma de representar conjuntos de ı́ndices consiste em usar um array de inteiros contendo
1 ou 0 consoante esse ı́ndice pertença ou não ao conjunto. Assim o conjunto {1, 4, 7} seria
representado por um array em que as primeiras 8 posições conteriam {0,1,0,0,1,0,0,1}.
Apresente uma definição da função int unionSet (int N, int v1[N], int v2[N], int
r[N]) que coloca no array r o resultado da união dos conjuntos v1 e v2. (https://codeboard.
io/projects/14685)*/

int unionSet (int N, int v1[N], int v2[N], int r[N])
{
	int i;
	for (i=0; i<N; i++)
		r[i] = v1[i] || v2[i];
			
}

/*43. Uma forma de representar conjuntos de ı́ndices consiste em usar um array de inteiros contendo
1 ou 0 consoante esse ı́ndice pertença ou não ao conjunto. Assim o conjunto {1, 4, 7} seria
representado por um array em que as primeiras 8 posições conteriam {0,1,0,0,1,0,0,1}.
Apresente uma definição da função int intersectSet (int N, int v1[N], int v2[N],
int r[N]) que coloca no array r o resultado da intersecção dos conjuntos v1 e v2. (https:
//codeboard.io/projects/14694)*/

int intersectSet (int N, int v1[N], int v2[N], int r[N])
{
    int i;
	for (i=0; i<N; i++)
		r[i] = v1[i] && v2[i];
}

/*47. Considere as seguintes definições para representar as posições e movimentos de um robot.
typedef enum movimento {Norte, Oeste, Sul, Este} Movimento;
typedef struct posicao {
int x, y;
} Posicao;
Defina a função Posicao posFinal (Posicao inicial, Movimento mov[], int N) que,
dada uma posição inicial e um array com N movimentos, calcula a posição final do robot depois
de efectuar essa sequência de movimentos. (https://codeboard.io/projects/73018)*/

Posicao posFinal (Posicao inicial, Movimento mov[], int N)
{
	int i;
	for(i=0; i<N; i++)
	{
		if (mov[i] == Norte)
			inicial.y++;
		if (mov[i] == Sul)
			inicial.y--;
		if (mov[i] == Este)
			inicial.x++;
		if (mov[i] == Oeste)
			inicial.x--;
	}
	return inicial;
}

/*48. Considere as seguintes definições para representar as posições e movimentos de um robot.
typedef enum movimento {Norte, Oeste, Sul, Este} Movimento;
typedef struct posicao {
int x, y;
} Posicao;
Defina a função int caminho (Posicao inicial, Posicao final, Movimento mov[], int
N) que, dadas as posições inicial e final do robot, preenche o array com os movimentos sufi-
cientes para que o robot passe de uma posição para a outra.
A função deverá preencher no máximo N elementos do array e retornar o número de elementos
preenchidos. Se não for possı́vel atingir a posição final com N movimentos, a função deverá
retornar um número negativo. (https://codeboard.io/projects/73019)*/

int caminho (Posicao inicial, Posicao final, Movimento mov[], int N)
{
	int i;
	for(i=0; i<N; i++)
	{
		if (inicial.y > final.y )
		{
			inicial.y--;
			mov[i] = Sul;
		}	
		else
			if (inicial.y < final.y )
		{
			inicial.y++;
			mov[i] = Norte;
		}
		else 
			if (inicial.x > final.x )
		{
			inicial.x--;
			mov[i] = Oeste;
		}
		else 
			if (inicial.x < final.x )
		{
			inicial.x++;
			mov[i] = Este;
		}
		else
			break;
	}
	if (inicial.x != final.x || inicial.y != inicial.y)
		return -1;
	else 
		return i;
}

/*49. Considere o seguinte tipo para representar a posição de um robot numa grelha.
typedef struct posicao {int x, y;} Posicao;
Defina a função int maisCentral (Posicao pos[], int N) que, dado um array com N
posições, determina o ı́ndice da posição que está mais perto da origem (note que as coor-
denadas de cada ponto são números inteiros). (https://codeboard.io/projects/73020)*/

int maiscentral (Posicao pos[], int N) 
{
	int i,c,r;
	c = 0;
	r = pos[0].x * pos[0].x + pos[0].y * pos[0].y;
	for(i=1; i<N; i++)
	{
		if (r > pos[i].x * pos[i].x + pos[i].y * pos[i].y)
		{
			c = i;
			r = pos[i].x * pos[i].x + pos[i].y * pos[i].y;
		}
	}

	return c;
}

/*50. Considere o seguinte tipo para representar a posição de um robot numa grelha.
typedef struct posicao {int x, y;} Posicao;
Defina a função int vizinhos (Posicao p, Posicao pos[], int N) que, dada uma posição
e um array com N posições, calcula quantas dessas posições são adjacentes à posição dada.
(https://codeboard.io/projects/73021)*/

int vizinhos (Posicao p, Posicao pos[], int N)
{
	int i,c;
	c = 0;
	for (i=0; i<N; i++)
	{
		if (p.x == pos[i].x && (p.y - pos[i].y == 1 || p.y - pos[i].y == -1))
			c++;
		if (p.y == pos[i].y && (p.x - pos[i].x == 1 || p.x - pos[i].x == -1))
			c++;
	}
	return c;

}
    