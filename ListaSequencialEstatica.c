#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "ListaSeqEst.h"


char compare(ITEM x, ITEM y)
{
    return x > y ? 1 : (x < y ? -1 : 0);
}


bool igual(ITEM x, ITEM y)
{
    return compare(x,y) == 0;
}


void inicializar(LISTA *l)
{
    l->tamanho = 0;
}


long tamanho(LISTA *l)
{
    return l->tamanho;
}


bool cheia(LISTA *l)
{
    return tamanho(l) == MAX;
}


bool vazia(LISTA *l)
{
    return tamanho(l) == 0;
}


bool inserir(ITEM item, LISTA *l)
{
    if (tamanho(l) == MAX) 
        return false; // lista cheia
    else
       l->itens[l->tamanho++] = item;
    return true;
}


// long buscar(ITEM item, LISTA *l)
// {
//     for (long pos = 0; pos < tamanho(l); pos++)
//        if (igual(item, l->itens[pos]))
//            return pos; // achou
//     return -1; // nao achou
// }

// ITEM buscar(ITEM item, LISTA *l) {
//     // Ajustando a função buscar padrão para utilizar buscarEm
//     return buscarEm(item, 0, tamanho(l), l);
// }


ITEM enesimo(long n, LISTA *l)
{
    if (n >= 0 && n < tamanho(l))
       return (l->itens[n]);
    else 
    {
        printf("ERRO: Posicao %ld fora dos limites da lista (0 a %ld).\n",
               n, tamanho(l)-1);
        exit(EXIT_FAILURE);
    }
}


bool alterar(ITEM item, long pos, LISTA *l)
{
    if (pos >= 0 && pos < tamanho(l))
    {
        l->itens[pos] = item;
        return true;
    } 
    return false;
}


bool inserirNaPos(ITEM item, long i, LISTA *l)
{
    // A posicao tem que estar entre 0 e MAX-1 e ate o tamanho atual
    if ((tamanho(l) >= MAX) || (i < 0) || (i > tamanho(l)))
        return false; // lista cheia ou indice invalido

    // Se for inserido no meio, e necessario abrir espaco para o item
    for (long j = tamanho(l); j > i; j--)
        l->itens[j] = l->itens[j-1];

    // Coloca o item em um espaco vago e ajusta o tamanho        
    l->itens[i] = item;
    l->tamanho++;
    return true;
}


bool remover(ITEM item, LISTA *l)
{
    long i, j;
    for (i = 0; i < tamanho(l); i++)
        if (igual(item, l->itens[i]))
        {
            for (j = i; j < l-> tamanho - 1; j++)
               l->itens[j] = l->itens[j + 1];

            l->tamanho--;
            return true; // achou
        }   
    return false; // nao achou
}


void exibirItem(ITEM i)
{
    printf("%d", i);
}


void exibirLista(LISTA *l)
{
    printf("[");
    for(long i = 0; i < tamanho(l);)
    {
        exibirItem(l->itens[i++]);
        if (i < tamanho(l))
           printf(",");
    }
    printf("]");
}

void limpar(LISTA *l)
{
    l->tamanho = 0;
}

void destruir(LISTA *l)
{
   limpar(l);
}

void exibirListaReversa(LISTA *l) {
    printf("[");
    for (long i = tamanho(l) - 1; i >= 0; i--) {
        exibirItem(l->itens[i]);
        if (i > 0) {
            printf(",");
        }
    }
    printf("]\n");
}

bool removerDaPos(ITEM *item, int i, LISTA *l) {
    if (i < 0 || i >= tamanho(l)) {
        // Posição inválida
        return false;
    }

    *item = l->itens[i];

    for (int j = i; j < tamanho(l) - 1; j++) {
        l->itens[j] = l->itens[j + 1];
    }

    l->tamanho--;

    return true;
}
    
int buscarEm(ITEM item, int inicio, int fim, LISTA *l) {
    if (inicio < 0 || fim >= tamanho(l) || inicio >= fim) {
        // Parâmetros inválidos
        return -1;
    }

    for (int i = inicio; i < fim; i++) {
        if (igual(item, l->itens[i])) {
            // Item encontrado
            return i;
        }
    }

    // Item não encontrado
    return -1;
}

void reversa(LISTA *l) {
    long i, j;
    ITEM temp;

    for (i = 0, j = tamanho(l) - 1; i < j; i++, j--) {
        // Troca os elementos do início com os do final
        temp = l->itens[i];
        l->itens[i] = l->itens[j];
        l->itens[j] = temp;
    }
}