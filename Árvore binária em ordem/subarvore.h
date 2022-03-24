/*
 * subarvore.h
 *
 *  Created on: Jul 5, 2016
 *      Author: Renan Augusto Starke
 */

#ifndef GRAFO_subarvore_H_
#define GRAFO_subarvore_H_

#include "lista_enc.h"

/* Exporta os tipos de dados do subarvore e arestas */
typedef struct subarvores subarvore_t;

/* Tipo enum o status das arestas: utilizado para exportação do DOT */
typedef enum status_aresta
{
    VAZIO,
    EXPORTADA
} status_aresta_t;

/* Cria um novo subarvore com id */
subarvore_t *cria_subarvore(int id);

/* Obtem id de um subarvore */
int subarvore_get_id(subarvore_t *subarvore);

/* Configura membro do subarvore
 * Ver: struct subarvores */
void subarvore_set_pai(subarvore_t *subarvore, subarvore_t *pai);
void subarvore_set_esq(subarvore_t *subarvore, subarvore_t *esq);
void subarvore_set_dir(subarvore_t *subarvore, subarvore_t *dir);
void subarvore_set_chave(subarvore_t *subarvore, int freq);

subarvore_t *subarvore_get_esq(subarvore_t *subarvore);
subarvore_t *subarvore_get_dir(subarvore_t *subarvore);
subarvore_t *subarvore_get_pai(subarvore_t *subarvore);
int subarvore_get_chave(subarvore_t *subarvore);

int subarvore_eh_folha(subarvore_t *subarvore);

#endif /* GRAFO_subarvore_H_ */