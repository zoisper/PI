#ifndef _LLINT
#define _LLINT

typedef struct slist *LInt;
typedef struct slist {
int valor;
LInt prox;
} Nodo;

void showLInt(LInt l);
void showLIntRec(LInt l);
LInt cons (LInt l, int x);
LInt tail (LInt l);
LInt init (LInt l);
LInt snoc (LInt l, int x);
LInt concat (LInt a, LInt b);

#endif