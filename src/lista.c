#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

void lista_iniciar(Lista *l) {
    if (l == NULL) {
        return;
    }
    l->ini = NULL;
    l->fim = NULL;
}

int lista_inserir_fim(Lista *l, int id) {
    if (l == NULL) {
        return 0;
    }
    NoLista *novo = (NoLista *)malloc(sizeof(NoLista));
    if (novo == NULL) {
        return 0;
    }
    novo->id = id;
    novo->prox = NULL;

    if (l->ini == NULL) {
        l->ini = novo;
        l->fim = novo;
    } else {
        l->fim->prox = novo;
        l->fim = novo;
    }
    return 1;
}

void lista_imprimir(const Lista *l) {
    if (l == NULL || l->ini == NULL) {
        printf("Lista vazia.\n");
        return;
    }
    NoLista *atual = l->ini;
    while (atual != NULL) {
        printf("%d", atual->id);
        if (atual->prox != NULL) {
            printf(" -> ");
        }
        atual = atual->prox;
    }
    printf("\n");
}

void lista_liberar(Lista *l) {
    if (l == NULL) {
        return;
    }
    NoLista *atual = l->ini;
    while (atual != NULL) {
        NoLista *prox = atual->prox;
        free(atual);
        atual = prox;
    }
    l->ini = NULL;
    l->fim = NULL;
}
