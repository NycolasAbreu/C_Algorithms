#include <stdio.h>
#include <stdlib.h>

#include "insert_sort.h"
#include "utils.h"

void insert_sort(float *vetor, int tam)
{
    int i, j;
    for (i = 1; i < tam; i++)
    {
        for (j = i; j > 0 && vetor[j - 1] > vetor[j]; j--)
            swap(vetor, j, j - 1);
    }
}