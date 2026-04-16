#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include "TAD_vetor.h"
#include "TAD_lista.h"
#include "estatisticas.h"

#define TAMANHO_ATUAL 1000000 
#define NUM_EXECUCOES 30

//tocando agora: normal - bts
int main() {
    setlocale(LC_ALL, "pt_BR.UTF-8");
    srand(time(NULL));

    printf("QUESTÃO 02 - Busca sequencial com vetor desordenado VS Busca sequencial com lista encadeada\n");

    Vetor *vetor = criarVetor(TAMANHO_ATUAL);
    preencherDesordenado(vetor);

    Lista *lista = criarLista();
    for (int i = 0; i < TAMANHO_ATUAL; i++) {
        inserirNoFinal(lista, obterValor(vetor, i));
    }

    double temposVetor[NUM_EXECUCOES];
    double temposLista[NUM_EXECUCOES];

    for (int i = 0; i < NUM_EXECUCOES; i++) {
        int alvo;
        if (i < 15) {
            int indice = randGrande() % TAMANHO_ATUAL;
            alvo = obterValor(vetor, indice);
        } else {
            alvo = randGrande();
        }

        double inicioVetor = tempoAtual();
        buscaSequencialEmVetor(vetor, alvo);
        temposVetor[i] = tempoAtual() - inicioVetor;

        double inicioLista = tempoAtual();
        buscaSequencialEmLista(lista, alvo);
        temposLista[i] = tempoAtual() - inicioLista;

        printf("\nExecução %d: (Vetor: %.6f segundos | Lista: %.6f segundos)\n", i + 1, temposVetor[i], temposLista[i]);
    }

    double mediaVetor = media(temposVetor, NUM_EXECUCOES);
    double mediaLista = media(temposLista, NUM_EXECUCOES);
    double dpVetor = desvioPadrao(temposVetor, NUM_EXECUCOES, mediaVetor);
    double dpLista = desvioPadrao(temposLista, NUM_EXECUCOES, mediaLista);

    printf("\nMédia de tempos de execução:\n");
    printf("  Vetor: %.6f seg\n", mediaVetor);
    printf("  Lista: %.6f seg\n", mediaLista);
    printf("\nDesvio Padrão:\n");
    printf("  Vetor: %.6f seg\n", dpVetor);
    printf("  Lista: %.6f seg\n", dpLista);

    freeVetor(vetor);
    freeLista(lista);

    return 0;
}