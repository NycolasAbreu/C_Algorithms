#ifndef DADO_H_INCLUDED

/* CriaÃ§Ã£o de tipo abstrato dado_t */
typedef struct dados dado_t;

#include "fila.h"

fila_t *ler_dados_csv_fila(char *nome_do_arquivo);

dado_t *criar_dado(char *nome, int idade, char sexo);

char *obter_nome(dado_t *dado);

int obter_idade(dado_t *dado);

char obter_sexo(dado_t *dado);

void liberar_dados(fila_t *fila);

#endif
