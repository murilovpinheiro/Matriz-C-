#pragma once
#include "./MetodoNumerico.h"

class LU : public MetodoNumerico {

    public:
    LU(int n);

    int eliminateColumn(int coord, Matrix* m);

    int transformar(Matrix* m);

    int resolver(Matrix* m);
};