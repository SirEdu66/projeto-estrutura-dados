#include <stdlib.h>
#include "fila.h"

void fila_iniciar(Fila *f) {
    if (f == NULL) {
        return;
    }
    f->ini = NULL;
    f->fim = NULL;
}

int fila_enfileirar(Fila *f, int id) {
    if (f == NULL) {
        return 0;
    }
    NoFila *novo = (NoFila *)malloc(sizeof(NoFila));
    if (novo == NULL) {
        return 0;
    }
    novo->id = id;
    novo->prox = NULL;

    if (f->ini == NULL) {
        f->ini = novo;
        f->fim = novo;
    } else {
        f->fim->prox = novo;
        f->fim = novo;
    }
    return 1;
}

int fila_desenfileirar(Fila *f, int *id) {
    if (f == NULL || f->ini == NULL) {
        return 0;
    }
    NoFila *aux = f->ini;
    if (id != NULL) {
        *id = aux->id;
    }
    f->ini = aux->prox;
    if (f->ini == NULL) {
        f->fim = NULL;
    }
    free(aux);
    return 1;
}

int fila_vazia(const Fila *f) {
    return (f == NULL || f->ini == NULL) ? 1 : 0;
}

void fila_liberar(Fila *f) {
    if (f == NULL) {
        return;
    }
    int lixo;
    while (fila_desenfileirar(f, &lixo)) {
    }
}
