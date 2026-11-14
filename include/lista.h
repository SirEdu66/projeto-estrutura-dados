#ifndef LISTA_H
#define LISTA_H

typedef struct NoLista {
    int id;
    struct NoLista *prox;
} NoLista;

typedef struct {
    NoLista *ini;
    NoLista *fim;
} Lista;

void lista_iniciar(Lista *l);
int  lista_inserir_fim(Lista *l, int id);
void lista_imprimir(const Lista *l);
void lista_liberar(Lista *l);

#endif
