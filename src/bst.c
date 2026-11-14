#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

int bst_inserir(No **raiz, Equipamento e) {
    if (raiz == NULL) {
        return -1;
    }
    if (*raiz == NULL) {
        No *novo = (No *)malloc(sizeof(No));
        if (novo == NULL) {
            return -1;
        }
        novo->dado = e;
        novo->esq = NULL;
        novo->dir = NULL;
        *raiz = novo;
        return 1;
    }
    if (e.id < (*raiz)->dado.id) {
        return bst_inserir(&(*raiz)->esq, e);
    }
    if (e.id > (*raiz)->dado.id) {
        return bst_inserir(&(*raiz)->dir, e);
    }
    return 0; /* ID duplicado */
}

No *bst_buscar(No *raiz, int id) {
    if (raiz == NULL) {
        return NULL;
    }
    if (id == raiz->dado.id) {
        return raiz;
    }
    if (id < raiz->dado.id) {
        return bst_buscar(raiz->esq, id);
    }
    return bst_buscar(raiz->dir, id);
}

int bst_remover(No **raiz, int id) {
    if (raiz == NULL || *raiz == NULL) {
        return 0;
    }
    if (id < (*raiz)->dado.id) {
        return bst_remover(&(*raiz)->esq, id);
    }
    if (id > (*raiz)->dado.id) {
        return bst_remover(&(*raiz)->dir, id);
    }

    /* Encontrou o no */
    if ((*raiz)->esq == NULL && (*raiz)->dir == NULL) {
        free(*raiz);
        *raiz = NULL;
    } else if ((*raiz)->esq == NULL) {
        No *aux = *raiz;
        *raiz = (*raiz)->dir;
        free(aux);
    } else if ((*raiz)->dir == NULL) {
        No *aux = *raiz;
        *raiz = (*raiz)->esq;
        free(aux);
    } else {
        No *sucessor = bst_menor((*raiz)->dir);
        (*raiz)->dado = sucessor->dado;
        bst_remover(&(*raiz)->dir, sucessor->dado.id);
    }
    return 1;
}

void bst_em_ordem(No *raiz) {
    if (raiz == NULL) {
        return;
    }
    bst_em_ordem(raiz->esq);
    printf("ID: %d | Nome: %s | Tipo: %s | Local: %s\n",
           raiz->dado.id,
           raiz->dado.nome,
           raiz->dado.tipo,
           raiz->dado.localizacao);
    bst_em_ordem(raiz->dir);
}

No *bst_menor(No *raiz) {
    if (raiz == NULL) {
        return NULL;
    }
    while (raiz->esq != NULL) {
        raiz = raiz->esq;
    }
    return raiz;
}

No *bst_maior(No *raiz) {
    if (raiz == NULL) {
        return NULL;
    }
    while (raiz->dir != NULL) {
        raiz = raiz->dir;
    }
    return raiz;
}

int bst_contar(No *raiz) {
    if (raiz == NULL) {
        return 0;
    }
    return 1 + bst_contar(raiz->esq) + bst_contar(raiz->dir);
}

void bst_copiar(No *raiz, Equipamento *v, int *i) {
    if (raiz == NULL || v == NULL || i == NULL) {
        return;
    }
    bst_copiar(raiz->esq, v, i);
    v[*i] = raiz->dado;
    (*i)++;
    bst_copiar(raiz->dir, v, i);
}

void bst_liberar(No *raiz) {
    if (raiz == NULL) {
        return;
    }
    bst_liberar(raiz->esq);
    bst_liberar(raiz->dir);
    free(raiz);
}
