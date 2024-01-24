#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int ITEM; 

typedef struct {
    ITEM *item;
    struct NO *prox;
} NO;

typedef struct {
    NO *cabeca;
    long tamanho;
} LISTA;

char compare(ITEM x, ITEM y) {
    return x > y ? 1 : (x < y ? -1 : 0);
}

bool igual(ITEM x, ITEM y) {
    return compare(x, y) == 0;
}

void inicializar(LISTA *l) {
    l->cabeca = NULL;
    l->tamanho = 0;
}

long tamanho(LISTA *l) {
    return l->tamanho;
}

NO *criarNo(ITEM valor) {
    NO *pNovo = (NO*)malloc(sizeof(NO));
    if (pNovo == NULL) {
        printf("Erro: Falha na alocação de memória.\n");
        exit(EXIT_FAILURE);
    }

    pNovo->item = (ITEM *)malloc(sizeof(ITEM));
    if (pNovo->item == NULL) {
        printf("Erro: Falha na alocação de memória para o item.\n");
        free(pNovo);
        exit(EXIT_FAILURE);
    }

    *(pNovo->item) = valor;
    pNovo->prox = NULL;

    return pNovo;
}

// Função para liberar um nó e seu item dinâmico
void liberarNo(NO *no) {
    free(no->item);
    free(no);
}


bool inserir(ITEM item, LISTA *l) {
    NO *pNovo = criarNo(item);

    pNovo->prox = l->cabeca;
    l->cabeca = pNovo;
    l->tamanho++;

    return true;
}

bool remover(ITEM item, LISTA *l) {
    NO *atual = l->cabeca;
    NO *pAnt = NULL;

    while (atual != NULL) {
        if (igual(item, *(atual->item))) {
            if (pAnt == NULL) {
                // Remoção do primeiro nó
                l->cabeca = atual->prox;
            } else {
                pAnt->prox = atual->prox;
            }

            liberarNo(atual);
            l->tamanho--;

            return true;
        }

        pAnt = atual;
        atual = atual->prox;
    }

    return false;
}

void limpar(LISTA *l) {
    NO *atual = l->cabeca;
    NO *prox = NULL;

    while (atual != NULL) {
        prox = atual->prox;
        liberarNo(atual);
        atual = prox;
    }

    l->cabeca = NULL;
    l->tamanho = 0;
}

void destruir(LISTA *l) {
    limpar(l);
}

