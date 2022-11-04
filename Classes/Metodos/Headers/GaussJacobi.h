#pragma once
#include "./MetodoNumerico.h"

class GaussJacobi : public MetodoNumerico{

    public:
    GaussJacobi(int n);

    int obterXZero(Matrix *m, vector<double>* XZero);

    int obterC(Matrix *m, vector<vector<double>> *c);
    
    int obterG(Matrix *m, vector<double> *g);

    double maximaDistancia(vector<double> vetor1, vector<double> vetor2, int size);

    int resolver(Matrix* m, double eps);
    
};