#include "Pilha.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CAPACIDADE_INICIAL 10

struct node {
  Aluno *aluno;
  struct node *proximo;
};

typedef struct node No;

struct pilha {
  No *primeiro;
};

/* Aloca espaço em memória e retorna uma pilha. */
Pilha *pilha_cria() {
  Pilha *pilha = (Pilha *)malloc(sizeof(Pilha));
  pilha->primeiro = NULL;
  return pilha;
}

/* Libera a memória de uma pilha previamente criada e atribui NULL ao ponteiro
 * pilha. Retorna 1 caso seja possível fazer a liberação e 0 caso a pilha
 * informada seja NULL. */
int pilha_libera(Pilha **pilha) {
  if (pilha != NULL) {
    if ((*pilha)->primeiro != NULL) {
      No *aux = (*pilha)->primeiro;
      do {
        alu_libera(&aux->aluno);
        aux = aux->proximo;
      } while (aux != NULL);
    }
    free(*pilha);
    *pilha = NULL;
    return 1;
  }
  return 0;
}

/* Insere um aluno na Pilha. Retorna 1 se foi possível adicionar, 0 caso já
 * exista um aluno com a mesma matricula (nesse caso, o aluno não pode ser
 * adicionado) e -1 caso a pilha ou aluno sejam NULL.
 */
int pilha_push(Pilha *pilha, Aluno *aluno) {
  if (pilha == NULL || aluno == NULL) { // verificação de nulidade
    return-1;
  }

  // criação de variáveis para receberem os valores do aluno criado
  int matriculaAluno;
  int matriculaParaComparar;
  char nome[50];
  char curso[30];

  alu_acessa(aluno, &matriculaAluno, nome, curso); // acessando os dados do aluno criado 

  No *noAtual = pilha->primeiro; 
  No *noAux = noAtual;

  // checagem se o primeiro nó (noAtual) é NULL, se for, o primeiro nó vai receber o novoNo criado
  if (pilha->primeiro == NULL) {
    // criação de um novo nó, que recebe o aluno criado e o próximo = NULL
    
    No *novoNo = (No*) malloc(sizeof(No));
    novoNo->aluno = aluno;
    novoNo->proximo = NULL;

    No ** auxiliar = &(pilha->primeiro);
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

/* Remove um aluno na pilha. Retorna o aluno ou NULL caso a pilha esteja vazia
 * ou seja NULL. */
Aluno *pilha_pop(Pilha *pilha) {
  if (pilha == NULL || pilha->primeiro == NULL) {
    return NULL;
  }

  Aluno *aluno_removido = pilha_top(pilha);

  No *noAux = pilha->primeiro;
  No *anterior = noAux;
  No *anteriorOutro = noAux;

  while(noAux != NULL) {
    anteriorOutro = anterior;
    anterior = noAux;
    noAux = noAux->proximo;
  }  

  free(anterior);
  free(noAux);
  anteriorOutro->proximo = NULL;

  return aluno_removido;
}

/* Recupera o primeiro aluno da pilha. Retorna o aluno ou NULL caso a pilha
 * esteja vazia ou seja NULL. */
Aluno *pilha_top(Pilha *pilha) {
  if (pilha == NULL || pilha->primeiro == NULL) {
    return NULL;
  }

  No *noAux = pilha->primeiro;

  while(noAux->proximo != NULL) {
    noAux = noAux->proximo;
  }

  return noAux->aluno;
}

/* Busca aluno pelo número de matricula. Retorna o aluno se este estiver na
 * lista e NULL caso contrário, isto é, (i) pilha vazia; (ii) não exista aluno
 * com a matricula fornecida; ou (iii) a pilha seja NULL */
Aluno *pilha_busca(Pilha *pilha, int matricula) {
  if (pilha_vazia(pilha) == 1 || pilha == NULL) {
    return NULL;
  }

  // criação de variáveis para receberem os valores do aluno criado
  int matriculaAluno;
  char nome[50];
  char curso[30];

  No *noAtual = pilha->primeiro; 
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

/* Verifica se a pilha está vazia. Retorna 1 se a pilha estiver vazia, 0 caso
 * não esteja vazia e -1 se p Pilha for NULL
 */
int pilha_vazia(Pilha *pilha) {
  if (pilha == NULL) {
    return -1;
  }
  if (pilha->primeiro == NULL) {
    return 1;
  }
  return 0;
}

/* Computa a quantidade de alunos na pilha. Retorna a quantidade de alunos
 * ou -1, caso a Pilha for NULL.
 */
int pilha_quantidade(Pilha *pilha) {
  if (pilha == NULL) {
    return -1;
  }
  No *aux = pilha->primeiro;
  int cont = 0;
  while (aux != NULL) {
    aux = aux->proximo;
    cont++;
  }
  return cont;
}