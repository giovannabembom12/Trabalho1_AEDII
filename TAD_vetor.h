#ifndef VETOR_H
#define VETOR_H

typedef struct {
    int *dados;
    int tamanho;
} Vetor;

Vetor* criarVetor(int tamanho);
void freeVetor(Vetor *vetor);
int randGrande();
void preencherDesordenado(Vetor *vetor);
void preencherOrdenado(Vetor *vetor);
void copiarVetor(Vetor *origem, Vetor *destino);
int obterValor(Vetor *vetor, int indice);

int buscaSequencialEmVetor(Vetor *vetor, int alvo);
int buscaBinaria(Vetor *vetor, int alvo);

void bubbleSort(Vetor *v);
void selectionSort(Vetor *v);
void insertionSort(Vetor *v);
void mergeSort(Vetor *v, int inicio, int fim);
void quickSort(Vetor* v, int inicio, int fim);

#endif
