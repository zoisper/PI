#include <stdio.h>
#include <stdlib.h>

// Parte A

/*1. Apresente uma definição da função pré-definida em C char *strcat (char s1[], char s2[]) que
concatena a string s2 a s1 (retornando o endereço da primeira).*/

char *mystrcat(char s1[], char s2[]) 
{
    int i, j;
    for (i=0; s1[i]; i++);
    
    for (j=0; s2[j]; j++)
        s1[i+j] = s2[j];
    s1[i+j] = '\0';
    
    return s1;
}


/*2. Defina uma função int remRep (char x[]) que elimina de uma string todos os caracteres que
se repetem sucessivamente deixando lá apenas uma cópia. A função deverá retornar o compri-
mento da string resultante. Assim, por exemplo, ao invocarmos a função com uma vector contendo
"aaabaaabbbaaa", o vector deve passar a conter a string "ababa" e a função deverá retornar o valor
5.*/

int remRep (char texto []) 
{
    
    int i, j;
    
    for(i=0, j=0; texto[i]; i++)
        if (texto[i] != texto[i+1])
            texto[j++] = texto[i];
    texto[j] = '\0';
    
    return j;
}


/*3. Defina uma função int nivelV (ABin a, int n, int v[]) que preenche o vector v com os elementos de a 
que se encontram no nı́vel n. Considere que a raı́z da árvore se encontra no nı́vel 1.
A função deverá retornar o número de posições preenchidas doarray.*/

typedef struct nodo {
int valor;
struct nodo *esq, *dir;
} *ABin;

int nivelV (ABin a, int n, int v[]) 
{
    int r = 0;
    int e = 0, d = 0; 
    
    if (a)
    {
        
        if (n == 1)
        {
            *v = a->valor;
            r++;
        }
    
        else
            if (n>1)
            {
                e = nivelV (a->esq, n-1, v);
                d = nivelV (a->dir, n-1, v+e);
                r = e+d;
            }
    }
    return r;
}


/*4. Apresente uma definição não recursiva da função int addOrd (ABin *a, int x) que adiciona um
elemento a uma árvore binária de procura. A função deverá retornar 1 se o elemento a inserir já existir
na árvore (e nesse caso a árvore não é alterada) ou 0 no outro caso.*/

int addOrd (ABin *a, int x) 
{
    int r = 0;
    if (*a)
    {
        if ((*a)->valor == x)
            r = 1;
        else 
            if ((*a)->valor > x)
                r = addOrd (&((*a)->esq), x);
            
            else
                r = addOrd ((&(*a)->dir), x);
    }
    else
    {
        *a = malloc (sizeof (struct nodo));
        (*a)->valor = x;
        (*a)->esq = NULL;
        (*a)->dir = NULL;
        
    }
    return r;
}

// Parte B

/*Existem domı́nios de aplicação onde se faz uso de matrizes de grandes dimensões em que a maior parte
das respectivas entradas é “0” (matrizes esparsas). Nessas condições, é normalmente preferı́vel armazenar
apenas as entradas não nulas da matriz. Para tal considere os seguintes tipos de dados:*/

typedef struct listaC {
int coluna;
float valor;
struct listaC *prox;
} *Colunas;

typedef struct listaL {
int linha;
Colunas lcol;
struct listaL *prox;
} *Mat;

/*Uma matriz é assim representada como uma lista de linhas, onde cada uma das entradas dessa lista contém
por sua vez uma lista de colunas. Considere ainda que todas as listas (Mat e Colunas) estão ordenadas
por ordem crescente do valor respectivo (linha e coluna). Além disso, todas as funções que constroem ou
modificam matrizes têm que manter essas listas ordenadas. (obs: na resolução das questões que se
seguem, defina as funções auxiliares que entenda necessárias)*/

Colunas ColformArray ( int N, float v[N])   /// cria coluna apartir de array
{
    Colunas col = NULL;
    Colunas * ptr = &col;
    int i;

    for (i=0; i<N; i++)
    {
        if (v[i] != 0)
        {
            *ptr = malloc (sizeof (struct listaC));
            (*ptr)->coluna = i+1;
            (*ptr)->valor = v[i];
            (*ptr)->prox = NULL;
            ptr = &((*ptr)->prox);
        }
        
    }


    return col;

}

void showCol (Colunas col)  /// imprime coluna
{
    while (col)
    {
        printf ("%.1f ", col->valor);
        col = col->prox;
    }
}

Mat MatfromArray (int l, int c, float v[l][c]) /// cria Mat apartir de array bidimensional
{
    Mat m = NULL;
    Mat * ptr = &m;
    Colunas col = NULL;
    int i;

    for (i=0; i<l; i++)
    {
        col = ColformArray (c, v[i]);
        if (col)
        {
            *ptr = malloc (sizeof (struct listaL));
            (*ptr)->lcol = col;
            (*ptr)->prox = NULL;
            
            (*ptr)->linha = i+1;
            ptr = &((*ptr)->prox);
        } 
    }


    return m;
}

void showMat (Mat m)  /// imprime Mat
{
    while (m)
    {
        showCol (m->lcol);
        putchar ('\n');
        m = m->prox;
    }
}



/*1. Defina a função float getEntry (Mat m, int linha, int coluna) que retorna a entrada solicitada
na matriz (obs: note que o valor das entradas que não existam em m é implicitamente 0).*/

float getEntryCol (Colunas col, int c)  /// funçao auxiliar que retorna a entrada solicitada na coluna
{
    float r = 0;
    
    if (col)
    {
        if (col->coluna == c)
            r = col->valor;
        else
            if (col->coluna < c)
                r = getEntryCol (col->prox, c);
    }

    return r;
}

float getEntry (Mat m, int linha, int coluna)
{
    float r = 0;
    
    if (m)
    {
        if (m->linha == linha)
            r = getEntryCol (m->lcol, coluna);
        else 
            if (m->linha < linha)
                r = getEntry (m->prox, linha, coluna); 
    }

    return r;
}

/*2. Defina a função void setEntry (Mat *m, int linha, int coluna, float valor) que insere uma
nova entrada na matriz (ou altera o valor dessa entrada, se ela já existir)*/

void setEntryCol (Colunas *col, int coluna, float valor)  /// insere uma nova entrada numa coluna
{
    if (*col)
    {
        Colunas ant = NULL, new = NULL;
        while (*col && (*col)->coluna < coluna)
        {
            ant = *col;
            col = &((*col)->prox);
        }
      
        if (*col && (*col)->coluna == coluna)
            if (valor !=0)
                (*col)->valor = valor;
            else 
                if (ant)
                {
                    free(ant->prox);
                    ant->prox = *col;
                }
                else 
                {
                    ant = *col;
                    *col = (*col)->prox;
                    free(ant);
                }
        
        else
            if(valor !=0)
            {
                new = malloc (sizeof (struct listaC));
                new->coluna = coluna;
                new->valor = valor;
                new->prox = *col;
                if (ant)
                    ant->prox = new;
                else
                    *col = new; 

            }
    }
    else
        if(valor !=0)
        {
            *col = malloc (sizeof (struct listaC));
            (*col)->coluna = coluna;
            (*col)->valor = valor;
            (*col)->prox = NULL; 
        }
    
}

void setEntry (Mat *m, int linha, int coluna, float valor)
{
    if (*m)
    {
        Mat ant = NULL;
        Mat new = NULL;

        while (*m && (*m)->linha < linha)
        {
            ant = *m;
            m = &((*m)->prox);
        }
        
        
        if (*m && (*m)->linha == linha)
            {
                setEntryCol (&((*m)->lcol), coluna, valor);

                if (!(*m)->lcol)
                {
                    if (ant)
                    {
                        free(ant->prox);
                        ant->prox = *m;   
                    }
                    else
                    {
                        ant = *m;
                        *m = (*m)->prox;
                        free (ant); 
                    }
                    
                }
            }
        
        else
            if(valor !=0)
            {
                new = malloc (sizeof (struct listaL));
                setEntryCol (&(new->lcol), coluna, valor);
                new->linha = linha;
                new->prox = *m;
                if (ant)
                    ant->prox = new;
                else
                    *m = new;
            
            }    
    }

    else
        if(valor !=0)
        {
            *m = malloc (sizeof (struct listaL));
            setEntryCol (&((*m)->lcol), coluna, valor);
            (*m)->linha = linha;
            (*m)->prox = NULL;

        }
    
}

/*3. Defina a função void addTo (Mat *m1, Mat m2) que adiciona à matriz *m1 a matriz m2.*/

void addToCol (Mat *m1, int linha, Colunas col) // adiciona coluna a matriz
{
    while (col)
    {
        setEntry (m1, linha, col->coluna, col->valor);
        col = col->prox;
    }
}

void addTo (Mat *m1, Mat m2)
{
    while (m2)
    {
        addToCol (m1, m2->linha, m2->lcol);
        m2 = m2->prox;
    }
}

/*4. Defina a função void transpose (Mat *m) que transpõe a matriz *m.*/

void troca (float *a, float *b)  /// faz switch entre dois floats
{
    float aux = *a;
    *a = *b;
    *b = aux;

}


int numLinhas (Mat m) /// calcula numumero de linhas da matriz
{
    int r = 0;
    while (m)
    {
        r = m->linha;
        m = m-> prox;
        
    }

    return r;
}

int compLinha (Colunas col) /// calcula comprimento de uma linha
{
    int r = 0;
    while (col)
    {
        r = col->coluna;
        col = col->prox;
    }

    return r;
}

int numColunas (Mat m) /// calcula o numero de colunas da matriz
{
    int r = 0, aux =0;
    while (m)
    {
        aux = compLinha (m->lcol);
        if (aux > r)
        r = aux;
        m = m->prox;
    }

    return r;
}

int dimMat (Mat m) ///calcula a dimensao da matriz
{
    int num_lin = numLinhas (m); 
    int num_col = numColunas (m);

    if (num_lin > num_col)
        return num_lin;
    else
        return num_col; 

}



void transpose (Mat *m)
{
    int dim = dimMat (*m);
    int l, c;
    float a, b;
    for (l=1; l<=dim; l++)
        for (c=1; c<l; c++)
        {
            a = getEntry (*m, l, c);
            b = getEntry (*m, c, l);
            
            troca (&a,&b);
            
            setEntry (m, l, c, a);
            setEntry (m, c, l, b);
        }
}

