/** Programa que exibe na tela dados formatados
 * de um arquivo CSV conforme o padrÃ£o:
 *         Series;Value;Time
 *         <int>;<float>;<string>
 *         <int>;<float>;<string>
 */

#include <stdio.h>
#include <stdlib.h>
#include "dados.h"
#include "pilha.h"
#include "no.h"
#include "lista_enc.h"

int main()
{
  pilha_t *pilha = ler_dados_csv_pilha("velhinhos.csv");
  dado_t *dado;

  while (!pilha_vazia(pilha))
  {
    dado = pop(pilha);
    printf("%s - %d - %c\n", obter_nome(dado), obter_idade(dado), obter_sexo(dado));
    free(dado);
  }

  liberar_dados(pilha);

  return 0;
}
