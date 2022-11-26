#pragma once
#include <iostream>
#include <fstream>
#include "../Metodos/Headers/GaussJacobi.h"
#include "../Metodos/Headers/gauss.h"
#include "../Metodos/Headers/GaussJordan.h"
#include "../Metodos/Headers/GaussSeidel.h"
#include "../Metodos/Headers/LU.h"

class EntradaSaida {

    public:
    EntradaSaida();

    void salvarArquivo(string metodo, int iteracoes, double erromedio, double eps);

    void printResultado(string metodo, vector<double> resposta, int iteracoes, double erromedio, double eps);

    void quadroResposta(string nome, Matrix* inversa, vector<double> resultado);

    double calculaErroMedio(vector<double> encontrados, vector<double> reais);

    Matrix receberMatrizEntrada();


};