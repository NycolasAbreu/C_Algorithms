/* de um arquivo CSV conforme o padrÃ£o: 
 *         Series;Value;Time
 *         <int>;<float>;<string> 
 *         <int>;<float>;<string> */

/* Includes de sistema */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Includes do mÃ³dulo */
#include "dados.h"

/* Ativa depuraÃ§Ã£o do mÃ³dulo, comente para cÃ³digo final */
//#define DEBUG

struct dados
{
  char nome[64]; /*!< Nome: string */
  int idade;     /*!< Idade */
  char sexo;     /*!< Sexo */
};

dado_t *criar_dado(char *nome, int idade, char sexo)
{

  dado_t *meu_novo_dado = malloc(sizeof(struct dados));

  if (meu_novo_dado == NULL)
  {
    perror("Função: cria_dado");
    exit(EXIT_FAILURE);
  }

  strncpy(meu_novo_dado->nome, nome, 64);
  meu_novo_dado->idade = idade;
  meu_novo_dado->sexo = sexo;

  return meu_novo_dado;
}

dado_t **ler_dados_csv(char *nome_do_arquivo, int *total_dados)
{

  char info[64];
  int contador = 0;
  int i = 0;

  char nome[64]; /* Variaveis temporarias */
  int idade;
  char sexo;

  dado_t **meus_dados;

  FILE *fp = fopen(nome_do_arquivo, "r");

  if (!fp)
  {
    perror("Funcao: ler_dados_csv");
    exit(EXIT_FAILURE);
  }

  /* Ignora primeira linha */
  fgets(info, 64, fp);
  while (fgets(info, sizeof(info), fp) != NULL) // Le todas as linhas até achar o final
    contador++;

#ifdef DEBUG
  printf("%d", contador);
#endif
  rewind(fp);

  /* Ignora primeira linha */
  fgets(info, 64, fp);

  meus_dados = malloc(sizeof(dado_t *) * contador);

  if (meus_dados == NULL)
  {
    perror("Função: ler_dados_csv, alocação de memória");
    exit(EXIT_FAILURE);
  }

  while (fscanf(fp, "%64[^,],%d,%c", nome, &idade, &sexo) == 3)
  {
#ifdef DEBUG
    printf("%s - %d - %c", nome, idade, sexo);
#endif
    meus_dados[i] = criar_dado(nome, idade, sexo);
    i++;
  }

  fclose(fp);

  *total_dados = contador;
  return meus_dados;
}

char *obter_nome(dado_t *dado)
{
  return dado->nome;
}
int obter_idade(dado_t *dado)
{
  return dado->idade;
}
char obter_sexo(dado_t *dado)
{
  return dado->sexo;
}

void liberar_dados(dado_t **vetor, int n_linhas)
{
  int i = 0;

  for (i = 0; i < n_linhas; i++)
  {
    free(vetor[i]);
  }
  free(vetor);
}
