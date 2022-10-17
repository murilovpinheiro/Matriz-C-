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

    ~Matrix(){
        //não sei oq fazer aqui
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

    int opBetweenLines(int row1, int row2, function<double(double, double)> operation){
        if(row1 >= row || row2 >= row){
            return -1;
        }
        else if(row1 < 0 || row2 < 0){
            return -2;
        }
        for(int i = 0; i < column; i++){
            values.at(row1).at(i) = operation(values.at(row1).at(i), values.at(row2).at(i));
        }
        return 0;
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

};

int main(){
    Matrix m(3, 3);
    Matrix m2(3, 3);
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            m.inputValue(i, j, i + j + 1);
            m2.inputValue(j, i, i + j + 2);
        }
    }
    m.print();
    cout << '\n';
    m2.print();
    cout << '\n';
    m.opEscalar(5, divValues);
    m.print();
}