#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>

struct dados
{
    char nome[64]; /*!< Nome: string */
    int idade;     /*!< Idade */
    char sexo;     /*!< Sexo */
};

int main()
{
    int i = 0;
    int n_linhas = 0;
    char info[64];

    /* Ponteiro para alocação dinâmica dos dados */
    struct dados *dados = NULL;

    FILE *fp = fopen("velhinhos.csv", "r");

    if (!fp)
    {
        perror("main");
        exit(-1);
    }

    /* Ignora primeira linha */
    fgets(info, 64, fp);

    /* Contar todas as linhas: use while e fgets() */
    while (fgets(info, sizeof(info), fp) != NULL) // Le todas as linhas até achar o final
    {
        n_linhas++;
    }

    //printf("%d\n", n_linhas);

    /* Aloque memória: */
    dados = malloc(sizeof(struct dados) * n_linhas);

    if (dados == NULL)
    {
        perror("main");
        exit(EXIT_FAILURE);
    }

    rewind(fp);
    /* Ignora primeira linha */
    fgets(info, 64, fp);

    /* Modifique aqui para colocar os dados no vetor de estruturas alocado  dinamicamente ex: dados[i].sexo <- recebe sexo do arquivo;*/
    //while (...){
    //   printf(...);
    //}

    while (fscanf(fp, "%64[^,],%d,%c", dados[i].nome, &dados[i].idade, &dados[i].sexo) == 3)
    {
        i++;
    }

    /* Imprima os dados:*/
    for (i = 0; i < n_linhas; i++)
    {
        printf("%s - %d - %c", dados[i].nome, dados[i].idade, dados[i].sexo);
    }

    free(dados);
    fclose(fp);
}
