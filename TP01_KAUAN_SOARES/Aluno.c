#include "Aluno.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct aluno {
    int matricula;
    char nome[50];
    char curso[30];
};

/* Aloca e retorna um aluno com os dados passados por parâmetro. 
    Porém, para os casos em que: 
    (i) pelo menos um dos parâmetros sejam nulos <-1, NULL, NULL>; e
    (ii) o tamanho das strings nome e curso sejam maiores que os da especificação
 * (50 e 30, respectivamente), a função deve retornar NULL. */
Aluno *alu_novo(int matricula, char *nome, char *curso) {

    if (matricula == -1 || nome == NULL || curso == NULL) {
        return NULL;
    }
    if (strlen(nome) > 50 && strlen(curso) > 30) {
        return NULL;
    }
    
    Aluno *aluno = (Aluno *) malloc(sizeof(Aluno));

    aluno -> matricula = matricula; 
    strcpy(aluno->nome, nome); 
    strcpy(aluno->curso, curso); 

    return aluno;
}

/* Libera a memória de um aluno previamente criado e atribui NULL ao aluno. */
void alu_libera(Aluno **aluno) {
    free(*aluno);
    *aluno = NULL;
}

/* Copia os valores de um aluno para as referências informadas. Em caso de aluno
 * NULL, atribuir valor padrão <-1, "NULL", "NULL"> aos parâmetros. */
void alu_acessa(Aluno *aluno, int *matricula, char *nome, char *curso) {
    if (aluno == NULL) {
        *matricula = -1;
        nome = NULL;
        curso = NULL;
    }

    *matricula = aluno -> matricula;
    strcpy(nome, aluno -> nome);
    strcpy(curso, aluno -> curso);
}

/*  Atribui novos valores aos campos de um aluno. 
    Porém, para os casos em que:
        (i) algum dos parâmetros sejam nulos <NULL, -1, NULL, NULL>; ou 
        (ii) o tamanho das strings nome e curso sejam maiores que os da especificação (50 e 30, respectivamente), 
    a função não deve fazer a atribuição. */
void alu_atribui(Aluno *aluno, int matricula, char *nome, char *curso) {
    if (matricula != -1 && curso != NULL && nome != NULL) {
        if (strlen(curso) <= 30 && strlen(nome) <= 50) {
            aluno -> matricula = matricula; 
            strcpy(aluno->nome, nome); 
            strcpy(aluno->curso, curso); 
        }
    }
}

/* Avalia se dois alunos são iguas. A função deve retornar 1 se os alunos
 * possuem os mesmos dados, 0 caso os dados dos alunos possuam alguma diferença
 * e -1 caso pelo menos um dos alunos seja NULL.
 */
int alu_igual(Aluno *aluno1, Aluno *aluno2) {
    if (aluno1 == NULL || aluno2 == NULL) {
        return -1;
    } else if ((aluno1->matricula != aluno2->matricula) || (aluno1->nome != aluno2->nome) || (aluno1->curso != aluno2->curso)) {
        return 0;
    }
    return 1;
}

/* Retorna o tamanho em bytes do TAD aluno. */
int alu_tamanho() {
    return (sizeof(Aluno)/8);
}