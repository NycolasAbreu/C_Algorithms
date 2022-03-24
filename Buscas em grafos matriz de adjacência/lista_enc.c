#include <stdio.h>
#include <stdlib.h>

#include "lista_enc.h"
#include "no.h"

/* #define DEBUG */

struct listas_enc
{
  no_t *cabeca; /*!< ReferÃªncia da cabeÃ§a da lista encadeada: primeiro elemento. */
  no_t *cauda;  /*!< ReferÃªncia da cauda da lista encadeada: Ãºltimo elemento. */
  int tamanho;  /*!< Tamanho atual da lista. */
};

/**
 * @brief  Cria uma nova lista encadeada vazia.
 * @param	Nenhum
 *
 * @retval lista_enc_t *: ponteiro (referÃªncia) da nova lista encadeada.
 */
lista_enc_t *criar_lista_enc(void)
{
  lista_enc_t *p = malloc(sizeof(lista_enc_t));

  if (p == NULL)
  {
    perror("cria_lista_enc:");
    exit(EXIT_FAILURE);
  }

  p->cabeca = NULL;
  p->cauda = NULL;
  p->tamanho = 0;

  return p;
}

/**
 * @brief  ObtÃ©m a referÃªncia do inÃ­cio (cabeÃ§a) da lista encadeada.
 * @param	lista: lista que se deseja obter o inÃ­cio.
 *
 * @retval no_t *: nÃ³ inicial (cabeÃ§a) da lista.
 */
no_t *obter_cabeca(lista_enc_t *lista)
{
  return lista->cabeca;
}

/**
 * @brief  Adiciona um nÃ³ de lista no final.
 * @param	lista: lista encadeada que se deseja adicionar.
 * @param  elemento: nÃ³ que serÃ¡ adicionado na cauda.
 *
 * @retval Nenhum
 */
void add_cauda(lista_enc_t *lista, no_t *elemento)
{
  if (lista == NULL || elemento == NULL)
  {
    fprintf(stderr, "add_cauda: ponteiros invalidos");
    exit(EXIT_FAILURE);
  }

#ifdef DEBUG
  printf("Adicionando %p --- tamanho: %d\n", elemento, lista->tamanho);
#endif // DEBUG

  //lista vazia
  if (lista->tamanho == 0)
  {
#ifdef DEBUG
    printf("add_cauda: add primeiro elemento: %p\n", elemento);
#endif // DEBUG

    lista->cauda = elemento;
    lista->cabeca = elemento;
    lista->tamanho++;

    desligar_no(elemento);
  }
  else
  {
    // Remove qualquer ligacao antiga
    desligar_no(elemento);
    // Liga cauda da lista com novo elemento
    ligar_nos(lista->cauda, elemento);

    lista->cauda = elemento;
    lista->tamanho++;
  }
}

void add_cabeca(lista_enc_t *lista, no_t *elemento)
{
  if (lista == NULL || elemento == NULL)
  {
    fprintf(stderr, "add_cauda: ponteiros invalidos");
    exit(EXIT_FAILURE);
  }

#ifdef DEBUG
  printf("Adicionando %p --- tamanho: %d\n", elemento, lista->tamanho);
#endif // DEBUG

  //lista vazia
  if (lista->tamanho == 0)
  {
#ifdef DEBUG
    printf("add_cauda: add primeiro elemento: %p\n", elemento);
#endif // DEBUG

    lista->cauda = elemento;
    lista->cabeca = elemento;
    lista->tamanho++;

    desligar_no(elemento);
  }
  else
  {
    // Remove qualquer ligacao antiga
    //desligar_no(elemento);
    // Liga cauda da lista com novo elemento
    ligar_nos(elemento, lista->cabeca);

    lista->cabeca = elemento;
    lista->tamanho++;
  }
}

no_t *remover_cabeca(lista_enc_t *lista)
{
  if (lista_vazia(lista))
  {
    fprintf(stderr, "Aviso: liberando fila não vazia");
    return NULL;
  }
  else
  {
    no_t *retirado = obter_cabeca(lista);
    lista->cabeca = obter_proximo(retirado);
    lista->tamanho--;
    return retirado;
  }
}

/**
  * @brief  Remove um dado do final (cauda) da lista encadeada.
  * @param	lista: lista que se deseja remover da cauda
  *
  * @retval no_t *: nó removido da lista.
  */
no_t *remover_cauda(lista_enc_t *lista)
{
  no_t *anterior;
  no_t *removido;

  if (lista == NULL)
  {
    fprintf(stderr, "remover_cauda: ponteiro invalido");
    exit(EXIT_FAILURE);
  }

  if (lista->cauda == NULL)
    return NULL;

  removido = lista->cauda;

  if (lista->cauda == lista->cabeca)
  {
    lista->tamanho = 0;

    lista->cauda = NULL;
    lista->cabeca = NULL;

    return removido;
  }

  anterior = obtem_anterior(lista->cauda);
  desligar_no(removido);
  lista->cauda = anterior;
  desliga_no_proximo(anterior);
  lista->tamanho--;

  return removido;
}

int lista_vazia(lista_enc_t *lista)
{
  if (lista->tamanho == 0)
    return 1;
  else
    return 0;
}
