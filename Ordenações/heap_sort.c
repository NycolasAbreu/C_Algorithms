#include <stdio.h>
#include <stdlib.h>

#include "heap_sort.h"
#include "utils.h"

void heap_sort(float *vetor, int tam)
{
    build_heap(vetor, tam);

    for (int i = tam; i >= 1; i--)
    {
        swap(vetor, 0, i);
        max_heapify(vetor, 0, --tam);
    }
}

void build_heap(float *vetor, int tam)
{
    for (int i = (tam / 2) - 1; i >= 0; i--)
        max_heapify(vetor, i, tam);
}

void max_heapify(float *vetor, int i, int tam)
{
    int esq = esquerda(i);
    int dir = direita(i);
    int maior;
    if (esq < tam && vetor[esq] > vetor[i])
        maior = esq;
    else
        maior = i;

    if ((dir < tam) && (vetor[dir] > vetor[maior]))
        maior = dir;

    if (maior != i)
    {
        swap(vetor, i, maior);
        max_heapify(vetor, maior, tam);
    }
}

int esquerda(int i)
{
    return (2 * i + 1);
}

int direita(int i)
{
    return (2 * i + 2);
}