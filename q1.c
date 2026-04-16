#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <locale.h>
#include "TAD_vetor.h"
#include "estatisticas.h"

#define TAMANHO_VETOR 1000000
#define NUM_EXECUCOES 30

int compararInts(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}
 
int main() {

    setlocale(LC_ALL, "pt_BR.UTF-8"); 

    printf("QUESTÃO 01 - Busca sequencial com vetor desordenado VS Busca binária com vetor ordenado");
    srand(time(NULL));

    Vetor *vetorSeq = criarVetor(TAMANHO_VETOR);
    preencherDesordenado(vetorSeq);   // valores aleatórios n ordenados

    Vetor *vetorBin = criarVetor(TAMANHO_VETOR);
    copiarVetor(vetorSeq, vetorBin);

    qsort(vetorBin->dados, vetorBin->tamanho, sizeof(int), compararInts);

    // vetores pra guardar os tempos das execuções
    double temposSeq[NUM_EXECUCOES];
    double temposBin[NUM_EXECUCOES];

    for (int i = 0; i < NUM_EXECUCOES; i++) {
        int alvoSeq, alvoBin;

        if (i < 15) {
            // primeiras quinze execuções tem o valor presente no vetor
            int indice = rand() % TAMANHO_VETOR;
            alvoSeq = obterValor(vetorSeq, indice);
            alvoBin = obterValor(vetorBin, indice);  // mesmo valor, mas no vetor ordenado
        } else {
            // últimas quinze execuções tem um valor que prov n tá no vetor
            alvoSeq = rand() % (TAMANHO_VETOR * 10); 
            alvoBin = rand() % (TAMANHO_VETOR * 10);
        }

        //sequencial
        double inicioSeq = tempoAtual();
        buscaSequencialEmVetor(vetorSeq, alvoSeq);
        temposSeq[i] = tempoAtual() - inicioSeq;

        //binária
        double inicioBin = tempoAtual();
        buscaBinaria(vetorBin, alvoBin);
        temposBin[i] = tempoAtual() - inicioBin;
    }

    printf("\nBUSCA SEQUENCIAL com o Vetor Desordenado:\n");
    for (int i = 0; i < NUM_EXECUCOES; i++) {
        printf("Execução %2d: %f segundos\n", i + 1, temposSeq[i]);
    }
    double mediaSeq = media(temposSeq, NUM_EXECUCOES);
    double dpSeq = desvioPadrao(temposSeq, NUM_EXECUCOES, mediaSeq);
    printf("Média: %f seg \nDesvio Padrão: %f seg\n\n", mediaSeq, dpSeq);

    printf("BUSCA BINÁRIA com o Vetor Ordenado:\n");
    for (int i = 0; i < NUM_EXECUCOES; i++) {
        printf("Execução %2d: %f segundos\n", i + 1, temposBin[i]);
    }
    double mediaBin = media(temposBin, NUM_EXECUCOES);
    double dpBin = desvioPadrao(temposBin, NUM_EXECUCOES, mediaBin);
    printf("Média: %f seg \nDesvio Padrão: %f seg\n", mediaBin, dpBin);

    freeVetor(vetorSeq);
    freeVetor(vetorBin);

    return 0;
}
