#include <vector>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

double sumValues(double a, double b){
        return a + b;
}

double subValues(double a, double b){
        return a - b;
}

double multValues(double a, double b){
        return a * b;
}

double divValues(double a, double b){
        return a / b;
}

class Matrix{
    public:
    const int row;
    const int column;
    vector<vector<double>> values;

    Matrix(int rows, int columns) : row(rows), column(columns){
        vector<vector<double>> vetor(rows, vector<double>(columns));
        values = vetor;
    }

    void print(){
        for(int i = 0; i < row; i++){
            for(int j = 0; j < column; j++){
                cout << values[i][j] << ' ';
            }
            cout << '\n';
        }
    }

    void inputValue(int i, int j, double value){
        values.at(i).at(j) = value;
    }

    int swapLines(int row1, int row2){
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

    int opBetweenLines(int row1, vector<double> row2, function<double(double, double)> operation){
        if(row1 >= row || row1 < 0){
            return -1;
        }
        else if(column != row2.size()){
            return -2;
        }
        double value;
        for(int i = 0; i < column; i++){
            value = operation(values.at(row1).at(i), row2.at(i));
            if(value < 0.0001 && value > 0) value = 0;
            values.at(row1).at(i) = value;
        }
        return 0;
    }

    vector<double> multLine(double value, int line){
        vector<double> aux(column);
        for (int i = 0; i < column; i++){
            aux.at(i) = (values.at(line).at(i) * value);
        }
        return aux;
    }

    int opEscalar(double value, function<double(double, double)> operador){
        for (int i = 0; i < row; i++){
            for(int j = 0; j < column; j++){
                values.at(i).at(j) = operador(values.at(i).at(j), value);
            }
        }
        return 0;
    }

    int opMatrix(Matrix m1, function<double(double,double)> operation){
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

    int multMatrix(Matrix m1){
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

    int GaussElimation(){
        for(int i = 0; i < row; i++){
            eliminateLine(i);
        }
        return 0;
    }

    int eliminateLine(int coord){
        double pivot = values.at(coord).at(coord);
        double value;
        vector<double> aux;
        for(int i = coord + 1; i < row; i++){
            value = values.at(i).at(coord)/values.at(coord).at(coord);
            aux = multLine(value, coord);
            opBetweenLines(i, aux, subValues);
        }
        return 0;
    }

};

int main(){
    Matrix m(3, 3);
    m.values.at(0).at(0) =  1; m.values.at(0).at(1) =  3; m.values.at(0).at(2) = -1;
    m.values.at(1).at(0) =  2; m.values.at(1).at(1) =  1; m.values.at(1).at(2) =  1;
    m.values.at(2).at(0) =  3; m.values.at(2).at(1) = -1; m.values.at(2).at(2) =  1;
    
    //eliminação de Gauss aparentemente funcionando
    //tá tendo aquela problema caso o valor seja MUITO próximo de 0
    //então quando o valor está em um limite tal, eu simplesmente aproximo pra 0
    //pensar em como fazer pra adicionar o vetor de respostas
    m.print();
    m.GaussElimation();
    m.print();
}