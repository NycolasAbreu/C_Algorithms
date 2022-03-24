#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED

#include "lista_enc.h"
struct filas
{
    lista_enc_t *dados;
};
typedef struct filas fila_t;

fila_t *cria_fila(void);

void enqueue(void *dado, fila_t *fila);
void *dequeue(fila_t *fila);

int fila_vazia(fila_t *fila);
void libera_fila(fila_t *fila);

#endif // FILA_H_INCLUDED
