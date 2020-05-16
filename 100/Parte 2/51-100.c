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
		r = inserecabeça (l->valor, r);
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

