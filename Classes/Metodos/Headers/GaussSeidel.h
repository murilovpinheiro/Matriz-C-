#pragma once
#include "./MetodoNumerico.h"

class GaussSeidel : public MetodoNumerico{

    public:
    GaussSeidel(int n);

    int obterXZero(Matrix *m, vector<double>* x0);

    int obterC(Matrix *m, vector<vector<double>> *c);
    
    int obterG(Matrix *m, vector<double> *g);

    double maximaDistancia(vector<double> vetor1, vector<double> vetor2, int size);

    int resolver(Matrix* m, double eps);
    
    int resolverPorInversa(Matrix* m, Matrix* inversa);
    
};