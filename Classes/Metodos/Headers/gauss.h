#pragma once
#include "./MetodoNumerico.h"

class Gauss : public MetodoNumerico {

    public:
    Gauss(int n);

    int eliminateColumn(int coord, Matrix* m);

    int transformar(Matrix* m);

    int resolver(Matrix* m);
};