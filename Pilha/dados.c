#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

    // Colocar a criaÃ§Ã£o dos dados aqui

    strncpy(meu_novo_dado->nome, nome, 64);
    meu_novo_dado->idade = idade;
    meu_novo_dado->sexo = sexo;

    return meu_novo_dado;
}

pilha_t *ler_dados_csv_pilha(char *nome_do_arquivo)
{

    char texto[64];
    char nome[64];
    int idade;
    char sexo;
    pilha_t *pilha;
    dado_t *dado;

    FILE *fp = fopen(nome_do_arquivo, "r");

    if (!fp)
    {
        perror("ler_dados_csv");
        exit(-1);
    }

    pilha = cria_pilha();

    /* Ignora primeira linha */
    fgets(texto, 64, fp);

    /* Note que nÃ£o e mais necessÃ¡rio contar as linhas */

    while (fscanf(fp, "%64[^,],%d,%c", nome, &idade, &sexo) == 3)
    {
        //printf("%s - %d - %c", nome, idade, sexo);

        /* Cria um novo dado abstrato e armazena a sua referÃªncia */
        dado = criar_dado(nome, idade, sexo);
        push(dado, pilha);
    }

    fclose(fp);
    return pilha;
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

void liberar_dados(pilha_t *pilha)
{
    free(pilha->dados);
    free(pilha);
}
