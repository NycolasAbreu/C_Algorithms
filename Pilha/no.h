#ifndef NO_H_INCLUDED
#define NO_H_INCLUDED

/**
  * @brief  Estrutura do nó.
  * struct nos
  * {
    	void* dados;
    	no_t *proximo;
    }
  */
typedef struct nos no_t;

/**
  * @brief  Cria um novo nÃ³ de lista encadeada.
  * @param	dado: ponteiro genÃ©rico para qualquer tipo de dado.
  *
  * @retval no_t: ponteiro do tipo nÃ³ contendo a referÃªncia do dado.
  */
no_t *criar_no(void *dado);

/**
  * @brief  Faz o encadeamento entre dois nÃ³s de encadeados.
  * @param	fonte: ponteiro da fonte entre a ligaÃ§Ã£o.
  *         destino: ponteiro do destino entre a ligaÃ§Ã£o.
  *
  * @retval Nenhum.
  */
void ligar_nos(no_t *fonte, no_t *destino);

/**
  * @brief  Remove encadeamento um nÃ³ encadeado.
  * @param	no: nÃ³ de lista que se deseja remover ligaÃ§Ã£o.
  *
  * @retval Nenhum.
  */
void desligar_no(no_t *no);

/**
  * @brief  ObtÃ©m a referÃªncia do dado pertencente ao nÃ³ de lista encadeada.
  * @param	no: nÃ³ de lista que se deseja obter o dado.
  *
  * @retval void *: dado referenciado pelo nÃ³ encadeado. 
  */
no_t *obter_proximo(no_t *no);

/**
  * @brief  ObtÃ©m a prÃ³xima referÃªncia encadeada.
  * @param	no: nÃ³ de lista que se deseja obter o prÃ³ximo elemento.
  *
  * @retval no_t *: onteiro do prÃ³ximo elemento da lista. NULL se final de lista.
  */
void *obter_dado(no_t *no);

#endif // NO_H_INCLUDED
