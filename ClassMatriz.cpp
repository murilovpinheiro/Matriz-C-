#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include "operations.h"
using namespace std;


//Func. que servem como operacoes nas operacoes de matrizes


class Matrix{
    private:
    const int row;
    const int column;
    vector<vector<double>> values;

    public:
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

    //metodo que troca duas linhas entre se de uma mesma matriz
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

    //esse metodo realiza alguma operacao entre uma linha da Matriz e outro vetor linha
    //metodo util na Eliminacao de Gauss
    int opBetweenLines(int row1, vector<double> row2, function<double(double, double)> operation){
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
    vector<double> multLine(double value, int line){
        vector<double> aux(column);
        for (int i = 0; i < column; i++){
            aux.at(i) = (values.at(line).at(i) * value);
        }
        return aux;
    }

    //operacao de uma matriz inteira com um Escalar
    //as Operacoes podem ser soma, subtracao, divisao ou mult.
    int opEscalar(double value, function<double(double, double)> operador){
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

    //multiplicacao entre 2 matrizes
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

    //um subprocesso da eliminacao de Gauss, basicamente zera todo a coluna exceto o pivo e tudo acima dele
    //utilizando claro apenas as operacoes que mantenham a condicao de sistema equivalente
    int eliminateColumn(int coord){
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

    //Eliminacao de Gauss, transforma a matriz em sua equivalente triangular superior
    int GaussElimination(){
        //Depois fazer ifs para casos onde temos sistemas sem resolução
        //Ex: tamanhos não quadrados e determinantes 
        //Por enquanto o vetor resposta é imbutido na matriz, mas acho que é melhor fazer separado
        for(int i = 0; i < row; i++){
            eliminateColumn(i);
        }
        return 0;
    }

    //metodo resolutor da matriz triangular superior
    //basicamente vai descobrindo os valores do vetor resposta
    //atualmente ta so printando os resultados mas posteriormente posso aprimorar
    int resolutionTriangleUpper(){
        vector<double> X(row);
        X.at(row - 1) = values.at(row - 1).at(column - 1)/ values.at(row - 1).at(column - 2);
        for(int i = row - 2; i >= 0; i--){
            double S = 0;
            for(int j = i + 1; j < column - 1; j++){
                S = S + values.at(i).at(j) * X.at(j);
            }
            X.at(i) = (values.at(i).at(column - 1) - S)/(values.at(i).at(i));
        }
        cout << "Resposta da Matriz: [ ";
        for(int i = 0; i < row; i++){
                cout << X.at(i) << ' ';
        }
        cout << "]";
        return 0;
    }

    //fazer pivotacao simples, nao pretendo fazer a total, e apos isso comecar outros Metodos (Gauss-Jordan, LU e outros)
};

int main(){
    Matrix m(3, 4);
    m.inputValue(0, 0, 3); m.inputValue(0, 1, 4); m.inputValue(0, 2, 2); m.inputValue(0, 3, 1);
    m.inputValue(1, 0, 7); m.inputValue(1, 1, -2); m.inputValue(1, 2, 3); m.inputValue(1, 3, 5);
    m.inputValue(2, 0, 2); m.inputValue(2, 1, 1); m.inputValue(2, 2, 8); m.inputValue(2, 3, -4);
    
    //eliminação de Gauss aparentemente funcionando
    //tá tendo aquela problema caso o valor seja MUITO próximo de 0
    //então quando o valor está em um limite tal, eu simplesmente aproximo pra 0
    //pensar em como fazer pra adicionar o vetor de respostas
    

    m.GaussElimination();
    m.resolutionTriangleUpper();
    //resolucao aparentemente funcionando bem
   
    //m.print();
}