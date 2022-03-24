/*
 * arvore.h
 *
 *  Created on: Nov 25, 2016
 *      Author: Renan Augusto Starke
 */

#ifndef SRC_ARVORE_ARVORE_H_
#define SRC_ARVORE_ARVORE_H_

#include "subarvore.h"

typedef struct arvores arvore_t;

arvore_t *cria_arvore(int id);
subarvore_t *arvore_adicionar_subarvore_id(arvore_t *arvore, int id);
subarvore_t *arvore_adicionar_subarvore(arvore_t *arvore, subarvore_t *subarvore);
subarvore_t *procura_subarvore(arvore_t *arvore, int id);
subarvore_t *arvore_get_raiz(arvore_t *arvore);
lista_enc_t *arvore_obter_subarvores(arvore_t *arvore);

void exportar_arvore_dot(const char *filename, arvore_t *arvore);
void arvore_adiciona_filhos(arvore_t *arvore, subarvore_t *subarvore, int esq, int dir);
void arvore_set_raiz(arvore_t *arvore, subarvore_t *subarvore);
void libera_arvore(arvore_t *arvore);
int arvore_get_id(arvore_t *arvore);
subarvore_t *emordem_recursivo(subarvore_t *subarvore, int chave);
int buscabin(arvore_t *arvore, int chave);
arvore_t *ler_dados_csv(char *nome_do_arquivo);

#endif /* SRC_ARVORE_ARVORE_H_ */