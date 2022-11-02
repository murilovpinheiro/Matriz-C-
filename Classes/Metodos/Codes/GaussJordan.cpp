#include "../Headers/GaussJordan.h"

GaussJordan::GaussJordan(int n) : MetodoNumerico(n) {}

int GaussJordan::eliminateColumn(int coord, Matrix* m){
    double pivot = m->values.at(coord).at(coord);
    m->values.at(coord) = m->multLine(1/pivot, coord);
    double value;
    vector<double> aux;

    for(int i = 0; i < m->row; i++){
        if(i != coord){
            value = m->values.at(i).at(coord) / m->values.at(coord).at(coord);
            aux = m->multLine(value, coord);
            m->opBetweenLines(i, aux, subValues);
        }
    }
    return 0;
}

int GaussJordan::transformar(Matrix* m){
    for(int i = 0; i < m->row; i++){
            eliminateColumn(i, m);
        }
    return 0;
}

int GaussJordan::resolver(Matrix* m){
    for(int i = 0; i < m->row; i++){
        resposta.at(i) = m->values.at(i).at(m->column - 1);
    }
    return 0;
}