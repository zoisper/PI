#include <stdio.h>
#include <stdlib.h>

typedef struct slist *LInt;
typedef struct slist {
int valor;
LInt prox;
} Nodo;

typedef LInt Stack;

int main ()

{

	void showL(LInt l)
	{
		while(l)
		{
			printf("%d ", l->valor);
			l = l->prox;
		}
		putchar('\n');
	}

//ex 1

//a)

	LInt a, b, c;
	a = malloc (sizeof(Nodo));
	a->valor = 10;
	b = malloc (sizeof(Nodo));
	b->valor = 5;
	c = malloc (sizeof(Nodo));
	c->valor = 15;
	c->prox = NULL;
	b->prox = c;
	a->prox = b;


	showL(a);
	putchar('\n');

//b)

//i.
	LInt cons (LInt l, int x)
	{
		LInt h = malloc (sizeof(Nodo));
		h->valor = x;
		h->prox = l;
		return h;
	}

	a = cons (a, 9);
	showL(a);
	putchar('\n');

//ii.
	LInt tail (LInt l)
	{
		LInt r = NULL;
		if (l)
		{
			r = l->prox;
			free(l);
		}
		return r;
	}

	a = tail (a);
	printf("tail\n");
	showL(a);
	putchar('\n');

//iii.
	LInt init (LInt l)
	{
		LInt b, ant;
		b = l;
		if (!b || !b->prox)
			return NULL;
		while(b && b->prox)
		{
			ant = b;
			b = b->prox;
		}
		ant->prox = NULL;
		free(b);
		return l;
	}

	a = init (a);
	showL(a);
	putchar('\n');

//iv.
	LInt snoc (LInt l, int x)
	{
		LInt b = l;
		LInt c = malloc(sizeof(Nodo));
		c->valor = x;
		c->prox = NULL;
		if (!b)
			return c;
		while (b && b->prox)
			b = b->prox;
		b->prox = c;
		return l;
	}

	a = snoc (a, 42);
	showL (a);
	putchar('\n');

//v.
	LInt concat (LInt a, LInt b)
	{
		LInt c;
		if (!a)
			return b;
		for (c = a; c->prox ; c = c->prox);
		c->prox = b;
		return a;
	}

	LInt x,y;
	x = NULL;
	y = NULL;

	int i;
	for(i=5; i>0; i--)
		x = cons(x,i);
	
	for(i=10; i>5; i--)
		y = cons(y,i);
	
	x = concat(x,y);
	showL(x);
	putchar('\n');

//ex 2

//a)
	typedef struct aluno
	{
		char nome[61];
		int numeroAluno, nota;
	}Aluno;

	typedef struct turma *Turma;

	typedef struct turma
	{
		Aluno aluno;
		Turma proxAluno;
	}NodoTurma;

	void showT (Turma t)
	{
		while (t)
		{
			printf("Nome:%s ",t->aluno.nome);
			printf("Numero:%d ",t->aluno.numeroAluno);
			printf("Nota:%d ",t->aluno.nota);
			putchar('\n');
			t = t->proxAluno;
		}
	}

	void showAluno (Aluno a)
	{
		printf("Nome:%s ",a.nome);
		printf("Numero:%d ",a.numeroAluno);
		printf("Nota:%d ",a.nota);
		putchar('\n');
	}

//b)

	Aluno a1 = {"Jorge", 1, 5};
	Aluno a2 = {"Ana", 2, 17};
	Aluno a3 = {"Rui", 3, 14};
	Aluno a4 = {"Francisco", 4, 10};
	Aluno a5 = {"Joana", 5, 7};
	Aluno a6 = {"Marta", 6, 11};

	Turma t = NULL;

	int acrescentaAluno (Turma *t, Aluno a)
	{
		Turma b,c; 
		b = malloc(sizeof(NodoTurma));
		if (!b)
			return 1;
		b->aluno = a;
		b->proxAluno = NULL;
		c = *t;
		if (!c)
		{
			*t = b;
			return 0;
		}
		while(c->proxAluno)
			c = c->proxAluno;
		c->proxAluno = b; 
		return 0;
	}

	acrescentaAluno (&t, a1);
	acrescentaAluno (&t, a2);
	acrescentaAluno (&t, a3);
	acrescentaAluno (&t, a4);
	acrescentaAluno (&t, a5);
	acrescentaAluno (&t, a6);


	showT (t);
	putchar('\n');

//c)
	Aluno *procura (Turma t, int numero)
	{
		while(t && t->aluno.numeroAluno != numero)
			t = t->proxAluno;
		if (t)
			return &t->aluno;
		else 
			return NULL;
	}

	showAluno(*procura(t,2));
	putchar('\n');

//d)
	int aprovados(Turma t)
	{
		int r = 0;
		//Turma a = t;
		while (t)
		{
			if (t->aluno.nota >= 10)
				r++;
			t = t->proxAluno;
		}
		return r;
	}

	int aprovadosRec (Turma t)
	{
		if (!t)
			return 0;
		return (t->aluno.nota >=10) + aprovadosRec(t->proxAluno);

	}

	int numero_aprovadados = aprovados(t);
	printf("Aprovados = %d\n", numero_aprovadados );
	putchar('\n');

	int numero_aprovadadosRec = aprovadosRec(t);
	printf("Aprovados = %d\n", numero_aprovadados );
	putchar('\n');

//3

	void initStack (Stack *s)
	{
		(*s) = NULL;
	}
	
	int isEmptyS (Stack *s)
	{
		if (*s)
			return 0;
		else 
			return 1;
	}
	int push (Stack *s, int x)
	{
		Stack aux = malloc (sizeof(Nodo));
		if(aux)
		{
			aux->valor = x;
			aux->prox = *s;
			*s = aux;
			return 0;
		}
		return 0;
	}
	
	
	int pop (Stack *s, int *x) 
	{
    	Stack pt;
    	if(!isEmptyS(s)) 
    	{
        	*x = (*s)->valor;
        	pt = (*s)->prox;
        	free(*s);
        	*s=pt;
        return 0;
   		} 
    	else
        	return 1;
	}
	

	int top (Stack *s, int *x)
	{
    	if(!isEmptyS(s)) 
    	{
        	*x = (*s)->valor;
        	return 0;
   		} 
    	else
        	return 1;
	}


	return 0;
}
