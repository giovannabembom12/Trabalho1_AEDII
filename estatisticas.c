#include <math.h>
#include <time.h>
#include "estatisticas.h"

double tempoAtual(void) {
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    return ts.tv_sec + (ts.tv_nsec / 1e9);
}

double media(double tempos[], int n) {
    double soma = 0.0;
    for (int i = 0; i < n; i++) {
        soma += tempos[i];
    }
    return soma / n;
}

double desvioPadrao(double tempos[], int n, double media) {
    double variancia = 0.0;
    for (int i = 0; i < n; i++) {
        variancia += pow(tempos[i] - media, 2);
    }
    return sqrt(variancia / (n-1));
}
