#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include<stdlib.h>



typedef struct entrada{
	
	char *palavra;
	int ocorr;
	struct entrada *prox;
} *Palavras, Palavra;


typedef struct sDic {
	Palavras lista;
	int npal;
} Dicionario;



void initDic (Dicionario *d)
{
	d->lista = NULL;
	d->npal = 0;
}

Palavras existePal (Palavras pals, char *pal)
{
	Palavras res = NULL;
	while (pals && strcmp (pals->palavra, pal) !=0 )
		pals = pals->prox;
	if(pals && strcmp (pals->palavra, pal)==0)
		res = pals;
	return res;
}

Palavras insPal (Palavras pals, char *pal)
{
	Palavras palPtr, res;
	
	if(palPtr = existePal(pals, pal))
		{
			palPtr->ocorr++;
		res = pals;
		}
	else 
	{
		palPtr = malloc (sizeof(Palavra));
		palPtr->palavra = strdup(pal);
		palPtr->ocorr = 1;

		palPtr->prox = pals;
		res = palPtr;

	}

	return res;
}
int acrescenta (Dicionario *d, char *pal)
{
	d->lista = insPal(d->lista, pal);
	return 0;
}
void showPalavras (Palavras pals)
{
	if(pals)
	{
		printf("%s : %d\n", pals->palavra, pals->ocorr);
		showPalavras(pals->prox); 
	}
		
}
void showDic (Dicionario d)
{
	if (d.lista)
	showPalavras(d.lista);		
}
int *maisFreq (Dicionario *d, char *pal);

/*int main (int argc, char *argv[])
{
	FILE *input;
	int r=0, count=0;
	char word[100];
	if (argc==1) 
		input=stdin;
	else 
		input=fopen(argv[1],"r");
	if (input==NULL) 
		r=1;
	else 
		{
			while ((fscanf(input,"%s",word)==1))
			count ++;
			fclose (input);
			printf ("%d palavras\n", count);
		}
		return r;
}

*/

/*
    1. Tornar o buffer dinâmico;
    2. Tornar o word boundary mais inteligente.
*/

#define SIZE 80

int main()
{
    char buffer[SIZE];
    int index, c;
    Dicionario dic1;

    /* initalize variables */
    c = 1;                          /* avoid random EOF */
    index = 0;
    buffer[index] = '\0';
    initDic (&dic1);

    /* process standard input */
    while(c != EOF)
    {
        c = getchar();
        if( !isalpha(c) && c != '-' && index!=0)            /* whitespace found */
        {
            buffer[index] = '\0';   /* cap the string */
            acrescenta(&dic1, buffer);
            //puts(buffer);           /* display w/newline */
            index = 0;				/* reset index */

        }
        else if (isalpha(c) || c =='-')                       /* keep filling the buffer */
        {
            buffer[index] = c;
            index++;
        }
    }
    showDic (dic1);
    return(0);
}

