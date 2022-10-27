#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct aluno {
  char nome[81];
  char matricula[8];
  char turma;
  float p1;
  float p2;
  float p3;
};

typedef struct aluno Aluno;

Aluno **alocar_turmas(int n_turmas, int n_alunos) {
  Aluno **turmas;
  turmas = malloc(n_turmas * sizeof(Aluno *));
  for (int i = 0; i < n_turmas; ++i) {
    turmas[i] = (Aluno *)malloc(n_alunos * sizeof(Aluno));
  }
  return turmas;
}

void preencher_aluno(char turma, char *matricula, char *nome, float p1, float p2, float p3, Aluno *aluno) {
  aluno->turma = turma;
  strcpy(aluno->matricula, matricula);
  strcpy(aluno->nome, nome);
  aluno->p1 = p1;
  aluno->p2 = p2;
  aluno->p3 = p3;
}

void print_aluno(Aluno *aluno) {
  printf("Truma: %c", aluno->turma);
  printf("\nMatricula: %s", aluno->matricula);
  printf("\nNome: %s", aluno->nome);
  printf("\nNota P1: %f", aluno->p1);
  printf("\nNota P2: %f", aluno->p2);
  printf("\nNota P3: %f", aluno->p3);
}

void print_turmas(int n_turmas, int n_alunos, Aluno **turmas) {
  for (int i = 0; i < n_turmas; ++i) {
    printf("==============================\n");
    for (int j = 0; j < n_alunos; ++j) {
      print_aluno(&turmas[i][j]);
      printf("\n\n");
    }
  }
}

void liberar_turmas(int n_turmas, Aluno **turmas) {
  for (int i = 0; i < n_turmas; i++)
    free(turmas[i]);
  free(turmas);
}

int main(void) {
  Aluno **turmas;
  int n_turmas = 2;
  int n_alunos = 2;

  turmas = alocar_turmas(n_turmas, n_alunos);
  preencher_aluno('A', "00", "Aluno1", 5.0, 5.0, 5.0, &turmas[0][0]);
  preencher_aluno('A', "01", "Aluno2", 6.0, 6.0, 6.0, &turmas[0][1]);

  preencher_aluno('B', "10", "Aluno3", 7.0, 7.0, 7.0, &turmas[1][0]);
  preencher_aluno('B', "11", "Aluno4", 8.0, 8.0, 8.0, &turmas[1][1]);

  print_turmas(n_turmas, n_alunos, turmas);
  liberar_turmas(n_turmas, turmas);
}