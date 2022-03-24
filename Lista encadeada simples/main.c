/** Programa que exibe na tela dados formatados
  * de um arquivo CSV conforme o padrão:
  *         Series;Value;Time
  *         <int>;<float>;<string>
  *         <int>;<float>;<string>
  */

#include <stdio.h>
#include "dados.h"
#include "lista_enc.h"

int main()
{
  lista_enc_t *lista = ler_dados_csv("velhinhos.csv");

  no_t *no;
  dado_t *meu_dado;

  no = obter_cabeca(lista);

  /* Imprima os dados:*/
  while (no != NULL)
  {
    meu_dado = obter_dado(no);

    printf("%s - %d - %c", obter_nome(meu_dado), obter_idade(meu_dado), obter_sexo(meu_dado));

    no = obter_proximo(no);
  }

  liberar_dados(lista);

  return 0;
}
