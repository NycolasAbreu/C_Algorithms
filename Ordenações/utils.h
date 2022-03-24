#ifndef UTILS_H_
#define UTILS_H_

/**
  * @brief  Exibe todos os valores de um vetor de inteiros
  * @param	vetor: referência de um vetor
  *         tam: tamanho do vetor
  *
  * @retval Nenhum
  */
void exibir_vetor(float *vetor, int tam);

/**
  * @brief  Completa com números aleatórios um vetor
  * @param	vetor: referência de um vetor
  *         tam: tamanho do vetor
  *
  * @retval Nenhum
  */
void completar_vetor(float *vetor, int tam);

void swap(float *vetor, int i, int j);

void cria_txt(const char *filename, float *vetor, int tam);

#endif /* UTILS_H_ */