/*
 * subarvore.c
 *
 *  Created on: Jul 5, 2016
 *      Author: Renan Augusto Starke
 */

#include <stdlib.h>
#include <stdio.h>

#include "subarvore.h"
#include "lista_enc.h"

#define TRUE 1
#define FALSE 0

struct subarvores
{
    int id; /*!< Identificação numérica do vértice  */

    subarvore_t *direita;  /*!< Filho à direta do vértice  */
    subarvore_t *esquerda; /*!< Filho à esquerda do vértice  */
    subarvore_t *pai;      /*!< Pai do vértice. Null se raíz da árvore  */

    /* Dados associados ao subarvore */
    int chave;
};

/**
  * @brief  Cria uma novo vértice
  * @param	id: identificação numérica do vértice
  *
  * @retval subarvore_t: ponteiro para um novo vértice
  */
subarvore_t *cria_subarvore(int id)
{
    subarvore_t *p = NULL;

    p = malloc(sizeof(subarvore_t));

    if (p == NULL)
    {
        perror("cria_subarvore:");
        exit(EXIT_FAILURE);
    }

    p->id = id;
    p->direita = NULL;
    p->esquerda = NULL;
    p->pai = NULL;

    return p;
}

/**
  * @brief  Obtém o identificador de um vértice
  * @param	subarvore: ponteiro de um vértice
  *
  * @retval int: identificador numérico do vértice
  */
int subarvore_get_id(subarvore_t *subarvore)
{
    if (subarvore == NULL)
    {
        fprintf(stderr, "subarvore_obter_id: subarvore invalido!\n");
        exit(EXIT_FAILURE);
    }

    return subarvore->id;
}

/**
  * @brief  Configura o pai de um vértice
  * @param	subarvore: ponteiro de um vértice
  * @param  pai: ponteiro do vértice pai
  *
  * @retval Nenhum
  */
void subarvore_set_pai(subarvore_t *subarvore, subarvore_t *pai)
{

    if (subarvore == NULL)
    {
        fprintf(stderr, "subarvore_set_pai: subarvore invalido\n");
        exit(EXIT_FAILURE);
    }

    subarvore->pai = pai;
}

/**
  * @brief  Configura o filho à esquerda de um vértice
  * @param	subarvore: ponteiro de um vértice
  * @param  esq: ponteiro do vértice à esquerda
  *
  * @retval Nenhum
  */
void subarvore_set_esq(subarvore_t *subarvore, subarvore_t *esq)
{

    if (subarvore == NULL)
    {
        fprintf(stderr, "subarvore_set_esq: subarvore invalido\n");
        exit(EXIT_FAILURE);
    }

    subarvore->esquerda = esq;
}

/**
  * @brief  Configura o filho à direita de um vértice
  * @param	subarvore: ponteiro de um vértice
  * @param  dir: ponteiro do vértice à direita
  *
  * @retval Nenhum
  */
void subarvore_set_dir(subarvore_t *subarvore, subarvore_t *dir)
{

    if (subarvore == NULL)
    {
        fprintf(stderr, "subarvore_set_esq: subarvore invalido\n");
        exit(EXIT_FAILURE);
    }

    subarvore->direita = dir;
}

/**
  * @brief  Obtém o vértice filho à esquerda
  * @param	subarvore: ponteiro de um vértice.
  *
  * @retval subarvore_t: ponteiro do vértice à esquerda. NULL se não há nenhum filho
  */
subarvore_t *subarvore_get_esq(subarvore_t *subarvore)
{

    if (subarvore == NULL)
    {
        fprintf(stderr, "subarvore_get_esq: subarvore invalido\n");
        exit(EXIT_FAILURE);
    }

    return subarvore->esquerda;
}

/**
  * @brief  Obtém o vértice filho à direita
  * @param	subarvore: ponteiro de um vértice.
  *
  * @retval subarvore_t: ponteiro do vértice à direita.  NULL se não há nenhum filho
  */
subarvore_t *subarvore_get_dir(subarvore_t *subarvore)
{

    if (subarvore == NULL)
    {
        fprintf(stderr, "subarvore_get_dir: subarvore invalido\n");
        exit(EXIT_FAILURE);
    }

    return subarvore->direita;
}

/**
  * @brief  Obtém o dado "chave" associado à um vértice
  * @param	subarvore: ponteiro de um vértice. 
  *
  * @retval int: dado inteiro associado
  */
int subarvore_get_chave(subarvore_t *subarvore)
{

    if (subarvore == NULL)
    {
        fprintf(stderr, "subarvore_get_freq: subarvore invalido\n");
        exit(EXIT_FAILURE);
    }

    return subarvore->chave;
}

/**
  * @brief  Configura o dado "chave" associado à um vértice
  * @param	subarvore: ponteiro de um vértice. 
  * @param  chave: chave numérica associada à um vértice
  *
  * @retval Nenhum
  */
void subarvore_set_chave(subarvore_t *subarvore, int chave)
{

    if (subarvore == NULL)
    {
        fprintf(stderr, "subarvore_set_freq: subarvore invalido\n");
        exit(EXIT_FAILURE);
    }

    subarvore->chave = chave;
}

/**
  * @brief  Obtém o pai de um vértice
  * @param	subarvore: ponteiro de um vértice. 
  *
  * @retval subarvore_t: ponteiro que representa o pai
  */
subarvore_t *subarvore_get_pai(subarvore_t *subarvore)
{

    if (subarvore == NULL)
    {
        fprintf(stderr, "subarvore_set_freq: subarvore invalido\n");
        exit(EXIT_FAILURE);
    }

    return subarvore->pai;
}
/**
  * @brief  Retorna se um vértice é uma folha.
  * @param	subarvore: ponteiro de um vértice. 
  *
  * @retval int: 0 se não for folha, > 0 se for uma folha
  */
int subarvore_eh_folha(subarvore_t *subarvore)
{

    if (subarvore == NULL)
    {
        fprintf(stderr, "eh_folha: subarvore invalido\n");
        exit(EXIT_FAILURE);
    }

    if (subarvore->direita == NULL && subarvore->esquerda == NULL)
        return TRUE;

    return FALSE;
}