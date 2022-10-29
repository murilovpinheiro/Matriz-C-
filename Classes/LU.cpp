#include "./LU.h"

LU::LU(int n) : MetodoNumerico(n) {}

    int LU::eliminateColumn(int coord, Matrix* m, Matrix* l){
        double pivot = m->values.at(coord).at(coord);
        l->values.at(coord + 1).at(coord + 1) = 1;
        //Coloquei esse + 1 por que a Primeira Linha a gente n faz nada so preenche com 1 na pos 0 0 
        double value;
        vector<double> aux;
        for(int i = coord + 1; i < m->row; i++){
            value = m->values.at(i).at(coord) / m->values.at(coord).at(coord);
            l->values.at(i).at(coord) = value;
            aux = m->multLine(value, coord);
            m->opBetweenLines(i, aux, subValues);
        }
        return 0;
    }

    int LU::transformar(Matrix* m, Matrix* l){
        //preenche a matriz L sendo a matriz Lower
        l->values.at(0).at(0) = 1;
        for(int i = 0; i < m->row - 1; i++){
            eliminateColumn(i, m, l);
        }
        return 0;
    }