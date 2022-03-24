#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lista_enc.h"
#include "dados.h"

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

lista_enc_t *ler_dados_csv(char *nome_do_arquivo)
{
    char texto[64];

    /* Demais Variáveis */
    lista_enc_t *lista;
    dado_t *dado;
    no_t *meu_no;

    char nome[64];
    int idade;
    char sexo;

    /* Veriáveis locais, conforme struct dados */

    FILE *fp = fopen(nome_do_arquivo, "r");

    if (!fp)
    {
        perror("ler_dados_csv");
        exit(-1);
    }

    lista = criar_lista_enc();

    /* Ignora primeira linha */
    fgets(texto, 64, fp);

    /* Note que não e mais necessário contar as linhas */

    while (fscanf(fp, "%64[^,],%d,%c", nome, &idade, &sexo) == 3)
    {
        //printf("%s - %d - %c", nome, idade, sexo);

        /* Cria um novo dado abstrato e armazena a sua referência */
        dado = criar_dado(nome, idade, sexo);
        meu_no = criar_no(dado);
        add_cauda(lista, meu_no);
    }

    fclose(fp);
    return lista;
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

void liberar_dados(lista_enc_t *lista)
{
    if (lista == NULL)
    {
        fprintf(stderr, "Erro desalocando memoria da lista, ponteiro invalido!");
        exit(EXIT_FAILURE);
    }

    dado_t *meu_dado;
    no_t *no_ant, *no;
    no = obter_cabeca(lista);

    while (no != NULL)
    {
        meu_dado = obter_dado(no);
        free(meu_dado);
        no_ant = no;
        no = obter_proximo(no);
        free(no_ant);
    }

    free(lista);
}