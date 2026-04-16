#include <stdlib.h>
#include <string.h>
#include "TAD_vetor.h"

Vetor* criarVetor(int tamanho) {
    Vetor *vetor = (Vetor*) malloc(sizeof(Vetor));
    vetor->dados = (int*) malloc(tamanho * sizeof(int));
    vetor->tamanho = tamanho;
    return vetor;
}

void freeVetor(Vetor *vetor) {
    if (vetor != NULL) {
        free(vetor->dados);
        free(vetor);
    }
}

int randGrande() {
    return (rand() * 32768) + rand();
}

void preencherDesordenado(Vetor *vetor) {
    for (int i = 0; i < vetor->tamanho; i++) {
        vetor->dados[i] = randGrande();
    }
}

void preencherOrdenado(Vetor *vetor) {
    int valorAtual = 0;
    for (int i = 0; i < vetor->tamanho; i++) {
        vetor->dados[i] = valorAtual;
        valorAtual += (randGrande() % 10) + 1;
    }
}

void copiarVetor(Vetor *origem, Vetor *destino) {
    memcpy(destino->dados, origem->dados, origem->tamanho * sizeof(int));
}

int obterValor(Vetor *vetor, int indice) {
    if (indice >= 0 && indice < vetor->tamanho) {
        return vetor->dados[indice];
    }
    return -1;
}

int buscaSequencialEmVetor(Vetor *vetor, int alvo) {
    for (int i = 0; i < vetor->tamanho; i++) {
        if (vetor->dados[i] == alvo) return i;
    }
    return -1;
}

int buscaBinaria(Vetor *vetor, int alvo) {
    int esq = 0, dir = vetor->tamanho - 1;
    while (esq <= dir) {
        int meio = (esq + dir) / 2;
        if (vetor->dados[meio] == alvo) return meio;
        else if (vetor->dados[meio] < alvo) esq = meio + 1;
        else dir = meio - 1;
    }
    return -1;
}

void troca(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(Vetor *vet){
    int i, continua, aux, fim = vet->tamanho;
    do{
        continua = 0;
        for(i = 0; i < fim - 1; i++){
            if(vet->dados[i]>vet->dados[i+1]){
                aux = vet->dados[i];
                vet->dados[i] = vet->dados[i+1];
                vet->dados[i+1] = aux;
                continua = i;
            }
        }
        fim--;
    }while(continua != 0);
}

void selectionSort(Vetor *vet){
    int i, j, menor, troca;
    for(i = 0; i < vet->tamanho - 1;i++){
        menor = i;
        for(j = i + 1; j < vet->tamanho; j++){
            if(vet->dados[j] < vet->dados[menor])
                menor = j;
        }
        if(i != menor){
            troca = vet->dados[i];
            vet->dados[i] = vet->dados[menor];
            vet->dados[menor] = troca;
        }
    }
}

void insertionSort(Vetor *vet){
    int i, j, atual;
    for(i = 1; i < vet->tamanho; i++){
        atual = vet->dados[i];
        for(j = i; (j > 0) && (atual < vet->dados[j-1]);j--)
            vet->dados[j] = vet->dados[j - 1];
        vet->dados[j] = atual;
    }
}

void merge(Vetor *vet, int inicio, int meio, int fim){
    int *temp, p1, p2, tamanho, i, j, k;
    int fim1 = 0, fim2 = 0;
    tamanho = fim - inicio+1;
    p1 = inicio;
    p2 = meio + 1;
    temp = (int*) malloc((size_t)tamanho*sizeof(int));
    if(temp != NULL){
        for(i = 0; i < tamanho; i++){
            if(!fim1 && !fim2){
                if(vet->dados[p1] < vet->dados[p2]){
                    temp[i] = vet->dados[p1++];
                }else{
                    temp[i] = vet->dados[p2++];
                }
                if(p1>meio) fim1 = 1;
                if(p2>fim) fim2 = 1;
            }else{
                if(!fim1){
                    temp[i] = vet->dados[p1++];
                }else{
                    temp[i] = vet->dados[p2++];
                }
            }
        }
        for(j = 0, k = inicio; j < tamanho; j++, k++){
            vet->dados[k] = temp[j];
        }
    }
    free(temp);
}

void mergeSort(Vetor* vet, int inicio, int fim){
    int meio;
    if(inicio < fim){
        meio = (inicio+fim)/2;
        mergeSort(vet,inicio,meio);
        mergeSort(vet, meio+1,fim);
        merge(vet,inicio,meio,fim);
    }
}

int particiona(Vetor* vet, int inicio, int fim){
    int esq,dir,pivo,aux;
    esq = inicio;
    dir = fim;
    pivo = vet->dados[inicio];
    while(esq < dir){
        while(vet->dados[esq] <= pivo && esq <= dir)
            esq++;
        while(vet->dados[dir] > pivo)
            dir--;
        if(esq < dir){
            aux = vet->dados[esq];
            vet->dados[esq] = vet->dados[dir];
            vet->dados[dir] = aux;
        }
    }
    vet->dados[inicio] = vet->dados[dir];
    vet->dados[dir] = pivo;
    return dir;
}

void quickSort(Vetor* vet, int inicio, int fim){
    int pivo;
    if(fim > inicio){
        pivo = particiona(vet,inicio,fim);
        quickSort(vet,inicio,pivo-1);
        quickSort(vet,pivo+1,fim);
    }
}