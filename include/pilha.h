#ifndef PILHA_H
#define PILHA_H

typedef struct Acao {
    int tipo;
    int id;
    struct Acao *prox;
} Acao;

typedef struct {
    Acao *topo;
} Pilha;

void pilha_iniciar(Pilha *p);
int  pilha_push(Pilha *p, int tipo, int id); 
int  pilha_pop(Pilha *p, int *tipo, int *id); 
int  pilha_peek(const Pilha *p, int *tipo, int *id);
void pilha_imprimir_ultimas(const Pilha *p);
void pilha_liberar(Pilha *p);

#endif
