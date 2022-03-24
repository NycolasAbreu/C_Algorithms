/*
 * grafo.h
 *
 *  Created on: Nov 18, 2016
 *      Author: Renan Augusto Starke
 */

#ifndef GRAFO_H_
#define GRAFO_H_

#define TRUE 1
#define FALSE 0

typedef struct vertices vertice_t;
typedef struct arestas aresta_t;
typedef struct grafos grafo_t;

grafo_t *cria_grafo(int vertices);
void libera_grafo(grafo_t *g);
int cria_adjacencia(grafo_t *g, int u, int v);
int rem_adjacencia(grafo_t *g, int u, int v);
int adjacente(grafo_t *g, int u, int v);
void bfs(grafo_t *g, int fonte);
void dfs(grafo_t *g, int fonte);
void mostra_bfs(grafo_t *g);
grafo_t *ler_dados_csv(char *nome_do_arquivo, int *int_n_vertice);
void exportar_dot(grafo_t *g);

#endif /* GRAFO_H_ */
