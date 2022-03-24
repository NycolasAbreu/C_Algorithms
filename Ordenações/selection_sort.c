#include <stdio.h>
#include <stdlib.h>

#include "selection_sort.h"
#include "utils.h"

void selection_sort(float *vetor, float n)
{
    int max;
    for (int i = n; i > 1; i--)
    {
        max = 0;
        for (int j = 1; j < i; j++)
            if (vetor[j] > vetor[max])
                max = j;

        swap(vetor, i - 1, max);
    }
}