#ifndef LISTA_ENC_H_INCLUDED
#define LISTA_ENC_H_INCLUDED

#include "no.h"

typedef struct listas_enc lista_enc_t;

/**
  * @brief  Cria uma nova lista encadeada vazia.
  * @param	Nenhum
  *
  * @retval lista_enc_t *: ponteiro (referÃªncia) da nova lista encadeada.
  */
lista_enc_t *criar_lista_enc(void);

/**
  * @brief  Adiciona um nÃ³ de lista no final.
  * @param	lista: lista encadeada que se deseja adicionar.
  *         elemento: nÃ³ que serÃ¡ adicionado na cauda.
  *
  * @retval Nenhum
  */
void add_cauda(lista_enc_t *lista, no_t *elemento);

/**
  * @brief  Adiciona um nÃ³ de lista no inÃ­cio.
  * @param	lista: lista encadeada que se deseja adicionar.
  *         elemento: nÃ³ que serÃ¡ adicionado na cabeÃ§a.
  *
  * @retval Nenhum
  */
void add_cabeca(lista_enc_t *lista, no_t *elemento);

/**
  * @brief  ObtÃ©m a referÃªncia do inÃ­cio (cabeÃ§a) da lista encadeada.
  * @param	lista: lista que se deseja obter o inÃ­cio.
  *
  * @retval no_t *: nÃ³ inicial (cabeÃ§a) da lista.
  */
no_t *obter_cabeca(lista_enc_t *lista);

int lista_vazia(lista_enc_t *lista);
no_t *remover_cauda(lista_enc_t *lista);
no_t *remover_cabeca(lista_enc_t *lista);

#endif // LISTA_ENC_H_INCLUDED
