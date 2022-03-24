#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dados.h"
#include "fila.h"

struct dados
{
    char nome[64];
    int idade;
    char sexo;
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

fila_t *ler_dados_csv_fila(char *nome_do_arquivo)
{
    char texto[64];
    char nome[64];
    int idade;
    char sexo;
    fila_t *fila;
    dado_t *dado;

    FILE *fp = fopen(nome_do_arquivo, "r");

    if (!fp)
    {
        perror("ler_dados_csv");
        exit(-1);
    }

    fila = cria_fila();

    /* Ignora primeira linha */
    fgets(texto, 64, fp);

    while (fscanf(fp, "%64[^,],%d,%c\n", nome, &idade, &sexo) == 3)
    {
        //printf("%s - %d - %c", nome, idade, sexo);

        /* Cria um novo dado abstrato e armazena a sua referÃªncia */
        dado = criar_dado(nome, idade, sexo);
        enqueue(dado, fila);
    }

    fclose(fp);
    return fila;
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

void liberar_dados(fila_t *fila)
{
    if (!fila_vazia(fila))
        fprintf(stderr, "Aviso: librando fila não vazia");
    else
    {
        free(fila->dados);
        free(fila);
    }
}
