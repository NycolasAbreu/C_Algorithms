/*
 ============================================================================
 Name        : ordenacao.c
 Author      : Nycolas Coelho de Abreu
 Version     :
 Copyright   : Instituto Federal de Santa Catarina
 Description : Exemplo de projeto para benchmark das ordenações
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

/* Funções auxiliares */
#include "utils.h"

/* Include das ordencações */
#include "bubble_sort.h"
#include "quick_sort.h"
#include "selection_sort.h"
#include "insert_bin_sort.h"
#include "merge_sort.h"
#include "insert_sort.h"
#include "heap_sort.h"

#define TAM_VETOR 100000 /* Tamanho do vetor */
#define TRUE 1
#define NUM_EXEC 20 /* Número de execuções que o programa ira fazar para cada ordenação */

int main(void)
{
    /* Muda a semente do gerador de número aleatórios */
    srand(getpid() ^ time(NULL));

    int escolha;
    float *vet;
    clock_t inicio, fim;
    double tempo[NUM_EXEC], soma;
    FILE *txt;

    vet = (float *)malloc(sizeof(float) * TAM_VETOR); /* Aloca memória do vetor */

    txt = fopen("relatorio.csv", "w");

    if (txt == NULL)
    {
        perror("erro ao abrir arquivo execuções.txt");
        exit(EXIT_FAILURE);
    }

    while (escolha != 0)
    {
        system("cls");
        completar_vetor(vet, TAM_VETOR); /* Preenche vetor com numeros aleatórios */

        //exibir_vetor(vet, TAM_VETOR); /* Exibe vetors */
        cria_txt("vetor.txt", vet, TAM_VETOR); /* Cria arquivo txt com o vetor desordenado */

        printf("===========================\n");
        printf("(1). Bubble sort\n");
        printf("(2). Quick sort\n");
        printf("(3). Selection sort\n");
        printf("(4). Insertion binary sort\n");
        printf("(5). Merge sort\n");
        printf("(6). Insertion sort\n");
        printf("(7). heap sort\n");
        printf("(0). Exit\n");
        printf("===========================\n\n");

        scanf("%d", &escolha);

        switch (escolha)
        {
        case 1:

            for (int i = 0; i < NUM_EXEC; i++) /* Este for é para o teste de 20 execuções, retire ele para fazer apenas 1 */
            {
                inicio = clock();
                bubble_sort(vet, TAM_VETOR); /* Ordena bubble */
                fim = clock();

                //exibir_vetor(vet, TAM_VETOR); /* Exibe vetor */

                tempo[i] = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
                //printf("\nTempo gasto: %lfs\n\n", tempo[i]); /* Exibe o tempo gasto */
                fprintf(txt, "bubble_sort[%d], %lfs\n", i, tempo[i]);

                cria_txt("bubble_sort.txt", vet, TAM_VETOR);
                completar_vetor(vet, TAM_VETOR); /* Cria arquivo .txt com vetor ordenado */
            }

            soma = 0;

            for (int j = 0; j < NUM_EXEC; j++)
            {
                soma += tempo[j];
            }

            printf("Media bubble_sort: %lfs\n", soma / NUM_EXEC);
            fprintf(txt, "Media bubble_sort, %lfs\n", soma / NUM_EXEC);

            fputs("---------------------------\n", txt);
            system("pause");

            break;
        case 2:

            for (int i = 0; i < NUM_EXEC; i++) /* Este for é para o teste de 20 execuções, retire ele para fazer apenas 1 */
            {
                inicio = clock();
                quick_sort(vet, 0, TAM_VETOR - 1); /* Ordena quick */
                fim = clock();

                //exibir_vetor(vet, TAM_VETOR); /* Exibe vetor */

                tempo[i] = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
                //printf("\nTempo gasto: %lfs\n\n", tempo[i]); /* Exibe o tempo gasto */
                fprintf(txt, "quick_sort[%d], %lfs\n", i, tempo[i]);

                cria_txt("quick_sort.txt", vet, TAM_VETOR);
                completar_vetor(vet, TAM_VETOR); /* Cria arquivo .txt com vetor ordenado */
            }

            soma = 0;

            for (int j = 0; j < NUM_EXEC; j++)
            {
                soma += tempo[j];
            }

            printf("Media quick_sort: %lfs\n", soma / NUM_EXEC);
            fprintf(txt, "Media quick_sort, %lfs\n", soma / NUM_EXEC);

            fputs("---------------------------\n", txt);
            system("pause");

            break;
        case 3:

            for (int i = 0; i < NUM_EXEC; i++) /* Este for é para o teste de 20 execuções, retire ele para fazer apenas 1 */
            {
                inicio = clock();
                selection_sort(vet, TAM_VETOR); /* Ordena selection */
                fim = clock();

                //exibir_vetor(vet, TAM_VETOR); /* Exibe vetor */

                tempo[i] = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
                //printf("\nTempo gasto: %lfs\n\n", tempo[i]); /* Exibe o tempo gasto */
                fprintf(txt, "selection_sort[%d], %lfs\n", i, tempo[i]);

                cria_txt("selection_sort.txt", vet, TAM_VETOR);
                completar_vetor(vet, TAM_VETOR); /* Cria arquivo .txt com vetor ordenado */
            }

            soma = 0;

            for (int j = 0; j < NUM_EXEC; j++)
            {
                soma += tempo[j];
            }

            printf("Media selection_sort: %lfs\n", soma / NUM_EXEC);
            fprintf(txt, "Media selection_sort, %lfs\n", soma / NUM_EXEC);

            fputs("---------------------------\n", txt);
            system("pause");

            break;
        case 4:

            for (int i = 0; i < NUM_EXEC; i++) /* Este for é para o teste de 20 execuções, retire ele para fazer apenas 1 */
            {
                inicio = clock();
                insert_bin_sort(vet, TAM_VETOR); /* Ordena insertion bin */
                fim = clock();

                //exibir_vetor(vet, TAM_VETOR); /* Exibe vetor */

                tempo[i] = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
                // printf("\nTempo gasto: %lfs\n\n", tempo[i]); /* Exibe o tempo gasto */
                fprintf(txt, "insert_bin_sort[%d], %lfs\n", i, tempo[i]);

                cria_txt("insert_bin_sort.txt", vet, TAM_VETOR);
                completar_vetor(vet, TAM_VETOR); /* Cria arquivo .txt com vetor ordenado */
            }

            soma = 0;

            for (int j = 0; j < NUM_EXEC; j++)
            {
                soma += tempo[j];
            }

            printf("Media insert_bin_sort: %lfs\n", soma / NUM_EXEC);
            fprintf(txt, "Media insert_bin_sort, %lfs\n", soma / NUM_EXEC);

            fputs("---------------------------\n", txt);
            system("pause");

            break;

        case 5:

            for (int i = 0; i < NUM_EXEC; i++) /* Este for é para o teste de 20 execuções, retire ele para fazer apenas 1 */
            {
                inicio = clock();
                merge_sort(vet, 0, TAM_VETOR - 1); /* Ordena merge */
                fim = clock();

                //exibir_vetor(vet, TAM_VETOR); /* Exibe vetor */

                tempo[i] = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
                //printf("\nTempo gasto: %lfs\n\n", tempo[i]); /* Exibe o tempo gasto */
                fprintf(txt, "merge_sort[%d], %lfs\n", i, tempo[i]);

                cria_txt("merge_sort.txt", vet, TAM_VETOR);
                completar_vetor(vet, TAM_VETOR); /* Cria arquivo .txt com vetor ordenado */
            }

            soma = 0;

            for (int j = 0; j < NUM_EXEC; j++)
            {
                soma += tempo[j];
            }

            printf("Media merge_sort: %lfs\n", soma / NUM_EXEC);
            fprintf(txt, "Media merge_sort, %lfs\n", soma / NUM_EXEC);

            fputs("---------------------------\n", txt);
            system("pause");

            break;

        case 6:

            for (int i = 0; i < NUM_EXEC; i++) /* Este for é para o teste de 20 execuções, retire ele para fazer apenas 1 */
            {
                inicio = clock();
                insert_sort(vet, TAM_VETOR); /* Ordena insertion */
                fim = clock();

                //exibir_vetor(vet, TAM_VETOR); /* Exibe vetor */

                tempo[i] = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
                //printf("\nTempo gasto: %lfs\n\n", tempo[i]); /* Exibe o tempo gasto */
                fprintf(txt, "insert_sort[%d], %lfs\n", i, tempo[i]);

                cria_txt("insert_sort.txt", vet, TAM_VETOR);
                completar_vetor(vet, TAM_VETOR); /* Cria arquivo .txt com vetor ordenado */
            }

            soma = 0;

            for (int j = 0; j < NUM_EXEC; j++)
            {
                soma += tempo[j];
            }

            printf("Media insert_sort: %lfs\n", soma / NUM_EXEC);
            fprintf(txt, "Media insert_sort, %lfs\n", soma / NUM_EXEC);

            fputs("---------------------------\n", txt);
            system("pause");

            break;

        case 7:

            for (int i = 0; i < NUM_EXEC; i++) /* Este for é para o teste de 20 execuções, retire ele para fazer apenas 1 */
            {
                inicio = clock();
                heap_sort(vet, TAM_VETOR); /* Ordena insertion */
                fim = clock();

                //exibir_vetor(vet, TAM_VETOR); /* Exibe vetor */

                tempo[i] = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
                //printf("\nTempo gasto: %lfs\n\n", tempo[i]); /* Exibe o tempo gasto */
                fprintf(txt, "heap_sort[%d], %lfs\n", i, tempo[i]);

                cria_txt("heap_sort.txt", vet, TAM_VETOR);
                completar_vetor(vet, TAM_VETOR); /* Cria arquivo .txt com vetor ordenado */
            }

            soma = 0;

            for (int j = 0; j < NUM_EXEC; j++)
            {
                soma += tempo[j];
            }

            printf("Media heap_sort: %lfs\n", soma / NUM_EXEC);
            fprintf(txt, "Media heap_sort, %lfs\n", soma / NUM_EXEC);

            fputs("---------------------------\n", txt);
            system("pause");

            break;

        default:
            break;
        }
    }

    fclose(txt);
    free(vet);
    return EXIT_SUCCESS;
}