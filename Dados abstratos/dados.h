#ifndef DADO_H_INCLUDED

/* CriaÃ§Ã£o de tipo abstrato dado_t */
typedef struct dados dado_t;

dado_t *criar_dado(char *nome, int idade, char sexo);

/* Outras funÃ§Ãµes aqui: fazer os comentÃ¡rios */

dado_t **ler_dados_csv(char *nome_do_arquivo, int *total_dados);

char *obter_nome(dado_t *dado);
int obter_idade(dado_t *dado);
char obter_sexo(dado_t *dado);
void liberar_dados(dado_t **vetor, int n_linhas);
#endif
