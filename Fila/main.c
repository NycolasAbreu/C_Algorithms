#include <stdio.h>
#include <stdlib.h>

#include "dados.h"
#include "fila.h"
#include "no.h"
#include "lista_enc.h"

int main()
{
  fila_t *fila = ler_dados_csv_fila("velhinhos.csv");
  dado_t *meu_dado;

  /* Imprima os dados:*/
  while (!fila_vazia(fila))
  {
    meu_dado = dequeue(fila);
    printf("%s - %d - %c\n", obter_nome(meu_dado), obter_idade(meu_dado), obter_sexo(meu_dado));
    free(meu_dado);
  }

  liberar_dados(fila);

  return 0;
}
