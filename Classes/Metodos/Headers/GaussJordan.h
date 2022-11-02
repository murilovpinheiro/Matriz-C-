#include "./MetodoNumerico.h"

class GaussJordan : public MetodoNumerico{

    public:
    GaussJordan(int n);

    int eliminateColumn(int coord, Matrix* m);

    int transformar(Matrix* m);

    int resolver(Matrix* m);
    
};