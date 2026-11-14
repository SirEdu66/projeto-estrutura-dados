#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include <limits.h>
#include "entrada.h"

static void descartar_resto_linha(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
    }
}

int ler_texto(const char *msg, char *dest, int tam) {
    char buf[256];
    size_t len;
    int tem_conteudo = 0;

    if (dest == NULL || tam <= 1) {
        return 0;
    }

    if (msg != NULL) {
        printf("%s", msg);
    }

    if (fgets(buf, sizeof(buf), stdin) == NULL) {
        return 0;
    }

    if (strchr(buf, '\n') == NULL) {
        descartar_resto_linha();
        return 0;
    }
    buf[strcspn(buf, "\r\n")] = '\0';

    len = strlen(buf);
    if (len >= (size_t)tam) {
        return 0;
    }

    for (size_t i = 0; i < len; i++) {
        if (!isspace((unsigned char)buf[i])) {
            tem_conteudo = 1;
            break;
        }
    }

    if (!tem_conteudo) {
        return 0;
    }

    strcpy(dest, buf);
    return 1;
}

int ler_inteiro(const char *msg, int *valor) {
    char buf[256];
    char *p;
    char *endptr;
    long val;

    if (valor == NULL) {
        return 0;
    }

    if (msg != NULL) {
        printf("%s", msg);
    }

    if (fgets(buf, sizeof(buf), stdin) == NULL) {
        return 0;
    }

    if (strchr(buf, '\n') == NULL) {
        descartar_resto_linha();
        return 0;
    }

    buf[strcspn(buf, "\r\n")] = '\0';

    p = buf;
    while (isspace((unsigned char)*p)) {
        p++;
    }
    if (*p == '\0') {
        return 0;
    }

    errno = 0;
    val = strtol(p, &endptr, 10);

    if (endptr == p) {
        return 0;
    }

    while (isspace((unsigned char)*endptr)) {
        endptr++;
    }
    if (*endptr != '\0') {
        return 0;
    }

    if (errno == ERANGE || val < INT_MIN || val > INT_MAX) {
        return 0;
    }

    *valor = (int)val;
    return 1;
}
