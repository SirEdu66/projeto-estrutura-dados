#ifndef BST_H
#define BST_H

#include "equipamento.h"

typedef struct No {
    Equipamento dado;
    struct No *esq;
    struct No *dir;
} No;

int  bst_inserir(No **raiz, Equipamento e);
No  *bst_buscar(No *raiz, int id);
int  bst_remover(No **raiz, int id);
void bst_em_ordem(No *raiz);
No  *bst_menor(No *raiz);
No  *bst_maior(No *raiz);
int  bst_contar(No *raiz);
void bst_copiar(No *raiz, Equipamento *v, int *i);
void bst_liberar(No *raiz);

#endif
