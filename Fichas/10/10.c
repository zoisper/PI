#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct aluno {
int numero;
char *nome;
int nota;
} Aluno;

typedef struct arv {
Aluno a;
struct arv *esq, *dir;
} *Turma;

/*Relembre o problema proposto na Ficha 7 sobre a gestão da
informação sobre alunos.
Uma forma de representar a informação de cada aluno definiu-
se o tipo Aluno.
Considere agora que os vários alunos são organizados numa
árvore binária de procura, ordenada pelo número do aluno (o
tipo Turma).*/

//1. Defina as seguintes funções sobre este tipo de dados.



/*• int acrescentaAluno (Turma *t, Aluno a) que acrescenta a informação de um dado aluno
a uma turma. A função deverá retornar 0 se a operação for feita com sucesso.
Nos casos em que a operação não puder ser feita (por exemplo, porque já existe um aluno
com esse número na turma) deverá retornar um valor diferente de zero.*/

int acrescentaAluno (Turma *t, Aluno a)
{
    int r = 0;
    
    if (! *t)
    {
        *t = malloc (sizeof (struct arv));
        if(!t)
            return 1; 
        (*t)->a = a;
        (*t)->esq = NULL;
        (*t)->dir = NULL;
        
    }
    else
    {
        if (strcmp (a.nome, (*t)->a.nome) == 0)
            return 1;
        else
            if (strcmp (a.nome, (*t)->a.nome) < 0)
                return acrescentaAluno (&((*t)->esq), a);
            else
                return acrescentaAluno (&((*t)->dir), a);
    }

    return 0;
}



/*• Aluno *procura (Turma t, int numero) que procura o aluno com um dado número na
turma. A função deve retornar NULL se a informação desse aluno não existir; caso exista deve
retornar o endereço onde essa informação se encontra.*/

Aluno *procura (Turma t, int numero)
{
    if (!t)
        return NULL;
    
    else
        if (t->a.numero == numero)
            return &((t->a));
        else
            if (t->a.numero > numero)
                return procura (t->esq, numero);
            else
                return procura (t->dir, numero);
}




/*• int aprovados (Turma t, int numero) que determina quantos alunos obtiveram aproveita-
mento à disciplina (nota final maior ou igual a 10).*/

int aprovados (Turma t) //// alterei o cabeçalho da função porque nao fazia sentido tambem receber um int como parâmetro.
{
    int r = 0;
    
    if (t)
    {
        if (t->a.nota >= 10)
            r++;
        r+= aprovados (t->esq);
        r+= aprovados(t->dir);
    }
    
    return r;
}



/*• void printTurma (Turma t) que imprime (no ecran) a informação de todos os alunos (um
por linha).*/


void showAluno (Aluno a)
{
    printf ("%d :: %s :: %d\n", a.numero, a.nome, a.nota);
}

void printTurma (Turma t)
{
    if (t)
    {
        printTurma (t->esq);
        showAluno (t->a);
        printTurma (t->dir);
    }
}


int main ()
{
    
    Aluno 
        a1 = {1011, "João Ferreira Matos", 15},
        a2 = {4037, "Juliana Batos Marques", 17},
        a3 = {8744, "Anastacia Borges Pereia", 18},
        a4 = {3544, "Antonio João Rocha", 14};

    Turma t = NULL;
    int aprov = 0;
    

    acrescentaAluno (&t, a1);
    acrescentaAluno (&t, a2);
    acrescentaAluno (&t, a3);
    acrescentaAluno (&t, a4);

    printf("Alunos: \n");
    printTurma (t);

    printf("......................................\n");

    aprov = aprovados (t);
    printf("Alunos Aprovados: %d\n", aprov);
    printf("......................................\n");



    

    


    
    
    
    return 0;
}