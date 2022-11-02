#include "../Headers/Gauss.h"

    Gauss::Gauss(int n) : MetodoNumerico(n) {}

    //um subprocesso da eliminacao de Gauss, basicamente zera todo a coluna exceto o pivo e tudo acima dele
    //utilizando claro apenas as operacoes que mantenham a condicao de sistema equivalente
    int Gauss::eliminateColumn(int coord, Matrix* m){
        double pivot = m->values.at(coord).at(coord);
        double value;
        vector<double> aux;
        for(int i = coord + 1; i < m->row; i++){
            value = m->values.at(i).at(coord) / m->values.at(coord).at(coord);
            aux = m->multLine(value, coord);
            m->opBetweenLines(i, aux, subValues);
        }
        return 0;
    }

    //Eliminacao de Gauss, transforma a matriz em sua equivalente triangular superior
    int Gauss::transformar(Matrix* m){
        //Depois fazer ifs para casos onde temos sistemas sem resolução
        //Ex: tamanhos não quadrados e determinantes 
        //Por enquanto o vetor resposta é imbutido na matriz, mas acho que é melhor fazer separado
        for(int i = 0; i < m->row - 1; i++){
            eliminateColumn(i, m);
        }
        
        return 0;
    }

    //metodo resolutor da matriz triangular superior
    //basicamente vai descobrindo os valores do vetor resposta
    //atualmente ta so printando os resultados mas posteriormente posso aprimorar
    int Gauss::resolver(Matrix* m){
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