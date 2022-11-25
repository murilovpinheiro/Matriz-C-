#pragma once
#include <math.h>
#include "../../ClassMatriz/ClassMatriz.h"

class MetodoNumerico {
    public:
    vector<double> resposta;
    int iteracoes;

    MetodoNumerico(int n);

    int transformar(const Matrix& m);

    int resolver(const Matrix& m);
    
};