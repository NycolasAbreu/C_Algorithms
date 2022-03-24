#ifndef HEAP_SORT_H_INCLUDED
#define HEAP_SORT_H_INCLUDED

/**
 * @brief  Ordena um vetor de inteiros utilizando o algoritmo heap
 * @param	vetor: referência de um vetor
 * @param  tam: tamanho do vetor
 * @retval Nenhum
 */
void heap_sort(float *vetor, int tam);
void build_heap(float *vetor, int tam);
void max_heapify(float *vetor, int i, int tam);
int esquerda(int i);
int direita(int i);

#endif // HEAP_SORT_H_INCLUDED