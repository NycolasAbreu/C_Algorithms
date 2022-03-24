#include <stdlib.h>
#include <stdio.h>

#include "lista_enc.h"
#include "no.h"
#include "fila.h"
#include "dados.h"

//cria uma pilha generica
fila_t *cria_fila(void)
{
	fila_t *fila = malloc(sizeof(fila_t));
	fila->dados = criar_lista_enc();

	return fila;
}

//adiciona elemento
void enqueue(void *dado, fila_t *fila)
{
	no_t *novo_no = criar_no(dado);
	add_cauda(fila->dados, novo_no);
}

//retira elemento do topo
void *dequeue(fila_t *fila)
{
	no_t *elemento = remover_cabeca(fila->dados);
	dado_t *dado = obter_dado(elemento);
	free(elemento);

	return dado;
}

void libera_fila(fila_t *fila)
{
	if (fila == NULL)
	{
		fprintf(stderr, "free dado: ponteiro invalido");
		exit(EXIT_FAILURE);
	}
	if (!fila_vazia(fila))
	{
		fprintf(stderr, "Tentativa de Liberar lista com dados");
		exit(EXIT_FAILURE);
	}
	free(fila->dados);
	free(fila);
}

int fila_vazia(fila_t *fila)
{
	return lista_vazia(fila->dados);
}
