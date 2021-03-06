/*
 * grafo.c
 *
 *  Created on: Jul 5, 2016
 *      Author: Renan Augusto Starke
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <limits.h>
#include "grafo.h"
#include "vertice.h"
#include "lista_enc.h"
#include "no.h"
#include "fila.h"

#include "pilha.h"

#define FALSE 0
#define TRUE 1

//#define DEBUG

#define INFINITO INT_MAX

struct grafos
{
	int id;				   /*!< Identificação numérica do grafo  */
	lista_enc_t *vertices; /*!< Lista encadeada dos vértices: conjunto V  */
};

/**
  * @brief  Busca em largura
  * @param	grafo: ponteiro do grafo que se deseja executar a busca
  * @param  inicial: ponteiro do vértice inicial (fonte) da busca
  *
  * @retval Nenhum: Vértices são marcados internamente
  */
void bfs(grafo_t *grafo, vertice_t *inicial)
{
	fila_t *Q = criar_fila();
	no_t *no = obter_cabeca(grafo->vertices);

	while (no) /* Inicia todos os dados em NULL/INFINITO */
	{
		vertice_t *v = obter_dado(no);

		vertice_set_pai(v, NULL);
		vertice_set_dist(v, INFINITO);

		no = obter_proximo(no);
	}

	vertice_set_dist(inicial, 0); /* Distancia do inicio até o inicio é 0 */
	enqueue(inicial, Q);		  /* Coloca na fila o primeiro dado */

	while (!fila_vazia(Q)) /* Enquanto tiver elementos na fila faz o loop */
	{
		vertice_t *u = dequeue(Q);

		//printf("\tu: %d\n", vertice_get_id(u)); /* Vertice analisado no momento */

		lista_enc_t *lista_arestas = vertice_get_arestas(u); /* Recebe as arestas de u */
		no = obter_cabeca(lista_arestas);

		while (no) /* Para todo vertice adjacente de u faz */
		{
			arestas_t *aresta = obter_dado(no);			 /* Recebe os dados das arestas */
			vertice_t *v = aresta_get_adjacente(aresta); /* Pega o adjacente */

			//printf("\t\tAdjacente: %d\n", vertice_get_id(v));

			int distancia = vertice_get_dist(v);

			if (vertice_get_dist(v) == INFINITO) /* Se o vertice não foi analisado faz */
			{
				vertice_set_dist(v, vertice_get_dist(u) + 1); /* Aumenta a distancia */

				//printf("Incuido: %d ---- distancia: %d\n", vertice_get_id(v), vertice_get_dist(v));

				vertice_set_pai(v, u); /* Muda o pai para o id de u */
				enqueue(v, Q);
			}

			no = obter_proximo(no);
		}
	}
	liberar_fila(Q);
}

/**
  * @brief  Busca em profundidade
  * @param	grafo: ponteiro do grafo que se deseja executar a busca
  * @param  inicial: ponteiro do vértice inicial (fonte) da busca
  *
  * @retval Nenhum: Vértices são marcados internamente
  */
void dfs(grafo_t *grafo, vertice_t *inicial)
{
	pilha_t *pilha = cria_pilha();
	no_t *no = obter_cabeca(grafo->vertices);

	while (no) /* Inicia todos os dados de visitado em FALSE */
	{
		vertice_t *v = obter_dado(no);
		vertice_set_dist(v, FALSE);

		no = obter_proximo(no);
	}

	printf("\nIncuido: %d ---- distancia: %d\n", vertice_get_id(inicial), vertice_get_dist(inicial));

	push(inicial, pilha); /* Empilha o primeiro elemento */

	while (!pilha_vazia(pilha)) /* Enquanto tiver elementos na pilha faz o loop */
	{
		vertice_t *u = pop(pilha);

		if (vertice_get_dist(u) == FALSE) /* Se nao foi visitado ainda faz */
		{
			vertice_set_dist(u, TRUE); /* Estabelece como visitado */

			lista_enc_t *lista_aresta = vertice_get_arestas(u); /* Recebe as arestas de u */

			printf("\tu: %d\n", vertice_get_id(u));

			no_t *no_aresta = obter_cabeca(lista_aresta);

			while (no_aresta) /* Para todo vertice adjacente de u faz */
			{
				arestas_t *aresta = obter_dado(no_aresta);	 /* Recebe os dados das arestas */
				vertice_t *v = aresta_get_adjacente(aresta); /* Pega o adjacente */

				printf("\t\tAdjacente: %d\n", vertice_get_id(v));

				push(v, pilha);
				no_aresta = obter_proximo(no_aresta);
			}
		}
	}
	libera_pilha(pilha);
}

grafo_t *ler_dados_csv(char *nome_do_arquivo, int *int_n_vertice)
{
	grafo_t *grafo;
	vertice_t *vertice;
	char n_vertices[4];
	int i = 0, v1, v2;

	FILE *fp = fopen(nome_do_arquivo, "r");

	if (!fp)
	{
		perror("ler_dados_csv");
		exit(-1);
	}

	fscanf(fp, "%3s", n_vertices);	   /* Le a primeira linha */
	*int_n_vertice = atoi(n_vertices); /* Passa o valor para inteiro */

	grafo = criar_grafo(0); /* Cria o grafo */

	while (i < *int_n_vertice) /* Adiciona as vertices */
	{
		vertice = grafo_adicionar_vertice(grafo, i);
		i++;
	}

	while (fscanf(fp, "%d,%d", &v1, &v2) == 2) /* Varre o arquivo em busca de adjacencias */
	{
		//printf("\n%d %d", v1, v2);
		adicionar_adjacentes_id(grafo, v1, 1, v2);
	}

	fclose(fp);
	return grafo;
}

void print_vertice(grafo_t *grafo)
{
	no_t *no = obter_cabeca(grafo->vertices);
	int dist;

	while (no)
	{
		vertice_t *v = obter_dado(no);
		vertice_t *pai = vertice_get_pai(v);

		printf("Id do vertice: %d", vertice_get_id(v));

		if (pai != NULL)
			printf(" ---- Pai do vertice: %d", vertice_get_id(pai));
		else
			printf(" ---- Sem pai");

		dist = vertice_get_dist(v);

		if (dist == INFINITO)
		{
			printf(" ---- Distancia do inicio: Nao ligado\n");
		}
		else
			printf(" ---- Distancia do inicio: %d\n", dist);

		no = obter_proximo(no);
	}
}

/**
  * @brief  Cria uma novo grafo 
  * @param	id: Identificação numérica do grafo
  *
  * @retval grafo_t: ponteiro para um novo grafo
  */
grafo_t *criar_grafo(int id)
{
	grafo_t *p = NULL;

	p = (grafo_t *)malloc(sizeof(grafo_t));

	if (p == NULL)
	{
		perror("cria_grafo:");
		exit(EXIT_FAILURE);
	}

	p->id = id;
	p->vertices = cria_lista_enc();

	return p;
}

/**
  * @brief  Adicionar um vértice no grafo (conjunto V)
  * @param	grafo: ponteiro do grafo que se deseja adicionar um vértice
  * @param  id: identificação da vértice
  *
  * @retval vertice_t: ponteiro do vértice criado e adicionada no grafo
  */
vertice_t *grafo_adicionar_vertice(grafo_t *grafo, int id)
{
	vertice_t *vertice;
	no_t *no;

#ifdef DEBUG
	printf("grafo_adicionar_vertice: %d\n", id);
#endif

	if (grafo == NULL)
	{
		fprintf(stderr, "grafo_adicionar_vertice: grafo invalido!");
		exit(EXIT_FAILURE);
	}

	if (procurar_vertice(grafo, id) != NULL)
	{
		fprintf(stderr, "grafo_adicionar_vertice: vertice duplicado!\n");
		exit(EXIT_FAILURE);
	}

	vertice = criar_vertice(id);
	no = criar_no(vertice);

	add_cauda(grafo->vertices, no);

	return vertice;
}

/**
  * @brief  Procura um vértice com id específico no grafo
  * @param	grafo: ponteiro do grafo que se deseja busca o vértice
  * @param  id: identificação da aresta
  *
  * @retval vertice_t: ponteiro do vértice. NULL se não encontrado
  */
vertice_t *procurar_vertice(grafo_t *grafo, int id)
{
	no_t *no_lista;
	vertice_t *vertice;
	int meu_id;

	if (grafo == NULL)
	{
		fprintf(stderr, "procura_vertice: grafo invalido!");
		exit(EXIT_FAILURE);
	}

	if (lista_vazia(grafo->vertices) == TRUE)
		return FALSE;

	no_lista = obter_cabeca(grafo->vertices);

	while (no_lista)
	{
		//obtem o endereco da lista
		vertice = obter_dado(no_lista);

		//obterm o id do vertice
		meu_id = vertice_get_id(vertice);

		if (meu_id == id)
		{
			return vertice;
		}

		no_lista = obter_proximo(no_lista);
	}

	return NULL;
}

/**
  * @brief  Cria adjacências.
  * @param	grafo: ponteiro do grafo que contém o vértice (V pertence a G)
  * @param  vertice: vértice fonte da(s) adjacências
  * @param  n: número de vértices adjacentes
  * @param  ...: vértices adjacentes (máx n)
  *
  * @retval Nenhum
  *
  * Ex: adicionar uma aresta para o vertice 2 e 3
  * adiciona_adjacentes(grafo, vertice_id, 2, 2, 3);
  */

void adicionar_adjacentes_id(grafo_t *grafo, int vertice_id, int n, ...)
{
	va_list argumentos;
	vertice_t *vertice;
	vertice_t *sucessor;
	arestas_t *aresta;

	int x;
	int id_sucessor;

	vertice = procurar_vertice(grafo, vertice_id);

	if (vertice == NULL)
	{
		fprintf(stderr, "adiciona_adjacentes_id: vértice %d inexistente!", vertice_id);
		exit(-1);
	}

	/* Initializing arguments to store all values after num */
	va_start(argumentos, n);

	for (x = 0; x < n; x++)
	{
		id_sucessor = va_arg(argumentos, int);

		sucessor = procurar_vertice(grafo, id_sucessor);

		if (sucessor == NULL)
		{
			fprintf(stderr, "adiciona_adjacentes: sucessor nao encontrado no grafo\n");
			exit(EXIT_FAILURE);
		}

		aresta = criar_aresta(vertice, sucessor, 1);
		adicionar_aresta(vertice, aresta);

#ifdef DEBUG
		printf("\tvertice: %d\n", vertice_get_id(vertice));
		printf("\tsucessor: %d\n", id_sucessor);
		printf("\tpeso: %d\n", peso);
#endif
	}

	va_end(argumentos);
}

/**
  * @brief  Cria adjacências.
  * @param	grafo: ponteiro do grafo que contém o vértice (V pertence a G)
  * @param  vertice: vértice fonte da(s) adjacências
  * @param  n: número de parâmetros após n
  * @param  ...: pares ordenados dos vertices destino e peso da aresta: (id vertice destino, peso aresta)
  *
  * @retval Nenhum
  *
  * Ex: adicionar uma aresta para o vertice 2 e 3 com respectivos pesos 9 e 15
  * adiciona_adjacentes(grafo, vertice_id, 4(n), 2, 9, 3, 15);
  */

void adicionar_adjacentes_id_peso(grafo_t *grafo, int vertice_id, int n, ...)
{
	va_list argumentos;
	vertice_t *vertice;
	vertice_t *sucessor;
	arestas_t *aresta;

	int id_sucessor;
	int peso;
	int x;

	vertice = procurar_vertice(grafo, vertice_id);

	if (vertice == NULL)
	{
		fprintf(stderr, "adiciona_adjacentes_id: vértice %d inexistente!", vertice_id);
		exit(-1);
	}

	/* Initializing arguments to store all values after num */
	va_start(argumentos, n);

	for (x = 0; x < n; x = x + 2)
	{
		id_sucessor = va_arg(argumentos, int);
		peso = va_arg(argumentos, int);

		sucessor = procurar_vertice(grafo, id_sucessor);

		if (sucessor == NULL)
		{
			fprintf(stderr, "adiciona_adjacentes: sucessor nao encontrado no grafo\n");
			exit(EXIT_FAILURE);
		}

		aresta = criar_aresta(vertice, sucessor, peso);
		adicionar_aresta(vertice, aresta);

#ifdef DEBUG
		printf("\tvertice: %d\n", vertice_get_id(vertice));
		printf("\tsucessor: %d\n", id_sucessor);
		printf("\tpeso: %d\n", peso);
#endif
	}

	va_end(argumentos);
}

/**
  * @brief  Cria adjacências. 
  * @param	grafo: ponteiro do grafo que contém o vértice (V pertence a G)
  * @param  vertice: vértice fonte da(s) adjacências
  * @param  n: número de parâmetros após n
  * @param  ...: pares ordenados dos vertices destino e peso da aresta: (id vertice destino, peso aresta)
  *
  * @retval Nenhum
  * 
  * Ex: adicionar uma aresta para o vertice 2 e 3 com respectivos pesos 9 e 15
  * adiciona_adjacentes(grafo, vertice, 4(n), 2, 9, 3, 15);
  */

void adicionar_adjacentes_ptr_peso(grafo_t *grafo, vertice_t *vertice, int n, ...)
{
	va_list argumentos;
	vertice_t *sucessor;
	arestas_t *aresta;

	int id_sucessor;
	int peso;
	int x;

	/* Initializing arguments to store all values after num */
	va_start(argumentos, n);

	for (x = 0; x < n; x = x + 2)
	{
		id_sucessor = va_arg(argumentos, int);
		peso = va_arg(argumentos, int);

		sucessor = procurar_vertice(grafo, id_sucessor);

		if (sucessor == NULL)
		{
			fprintf(stderr, "adiciona_adjacentes: sucessor nao encontrado no grafo\n");
			exit(EXIT_FAILURE);
		}

		aresta = criar_aresta(vertice, sucessor, peso);
		adicionar_aresta(vertice, aresta);

#ifdef DEBUG
		printf("\tvertice: %d\n", vertice_get_id(vertice));
		printf("\tsucessor: %d\n", id_sucessor);
		printf("\tpeso: %d\n", peso);
#endif
	}

	va_end(argumentos);
}

/**
  * @brief  Exporta o grafo em formato dot.
  * @param	filename: nome do arquivo dot gerado
  * @param  grafo: ponteiro do grafo a ser exportado
  *
  * @retval Nenhum
  */
void exportar_grafo_dot(const char *filename, grafo_t *grafo)
{
	FILE *file;

	no_t *no_vert;
	no_t *no_arest;
	vertice_t *vertice;
	vertice_t *adjacente;
	arestas_t *aresta;
	arestas_t *contra_aresta;
	lista_enc_t *lista_arestas;

	int peso;

	if (filename == NULL || grafo == NULL)
	{
		fprintf(stderr, "exportar_grafp_dot: ponteiros invalidos\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(filename, "w");

	if (file == NULL)
	{
		perror("exportar_grafp_dot:");
		exit(EXIT_FAILURE);
	}

	fprintf(file, "graph {\n");

	//obtem todos os nos da lista
	no_vert = obter_cabeca(grafo->vertices);
	while (no_vert)
	{
		vertice = obter_dado(no_vert);

		//obtem todos as arestas
		lista_arestas = vertice_get_arestas(vertice);

		no_arest = obter_cabeca(lista_arestas);
		while (no_arest)
		{
			aresta = obter_dado(no_arest);

			//ignora caso já exportada
			if (aresta_get_status(aresta) == EXPORTADA)
			{
				no_arest = obter_proximo(no_arest);
				continue;
			}

			//marca como exportada esta aresta
			aresta_set_status(aresta, EXPORTADA);
			adjacente = aresta_get_adjacente(aresta);

			//marca contra-aresta também como exporta no caso de grafo não direcionados
			contra_aresta = procurar_adjacente(adjacente, vertice);
			aresta_set_status(contra_aresta, EXPORTADA);

			//obtem peso
			peso = aresta_get_peso(aresta);

			fprintf(file, "\t%d -- %d [label = %d];\n",
					vertice_get_id(vertice),
					vertice_get_id(adjacente),
					peso);

			no_arest = obter_proximo(no_arest);
		}
		no_vert = obter_proximo(no_vert);
	}
	fprintf(file, "}\n");
	fclose(file);
}

/**
  * @brief  Libera a memória utilizada pelo grafo
  * @param  grafo: ponteiro do grafo a ser exportado
  *
  * @retval Nenhum
  */
void liberar_grafo(grafo_t *grafo)
{
	no_t *no_vert;
	no_t *no_arest;
	no_t *no_liberado;
	vertice_t *vertice;
	arestas_t *aresta;
	lista_enc_t *lista_arestas;

	if (grafo == NULL)
	{
		fprintf(stderr, "libera_grafo: grafo invalido\n");
		exit(EXIT_FAILURE);
	}

	//varre todos os vertices
	no_vert = obter_cabeca(grafo->vertices);
	while (no_vert)
	{
		vertice = obter_dado(no_vert);

		//libera todas as arestas
		lista_arestas = vertice_get_arestas(vertice);
		no_arest = obter_cabeca(lista_arestas);
		while (no_arest)
		{
			aresta = obter_dado(no_arest);

			//libera aresta
			free(aresta);

			//libera no da lsita
			no_liberado = no_arest;
			no_arest = obter_proximo(no_arest);
			free(no_liberado);
		}

		//libera lista de arestas e vertice
		free(lista_arestas);
		free(vertice);

		//libera no da lista
		no_liberado = no_vert;
		no_vert = obter_proximo(no_vert);
		free(no_liberado);
	}

	//libera grafo e vertice
	free(grafo->vertices);
	free(grafo);
}
