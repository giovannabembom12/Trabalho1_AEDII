#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <locale.h>
#include "TAD_vetor.h"
#include "estatisticas.h"

#define TAMANHO_VETOR 100000 
#define NUM_RODADAS 10

int main() {
    setlocale(LC_ALL, "pt_BR.UTF-8");
    srand(time(NULL));
    
    printf("QUESTÃO 03 - Algoritmos de ordenação em vetor \n");

    double temposBubble[NUM_RODADAS];
    double temposInsertion[NUM_RODADAS];
    double temposSelection[NUM_RODADAS];
    double temposQuick[NUM_RODADAS];
    double temposMerge[NUM_RODADAS];

    Vetor *vetorBase = criarVetor(TAMANHO_VETOR);
    Vetor *vetorTeste = criarVetor(TAMANHO_VETOR);

    for (int r = 0; r < NUM_RODADAS; r++) {
       
        preencherDesordenado(vetorBase);

        copiarVetor(vetorBase, vetorTeste);
        double inicio = tempoAtual();
        bubbleSort(vetorTeste);
        temposBubble[r] = tempoAtual() - inicio;

        copiarVetor(vetorBase, vetorTeste);
        inicio = tempoAtual();
        insertionSort(vetorTeste);
        temposInsertion[r] = tempoAtual() - inicio;

        copiarVetor(vetorBase, vetorTeste);
        inicio = tempoAtual();
        selectionSort(vetorTeste);
        temposSelection[r] = tempoAtual() - inicio;

        copiarVetor(vetorBase, vetorTeste);
        inicio = tempoAtual();
        quickSort(vetorTeste, 0, vetorTeste->tamanho - 1);
        temposQuick[r] = tempoAtual() - inicio;

        copiarVetor(vetorBase, vetorTeste);
        inicio = tempoAtual();
        mergeSort(vetorTeste, 0, vetorTeste->tamanho - 1);
        temposMerge[r] = tempoAtual() - inicio;
    }

    double mediaBubble = media(temposBubble, NUM_RODADAS);
    double mediaInsertion = media(temposInsertion, NUM_RODADAS);
    double mediaSelection = media(temposSelection, NUM_RODADAS);
    double mediaQuick = media(temposQuick, NUM_RODADAS);
    double mediaMerge = media(temposMerge, NUM_RODADAS);

    double desvioBubble = desvioPadrao(temposBubble, NUM_RODADAS, mediaBubble);
    double desvioInsertion = desvioPadrao(temposInsertion, NUM_RODADAS, mediaInsertion);
    double desvioSelection = desvioPadrao(temposSelection, NUM_RODADAS, mediaSelection);
    double desvioQuick = desvioPadrao(temposQuick,NUM_RODADAS, mediaQuick);
    double desvioMerge = desvioPadrao(temposMerge, NUM_RODADAS, mediaMerge);

    printf("\nTempos de execução\n\n");

    for (int k = 0; k < 5; k++) {
        for (int l = 0; l < NUM_RODADAS; l++) {
            switch (k) {
                case 0: 
                printf("%f ", temposBubble[l]); 
                break;
                case 1: 
                printf("%f ", temposSelection[l]); 
                break;
                case 2: 
                printf("%f ", temposInsertion[l]); 
                break;
                case 3: 
                printf("%f ", temposMerge[l]);
                break;
                case 4: 
                printf("%f ", temposQuick[l]); 
                break;
            }
        }
        printf("\n\n");
    }

    printf("Médias de cada algoritmo de ordenação:\n");

    for (int k = 0; k < 5; k++) {
        switch (k) {
            case 0: printf("Média do BubbleSort: %f\n", mediaBubble); break;
            case 1: printf("Média do SelectionSort: %f\n", mediaSelection); break;
            case 2: printf("Média do InsertionSort: %f\n", mediaInsertion); break;
            case 3: printf("Média do MergeSort: %f\n", mediaMerge); break;
            case 4: printf("Média do QuickSort: %f\n", mediaQuick); break;
        }
    }
    
    printf("\nDesvio padrão de cada algoritmo de ordenação\n");

    for (int k = 0; k < 5; k++) {
        switch (k) {
            case 0: printf("Desvio Padrão do BubbleSort: %f\n", desvioBubble); break;
            case 1: printf("Desvio Padrão do SelectionSort: %f\n", desvioSelection); break;
            case 2: printf("Desvio Padrão do InsertionSort: %f\n", desvioInsertion); break;
            case 3: printf("Desvio Padrão do MergeSort: %f\n", desvioMerge); break;
            case 4: printf("Desvio Padrão do QuickSort: %f\n", desvioQuick); break;
        }
    }

    freeVetor(vetorBase);
    freeVetor(vetorTeste);

    return 0;
}
