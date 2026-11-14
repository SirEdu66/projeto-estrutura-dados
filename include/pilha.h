#ifndef PILHA_H
#define PILHA_H

typedef struct Acao {
    int tipo;            /* 1 = cadastro, 2 = remocao */
    int id;
    struct Acao *prox;
} Acao;

typedef struct {
    Acao *topo;
} Pilha;

void pilha_iniciar(Pilha *p);
int  pilha_push(Pilha *p, int tipo, int id);          /* 1 = ok, 0 = falha */
int  pilha_pop(Pilha *p, int *tipo, int *id);         /* 1 = ok, 0 = vazia */
int  pilha_peek(const Pilha *p, int *tipo, int *id);  /* 1 = ok, 0 = vazia */
void pilha_imprimir_ultimas(const Pilha *p);          /* ate 5, sem remover */
void pilha_liberar(Pilha *p);

#endif
