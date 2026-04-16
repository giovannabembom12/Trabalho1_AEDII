#include <stdlib.h>
#include "TAD_lista.h"

Lista* criarLista() {
    Lista *lista = (Lista*) malloc(sizeof(Lista));
    if (lista != NULL) {
        lista->prim = NULL;
        lista->ult = NULL;
        lista->tamanho = 0;
    }
    return lista;
}

void inserirNoFinal(Lista* l, int dado) {
    TipoNo *novo = (TipoNo*)malloc(sizeof(TipoNo));
    if (novo == NULL) return;

    novo->dado = dado;
    novo->prox = NULL;

    if (l->prim == NULL) {
        l->prim = novo;
        l->ult = novo;
    } else {
        l->ult->prox = novo;
        l->ult = novo;
    }
    l->tamanho++;
}

int buscaSequencialEmLista(Lista *l, int alvo) {
    TipoNo *atual = l->prim;
    while (atual != NULL) {
        if (atual->dado == alvo) {
            return atual->dado; // encontrou o valor ebaaa uhullll
        }
        atual = atual->prox;
    }
    // se chegou aqui, não encontrou o valor -> tristeza :(
    return -1; 
}

void freeLista(Lista *l){
    if(l != NULL){
        TipoNo *aux = l->prim;
        while(aux != NULL){
            TipoNo *tmp = aux;
            aux = aux->prox;
            free(tmp);
        }
    }
}