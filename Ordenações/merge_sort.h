#ifndef MERGE_SORT_H_INCLUDED
#define MERGE_SORT_H_INCLUDED

/**
  * @brief  Ordena um vetor de inteiros utilizando o algoritmo merge
  * @param	vetor: referência de um vetor
  * @param  esq: primeiro elemento
  * @param  dir: ultimo elemento
  * @retval Nenhum
  */
void merge_sort(float *vetor, int esq, int dir);
void mergesort_imp(float *vetor, int esq, int dir, float *vetor_temp);
void funde(float *vetor, int esq, int meio, int dir, float *vetor_temp);

#endif // MERGE_BIN_SORT_H_INCLUDED