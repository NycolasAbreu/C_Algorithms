#include <stdio.h>
#include <stdlib.h>

#include "insert_bin_sort.h"
#include "utils.h"

void insert_bin_sort(float *vetor, int tam)
{
    int meio, j;
    float valor;

    for (int i = 1; i < tam; i++)
    {
        valor = vetor[i];
        int esq = 0;
        int dir = i;

        while (esq < dir)
        {

            meio = (esq + dir) / 2;

            if (valor >= vetor[meio])
                esq = meio + 1;
            else
                dir = meio;
        }

        for (j = i; j > esq; j--)
            swap(vetor, j - 1, j);
    }
}