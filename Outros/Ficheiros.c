#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct slist {
	char nome [100];
	struct slist *prox;
} *Lista;

Lista acrescentaL (Lista l, char *n)
{
    Lista aux = NULL;
    Lista * ptr = &l;
    while (*ptr && strcmp ((*ptr)->nome, n) < 0)
        ptr = &((*ptr)->prox);
    if(!*ptr)
    {
        *ptr = malloc (sizeof (struct slist));
        strcpy((*ptr)->nome, n);
        (*ptr)->prox = NULL;
    }
    else
        if (strcmp ((*ptr)->nome, n) != 0)
        {
            aux = malloc (sizeof (struct slist));
            strcpy(aux->nome, n);
            aux->prox = *ptr;
            *ptr = aux;
        }
    return l;  
}

void imprimeL (Lista l)
{
    while (l)
    {
        printf ("%s\n", l->nome);
        l = l->prox;
    }
}

typedef struct flist {
	char nome [100];
	long int prox;
} Nodo;

void acrescentaF (FILE *fp, char *n)
{
    long int ant = 0L, pt = 0L, endN;
    Nodo novo, buff;
    fseek(fp, 0L, SEEK_SET);
    fread (&pt, sizeof (long int), 1, fp);
    fseek(fp, pt, SEEK_SET);
    fread (&buff, sizeof (struct flist), 1, fp);
    while(pt && strcmp (buff.nome, n) < 0)
    {
        ant = pt;
        pt = buff.prox;
        fseek (fp, pt, SEEK_SET);
        fread (&buff, sizeof (struct slist), 1, fp);
    }
    if (!pt || strcmp (buff.nome, n) != 0)
    {
        strcpy (novo.nome, n);
        novo.prox = pt;
        fseek (fp, 0L, SEEK_END);
        endN = ftell(fp);
        fwrite (&novo, sizeof (struct slist), 1, fp);
        if (!ant)
        {
            fseek(fp, 0L, SEEK_SET);
            fwrite (&endN, sizeof (long int), 1, fp);
        }
        else
        {
            fseek (fp, ant, SEEK_SET);
            fread (&buff, sizeof (struct slist), 1, fp);
            buff.prox = endN;
            fseek (fp, ant, SEEK_SET);
            fwrite (&buff, sizeof (struct slist), 1, fp);
        }
    }
}

void imprimeF (FILE * fp)
{
    long int pt = 0L;
    Nodo buff;
    fseek(fp, 0L, SEEK_SET);
    fread (&pt, sizeof (long int), 1, fp);
    while (pt)
    {
        fseek (fp, pt, SEEK_SET);
        fread (&buff, sizeof (struct slist), 1, fp);
        printf ("%s\n", buff.nome);
        pt = buff.prox;
    }
}

FILE * abreF (char *nome) // usar esta função para abrir o ficheiro
{
    FILE * fp = NULL;
    long int pt = 0L;
    fp = fopen (nome, "r+");
    if(!fp)
    {
        fp = fopen (nome, "w+");
        fseek (fp, 0L, SEEK_SET);
        fwrite (&pt, sizeof (long int), 1, fp);
    }   
    return fp;
}
