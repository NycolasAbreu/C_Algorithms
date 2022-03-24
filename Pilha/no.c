#include <stdio.h>
#include <stdlib.h>

#include "no.h"

struct nos
{
    void *dados;   /*!< ReferÃªncia do dado respectiva ao nÃ³ da lista encadeada. */
    no_t *proximo; /*!< ReferÃªncia do prÃ³ximo elemento da lista encadeada. */
};

/**
  * @brief  Cria um novo nÃ³ de lista encadeada.
  * @param	dado: ponteiro genÃ©rico para qualquer tipo de dado.
  *
  * @retval no_t: ponteiro do tipo nÃ³ contendo a referÃªncia do dado.
  */
no_t *criar_no(void *dado)
{
    no_t *no = malloc(sizeof(no_t));

    if (no == NULL)
    {
        perror("cria_no:");
        exit(EXIT_FAILURE);
    }

    no->dados = dado;
    no->proximo = NULL;

    return no;
}

/**
  * @brief  Faz o encadeamento entre dois nÃ³s de encadeados.
  * @param	fonte: ponteiro da fonte entre a ligaÃ§Ã£o.
  *         destino: ponteiro do destino entre a ligaÃ§Ã£o.
  *
  * @retval Nenhum.
  */
void ligar_nos(no_t *fonte, no_t *destino)
{
    if (fonte == NULL || destino == NULL)
    {
        fprintf(stderr, "liga_nos: ponteiros invalidos");
        exit(EXIT_FAILURE);
    }

    fonte->proximo = destino;
}

/**
  * @brief  Remove encadeamento um nÃ³ encadeado.
  * @param	no: nÃ³ de lista que se deseja remover ligaÃ§Ã£o.
  *
  * @retval Nenhum.
  */
void desligar_no(no_t *no)
{
    if (no == NULL)
    {
        fprintf(stderr, "liga_nos: ponteiros invalidos");
        exit(EXIT_FAILURE);
    }

    no->proximo = NULL;
}

/**
  * @brief  ObtÃ©m a referÃªncia do dado pertencente ao nÃ³ de lista encadeada.
  * @param	no: nÃ³ de lista que se deseja obter o dado.
  *
  * @retval void *: dado referenciado pelo nÃ³ encadeado. 
  */
void *obter_dado(no_t *no)
{
    if (no == NULL)
    {
        fprintf(stderr, "liga_nos: ponteiros invalidos");
        exit(EXIT_FAILURE);
    }

    return no->dados;
}

/**
  * @brief  ObtÃ©m a prÃ³xima referÃªncia encadeada.
  * @param	no: nÃ³ de lista que se deseja obter o prÃ³ximo elemento.
  *
  * @retval no_t *: ponteiro do prÃ³ximo elemento da lista. NULL se final de lista.
  */
no_t *obter_proximo(no_t *no)
{
    if (no == NULL)
    {
        fprintf(stderr, "liga_nos: ponteiros invalidos");
        exit(EXIT_FAILURE);
    }
    return no->proximo;
}
