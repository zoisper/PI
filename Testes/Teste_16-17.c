
typedef struct slist {
int valor;
struct slist *prox;
} *LInt;

typedef struct nodo {
int valor;
struct nodo *esq, *dir;
} *ABin;

// Parte A

/*1. Defina uma função int limpaEspacos (char t[]) que elimina repetições sucessivas de espaços
por um único espaço. A função deve retornar o comprimento da string resultante.*/

int limpaEspacos (char texto[]) 
{
    int i, j=0;
    
    for (i=0,j=0; texto[i]; i++)
    {
        if (texto[i] != ' ' || texto[i+1]!= ' ')
            texto[j++] = texto[i];
    }
    texto[j] = '\0';
    
    return j;
}

/*2. Defina uma função void transposta (int N, float m [N][N]) que transforma uma matriz
na sua transposta.*/

void transposta (int N, float m [N][N]) 
{
	float aux ;
    int i ,j ;
    for (i=0; i<N; i++)
        for (j=0; j<i; j++)
        {
            aux = m[i][j];
            m[i][j] = m[j][i];
            m[j][i] = aux;
        }
}

/*3. Apresente uma definição da função LInt cloneL (LInt) que cria uma nova lista ligada com
os elementos pela ordem em que aparecem na lista argumento.*/

LInt cloneL (LInt l) 
{
	LInt r =NULL;
	LInt *ptr = &r;
	while (l)
	{
		*ptr = malloc (sizeof (struct slist));
		(*ptr)->valor = l->valor;
		(*ptr)->prox = NULL;
		ptr = &((*ptr)->prox);
		l = l->prox;
	}
	return r;
}


void showL (LInt l)  //// imprime uma lista ligada
{
	while (l)
	{
		printf("%d\n", l->valor );
		l = l->prox;
	}
}

LInt LIntFromArray (int v[], int N)  ////// constroi lista ligada de array
{
	LInt r = NULL;
	LInt *ptr = &r;
	int i = 0;
	while (i<N)
	{
		*ptr = malloc (sizeof (struct slist));
		(*ptr)->valor = v[i];
		(*ptr)->prox = NULL;
		ptr = &((*ptr)->prox);
		i++;
	}

	return r;

}

/*4. Defina uma função int nivelV (ABin a, int n, int v[]) que preenche o vector v com os
elementos de a que se encontram no nı́vel n.
Considere que a raı́z da árvore se encontra no nı́vel 1.
A função deverá retornar o número de posições preenchidas do array.*/

int nivelV (ABin a, int n, int v[])
{
	int r = 0;
	
	if (a)
	{
		if (n==1)
		{
			*v = a->valor;
			r++;
		}
	
		else
			if (n>1)
			{
				int e = nivelV (a->esq, n-1,v);
				int d = nivelV (a->dir, n-1, v+e);
				r = e+d;
			}
	}
	return r;
}

/*5. Defina uma função void removeMaiorA (ABin *) que remove o maior elemento de uma árvore
binária de procura.*/

void removeMaiorA (ABin *a) 
{
   ABin aux = NULL;
   if(*a)
   {
		while ((*a)->dir)
   			a = &((*a)->dir);
		
		aux = *a;
		*a = (*a)->esq;
		free(aux);
	}
}

// Parte B

#define MAXc 3 

typedef struct chunk {
int vs [MAXc];
struct chunk *prox;
} *CList;

typedef struct stackC {
CList valores;
int sp;
} StackC;





/*1. int push (StackC *s, int x) que acrescenta um ele-mento x a s. Retorna 0 em caso de sucesso.*/

int push (StackC *s, int x) 
{
	int r = 1;
	if(s->sp >= MAXc)
	{
		CList new = malloc (sizeof (struct chunk));
		if (new)
		{
			s->sp=0;
			new->vs[s->sp] = x;
			s->sp++;
			new->prox = s->valores;
			s->valores = new;
			r = 0;	
		}		  
	}
	
	else
	{
		s->valores->vs[s->sp] = x;
		s->sp++;
		r=0;
	}

return r;

}

StackC initStack ()  ///// inicia uma StackC
{
	StackC s;
	s.sp = 0;
	s.valores = malloc (sizeof (struct chunk));
	(s.valores)->prox = NULL;

	return s;
}



StackC StackCFromArray (int v[], int N) ///// cria uma StacK apartir de uma array
{
	StackC r = initStack();
	int i = 0;
	while (i<N)
	{
		push (&r, v[i]);
		i++;
	}
	return r;
}

void showS (StackC s)  //// imprime uma StackC
{
	int limite = s.sp;
	while (s.valores)
	{
		int i = 0;
		
		while (i<limite)
		{
			printf("%d\n",(s.valores)->vs[i] );
			i++;
		}
		s.valores = (s.valores)->prox;
		limite = MAXc;
	}
}

/*2. int pop (StackC *s, int *x) que remove o elemento do
topo da stack, colocando-o em *x. Retorna 0 em caso de sucesso.*/

int pop (StackC *s, int *x) 
{
	int r = 1;

	
		if (s->sp == 0 && s->valores->prox)
		{
			CList aux = s->valores;
			s->valores = s->valores->prox;
			s->sp = MAXc-1;
			*x = s->valores->vs[s->sp];
			r=0;
			free (aux);
		}
		else
			if (s->sp > 0 && s->valores)
			{
				s->sp--;
				*x = s->valores->vs[s->sp];
				r=0;
			}
		
	return r;
}

/*3. int size(StackC s) que calcula o comprimento (número
de elementos) de s.*/

int size(StackC s)
{
	int r = s.sp;
	while ((s.valores)->prox)
	{
		r += MAXc;
		s.valores = (s.valores)->prox;	
	}
	return r;
}

/*4. Usando as funções push e pop acima defina a função void reverse (StackC *s) que inverte
a ordem dos elementos de s.
Apresente o resultado de aplicar essa função à stack apresentada como exemplo.*/

void reverse (StackC *s)
{
	StackC aux = initStack ();
	int x, controlo = 0;
	while(controlo == 0)
	{
		controlo = pop (s, &x);
		if (controlo == 0)
			push (&aux, x);
	}

	*s = aux;
}

/*5. Apresente uma definição alternativa da função reverse da alı́nea anterior que reutiliza as células
da lista, i.e., que não faz quaisquer push (malloc) ou pop (free).*/

void myswitch (int *x, int *y) // troca duas variaveis
{
	int aux; 
	aux = *x;
	*x = *y;
	*y = aux;
}

int *find (StackC s, int n)   /// encontra o elemento n na StackC
{
	int len = size (s);
	int num_chunk = (len/MAXc);
	
	int local = 0;
	while (n>MAXc)
	{
		n -= MAXc;
		local++;
	}
	while (num_chunk>local)
	{
		s.valores = (s.valores)->prox;
		num_chunk--;
	}

	return &((s.valores)->vs[n-1]);

}

void reverseSMF (StackC *s)
{
	int len = size (*s);
	int i = 1;
	int *x = NULL, * y = NULL;
	while (i<len)
	{
		x = find (*s, i);
		y = find (*s, len);
		myswitch (x,y);
		i++;
		len--;

	}

}



