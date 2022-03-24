#include <stdio.h>
#include <stdlib.h>

#include "merge_sort.h"

void merge_sort(float *vetor, int esq, int dir)
{

    float *vetor_temp = malloc(sizeof(float) * (dir - esq + 1));
    mergesort_imp(vetor, esq, dir, vetor_temp);
    free(vetor_temp);
}

void mergesort_imp(float *vetor, int esq, int dir, float *vetor_temp)
{
    if (esq < dir)
    {

        float meio = (esq + dir) / 2;

        mergesort_imp(vetor, esq, meio, vetor_temp);
        mergesort_imp(vetor, meio + 1, dir, vetor_temp);

        funde(vetor, esq, meio, dir, vetor_temp);
    }
}

void funde(float *vetor, int esq, int meio, int dir, float *vetor_temp)
{
    int i = esq;
    int j = esq;
    int k = meio + 1;
    while (j <= meio && k <= dir)
    {

        if (vetor[j] < vetor[k])
            vetor_temp[i++] = vetor[j++];
        else
            vetor_temp[i++] = vetor[k++];
    }

    while (j <= meio)
        vetor_temp[i++] = vetor[j++];

    for (i = esq; i < k; i++)
        vetor[i] = vetor_temp[i];
}