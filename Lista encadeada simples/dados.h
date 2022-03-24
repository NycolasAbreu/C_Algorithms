#ifndef DADO_H_INCLUDED

#include "lista_enc.h"

/* Criação de tipo abstrato dado_t */
typedef struct dados dado_t;

lista_enc_t *ler_dados_csv(char *nome_do_arquivo);

void liberar_dados(lista_enc_t *lista);

char *obter_nome(dado_t *dado);

int obter_idade(dado_t *dado);

char obter_sexo(dado_t *dado);

#endif
