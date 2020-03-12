#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX 100

int main(){
    return 0;
}

// FICHA 4
// EXERCÍCIO 1
int minusculas(char s[]){
    int i,j=0;
    for (i=0;s[i]!='\0';i++){
        if (s[i]>64 && s[i]<91){
            s[i]=+32;
            j++;
        }
    }
    return j;
}

// EXERCICIO 2
int contaLinhas (char s[]){
    int i,linhas=1;
    for (i=0;s[i]!='\0';i++){
        if (s[i]=='\n') linhas++;
    }
    return linhas;
}

//EXERCICIO 3
int contaPal (char s[]) {
    int i,pal=0;
    char c=' ';
    for (i=0; s[i]!='\0'; i++) {
        if (isspace(s[i])==0 && c==' ') pal++;
        c=s[i];
    }
    return pal;
}

// EXERCICIO 4
int procura (char *p, char *ps[], int N){
    int i;
    for (i=0;i<N;i++){
        if (strcmp(p,ps[i])==0) return i+1;
    }
    return -1;
}

// EXERCICIO 5
typedef struct stack{
    int sp;
    int valores [MAX];
} STACK;


// 5a
void initStack(STACK *s){
    s->sp=0;
}

// 5b
int isEmptyS(STACK *s){
    int empty=0;
    if (s->sp>=0 && s->sp<MAX) empty=-1;
    return empty;
}

// 5c
int push(STACK *s, int x){
    int success=1;
    if (s->sp<MAX){
        s->valores[s->sp]=x;
        success=0;
    }
    return success;
}

// 5d
int pop(STACK *s, int *x){
    int success=1;
    if (s->sp>0){
        (s->sp)--;
        *x=s->valores[s->sp];
        success=0;
    }
    return success;
}
// 5e
int top (STACK *s, int *x){
    int success=1;
    if (s->sp>0){
        *x=s->valores[(s->sp)-1];
        success=0;
    }
    return success;
}