typedef struct lligada {
int valor;
struct lligada *prox;
} *LInt;

/*1. Apresente uma definição não recursiva da função int length (LInt) que calcula o compri-
mento de uma lista ligada. (https://codeboard.io/projects/16161).*/
int length (LInt l)
{
	int r=0;
	while (l)
    {
        l = l->prox;
        r++;
    }   
    return r;
}


/*2. Apresente uma definição não recursiva da função void freeL (LInt) que liberta o espaço
ocupado por uma lista.*/

void freeL (Lint l)
{
	while(l)
	{
		LInt aux = l;
		l = l->prox;
		free (aux);	
	}
}

/*3. Apresente uma definição não recursiva da função void imprimeL (LInt) que imprime no
ecran os elementos de uma lista (um por linha).*/
void imprimeL (LInt l)
{
	while (l)
	{
		printf("%d\n",l->valor );
		l = l->prox;
	}
}

/*4. Apresente uma definição não recursiva da função LInt reverseL (LInt) que inverte uma
lista (sem criar uma nova lista). (https://codeboard.io/projects/16243)*/

LInt inserecabeça (int x, LInt l)
{
    LInt r = malloc (sizeof(struct lligada));
    r->valor = x;
    r->prox = l;
    return r;
}

LInt reverseL (LInt l)
{
   LInt r, freed;
   freed = NULL;
   r = NULL;
   while (l)
   {
 
       r = insere (l->valor, r);
       freed = l;
       l = l->prox;
       free(freed);
   }
   
   return r;
}

