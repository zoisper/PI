#include <stdio.h>


/*1. Podemos calcular o produto de um número m por um inteiro n através de um somatório
de n parcelas constantes (e iguais a m).
Este cálculo pode ser efectuado somando n vezes a quantidade m a uma variável inicial-
mente com o valor 0.
Apresente uma definição da função float multInt (int n, float m) baseada nesta
observação: a uma variável r (inicialmente com o valor 0) será somado o valor de m,
n vezes. Essa variável r vai ter os valores 0, m, 2*m, 3*m, . . . , e no final terá o valor
desejado n*m.*/

float multInt (int n, float m)
{
    float r = 0;
    while (n>0)
    {
        r += m;
        n--;
    }
    return r;
}

/*2. Uma forma alternativa (e muito mais eficiente) consiste em aproveitar a representação
binária dos inteiros (onde a multiplicação e divisão por 2 são pelo menos tão eficientes
como a adição).
Dados dois números m e n podemos construir uma tabela em
que vamos dividindo (divisão inteira) n por 2 e multiplicando
m por 2. A primeira linha da tabela tem o valor original de n
enquanto que a última corresponde a n ser 1.
Para obter o valor do produto de n por m basta somar os
valores de m correspondentes às linhas em que n é impar.
Apresente uma definição alternativa da função float multInt (int n, float m) us-
ando este processo.*/

float multIntAlt (int n, float m)
{
    float r = 0;
    while (n > 0)
    {
        if (n%2 == 1)
            r += m;
        n /= 2;
        m *= 2;
    }
    return r;
}

/*3. O cálculo do máximo divisor comum entre dois números inteiros não negativos pode ser
feito, de uma forma muito pouco eficiente, procurando de entre os divisores do menor
deles, o maior que é também divisor do outro.
Defina uma função int mdc (int a, int b) que usa esse método para calcular o
máximo divisor comum entre dois números).*/

int mdc (int a, int b)
{
    int r;
    if (a == 0)
        r = b;
    else
        if (b == 0)
            r = a;
    else
    {
        if (a > b)
            r = b;
        else
            r = a;
        while (a%r != 0 || b%r != 0)
            r--;
    }
    return r;
}

/*4. Uma forma alternativa de calcular o máximo divisor comum (mdc) baseia-se na seguinte
propriedade demonstrada por Euclides: para a e b inteiros positivos, mdc (a, b) = mdc (a + b, b).
O cálculo do máximo dicvisor comum pode serfeito por um processo repetitivo em que substituimos 
o maior dos argumentos pela diferença entre eles, até que um deles seja 0. Nessa altura, o
valor do outro corresponde ao valor pretendido.
Apresente uma definição alternativa da função int mdc (int a, int b) que usa esse 
método.*/

int mdcAlt (int a, int b)
{
    while (a != 0 && b != 0)
    {
        if (a > b)
            a -= b;
        else
            b -= a;
    }
    if (a == 0)
        return b;
    else
        return a;
}

// ou

int mdcAltRec (int a, int b) // versão recursiva
{
    int r;
    if (a == 0)
        r = b;
    else
        if (b == 0)
            r = a;
        else
            if (a > b)
                 r = mdcAltRec (a-b, b);
                else
                    r = mdcAltRec (b-a, a);
    return r;
}

/*5. Uma forma de melhorar o comportamento do algoritmo de Euclides consiste em substi-
tuir as operações de subtracção por operações de % (resto da divisão inteira). Repita o
exercı́cio da alı́nea anterior para essa variante do algoritmo.*/

int mdcEf (int a, int b)
{
    while (a != 0 && b != 0)
    {
        if (a > b)
            a = a%b;
        else
            b = b%a;
    }
    if (a == 0)
        return b;
    else
        return a;
}

// ou

int mdcEfRec (int a, int b) // versão recursiva
{
    int r;
    if (a == 0)
        r = b;
    else
        if (b == 0)
            return a;
        else 
            if (a>b)
                r = mdcEfRec (a%b,b);
            else
                r = mdcEfRec (b%a, a);
    return r;
}

/*6 A sequência de Fibonacci define-se como:

- se n < 2, fib (n) = 1; 
- se n >= 2, fib (n) = fib (n-1) + fib (n-2);*/

/*(a) Apresente uma definição recursiva de uma função que int fib (int n) calcula o
n-ésimo número da sequência de Fibonacci.*/

int fib (int n)
{
    int r = 1;
    if (n >= 2)
        r = fib(n-1) + fib (n-2);
    return r; 
}

/*(b) O cálculo do n-ésimo número de Fibonacci pode ser definido de uma forma mais
eficiente (e iterativa) se repararmos que ele apenas necessita de conhecer os valores
dos 2 valores anteriores. Apresente uma definição alternativa (e iterativa) da função
da alı́nea anterior que calcula o n-ésimo número de Fibonacci, usando duas variáveis
auxiliares que guardam os dois valores anteriores.*/

int fibEf (int n)
{
    int a = 1, b = 1;
    while (n >= 2)
    {
        if (a > b)
            b += a;
        else
            a += b;
        n--;
    }
    
    if (a > b)
        return a;
    else
        return b;
    
}
