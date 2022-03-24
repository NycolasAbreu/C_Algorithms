#include <stdio.h>
#include <stdlib.h>

#include "quick_sort.h"
#include "utils.h"

void quick_sort(float *vetor, int esq, int dir)
{
    if (esq < dir)
    {
        float pivo = partition(vetor, esq, dir);
        quick_sort(vetor, esq, pivo);
        quick_sort(vetor, pivo + 1, dir);
    }
}

float partition(float *vetor, int esq, int dir)
{
    int med, i, j;
    med = mediana_de_tres(vetor, esq, dir);

    i = esq - 1;
    j = dir + 1;

    while (1)
    {
        do
            i = i + 1;
        while (vetor[i] < vetor[med]);

        do
            j = j - 1;
        while (vetor[j] > vetor[med]);

        if (i >= j)
            return j;

        swap(vetor, i, j);
    }
}

float mediana_de_tres(float *vetor, int esq, int dir)
{
    int med = (esq + dir) / 2;

    if (vetor[dir] < vetor[esq])
        swap(vetor, esq, dir);

    if (vetor[med] < vetor[esq])
        swap(vetor, med, esq);

    if (vetor[dir] < vetor[med])
        swap(vetor, dir, med);

    return med;
}