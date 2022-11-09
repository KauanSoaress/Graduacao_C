#include "ABB.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
  int chave;
  char conteudo;
  No *esq;
  No *dir;
};

/* Aloca e retorna um No com os dados passados por parâmetro. Retorna no nó
 * criado ou NULL caso não seja posivel criar o nó. */
No *abb_cria_no(int chave, char conteudo) {
  if (chave < 0 || conteudo == NULL) {
    return NULL;
  } else {
    No *no = (No *)malloc(sizeof(No));
    no->chave = chave;
    no->conteudo = conteudo;
    no->esq = NULL;
    no->dir = NULL;
    return no;
  }
}

/* Libera a memória de um nó e toda as suas sub-árvores. Retorna 1 se for
 * possivel fazer a liberação ou 0 caso o nó seja NULL. */
int abb_libera_no(No *no) {
  return NULL;
}

/* Retorna a chave do nó ou -1 caso o nó seja NULL.  */
int abb_chave_no(No *no) {
  if (no == NULL) {
    return -1;
  }
  return no->chave;
}

/* Retorna o conteúdo do no ou '#' caso o nó seja NULL. */
char abb_conteudo_no(No *no) {
  if (no == NULL) {
    return '#';
  }
  return no->conteudo;
}

/* Adiciona um nó à esquerda ou à direita do no raiz. Retorna a raiz da árvore
 * resultante ou NULL caso (i) a raiz e o nó sejam NULL e (ii) caso o nó possua
 * mesma chave que outro nó previamente inserido na árvore. */
No *abb_insere_no(No *raiz, No *no) {
  No *auxiliarY = NULL;
  No *auxiliarX = raiz;
  while (auxiliarX != NULL) {
    auxiliarY = auxiliarX;
    if (no->chave <= auxiliarX->chave) {
      auxiliarX = auxiliarX->esq;
    }
    else {
      auxiliarX = auxiliarX->chave;
    }
  }
  if (no->chave == auxiliarY->chave) {
    return NULL;
  }
  else if (no->chave <= auxiliarY->chave) {
    auxiliarY->esq = no;
  }
  else {
    auxiliarY->dir = no;
  }
  if (raiz == NULL && no == NULL) {
    return NULL;
  }
  return raiz;

}

/* Procura o nó pela chave. Retorna o nó caso a busca obtenha sucesso ou NULL
 * em caso contrário. */
No *abb_busca_no(No *raiz, int chave) {
  No *aux = raiz;
  while (aux != NULL && aux->chave != chave) {
    if (aux->chave > chave) {
      aux = aux->esq;
    }
    else if (aux->chave < chave) {
      aux = aux->dir;
    }
  }
  return aux;
}


/* Remove o nó com a chave fornecida. Retorna a raiz da arvore atualizada ou
 * NULL em caso a raiz fornecida seja NULL. */
No *abb_remove_no(No *raiz, int chave) {
  No *aux = raiz;
  while (aux != NULL && aux->chave != chave) {
    if (aux->esq->chave > chave) {
      aux = aux->esq;
    }
    else if (aux->dir->chave < chave) {
      aux = aux->dir;
    }
  }
  No *remover;
  if (aux->esq->chave == chave) {
    remover = aux->esq;
    aux->esq = NULL;
  }
  else if (aux->dir->chave == chave) {
    remover = aux->dir;
    aux->dir = NULL;
  }
  return remover;
}

/* Retorna a altura da árvore ou -1 caso araiz seja NULL. */
int abb_altura(No *raiz) {
  if (raiz == NULL) {
    return NULL;
  }
}

/* Retorna o número de nós da árvore ou -1 caso araiz seja NULL. */
int abb_numero(No *raiz) {
  if (raiz == NULL) {
    return NULL;
  }
  int quant = 0;
}

/*Retorna a concatenação do conteúdo da árvore fazendo percurso em pré-ordem à
 * partir do nó ou '#' caso o nó seja NULL. */
char *abb_pre_ordem(No *no) {
  return "&";
}

/*Retorna a concatenação do conteúdo da árvore fazendo percurso em ordem à
 * partir do nó ou '#' caso o nó seja NULL. */
char *abb_ordem(No *no) {
  if (no == NULL) {
      return '#';
  }
  char concatenacao = ' ';
  
  return emOrdemConc(no, concatenacao);
}

/*Retorna a concatenação do conteúdo da árvore fazendo percurso em pós-ordem à
 * partir do nó ou '#' caso o nó seja NULL. */
char *abb_pos_ordem(No *no) {
  return "&";
}

char *emOrdemConc(No *no, char concatenacao) {
  if (no != NULL) {
    emOrdemConc(no->esq, concatenacao);
    strcat(concatenacao, no->conteudo);
    emOrdemConc(no->dir, concatenacao);
  }
}