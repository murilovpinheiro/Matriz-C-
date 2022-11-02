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
        //m é a matriz U e l é a matriz L
        l->values.at(0).at(0) = 1;
        for(int i = 0; i < m->row; i++){
            l->values.at(i).at(l->column - 1) = m->values.at(i).at(m->column - 1);
            m->values.at(i).at(m->column - 1) = 0;
            cout << m->values.at(i).at(m->column - 1)<<"\n";
        }
        //essas duas linhas são necessárias pois no func elimCol eu sempre faço a operação na linha i + 1, pulando a linha 0
        for(int i = 0; i < m->row - 1; i++){
            eliminateColumn(i, m, l);
        }
        return 0;
    }

    int LU::resolverL(Matrix* U, Matrix* m){
        U->values.at(U->row - 1).at(U->column - 1) = m->values.at(0).at(m->column - 1)/ m->values.at(0).at(0);
        for(int i = 0; i < m->row; i++){
            double S = 0;
            for(int j = i - 1; j >= 0; j--){
                S = S + m->values.at(i).at(j) * U->values.at(j).at(U->column - 1);
            }
            
            U->values.at(i).at(U->column - 1) = (m->values.at(i).at(m->column - 1) - S)/(m->values.at(i).at(i));
            double a = U->values.at(i).at(U->column - 1);
            if((a < 0.0001 && a > 0 ) || (a > -0.0001 && a < 0) ) U->values.at(i).at(U->column - 1) = 0;
        }
        return 0;
    }
    int LU::resolverU(Matrix* m){
        vector<double> X(m->row);
        X.at(m->row - 1) = m->values.at(m->row - 1).at(m->column - 1) / m->values.at(m->row - 1).at(m->column - 2);
        for(int i = m->row - 2; i >= 0; i--){
            double S = 0;
            for(int j = i + 1; j < m->column - 1; j++){
                S = S + m->values.at(i).at(j) * X.at(j);
            }
            X.at(i) = (m->values.at(i).at(m->column - 1) - S)/(m->values.at(i).at(i));
            
        }
        resposta = X;
        return 0;
    }