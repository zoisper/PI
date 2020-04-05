#include "alunos.h"
#include <stdlib.h>

int main()
{
	Aluno a1 = {"Ana Cristina", 91234, 16};
	Aluno a2 = {"Berto Almeida", 88919, 14};

	Turma t1;

	t1 = malloc(sizeof(NodoTurma));
	t1->proxAluno = malloc(sizeof(NodoTurma));

	t1->aluno = a1;
	t1->proxAluno = a2;
	t1->proxAluno->proxAluno = NULL; 

}