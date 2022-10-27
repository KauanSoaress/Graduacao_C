#include "Fila.h"
#include <stdio.h>
#include <stdlib.h>

struct node {
  Aluno *aluno;
  struct node *proximo;
};

typedef struct node No;

struct fila {
  No *primeiro;
};

/* Aloca espaço em memória e retorna uma fila */
Fila *fila_cria() {
  Fila *fila = (Fila *)malloc(sizeof(Fila));
  fila->primeiro = NULL;
  return fila;
}

/* Libera a memória de uma fila previamente criada e atribui NULL ao ponteiro
 * fila. Retorna 1 caso seja possível fazer a liberação e 0 caso a fila
 * informada seja NULL. */
int fila_libera(Fila **fila) {
  if (fila != NULL) {
    if ((*fila)->primeiro != NULL) {
      No *aux = (*fila)->primeiro;
      do {
        alu_libera(&aux->aluno);
        aux = aux->proximo;
      } while (aux != NULL);
    }
    free(*fila);
    *fila = NULL;
    return 1;
  }
  return 0;
}

/* Insere um aluno na fila. Retorna 1 se foi possível adicionar, 0 caso já
 * exista um aluno com a mesma matricula (nesse caso, o aluno não pode ser
 * adicionado) e -1 caso a fila ou aluno sejam NULL
 */
int fila_insere(Fila *fila, Aluno *aluno) {
  if (fila == NULL || aluno == NULL) { // verificação de nulidade
    return-1;
  }

  // criação de variáveis para receberem os valores do aluno criado
  int matriculaAluno;
  int matriculaParaComparar;
  char nome[50];
  char curso[30];

  alu_acessa(aluno, &matriculaAluno, nome, curso); // acessando os dados do aluno criado 

  No *noAtual = fila->primeiro; 
  No *noAux = noAtual;

  // checagem se o primeiro nó (noAtual) é NULL, se for, o primeiro nó vai receber o novoNo criado
  if (fila->primeiro == NULL) {
    // criação de um novo nó, que recebe o aluno criado e o próximo = NULL
    
    No *novoNo = (No*) malloc(sizeof(No));
    novoNo->aluno = aluno;
    novoNo->proximo = NULL;

    No ** auxiliar = &(fila->primeiro);
    *auxiliar = novoNo;
    return 1;
  }
  
  while(noAtual != NULL) {
    alu_acessa(noAtual->aluno, &matriculaParaComparar, nome, curso); // acessando os dados de cada aluno de cada nó visitado
    if (matriculaAluno == matriculaParaComparar) { // verifica se há matrícula igual a do aluno novo
      return 0;
    }
    noAux = noAtual;
    noAtual = noAtual->proximo;
  }
  No *novoNo = (No*) malloc(sizeof(No));
  novoNo->aluno = aluno;
  novoNo->proximo = NULL;

  No ** auxiliar = &(noAux->proximo);
  *auxiliar = novoNo;

  return 1;
}
 
/* Remove um aluno na fila. Retorna o aluno ou NULL caso a fila esteja vazia ou
 * seja NULL */
Aluno *fila_retira(Fila *fila) {
  if (fila == NULL || fila->primeiro == NULL) {
    return NULL;
  }
  Aluno *alunoAux = fila->primeiro->aluno;
  No **auxiliar = &fila->primeiro;
  *auxiliar = fila->primeiro->proximo;
  
  return alunoAux;
}

/* Recupera o primeiro aluno da fila. Retorna o aluno ou NULL caso a fila esteja
 * vazia ou seja NULL */
Aluno *fila_primeiro(Fila *fila) {
  if (fila == NULL || fila->primeiro == NULL) {
    return NULL;
  }
  return fila->primeiro->aluno;
}

/* Busca aluno pelo número de matricula. Retorna o aluno se este estiver na
 * lista e NULL caso contrário, isto é, (i) fila vazia; (ii) não exista aluno
 * com a matricula fornecida; ou (iii) a fila seja NULL */
Aluno *fila_busca(Fila *fila, int matricula) {
  if (fila_vazia(fila) == 1 || fila == NULL) {
    return NULL;
  }

  // criação de variáveis para receberem os valores do aluno criado
  int matriculaAluno;
  char nome[50];
  char curso[30];

  No *noAtual = fila->primeiro; 
  No *noAux = noAtual;
  
  while(noAtual != NULL) {
    alu_acessa(noAtual->aluno, &matriculaAluno, nome, curso); // acessando os dados de cada aluno de cada nó visitado
    if (matriculaAluno == matricula) { // verifica se há matrícula igual a do aluno novo
      return noAtual->aluno;
    }
    noAux = noAtual;
    noAtual = noAtual->proximo;
  }

  return NULL;
}

/* Verifica se a fila está vazia. Retorna 1 se a fila estiver vazia, 0 caso não
 * esteja vazia e -1 se a fila for NULL
 */
int fila_vazia(Fila *fila) {
  if (fila == NULL) {
    return -1;
  }
  if (fila->primeiro == NULL) {
    return 1;
  } 
  return 0;
}

/* Computa a quantidade de alunos alunos na fila. Retorna a quantidade de alunos
 * ou -1, caso a fila for NULL.
 */
int fila_quantidade(Fila *fila) {
  if (fila == NULL) {
    return -1;
  }
  No *aux = fila->primeiro;
  int cont = 0;
  while (aux != NULL) {
    aux = aux->proximo;
    cont++;
  }
  return cont;
}