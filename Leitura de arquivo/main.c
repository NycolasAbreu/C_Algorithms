/** Programa que exibe na tela dados formatados
  * de um arquivo CSV conforme o padrão:
  *
  *         Cabeçalho
  *         <string>;<int>;<char>
  *         <string>;<int>;<char>
  */

#include <stdio.h>  /* Para fgets, fscanf, ... */
#include <stdlib.h> /* Para exit, malloc, ... */

int main()
{
    /* Tipos das colunas do arquivo */
    char nome[128];
    int idade;
    char sexo;

    FILE *fp = fopen("velhinhos.csv", "r");

    if (fp == NULL)
    {
        perror("main");
        exit(-1);
    }

    /* Ignora primeira linha */
    fgets(nome, 128, fp);
    printf("Ignorando: %s", nome);

    /* Use a construção do fscanf para ler o arquivo e complete abaixo */

    while (fscanf(fp, "%127[^,],%d,%c", nome, &idade, &sexo) == 3)
    {
        printf("%s - %d - %c", nome, idade, sexo);
    }
    fclose(fp);
}
