/*
 ============================================================================
 Name        : grafos.c
 Author      :
 Version     :
 Copyright   : Renan Augusto Starke, todos os direitos reservados
 Description : grafos com lista encadeadas, Ansi-style
             : estruturas disponiveis:
             : pilha e fila
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#include "pilha.h"
#include "fila.h"
#include "grafo.h"

int main(void)
{

	grafo_t *grafo;
	vertice_t *vertice_inicial;
	int n_vertice;

	grafo = ler_dados_csv("Arquivocsv.csv", &n_vertice);
	printf("Numero de vertices:%d\n\n", n_vertice);

	vertice_inicial = procurar_vertice(grafo, 1);

	bfs(grafo, vertice_inicial);
	printf("Busca em largura:\n\n");
	print_vertice(grafo);
	printf("\nBusca em profundidade:\n");
	dfs(grafo, vertice_inicial);

	exportar_grafo_dot("grafo.dot", grafo);

	liberar_grafo(grafo);

	return EXIT_SUCCESS;
}
