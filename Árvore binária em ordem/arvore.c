/*
 * arvore.c
 *
 *  Created on: Nov 25, 2016
 *      Author: Renan Augusto Starke
 */

#include <stdio.h>
#include <stdlib.h>
#include "subarvore.h"
#include "arvore.h"

#define FALSE 0
#define TRUE 1

struct arvores
{
	int id;					 /*!< Identificação numérica da árvore */
	subarvore_t *raiz;		 /*!< Ponteiro para o vértice raiz  */
	lista_enc_t *subarvores; /*!< Lista encadeada de vértices  */
};

subarvore_t *arvore_procura_subarvore(arvore_t *arvore, int id);

/**
  * @brief  Cria uma árvore. Grau depende do vértice.
  * @param	id: identificação numérica da árvore.
  *
  * @retval arvore_t: ponteiro para uma nova árvore.
  */
arvore_t *cria_arvore(int id)
{
	arvore_t *p = NULL;

	p = (arvore_t *)malloc(sizeof(arvore_t));

	if (p == NULL)
	{
		perror("cria_grafo:");
		exit(EXIT_FAILURE);
	}

	p->id = id;
	p->subarvores = cria_lista_enc();

	return p;
}

/**
  * @brief  Adiciona um vértice na árvore. Essa função cria um novo vértice.
  * @param  arvore: ponteiro válido de uma árvore.
  * @param	id: identificação numérica do vértice.
  *
  * @retval subarvore_t: ponteiro do novo vértice criado e adicionado na árvore.
  */
subarvore_t *arvore_adicionar_subarvore_id(arvore_t *arvore, int id)
{
	subarvore_t *subarvore;
	no_t *no;

#ifdef DEBUG
	printf("grafo_adicionar_subarvore: %d\n", id);
#endif

	if (arvore == NULL)
	{
		fprintf(stderr, "grafo_adicionar_subarvore: grafo invalido!");
		exit(EXIT_FAILURE);
	}

	if (arvore_procura_subarvore(arvore, id) != NULL)
	{
		fprintf(stderr, "grafo_adicionar_subarvore: subarvore duplicado!\n");
		exit(EXIT_FAILURE);
	}

	subarvore = cria_subarvore(id);
	no = cria_no(subarvore);

	add_cauda(arvore->subarvores, no);

	return subarvore;
}

/**
  * @brief  Adiciona um vértice criado na árvore. Essa função NÃO cria um novo vértice.
  * @param  arvore: ponteiro válido de uma árvore.
  * @param	subarvore: ponteiro válido de um vértice.
  *
  * @retval subarvore_t: ponteiro do vértice adicionado na árvore.
  */
subarvore_t *arvore_adicionar_subarvore(arvore_t *arvore, subarvore_t *subarvore)
{
	no_t *no;

#ifdef DEBUG
	printf("grafo_adicionar_subarvore: %d\n", id);
#endif

	if (arvore == NULL)
	{
		fprintf(stderr, "grafo_adicionar_subarvore: grafo invalido!");
		exit(EXIT_FAILURE);
	}

	no = cria_no(subarvore);

	add_cauda(arvore->subarvores, no);

	return subarvore;
}

/**
  * @brief  Procura um vértice com identificador específico na árvore. 
  * @param  arvore: ponteiro válido de uma árvore.
  * @param	id: identificador do vértice procurado.
  *
  * @retval subarvore_t: NULL se vértice não pertencer a árvore. Um um ponteiro válido caso contrário.
  */
subarvore_t *arvore_procura_subarvore(arvore_t *arvore, int id)
{
	no_t *no_lista;
	subarvore_t *subarvore;
	int meu_id;

	if (arvore == NULL)
	{
		fprintf(stderr, "procura_subarvore: grafo invalido!");
		exit(EXIT_FAILURE);
	}

	if (lista_vazia(arvore->subarvores) == TRUE)
		return FALSE;

	no_lista = obter_cabeca(arvore->subarvores);

	while (no_lista)
	{
		//obtem o endereco da lista
		subarvore = obter_dado(no_lista);

		//obterm o id do subarvore
		meu_id = subarvore_get_id(subarvore);

		if (meu_id == id)
		{
			return subarvore;
		}

		no_lista = obtem_proximo(no_lista);
	}

	return NULL;
}

/**
  * @brief  Configura os filhos de um vértices PERTENCENTES à um árvore por identificador. 
  * @param  arvore: ponteiro válido de uma árvore.
  * @param  subarvore: ponteiro de um vértice à ser configurado.
  * @param	esq: identificador numérico do vértice à esquerda.
  * @param	dir: identificador numérico do vértice à direita.
  *
  * @retval Nenhum
  */
void arvore_adiciona_filhos(arvore_t *arvore, subarvore_t *subarvore, int esq, int dir)
{
	subarvore_t *esquerda;
	subarvore_t *direita;

	if (arvore == NULL)
	{
		fprintf(stderr, "arvore_arvore_adiciona_filhos: arvore invalida!");
		exit(EXIT_FAILURE);
	}

	if (esq != -1)
	{
		esquerda = arvore_procura_subarvore(arvore, esq);
		subarvore_set_pai(esquerda, subarvore);
		subarvore_set_esq(subarvore, esquerda);
	}

	if (dir != -1)
	{
		direita = arvore_procura_subarvore(arvore, dir);
		subarvore_set_pai(direita, subarvore);
		subarvore_set_dir(subarvore, direita);
	}
}

/**
  * @brief  Configura a raiz de uma árvore.
  * @param  arvore: ponteiro válido de uma árvore.
  * @param  subarvore: ponteiro válido de um vértice 
  *
  * @retval Nenhum
  */
void arvore_set_raiz(arvore_t *arvore, subarvore_t *subarvore)
{
	if (arvore == NULL)
	{
		fprintf(stderr, "libera_arvore: arvore invalida\n");
		exit(EXIT_FAILURE);
	}

	arvore->raiz = subarvore;
}

/**
  * @brief  Obtém a raiz de uma árvore.
  * @param  arvore: ponteiro válido de uma árvore.
    *
  * @retval subarvore_t: ponteiro do vértice raiz.
  */
subarvore_t *arvore_get_raiz(arvore_t *arvore)
{
	if (arvore == NULL)
	{
		fprintf(stderr, "arvore_get_raiz: arvore invalida\n");
		exit(EXIT_FAILURE);
	}

	return arvore->raiz;
}

/**
  * @brief  Obtém a lista encadeada de vértices.
  * @param  arvore: ponteiro válido de uma árvore.
    *
  * @retval lista_enc_t: ponteiro da lista encadeada contendo todos os vértices da árvore.
  */
lista_enc_t *arvore_obter_subarvores(arvore_t *arvore)
{

	if (arvore == NULL)
	{
		fprintf(stderr, "arvore_obter_subarvores: arvore invalida\n");
		exit(EXIT_FAILURE);
	}

	return arvore->subarvores;
}

int arvore_get_id(arvore_t *arvore)
{
	return arvore->id;
}

/**
  * @brief  Exporta em formato DOT uma árvore.
  * @param  filename: nome do arquivo DOT gerado.
  * @param  arvore: ponteiro válido de uma árvore.
    *
  * @retval Nenhum
  */
void exportar_arvore_dot(const char *filename, arvore_t *arvore)
{
}

/**
  * @brief  Libera memória dinâmica de uma uma árvore.
  * @param  arvore: ponteiro válido de uma árvore.
    *
  * @retval Nenhum
  */
void libera_arvore(arvore_t *arvore)
{
	no_t *no_subarvore;
	no_t *no_liberado;
	subarvore_t *subarvore;

	if (arvore == NULL)
	{
		fprintf(stderr, "libera_arvore: arvore invalida\n");
		exit(EXIT_FAILURE);
	}

	//varre todos os subarvores
	no_subarvore = obter_cabeca(arvore->subarvores);
	while (no_subarvore)
	{
		subarvore = obter_dado(no_subarvore);
		free(subarvore);
		//libera no da lista
		no_liberado = no_subarvore;
		no_subarvore = obtem_proximo(no_subarvore);
		free(no_liberado);
	}

	//libera grafo e subarvore
	free(arvore->subarvores);
	free(arvore);
}

subarvore_t *emordem_recursivo(subarvore_t *subarvore, int chave)
{

	if ((subarvore == NULL) || (subarvore_get_id(subarvore) == chave))
		return subarvore;

	if (chave < subarvore_get_id(subarvore))
	{
		return emordem_recursivo(subarvore_get_esq(subarvore), chave);
	}

	if (chave > subarvore_get_id(subarvore))
	{
		return emordem_recursivo(subarvore_get_dir(subarvore), chave);
	}
}

int buscabin(arvore_t *arvore, int chave)
{
	subarvore_t *raiz;
	subarvore_t *resultado;

	raiz = arvore_get_raiz(arvore);
	int teste = subarvore_get_id(raiz);
	resultado = emordem_recursivo(raiz, chave);

	if (resultado == NULL)
		return -1;
	else
		return subarvore_get_id(resultado);
}

arvore_t *ler_dados_csv(char *nome_do_arquivo)
{
	arvore_t *arvore;

	char n_subarvore[4], raiz[4];
	int i, v1, v2, v3;
	int int_n_raiz, int_n_subarvore;

	FILE *fp = fopen(nome_do_arquivo, "r");

	if (!fp)
	{
		perror("ler_dados_csv");
		exit(-1);
	}

	fscanf(fp, "%4s", n_subarvore);		 /* Le a primeira linha */
	int_n_subarvore = atoi(n_subarvore); /* Passa o valor para inteiro */
	//printf("\n%d", *int_n_subarvore);

	subarvore_t **subarvore = malloc(sizeof(subarvore_t *) * (int_n_subarvore));

	fscanf(fp, "%4s", raiz); /* Le a segunda linha */
	int_n_raiz = atoi(raiz); /* Passa o valor para inteiro */
	//printf("\n%d", int_n_raiz);

	arvore = cria_arvore(0); /* Cria o arvore */

	for (i = 0; i < int_n_subarvore; i++)
	{
		subarvore[i] = cria_subarvore(i);
		arvore_adicionar_subarvore(arvore, subarvore[i]);
	}

	if (int_n_raiz > int_n_subarvore)
	{
		fprintf(stderr, "ler_dados_csv: raiz invalida\n");
		exit(EXIT_FAILURE);
	}

	arvore_set_raiz(arvore, subarvore[int_n_raiz]);

	while (fscanf(fp, "%d,%d,%d", &v1, &v2, &v3) == 3) /* Varre o arquivo em busca de adjacencias */
	{
		if (v1 > int_n_subarvore)
		{
			fprintf(stderr, "ler_dados_csv: subarvore maior que numero de arvore\n");
			exit(EXIT_FAILURE);
		}

		//printf("\n%d %d %d", v1, v2, v3);
		arvore_adiciona_filhos(arvore, subarvore[v1], v2, v3);
	}

	fclose(fp);
	free(subarvore);
	return arvore;
}