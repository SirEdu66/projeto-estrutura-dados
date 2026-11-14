#include <stdio.h>
#include <stdlib.h>
#include "equipamento.h"
#include "bst.h"
#include "pilha.h"
#include "entrada.h"
#include "lista.h"
#include "fila.h"
#include "ordenacao.h"

static void exibir_menu(void) {
    printf("\n==========================================\n");
    printf("      SISTEMA DE EQUIPAMENTOS DE REDE\n");
    printf("============================================\n");
    printf(" 1 - Cadastrar equipamento\n");
    printf(" 2 - Buscar equipamento (BST)\n");
    printf(" 3 - Remover equipamento\n");
    printf(" 4 - Listar equipamentos (em-ordem por ID)\n");
    printf(" 5 - Ordenar e exibir por nome\n");
    printf(" 6 - Consultar menor/maior ID\n");
    printf(" 7 - Consultar historico (pilha)\n");
    printf(" 8 - Percurso por niveis (fila + lista)   [extra]\n");
    printf(" 0 - Encerrar\n");
    printf("===========================================\n");
}

int main(void) {
    No *raiz = NULL;
    Pilha hist;
    int opcao = -1;

    pilha_iniciar(&hist);

    do {
        exibir_menu();
        if (!ler_inteiro("Escolha uma opcao: ", &opcao)) {
            if (feof(stdin)) {
                break;
            }
            printf("Entrada invalida.\n");
            opcao = -1;
            continue;
        }

        switch (opcao) {
            case 1: {
                Equipamento eq;
                if (!ler_inteiro("ID: ", &eq.id) || eq.id <= 0) {
                    printf("Entrada invalida.\n");
                    break;
                }
                if (!ler_texto("Nome: ", eq.nome, 80)) {
                    printf("Entrada invalida.\n");
                    break;
                }
                if (!ler_texto("Tipo: ", eq.tipo, 80)) {
                    printf("Entrada invalida.\n");
                    break;
                }
                if (!ler_texto("Localizacao: ", eq.localizacao, 80)) {
                    printf("Entrada invalida.\n");
                    break;
                }

                if (bst_buscar(raiz, eq.id) != NULL) {
                    printf("ID ja cadastrado.\n");
                    break;
                }

                int res = bst_inserir(&raiz, eq);
                if (res == 1) {
                    pilha_push(&hist, 1, eq.id);
                    printf("Equipamento cadastrado com sucesso.\n");
                } else if (res == 0) {
                    printf("ID ja cadastrado.\n");
                } else {
                    printf("Erro: sem memoria.\n");
                }
                break;
            }

            case 2: {
                int id;
                if (!ler_inteiro("ID: ", &id) || id <= 0) {
                    printf("Entrada invalida.\n");
                    break;
                }
                No *no = bst_buscar(raiz, id);
                if (no == NULL) {
                    printf("ID nao encontrado.\n");
                } else {
                    printf("ID: %d | Nome: %s | Tipo: %s | Local: %s\n",
                           no->dado.id,
                           no->dado.nome,
                           no->dado.tipo,
                           no->dado.localizacao);
                }
                break;
            }

            case 3: {
                int id;
                if (!ler_inteiro("ID: ", &id) || id <= 0) {
                    printf("Entrada invalida.\n");
                    break;
                }
                if (bst_remover(&raiz, id)) {
                    pilha_push(&hist, 2, id);
                    printf("Equipamento removido com sucesso.\n");
                } else {
                    printf("ID nao encontrado.\n");
                }
                break;
            }

            case 4: {
                if (raiz == NULL) {
                    printf("Nenhum equipamento cadastrado.\n");
                } else {
                    bst_em_ordem(raiz);
                }
                break;
            }

            case 5: {
                int n = bst_contar(raiz);
                if (n == 0) {
                    printf("Nenhum equipamento cadastrado.\n");
                    break;
                }
                Equipamento *v = (Equipamento *)malloc((size_t)n * sizeof(Equipamento));
                if (v == NULL) {
                    printf("Erro: sem memoria.\n");
                    break;
                }
                int idx = 0;
                bst_copiar(raiz, v, &idx);
                ordenar_por_nome(v, n);

                for (int i = 0; i < n; i++) {
                    printf("ID: %d | Nome: %s | Tipo: %s | Local: %s\n",
                           v[i].id, v[i].nome, v[i].tipo, v[i].localizacao);
                }
                free(v);
                break;
            }

            case 6: {
                if (raiz == NULL) {
                    printf("Nenhum equipamento cadastrado.\n");
                    break;
                }
                No *menor = bst_menor(raiz);
                No *maior = bst_maior(raiz);
                printf("Menor ID -> ID: %d | Nome: %s | Tipo: %s | Local: %s\n",
                       menor->dado.id, menor->dado.nome,
                       menor->dado.tipo, menor->dado.localizacao);
                printf("Maior ID -> ID: %d | Nome: %s | Tipo: %s | Local: %s\n",
                       maior->dado.id, maior->dado.nome,
                       maior->dado.tipo, maior->dado.localizacao);
                break;
            }

            case 7: {
                pilha_imprimir_ultimas(&hist);
                break;
            }

            case 8: {
                if (raiz == NULL) {
                    printf("Nenhum equipamento cadastrado.\n");
                    break;
                }
                Fila f;
                Lista l;
                fila_iniciar(&f);
                lista_iniciar(&l);

                fila_enfileirar(&f, raiz->dado.id);
                while (!fila_vazia(&f)) {
                    int atual_id;
                    fila_desenfileirar(&f, &atual_id);
                    lista_inserir_fim(&l, atual_id);

                    No *no = bst_buscar(raiz, atual_id);
                    if (no != NULL) {
                        if (no->esq != NULL) {
                            fila_enfileirar(&f, no->esq->dado.id);
                        }
                        if (no->dir != NULL) {
                            fila_enfileirar(&f, no->dir->dado.id);
                        }
                    }
                }

                printf("Percurso por niveis (IDs): ");
                lista_imprimir(&l);
                lista_liberar(&l);
                fila_liberar(&f);
                break;
            }

            case 0:
                break;

            default:
                printf("Entrada invalida.\n");
                break;
        }
    } while (opcao != 0);

    bst_liberar(raiz);
    raiz = NULL;
    pilha_liberar(&hist);
    return 0;
}
