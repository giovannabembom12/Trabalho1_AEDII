#ifndef LISTA_H
#define LISTA_H

typedef struct TipoNo {
    int dado;
    struct TipoNo *prox;
} TipoNo;

typedef struct Lista {
    TipoNo *prim;
    TipoNo *ult;
    int tamanho;
} Lista;

Lista* criarLista();
void inserirNoFinal(Lista *l, int valor);
int buscaSequencialEmLista(Lista *l, int alvo);
void freeLista(Lista *l);

#endif