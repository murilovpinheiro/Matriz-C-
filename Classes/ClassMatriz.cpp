#include <vector>
#include <bits/stdc++.h>
#include "../Operations/operations.h"
#include "./ClassMatriz.h"

using namespace std;

//Construtor da Classe Matriz

    Matrix::Matrix(int rows, int columns) : row(rows), column(columns){
        vector<vector<double>> vetor(rows, vector<double>(columns));
        values = vetor;
    }
//IDEIA:
//Pensando em separar os métodos da ideia de matriz e tornar eles algo independente, com checagens e outras coisas

    void Matrix::print(){
        for(int i = 0; i < row; i++){
            for(int j = 0; j < column; j++){
                cout << values[i][j] << ' ';
            }
            cout << '\n';
        }
    }

    void Matrix::inputValue(int i, int j, double value){
        values.at(i).at(j) = value;
    }

    //metodo que troca duas linhas entre se de uma mesma matriz
    int Matrix::swapLines(int row1, int row2){
        if(row1 >= row || row2 >= row){
            return -1;
        }
        else if(row1 < 0 || row2 < 0){
            return -2;
        }
        vector<double> aux = values.at(row1);
        values.at(row1) = values.at(row2);
        values.at(row2) = aux;
        return 0;
    }

    //esse metodo realiza alguma operacao entre uma linha da Matriz e outro vetor linha
    //metodo util na Eliminacao de Gauss
    int Matrix::opBetweenLines(int row1, vector<double> row2, function<double(double, double)> operation){
        if(row1 >= row || row1 < 0){
            return -1;
        }
        else if(column != row2.size()){
            return -2;
        }
        for(int i = 0; i < column; i++){
            values.at(row1).at(i) = operation(values.at(row1).at(i), row2.at(i));
        }
        return 0;
    }

    //recebe multiplica uma linha da Matriz por um valor escalar, retorna a linha multiplicada, nao modifica a matriz original
    //utilizado tambem na Eliminacao de Gauss
    vector<double> Matrix::multLine(double value, int line){
        vector<double> aux(column);
        for (int i = 0; i < column; i++){
            aux.at(i) = (values.at(line).at(i) * value);
        }
        return aux;
    }

    //operacao de uma matriz inteira com um Escalar
    //as Operacoes podem ser soma, subtracao, divisao ou mult.
    int Matrix::opEscalar(double value, function<double(double, double)> operador){
        for (int i = 0; i < row; i++){
            for(int j = 0; j < column; j++){
                values.at(i).at(j) = operador(values.at(i).at(j), value);
            }
        }
        return 0;
    }

    //operacoes entre 2 matrizes
    //as operacoes podem ser subtracao e soma, futuro adicionar algum meio de evitar a multiplicacao e a divisao como entrada
    //como utiliza funcao de alta ordem, nao tenho muita ideia de como fazer isso direitinho
    int Matrix::opMatrix(Matrix m1, function<double(double,double)> operation){
        if (m1.row != row || m1.column != column){
            return -1;
        }
        for (int i = 0; i < row; i++){
            for(int j = 0; j < column; j++){
                values.at(i).at(j) = operation(values.at(i).at(j), m1.values.at(i).at(j));
            }
        }
        return 0;
    }

    //multiplicacao entre 2 matrizes
    int Matrix::multMatrix(Matrix m1){
        if(column == m1.row){
            vector<vector<double>> aux(row, vector<double>(column));
            for(int i = 0; i < row; i++){
                for(int j = 0; j < row; j++){
                    for(int k = 0; k < row; k++){
                        aux.at(i).at(j) += values.at(i).at(k) * m1.values.at(k).at(j);
                    }
                }
            }
            values = aux;
            return 0;
        }
        return -1;
    }
