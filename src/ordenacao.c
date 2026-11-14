#include <string.h>
#include "ordenacao.h"

void ordenar_por_nome(Equipamento *v, int n) {
    if (v == NULL || n <= 1) {
        return;
    }

    for (int i = 1; i < n; i++) {
        Equipamento chave = v[i];
        int j = i - 1;

        while (j >= 0) {
            int cmp = strcmp(v[j].nome, chave.nome);
            if (cmp > 0 || (cmp == 0 && v[j].id > chave.id)) {
                v[j + 1] = v[j];
                j--;
            } else {
                break;
            }
        }
        v[j + 1] = chave;
    }
}
