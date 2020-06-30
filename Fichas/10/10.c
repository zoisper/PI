#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct aluno {
int numero;
char nome[30];
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

/*
2. Considere agora que se pretende disponibilizar funções de leitura e escrita de um elemento deste
tipo (Turma) em ficheiro.
Apresente duas alternativas para implementar tais funções:*/

/*• A escrita da árvore deve permitir que ao ler essa estrutura do ficheiro, a árvore obtida tenha
a mesma forma da árvore que foi escrita no ficheiro.*/

 void guardaTurma (Turma t, FILE *fp)
{
    if (t && fp)
    {
        fwrite (&t, sizeof (Turma), 1, fp);
        guardaTurma (t->esq, fp);
        guardaTurma (t->dir, fp);
    }
    
}

void lerTurma (Turma *t, FILE *fp)
{
    
    if (fp)
    {
        Turma aux = NULL;
        
        while (fread(&aux, sizeof (Turma), 1, fp ))
            acrescentaAluno (t, aux->a);
    }
}

/*• A escrita da árvore deverá permitir que ao ler a árvore se obtenha uma árvore equilibrada.*/

void guardaTurmaEq (Turma t, FILE *fp)
{
    if (t && fp)
    {
        guardaTurmaEq (t->esq, fp);
        fwrite (&t, sizeof (Turma), 1, fp);
        guardaTurmaEq (t->dir, fp);
    }

    
}

void lerTurmaEqAux (Turma *t, FILE *fp, int inicio, int size)
{
    if (size > 0)
    {
        Turma aux = NULL;
        fseek (fp, (inicio + (size/2)) * sizeof (Turma), SEEK_SET);
        fread (&aux, sizeof(Turma), 1, fp);
        acrescentaAluno (t, aux->a);
        lerTurmaEqAux (t, fp, 0, size/2);
        lerTurmaEqAux (t, fp, (size/2) + 1, size - size/2 -1 );

        }
}

void lerTurmaEq (Turma *t, FILE *fp)
{
    if (fp)
    {
        fseek (fp, 0, SEEK_END);
        int size = ftell(fp);
        size /= sizeof (Turma);
        lerTurmaEqAux (t, fp, 0, size);   
    }
    
}

/*3. Uma alternativa ao exposto atrás, consiste em ter a informação sobre a turma, implementada
numa árvore binária de procura directamente num ficheiro. Note que neste caso, os endereços das
sub-árvores não serão mais do que endereços de disco.
Re-implemente as funções referidas na primeira alı́nea para esta solução alternativa.*/

typedef struct farv {
Aluno a;
long int  esq, dir;
} fTurma, buf, novo;

long acrescentaAlunoF (FILE *fp, Aluno a)
{
    
    long lugar, ant = 0L, endNovo;
    fTurma buf, novo;
    fseek (fp, 0L, SEEK_SET);
    fread (&lugar, sizeof (long), 1, fp);
    
    while(lugar != 0L && buf.a.numero != a.numero)
    {
        fseek(fp, lugar, SEEK_SET);
        fread (&buf,sizeof (struct farv), 1, fp);
        ant = lugar;
        
        if (buf.a.numero > a.numero)
            lugar = buf.esq;          
        else
            lugar = buf.dir;
                
    }

    if (lugar != 0)
        return 1;
    
    else
    {
        novo.a = a;
        novo.dir = 0L;
        novo.esq = 0L;
        fseek (fp, 0L, SEEK_END);
        endNovo = ftell (fp);
        fwrite (&novo, sizeof (struct farv), 1, fp);
        
        if ( ant == 0L)
        {
            fseek (fp, 0L, SEEK_SET);
            fwrite (&endNovo, sizeof (long), 1, fp);
     
        }
        else
        {
            fseek (fp, ant, SEEK_SET);
            fread (&buf, sizeof (struct farv), 1, fp);
            if (buf.a.numero > a.numero)
                buf.esq = endNovo;
            else
                buf.dir = endNovo;
            fseek (fp, ant, SEEK_SET);
            fwrite (&buf, sizeof (struct farv), 1, fp);
        }
        
    }

    return 0;
       
        
}

void printTurmaF (FILE *fp)
{
    long lugar;
    fTurma buf;
    fseek (fp, 0L, SEEK_SET);
    fread (&lugar, sizeof (long), 1, fp);
    while (lugar)
    {
        fseek (fp, lugar, SEEK_SET);
        fread (&buf, sizeof (struct farv), 1, fp);
        printf ("%d :: %s :: %d\n", buf.a.numero, buf.a.nome, buf.a.nota);
        lugar = buf.dir;
    }
    

}


int main ()
{
    
    Aluno 
        a1 = {1011, "João Ferreira Matos", 15},
        a2 = {4037, "Juliana Batos Marques", 17},
        a3 = {8744, "Anastacia Borges Pereia", 18},
        a4 = {3544, "Antonio João Rocha", 14};

    //Turma t1 = NULL, t2 = NULL, t3 = NULL;
    //int aprov = 0;
    //

    //acrescentaAluno (&t1, a1);
    //acrescentaAluno (&t1, a2);
    //acrescentaAluno (&t1, a3);
    //acrescentaAluno (&t1, a4);

    //printf("Alunos: \n");
    //printTurma (t1);

    //printf("......................................\n");

    ////aprov = aprovados (t1);
    ////printf("Alunos Aprovados: %d\n", aprov);
    ////printf("......................................\n");

    //FILE * fp = fopen ("alunos.txt", "w");
    //guardaTurmaEq (t1, fp);
    //fclose (fp);

    //fp = fopen ("alunos.txt", "r");
    //lerTurma (&t2, fp);
    //fclose (fp);
    //
    //printf("Alunos: \n");
    //printTurma (t2);
    //printf("......................................\n");

    //fp = fopen ("alunos.txt", "r");
    //lerTurmaEq(&t3, fp);
    //fclose (fp);
    //printf("Alunos: \n");
    //printTurma (t3);
    //printf("......................................\n");

    FILE * fp = fopen ("alunos.txt", "w+");
    long x = 0L;
	fwrite (&x, sizeof(long), 1, fp);
    acrescentaAlunoF (fp, a1);
    acrescentaAlunoF (fp, a2);
    acrescentaAlunoF (fp, a3);
    acrescentaAlunoF (fp, a4);
    fclose (fp);
    fp = fopen ("alunos.txt", "r");
    printTurmaF (fp);


    return 0;
}