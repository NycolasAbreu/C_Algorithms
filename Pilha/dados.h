#ifndef DADO_H_INCLUDED

#include "pilha.h"

/* CriaÃ§Ã£o de tipo abstrato dado_t */
typedef struct dados dado_t;

/**
  * @brief  Cria um novo dado
  * @param  amostra: identificador da amostra
  * @param  temperatura: valor da temperatura
  * @param  timestamp: data e hora da amostra 
  *
  * @retval dado_t: ponteiro para uma novo dado
  */
dado_t *criar_dado(char *nome, int idade, char sexo);

/* Outras funÃ§Ãµes aqui: fazer os comentÃ¡rios */
pilha_t *ler_dados_csv_pilha(char *nome_do_arquivo);

char *obter_nome(dado_t *dado);

int obter_idade(dado_t *dado);

char obter_sexo(dado_t *dado);

void liberar_dados(pilha_t *pilha);

#endif
