#ifndef _ALUNOS
#define _ALUNOS

typdef struct aluno 
{
	char nome[61];
	int numeroAluno, nota;
} Aluno;

typdef struct turma *Turma;

typdef struct turma 
{
	Aluno aluno;
	Turma proxAluno;
}NodoTurma;

#endif