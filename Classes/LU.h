#pragma once
#include "./MetodoNumerico.h"

class LU : public MetodoNumerico {

    public:
    LU(int n);

    int eliminateColumn(int coord, Matrix* m, Matrix* l);

    int transformar(Matrix* m, Matrix* l);

    int resolverL(Matrix* U, Matrix* m);

    int resolverU(Matrix* m);
};