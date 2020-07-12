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

// Nota: neste guião tive que alterar o campo "nome" na estrutura aluno de "*nome" para "nome[30]" de forma a conseguir resolver as alineas 2 e 3.


/*Relembre o problema proposto na Ficha 7 sobre a gestão da informação sobre alunos.
Uma forma de representar a informação de cada aluno definiu-se o tipo Aluno.
Considere agora que os vários alunos são organizados numa
árvore binária de procura, ordenada pelo número do aluno (otipo Turma).*/

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
} fTurma;

FILE * abreF (char * nome)  // para utilizar as funções abaixo, o ficheiro deve ser aberto com esta função.
{
    FILE * fp = fopen (nome, "r+");
    if (!fp)
    {
        fp = fopen (nome, "w+");
        long x = 0L;
        fwrite (&x, sizeof(long), 1, fp);
    }
    return fp;
}

long acrescentaAlunoF (FILE *fp, Aluno a) // acresenta aluno numa árvore binária de procura implementada directamente num ficheiro. 
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
            if (buf.a.numero < a.numero)
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


long procuraF (FILE *fp, int numero) // procura aluno numa árvore binária de procura impelmentada directamente num ficheiro. 
{
    fTurma buf;
    long lugar;
    fseek (fp, 0L, SEEK_SET);
    fread (&lugar, sizeof (long), 1, fp);
    
    while (lugar != 0 && buf.a.numero != numero)
    {
        fseek (fp, lugar, SEEK_SET);
        fread (&buf, sizeof(struct farv), 1, fp);
        if (buf.a.numero > numero)
            lugar = buf.esq;
        else
            if (buf.a.numero < numero)
                lugar = buf.dir;
    }
    if (lugar != 0)
        return lugar;
    else
        return 0;   
}

int aprovadosFAux (FILE *fp, long lugar) // função auxiliar para calcular o numero de alunos aprovados numa árvore binária de procura implementada directamente num ficheiro. 
{
    int r = 0;
    fTurma buf;
    if (lugar != 0)
    {
        fseek (fp, lugar, SEEK_SET);
        fread (&buf, sizeof (struct farv), 1, fp);
        if (buf.a.nota >= 10)
            r++;
        r += aprovadosFAux (fp, buf.esq);
        r += aprovadosFAux (fp, buf.dir);
    }
    return r;
}

int aprovadosF (FILE *fp) // calcula o numero de alunos aprovados numa árvore binária de procura implementada directamente num ficheiro. 
{
    int r = 0;
    long lugar;
    fseek (fp, 0L, SEEK_SET);
    fread (&lugar, sizeof (long), 1, fp);
    r = aprovadosFAux (fp, lugar);

    return r;    

}


void printTurmaFAux (FILE *fp, long lugar) // função auxiliar para imprimir os alunos de uma turma guardada numa árvore binária de procura, implementada directamente num ficheiro.
{
    
    fTurma buf;
    if (lugar)
    {
        fseek (fp, lugar, SEEK_SET);
        fread (&buf, sizeof (struct farv), 1, fp);
        printTurmaFAux (fp,buf.esq );
        printf ("%d :: %s :: %d\n", buf.a.numero, buf.a.nome, buf.a.nota);
        printTurmaFAux (fp,buf.dir);
    }
}

void printTurmaF (FILE *fp) // imprime os alunos de uma turma guardada numa árvore binária de procura, implementada directamente num ficheiro.
{
    long lugar;
    fseek (fp, 0L, SEEK_SET);
    fread (&lugar, sizeof (long), 1, fp);
    printTurmaFAux (fp, lugar);    
}

