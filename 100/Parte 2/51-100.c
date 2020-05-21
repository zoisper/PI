#include <stdio.h>
#include <stdlib.h>

typedef struct lligada {
int valor;
struct lligada *prox;
} *LInt;



LInt fromArrayL (int v[], int N)
{
	LInt r = NULL;
	LInt *a = &r;


	for(int i = 0; i<N; i++)
	{
		*a = malloc (sizeof (struct lligada));
		(*a)->valor = v[i];
		a = &((*a)->prox);
	}
	*a = NULL;

	



	return r;

}

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

void freeL (LInt l)
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

LInt inserecabeca (int x, LInt l)
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
		r = inserecabeca (l->valor, r);
		freed = l;
		l = l->prox;
		free(freed);
	}
	return r;
}

/*5. Apresente uma definição não recursiva da função void insertOrd (LInt *, int) que in-
sere ordenadamente um elemento numa lista ordenada. (https://codeboard.io/projects/
16244)*/

void insertOrd (LInt *l, int x)
{
   LInt new = (LInt) malloc (sizeof (struct lligada));
   new->valor = x;
   new->prox = NULL;
   
   while (*l && (*l)->valor < x)
   		l = (&(*l)->prox);
    
    new->prox = *l;
    *l = new;
    
   
}

/*6. Apresente uma definição não recursiva da função int removeOneOrd (LInt *, int) que
remove um elemento de uma lista ordenada. Retorna 1 caso o elemento a remover não exista,
0 no outro caso. (https://codeboard.io/projects/16245)*/

int removeOneOrd (LInt *l, int x)
{
	while (*l && (*l)->valor != x)
    	l = (&(*l)->prox);
    if (! *l)
    	return 1;
    else 
        *l = (*l)->prox;
    
    return 0;
}

/*7. Defina uma função merge (LInt *r, LInt a, LInt b) que junta duas listas ordenadas (a
e b) numa única lista ordenada (r). (https://codeboard.io/projects/16246)*/

void merge (LInt *r, LInt l1, LInt l2){
   int controlo =  1;
    while ((l1 || l2) && controlo )
    {
        if (!l2)
            {
                *r = l1;
                controlo = 0;
            }
        else if (!l1)
            {
                *r = l2;
                controlo = 0;
            }
            
        else if (l1->valor < l2->valor)
        {
            *r = (LInt) malloc (sizeof (struct lligada));
            (*r)->valor = l1->valor;
            (*r)->prox = NULL;
            l1 = l1->prox;
        }
        else 
        {
            *r = (LInt) malloc (sizeof (struct lligada));
            (*r)->valor = l2->valor;
            (*r)->prox = NULL;
            l2 = l2->prox;
        }
        r = &((*r)->prox);
    }
}

/*8. Defina uma função void splitQS (LInt l, int x, LInt *mx, LInt *Mx) que, dada uma
lista ligada l e um inteiro x, parte a lista em duas (retornando os endereços dos primeiros
elementos da lista em *mx e *Mx): uma com os elementos de l menores do que x e a outra com
os restantes. Note que esta função não deverá criar cópias dos elementos da lista. 
(https://codeboard.io/projects/16247)*/

void splitQS (LInt l, int x, LInt *mx, LInt *Mx)
{
    while (l)
    {
        if (l->valor<x)
        {
            *mx = malloc(sizeof(struct lligada));
            (*mx)->valor = l->valor;
            mx = &((*mx)->prox);
        }
        else
        {
            *Mx = malloc(sizeof(struct lligada));
            (*Mx)->valor = l->valor;
            Mx = &((*Mx)->prox);
        }
        l=l->prox;
    }
    
}

/*9. Defina uma função LLig parteAmeio (LLig *l) que, parte uma lista não vazia *l a meio.
Se x contiver os elementos {1,2,3,4,5}, após a invocação y=parteAmeio(&x) a lista y de-
verá conter os elementos {1,2} e a lista x os restantes {3,4,5} (https://codeboard.io/
projects/17392)*/

LInt parteAmeio (LInt *l){
    int len;
    LInt aux = *l;
    LInt ant =NULL;
    LInt r=*l;
    
    for(len=0; aux;len++ )
        aux=aux->prox;
    
    aux = *l;
    
    for(len /= 2; len>0; len--)
        {
            ant = aux;
            aux=aux->prox;
        }
    
    *l = aux;
    if (ant== NULL)
        r = NULL;
    else 
        ant->prox = NULL;
    return r;
}

/*10. Apresente uma definição não recursiva da função int removeAll (LInt *, int) que remove
todas as ocorrências de um dado inteiro de uma lista, retornando o número de células removi-
das. (https://codeboard.io/projects/16249)*/

int removeAll (LInt *l, int x){
    int n = 0;
    LInt ant=NULL;
    while (*l)
    {
        if ((*l)-> valor != x)
            l = &((*l)->prox);
        else
            if ((*l)->prox)
            {
                *l = (*l)->prox;
                n++;
            }
            else 
                {
                    *l=NULL;
                    n++;
                }
    }
    
    return n;
}

/*11. Apresente uma definição da função int removeDups (LInt *) que remove os valores repeti-
dos de uma lista (deixando apenas a primeira ocorrência). (https://codeboard.io/projects/
16250)*/

int isDup (LInt l, int x, int len)  // funçao auxiliar que verifica se algum elemento é repetido
{
   
    int r=0;
    while (l && len>0)
    {
        if (l->valor == x)
            r=1;
        l = l->prox;
        len--;
    }
    return r;
}

int removeDups (LInt *l){
    int r=0;
    int len=0;
    LInt init = *l;
    
    while(*l)
    {
        if (isDup (init, (*l)->valor, len) ==0)
            {
                l = &((*l)->prox);
                len++;
            }
        else
            if ((*l)->prox)
            {
                *l = (*l)->prox;
                r++;
            }
        else
            {
                *l = NULL;
                r++;
            }

            
    }
    
    return r;
}

/*12. Apresente uma definição da função int removeMaiorL (LInt *) que remove (a primeira
ocorrência) o maior elemento de uma lista não vazia, retornando o valor desse elemento.
(https://codeboard.io/projects/16251)*/

int maior (LInt l)  //funçao auxiliar que obtem o maior elemento da lista
{
    int r = l->valor;
    
    while (l)
    {
     if (l->valor >r)
        r = l->valor;
    l = l->prox;
    }
    return r;
    
}

int removeMaiorL (LInt *l)
{
    int r = maior (*l);
    int controlo = 1;
    
    while (*l && controlo)
    {
        if((*l)->valor != r)
            l = &((*l)->prox);
        else 
            if ((*l)->prox)
            {
                *l = (*l)->prox;
                controlo = 0;
            }
        else
            {
                *l = NULL;
                controlo = 0;
            }
    }
    
    return r;
}

/*13. Apresente uma definição não recursiva da função void init (LInt *) que remove o último
elemento de uma lista não vazia (libertando o correspondente espaço). (https://codeboard.
io/projects/16252)*/

void init (LInt *l){
    LInt ant=NULL;
    while ((*l)->prox)
        {
            ant = *l;
            l = &((*l)->prox);
        }
    if (!ant)
    {
        free (*l);
        *l = NULL;
    }
    else
    {
        free(*l);
        ant->prox = NULL;   
    }   
}

/*14. Apresente uma definição não recursiva da função void appendL (LInt *, int) que acres-
centa um elemento no fim da lista. (https://codeboard.io/projects/16253)*/

void appendL (LInt *l, int x)
{
    
    LInt new = malloc(sizeof(struct lligada));
    new->valor = x;
    new->prox = NULL;
    
    if (*l == NULL)
        *l = new;
    
    else
    {
    	while((*l)->prox)
        	l = &((*l)->prox);

        (*l)->prox = new;
    }
}

/*15. Apresente uma definição da função void concatL (LInt *a, LInt b) que acrescenta a lista
b à lista *a. (https://codeboard.io/projects/16254)*/
void concatL (LInt *a, LInt b)
{
   
   if(! *a)
    *a = b;
    
    else
    {
       while ((*a)->prox)
            a = &((*a)->prox);
        (*a)->prox = b; 
    }
}

/*16. Apresente uma definição da função LInt cloneL (LInt) que cria uma nova lista ligada com
os elementos pela ordem em que aparecem na lista argumento.*/

LInt cloneL (LInt l) 
{
	LInt r = NULL;
	LInt *ptr = & r;

	while (l)
	{
		*ptr = malloc (sizeof (struct lligada));
		(*ptr)->valor = l->valor;
		ptr = &((*ptr)->prox);
		l = l->prox; 
	}

	return r;
}

/*17. Apresente uma definição não recursiva da função LInt cloneRev (LInt) que cria uma nova
lista ligada com os elementos por ordem inversa.
Por exemplo, se a lista l tiver 5 elementos com os valores {1,2,3,4,5} por esta ordem, a
invocação cloneRev(l) deve corresponder a uma nova lista com os elementos {5,4,3,2,1}
por esta ordem. (https://codeboard.io/projects/16256)*/

LInt cloneRev (LInt l)
{
    LInt a = NULL;
    LInt r = NULL;
    while (l)
    {
        a = malloc (sizeof (struct lligada));
        a->valor = l->valor;
        a->prox = r;
        r = a;
        l = l->prox;
    }
    return r;
}

/*18. Defina uma função int maximo (LInt l) que calcula qual o maior valor armazenado numa
lista não vazia. (https://codeboard.io/projects/16257)*/


int maximo (LInt l)
{
    int r = l->valor;
    
    while (l)
    {
        if (l->valor >r)
        	r = l->valor;
        l = l->prox;
    }
    return r;
}

/*19. Apresente uma definição iterativa da função int take (int n, LInt *l) que, dado um in-
teiro n e uma lista ligada de inteiros l, apaga de l todos os nodos para além do n-ésimo
(libertando o respectivo espaço). Se a lista tiver n ou menos nodos, a função não altera a
lista.
A função deve retornar o comprimento final da lista. (https://codeboard.io/projects/
16258)*/
int take (int n, LInt *l)
{
	int r=0;
	LInt aux = NULL;
    while (*l  && n>0)
        {
            aux = *l;
            l = &((*l)->prox);
            n--;
            r++;
        }
    
    if (*l && n == 0)
    {
    	aux->prox = NULL;
     	while (*l)
     	{
     		aux = *l;
     		l = &((*l)->prox);
     		free(aux);
       
     	}
    }
    
   
    return r;
}

/*20. Apresente uma definição iterativa da função int drop (int n, LInt *l) que, dado um in-
teiro n e uma lista ligada de inteiros l, apaga de l os n primeiros elementos da lista (libertando
o respectivo espaço). Se a lista tiver n ou menos nodos, a função liberta a totalidade da lista.
A função deve retornar o número de elementos removidos. (https://codeboard.io/projects/
16259)*/

int drop (int n, LInt *l)
{
   int r = 0;
   LInt aux = NULL; 
   
   while (*l && r<n)
   {
       aux = *l;
       *l = (*l)->prox;
       aux->prox = NULL;
       free (aux);
       r++;
   }
   
    return r;
}

int main ()
{

	int v[5] = {1,2,3,4,5};
	
	LInt a = fromArrayL (v, 5);
	imprimeL (a);
	
	putchar ('\n');
	
	LInt b = cloneL (a);
	imprimeL(b);
	
	putchar ('\n');

	LInt c = cloneRev (a);
	imprimeL(c);

	putchar ('\n');
	return 0;

}

