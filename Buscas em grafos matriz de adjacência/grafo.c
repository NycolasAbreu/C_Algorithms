/*
 * grafo.c
 *
 *  Created on: Nov 18, 2016
 *      Author: Renan Augusto Starke
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>

#include "grafo.h"
#include "fila.h"
#include "pilha.h"
#include "lista_enc.h"
#include "no.h"

#define INFINITO INT_MAX

struct vertices
{
	int id; /*!< Identificação numérica do vértice  */

	/* Dados do BFS */
	int visitado;
	int distancia;
	int pai;
};

struct arestas
{
	int adj; /*!< Valor booleando. Verdadeiro representa uma adjacência entre dois vértices  */

	/* Mais informações, se necessário */
};

struct grafos
{
	int n_vertices;		   /*!< Número de vértices do grafo  */
	vertice_t *vertices;   /*!< Vetor de ponteiros: conjunto V */
	aresta_t **matriz_adj; /* Matriz de adjacência: conjunto E */
};

/**
  * @brief  Cria uma novo grafo estático
  * @param	vertices: quantidade de vértices
  *
  * @retval grafo_t: ponteiro para um novo grafo
  */
grafo_t *cria_grafo(int vertices)
{
	int i;
	aresta_t **matriz_adj;
	/* Aloca estrutura do grafo */
	grafo_t *g = malloc(sizeof(grafo_t));

	if (g == NULL)
	{
		perror("cria_grafo (g)");
		exit(EXIT_FAILURE);
	}

	/* Guarda número total de vértices */
	g->n_vertices = vertices;
	/* Aloca vértices */
	g->vertices = malloc(vertices * sizeof(vertice_t));

	if (g->vertices == NULL)
	{
		perror("cria_grafo (vertices)");
		exit(EXIT_FAILURE);
	}

	/* Zera vetor de vértices */
	memset(g->vertices, 0, vertices * sizeof(vertice_t));

	/* Inicializa ID */
	for (i = 0; i < vertices; i++)
	{
		g->vertices[i].id = i;
	}

	/* Aloca 1a dimensão da matriz de adjacência */
	matriz_adj = malloc(vertices * sizeof(aresta_t *));

	if (matriz_adj == NULL)
	{
		perror("cria_grafo (matriz_adj)");
		exit(EXIT_FAILURE);
	}

	/* Aloca 2a dimensão da matriz de adjacência */
	for (i = 0; i < vertices; i++)
	{
		matriz_adj[i] = calloc(vertices, sizeof(aresta_t));

		if (matriz_adj[i] == NULL)
		{
			perror("cria_grafo (matriz_adj[i])");
			exit(EXIT_FAILURE);
		}
	}

	g->matriz_adj = matriz_adj;

	return g;
}

/**
  * @brief  Libera a memória utilizada pelo grafo
  * @param	Nenhum
  *
  * @retval Nenhum
  */
void libera_grafo(grafo_t *g)
{
	int i;

	if (g == NULL)
	{
		perror("libera_grafo");
		exit(EXIT_FAILURE);
	}

	for (i = 0; i < g->n_vertices; i++)
		free(g->matriz_adj[i]);

	free(g->matriz_adj);
	free(g->vertices);
	free(g);
}

/**
  * @brief  Cria adjacência entre vértices u e v
  * @param	u: índice do vértice u
  * @param  v: índice do vértice v
  *
  * @retval int: verdadeiro se adjacência for criada
  */
int cria_adjacencia(grafo_t *g, int u, int v)
{

	if (g == NULL)
	{
		return FALSE;
	}

	if (u > g->n_vertices || v > g->n_vertices)
		return FALSE;

	g->matriz_adj[u][v].adj = TRUE;

	return TRUE;
}

/**
  * @brief  Remove adjacência entre vértices u e v
  * @param	u: índice do vértice u
  * @param  v: índice do vértice v
  *
  * @retval int: verdadeiro se adjacência for removida
  */
int rem_adjacencia(grafo_t *g, int u, int v)
{

	if (g == NULL)
	{
		return FALSE;
	}

	if (u > g->n_vertices || v > g->n_vertices)
		return FALSE;

	g->matriz_adj[u][v].adj = FALSE;

	return TRUE;
}

/**
  * @brief  Retorna adjacência entre vértices u e v
  * @param	u: índice do vértice u
  * @param  v: índice do vértice v
  *
  * @retval int: verdadeiro se u for adjacente a v
  */
int adjacente(grafo_t *g, int u, int v)
{
	if (u > g->n_vertices || v > g->n_vertices)
		return FALSE;

	return ((g->matriz_adj[u][v].adj));
}

void bfs(grafo_t *g, int fonte) /* Busca em largura */
{
	fila_t *fila = cria_fila(); /* Cria fila vazia */

	int i;
	for (i = 0; i < g->n_vertices; i++) /* Inicia os valores dos vértices */
	{
		g->vertices[i].distancia = INFINITO;
		g->vertices[i].pai = -1;
	}

	g->vertices[fonte].distancia = 0; /* Distância da fonte é 0 */

	enqueue((void *)fonte, fila); /* Coloca na fila o primeiro elemento */

	while (!fila_vazia(fila)) /* Enquanto a fila não está vazia percorre os elementos */
	{
		int u = (int)dequeue(fila);

		for (i = 0; i < g->n_vertices; i++)
		{

			if (adjacente(g, u, i) == TRUE) /* Se for adjacente ao próximo indice então entra no loop */
			{

				if (g->vertices[i].distancia == INFINITO) /* Se a distancia do proximo for INFINITO adiciona este elemento como pai e o seu adjacente como filho */
				{
					g->vertices[i].distancia = (g->vertices[u].distancia) + 1;
					g->vertices[i].pai = u;

					enqueue((void *)i, fila); /* Elemento entra na fila para checar se tem adjacente */
				}
			}
		}
	}
	libera_fila(fila);
}

void mostra_bfs(grafo_t *g)
{
	int i;
	for (i = 0; i < g->n_vertices; i++)
	{
		printf(" Vertice: %d, distancia: %d, pai: %d\n", i, g->vertices[i].distancia, g->vertices[i].pai);
	}
}

void dfs(grafo_t *g, int fonte) /* Busca em profundidade */
{
	pilha_t *pilha = cria_pilha(); /* Cria pilha vazia */

	int i;
	for (i = 0; i < g->n_vertices; i++) /* Inicia os valores dos vértices */
	{
		g->vertices[i].visitado = FALSE;
	}

	push((void *)fonte, pilha); /* Empilha o primeiro elemento */

	while (!pilha_vazia(pilha)) /* Enquanto a pilha não está vazia percorre os elementos */
	{
		int u = (int)pop(pilha);

		if ((g->vertices[u].visitado) == FALSE)
		{
			g->vertices[u].visitado = TRUE;

			printf("u: %d \n", u);

			for (i = 0; i < g->n_vertices; i++)
			{
				if (adjacente(g, u, i) == TRUE)
				{
					push((void *)i, pilha);
				}
			}
		}
	}
	libera_pilha(pilha);
}

void exportar_dot(grafo_t *g)
{
	int i, j;

	FILE *fp = fopen("grafo.dot", "w");

	if (!fp)
	{
		perror("exportar_dot");
		exit(EXIT_FAILURE);
	}

	fputs("graph {", fp);

	for (i = 0; i < g->n_vertices; i++)
		for (j = i; j < g->n_vertices; j++)
		{

			if (adjacente(g, i, j))
				fprintf(fp, "\t%d -- %d [label = %d];\n", i, j, 0);
		}
	fputs("}", fp);
	fclose(fp);
}

grafo_t *ler_dados_csv(char *nome_do_arquivo, int *int_n_vertice)
{
	grafo_t *g;
	char n_vertices[4];
	int i, v1, v2;

	FILE *fp = fopen(nome_do_arquivo, "r");

	if (!fp)
	{
		perror("ler_dados_csv");
		exit(-1);
	}

	fscanf(fp, "%3s", n_vertices);	   /* Le a primeira linha */
	*int_n_vertice = atoi(n_vertices); /* Passa o valor para inteiro */

	g = cria_grafo(*int_n_vertice); /* Cria o grafo com o numero de vertices lido */

	while (fscanf(fp, "%d,%d", &v1, &v2) == 2) /* Varre o arquivo em busca de adjacencias */
	{
		//printf("\n%d %d", v1, v2);
		cria_adjacencia(g, v1, v2);
	}

	fclose(fp);
	return g;
}