/** Programa que exibe na tela dados formatados
 * de um arquivo CSV conforme o padrÃ£o: 
 *         Series;Value;Time
 *         <int>;<float>;<string> 
 *         <int>;<float>;<string>
 */

#include <stdio.h>
#include "dados.h"

int main()
{
  int i;
  int n_linhas = 0;

  dado_t **dados = ler_dados_csv("velhinhos.csv", &n_linhas);

  /* Imprima os dados:*/
  for (i = 0; i < n_linhas; i++)
  {
    printf("%s - %d - %c", obter_nome(dados[i]), obter_idade(dados[i]), obter_sexo(dados[i]));
  }

  liberar_dados(dados, n_linhas);

  return 0;
}
