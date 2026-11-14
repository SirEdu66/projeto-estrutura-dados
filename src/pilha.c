#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

void pilha_iniciar(Pilha *p) {
    p->topo = NULL;
}

int pilha_push(Pilha *p, int tipo, int id) {
    Acao *novo = (Acao *)malloc(sizeof(Acao));
    if (novo == NULL) return 0;
    novo->tipo = tipo;
    novo->id = id;
    novo->prox = p->topo;
    p->topo = novo;
    return 1;
}

int pilha_pop(Pilha *p, int *tipo, int *id) {
    if (p->topo == NULL) return 0;
    Acao *rem = p->topo;
    *tipo = rem->tipo;
    *id = rem->id;
    p->topo = rem->prox;
    free(rem);
    return 1;
}

int pilha_peek(const Pilha *p, int *tipo, int *id) {
    if (p->topo == NULL) return 0;
    *tipo = p->topo->tipo;
    *id = p->topo->id;
    return 1;
}

void pilha_imprimir_ultimas(const Pilha *p) {
    if (p->topo == NULL) {
        printf("Historico vazio.\n");
        return;
    }
    const Acao *a = p->topo;
    int n = 0;
    while (a != NULL && n < 5) {
        printf("%d) %s - ID %d\n", n + 1,
               a->tipo == 1 ? "Cadastro" : "Remocao", a->id);
        a = a->prox;
        n++;
    }
}

void pilha_liberar(Pilha *p) {
    Acao *a = p->topo;
    while (a != NULL) {
        Acao *prox = a->prox;
        free(a);
        a = prox;
    }
    p->topo = NULL;
}
