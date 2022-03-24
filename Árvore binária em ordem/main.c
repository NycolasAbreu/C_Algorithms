/*
 * main.c
 *
 *  Created on: 4 de out de 2019
 *  Author: Nycolas Coelho de Abreu
 */

#include <stdio.h>
#include "arvore.h"

int main()
{
    arvore_t *arvore;
    int resposta;
    int n_subarvore;

    arvore = ler_dados_csv("arquivocsv.csv"); // Le o arquivo e cria uma arvore

    /*     Modelo da árvore no arquivo.csv  
    *            8
	*          /   \
	*         3     10
	*        / \      \
	*       1   6      14
	*          / \     /     
 	*         4   7   13
	*/

    resposta = buscabin(arvore, 6);          // Digite o id para procurar na árvore
    printf("Encontrado = %d\n\n", resposta); // -1 = NULL caso não encontre

    libera_arvore(arvore);
    return 0;
}