#ifndef QUICK_SORT_H_INCLUDED
#define QUICK_SORT_H_INCLUDED

/**
  * @brief  Ordena um vetor de inteiros utilizando o algoritmo Quick
  * @param	vetor: referência de um vetor
  * @param  esq: primeiro elemento
  * @param  dir: ultimo elemento
  *
  * @retval Nenhum
  */
void quick_sort(float *vetor, int esq, int dir);
float partition(float *vetor, int esq, int dir);
float mediana_de_tres(float *vetor, int esq, int dir);

#endif // QUICK_SORT_H_INCLUDED