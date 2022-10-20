#pragma once
#include <vector>
#include <bits/stdc++.h>
#include "../Operations/operations.h"

using namespace std;

class Matrix{
    private:
    const int row;
    const int column;
    vector<vector<double>> values;

    public:

    Matrix(int rows, int columns);

    void print();

    void inputValue(int i, int j, double value);

    int swapLines(int row1, int row2);

    int opBetweenLines(int row1, vector<double> row2, function<double(double, double)> operation);

    vector<double> multLine(double value, int line);

    int opEscalar(double value, function<double(double, double)> operador);

    int opMatrix(Matrix m1, function<double(double,double)> operation);

    int multMatrix(Matrix m1);
    
    int eliminateColumn(int coord);
    
    int GaussElimination();
    
    int resolutionTriangleUpper();
};