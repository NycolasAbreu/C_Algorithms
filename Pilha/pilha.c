#include <stdlib.h>
#include <stdio.h>

#include "pilha.h"
#include "dados.h"

//#define DEBUG
//cria uma pilha generica
pilha_t *cria_pilha(void)
{
    pilha_t *pilha = malloc(sizeof(pilha_t));
    pilha->dados = criar_lista_enc();
    return pilha;
}

//adiciona elemento
void push(void *dado, pilha_t *pilha)
{
    no_t *elemento = criar_no(dado);
    add_cabeca(pilha->dados, elemento);
}

//retira elemento do topo
void *pop(pilha_t *pilha)
{
    no_t *elemento = remover_cabeca(pilha->dados);
    dado_t *dado = obter_dado(elemento);
    free(elemento);
    return dado;
}

void libera_pilha(pilha_t *pilha)
{
    if (pilha == NULL)
    {
        fprintf(stderr, "free dado: ponteiro invalido");
        exit(EXIT_FAILURE);
    }
    if (!pilha_vazia(pilha))
    {
        fprintf(stderr, "Tentativa de Liberar lista com dados");
        exit(EXIT_FAILURE);
    }
    free(pilha->dados);
    free(pilha);
}

int pilha_vazia(pilha_t *pilha)
{
    return lista_vazia(pilha->dados);
}
