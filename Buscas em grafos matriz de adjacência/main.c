/*
 ============================================================================
 Name        : grafos-adj-matrix.c
 Author      : Renan Augusto Starke
 Version     :
 Copyright   : Renan, todo os direitos reservados
 Description : grafos com matriz de adjacencia, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#include "grafo.h"

int main(void)
{
	int i, j;
	grafo_t *g;
	int n_vertice;

	g = ler_dados_csv("Arquivocsv.csv", &n_vertice); /* Le o arquivo e cria o grafo com os dados */

	printf("Numero de vertices:%d\n", n_vertice);

	for (i = 0; i < n_vertice; i++)
	{
		for (j = 0; j < n_vertice; j++)
			printf("[%d] [%d] : %d\n", i, j, adjacente(g, i, j));
	}

	bfs(g, 1); /* Busca por largura */
	mostra_bfs(g);

	dfs(g, 1); /* Busca por profundidade */

	exportar_dot(g); /* Exporta um arquivo .dot com o grafo */

	libera_grafo(g);

	return EXIT_SUCCESS;
}
