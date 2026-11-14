#ifndef FILA_H
#define FILA_H

typedef struct NoFila {
    int id;
    struct NoFila *prox;
} NoFila;

typedef struct {
    NoFila *ini;
    NoFila *fim;
} Fila;

void fila_iniciar(Fila *f);
int  fila_enfileirar(Fila *f, int id);
int  fila_desenfileirar(Fila *f, int *id);
int  fila_vazia(const Fila *f);
void fila_liberar(Fila *f);

#endif
