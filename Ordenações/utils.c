#include <stdio.h>
#include <stdlib.h>

void exibir_vetor(float *vetor, int tam)
{
    for (int i = 0; i < tam; i++)
        printf("[%d] \t %f\n", i, vetor[i]);

    puts("---------------------------");
}

void completar_vetor(float *vetor, int tam)
{
    float a = 10;
    for (int i = 0; i < tam; i++)
        vetor[i] = ((float)rand() / (float)(RAND_MAX)) * a;
}

void swap(float *vetor, int i, int j)
{
    float temp = vetor[i];
    vetor[i] = vetor[j];
    vetor[j] = temp;
}

void cria_txt(const char *filename, float *vetor, int tam)
{
    FILE *file;
    int i = 0;

    if (filename == NULL || vetor == NULL)
    {
        fprintf(stderr, "cria_txt: vetor ou nome invalido\n");
        exit(EXIT_FAILURE);
    }

    file = fopen(filename, "w");

    if (file == NULL)
    {
        perror("cria_txt: erro ao abrir arquivo");
        exit(EXIT_FAILURE);
    }

    while (i != tam)
    {
        fputs("---------------------------\n", file);
        for (i = 0; i < tam; i++)
            fprintf(file, "[%d] \t %f\n", i, vetor[i]);

        fputs("---------------------------\n", file);
    }
    fclose(file);
}