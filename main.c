#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "ListaSeqEst.h"

// Imprime na tela o status da lista
void imprimirStatus(LISTA *l)
{
    printf("Tamanho = %ld\n", tamanho(l));
	exibirLista(l);
	printf("\n");
}

// Testa a insercao de valores na lista
void testarInserir(LISTA *l)
{
    printf("=> Teste de Inserir\n");
    long qtd;
    printf("Quantos itens deseja guardar na lista? ");
    scanf("%ld", &qtd);

    ITEM item;
	for (long i = 0; i < qtd; i++)
    {
        printf("Digite o valor para a posicao [%ld]: ", i);
        scanf("%d", &item);
        inserir(item, l);
	}

	imprimirStatus(l);
}

// Testa a insercao de valores na lista escolhendo a posicao
void testarInserirNaPos(LISTA *l)
{
    printf("=> Teste de InserirNaPos\n");
    long qtd;
    printf("Quantos itens deseja inserir na lista? ");
    scanf("%ld", &qtd);

	ITEM item;
	for (long i = 0; i < qtd; i++)
    {
        printf("Digite a posicao de insercao (de 0 a %ld): ", tamanho(l));
        long p;
        scanf("%ld", &p);
  
        printf("Digite o valor para a posicao [%ld]: ", p);
        scanf("%d", &item);
        if (inserirNaPos(item, p, l))
            printf("Insercao com sucesso\n");
        else
            printf("Erro na insercao\n");

        imprimirStatus(l);
	}

}
// Testa a busca de valores na lista
void testarBuscar(LISTA *l)
{
   // Testa a busca por um valor existente
    printf("=> Teste de Busca\n");
    printf("Digite o valor que deseja buscar: ");
    ITEM item;
    scanf("%d", &item);
    long pos = buscar(item, l); 
    if (pos >= 0)
        printf("Achou na posicao: %ld\n", pos);
    else
        printf("Nao achou o item na lista\n");

    // Testa a busca por uma posicao existente
    printf("Digite a posicao que deseja acessar (ou -1 para sair): ");
    long p;
    scanf("%ld", &p);
    while (p != -1)
    {
        ITEM item = enesimo(p, l);
        printf("Achou na posicao[%ld] o valor: %d\n", p, item);
        // Leitura da proxima posicao a ser acessada
        printf("Digite a posicao que deseja acessar (ou -1 para sair): ");
        scanf("%ld", &p);
    }

}

// Testa a alteracao de um valor numa posicao
void testarAlterar(LISTA *l)
{
    printf("=> Teste da Alteracao\n");
    long p;
    printf("Digite a posicao que deseja alterar (ou -1 para sair): ");
    scanf("%ld", &p);
    while (p != -1)
    {
        // Leitura do novo valor
        printf("Digite o NOVO valor para a posicao [%ld]: ", p);
        ITEM item;
        scanf("%d", &item);
        if (alterar(item, p, l))
           printf("Alterou com sucesso\n");
        else
           printf("Erro na alteracao\n");

        imprimirStatus(l);

        // Leitura da proxima posicao a ser acessada
        printf("Digite a posicao que deseja alterar (ou -1 para sair): ");
        scanf("%ld", &p);
    }
}

/////////////////////////////////////////////////////

int main(){
	LISTA l;
	
	inicializar(&l);
    testarInserir(&l);
    testarInserirNaPos(&l);
    testarBuscar(&l);   
    testarAlterar(&l);
    destruir(&l);
    imprimirStatus(&l);
        
    getchar();
	return 0;
}