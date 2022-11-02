#pragma once
#include "./MetodoNumerico.h"

class GaussJacobi : public MetodoNumerico{

    public:
    GaussJacobi(int n);

    int obterXZero(Matrix *m, vector<double>* XZero);

    int obterC(Matrix *m, vector<vector<double>> *c);

    int obterG(Matrix *m, vector<double> *g);

    int resolver(Matrix* m, double eps);
    
};