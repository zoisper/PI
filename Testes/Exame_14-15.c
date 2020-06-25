#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Parte A

/*Considere as seguintes definições de tipos:*/

typedef struct slist {
int valor;
struct slist *prox;
} *LInt;


/*1. Defina uma função int bitsUm (unsigned int n) que calcula o número de bits iguais a 1 usados na
representação binária de um dado número n.*/

int bitsUm (unsigned int x)
{
    int r=0;
    while (x>0)
    {
        if(x%2 == 1 )
            r++;
        x /= 2;
    }
    return r;
}

/*2. Defina uma função int limpaEspacos (char t[]) que elimina repetições sucessivas de espaços por
um único espaço. A função deve retornar o comprimento da string resultante.*/

int limpaEspacos (char texto[]) 
{
    int i, r;
    
    for(i=0, r=0; texto[i]; i++)
        if (texto[i]!= ' ' || texto[i+1]!= ' ')
            texto[r++] = texto[i];
            
        texto[r]= '\0';
    
    return r;
}

/*3. Defina uma função int dumpL (LInt l, int v[], int N) que, dada uma lista l, preenche o array v
com os elementos da lista. A função deverá preencher no máximo N elementos e retornar o número de
elementos preenchidos.*/

int dumpL (LInt l, int v[], int N)
{
    int r = 0;
   
    if (l && N>0)
    {
        *v = l->valor;
        r++;
        
        l = l->prox;
        r += dumpL (l, v+1, N-1);        
    }   
    return r;
}

/*4. Defina uma função LInt parte (LInt l) que parte uma lista l em duas: na lista l ficam apenas os
elementos das posições ı́mpares; na lista resultante ficam os restantes elementos.
Assim, se a lista x tiver os elementos {12,22,32,42,52,62} a chamada y = parte (x), coloca na lista
y os elementos {22,42,62} ficando em x apenas os elementos {12,32,52}.*/

LInt parte (LInt l)
{
    LInt r = NULL, aux = l;
    LInt * ptr = &r;
    
    while (aux)
    {
        *ptr = aux->prox;
        
        if (*ptr)
            {
                aux->prox = (*ptr)->prox;
                (*ptr)->prox = NULL;
                ptr = &((*ptr)->prox);
            }
        
        aux = aux->prox;
    }       
    return r;
}

// Parte B

/*Considere a seguinte definição para armazenar a informação sobre os alunos de uma turma numa árvore
binária de procura ordenada pelo número do aluno:*/

typedef struct nodo {
char nome[50] ;
int numero;
int nota; // >=0, <=20
struct nodo *esq , *dir ;
} *Alunos ;


Alunos addAluno (Alunos a, struct nodo novo)  ///// acresenta um novo nodo a Alunos
{
    
    
    if (a)
    {
        if(a->numero > novo.numero )
            a->esq = addAluno (a->esq, novo);
        else
            if (a->numero < novo.numero)
                a->dir = addAluno (a->dir, novo);
    }
    else
    {
        a = malloc (sizeof (struct nodo));
        a->numero = novo.numero;
        strcpy(a->nome, novo.nome);
        a->nota = novo.nota;
        a->esq = NULL;
        a->dir = NULL; 
    }
    
    return a;
} 

void formatAluno (Alunos a, int size) /// imprime formatado
{
    int len = strlen (a->nome);
    int i = size/5;
    size -= len;
    
    printf ("%d", a->numero);
    for ( ; i>=0; i--)
        putchar (' ');
    
    printf ("%s", a->nome);
    for (i=0; i<size; i++)
        putchar (' ');

    printf ("%d", a->nota);
    
     
}
void showAlunos (Alunos a) /// Imprime os alunos armazenados na estrutura Alunos
{
    if (a)
    {
        showAlunos (a->esq);
        formatAluno (a, 9);
        putchar ('\n');
        showAlunos (a->dir);
    }
}


/*1. Defina uma função int fnotas (Alunos a, int notas [21]) que preenche o array notas com a
frequência das notas da turma (por exemplo, em notas[12] deve ser colocado o número de alunos que
tiveram nota 12). A função deverá retornar o número de alunos da turma.*/

int fnotasAux (Alunos a, int notas [21])
{
    int r = 0;
    if(a)
    {
        notas[a->nota]++;
        r++;
        r += fnotasAux (a->esq, notas);
        r += fnotasAux (a->dir, notas);
    }

    return r;
}

int fnotas (Alunos a, int notas [21])
{
    int r = 0, i =0;
    
    while (i<21)
        notas[i++] = 0;
    
    r = fnotasAux(a, notas);
    
    return r;
}

void showfnotas (int v[], int N)  /// imprime array com frequencia das notas da turma
{
    int i = 0;
    while (i<N)
    {
        printf ("Nota: %.2d  Nº Alunos: %.2d\n", i, v[i]);
        i++;
    }
}

/*2. Defina uma função int rankAluno (Alunos a, int numero, int fnotas[21]) que, dada uma turma,
a frequência de notas (tal como calculado na alı́nea anterior) e o número de um aluno da turma, calcula
o rank de um dado aluno numa turma. Um aluno tem rank N sse existirem N-1 alunos com nota
superior.
Sugestão: Comece por definir uma função int rankNota (int nota, int fnotas[21]) que, dada
uma nota e a frequência de notas calcula o rank dessa nota.*/

int rankNota (int nota, int fnotas[21])
{
    int i = 20, r = 1;
    while (i>nota)
    {
        r += fnotas[i];
        i--;
    }

    return r;
}

int rankAluno (Alunos a, int numero, int fnotas[21])
{
    int r = 0;
    if (a)
    {
        if (a->numero == numero)
            r = rankNota (a->nota, fnotas);
        else
            if (a->numero > numero)
                r = rankAluno (a->esq, numero, fnotas);
            else 
                r = rankAluno (a->dir, numero, fnotas);
    }

    return r;
}












int main ()
{
    struct nodo Pedro = {"Pedro", 5, 12};
    struct nodo Maria = {"Maria", 3, 17};
    struct nodo Tiago = {"Tiago", 8, 14};
    struct nodo Teresa = {"Teresa", 7, 15};
    struct nodo Vicente = {"Vicente", 9, 15};
    Alunos a = NULL;
    a = addAluno (a, Pedro);
    a = addAluno (a, Maria);
    a = addAluno (a, Teresa);
    a = addAluno (a, Tiago);
    a = addAluno (a, Vicente);

    showAlunos (a);
    putchar ('\n');

    int notas[21];

    fnotas (a, notas);
    showfnotas (notas, 21);
    putchar ('\n');

    int rank = rankAluno (a, 7, notas);
    printf("%d", rank);


    
    return 0;
}
