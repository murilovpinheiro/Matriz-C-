#include <iostream>
#include <fstream>
#include "./Classes/Metodos/Headers/GaussJacobi.h"
#include "./Classes/Metodos/Headers/gauss.h"
#include "./Classes/Metodos/Headers/GaussJordan.h"
#include "./Classes/Metodos/Headers/GaussSeidel.h"
#include "./Classes/Metodos/Headers/LU.h"

using namespace std;

void salvarArquivo(string metodo, int iteracoes, double erromedio, double eps){
    ofstream arquivo;
    
    arquivo.open("metodos.csv", std::ios_base::app);
    arquivo << metodo << ','<< iteracoes << ','<< erromedio <<  ','<< eps << '\n';
    arquivo.close();
}

void printResultado(string metodo, vector<double> resposta, int iteracoes, double erromedio, double eps){
    // ofstream arquivo;
    // arquivo.open("print.txt", std::ios_base::app);
    // arquivo << metodo << "\niteracoes: " << iteracoes << "\nresultado: ";
    // for(int i = 0; i < resposta.size(); i++){
    //     arquivo << resposta[i];
    //     if (i < resposta.size()-1){
    //         arquivo << ", ";
    //     }
    // }
    // arquivo << "\nerro medio: " << erromedio <<  "\nepsilon: "<< eps << "\n\n";
    // arquivo.close();

    cout << metodo << "\niteracoes: " << iteracoes << "\nresultado real: ";
    for(int i = 0; i < resposta.size(); i++){
        cout << resposta[i];
        if (i < resposta.size()-1){
            cout << ", ";
        }
    }
    cout << "\nerro medio: " << erromedio <<  "\nepsilon: "<< eps << "\n\n";
}

void quadroResposta(string nome, Matrix* inversa, vector<double> resultado){
    cout << endl << nome << endl;
    cout << "Matriz Inversa A^-1: " << endl;
    Matrix inv(inversa->row, inversa->column);
    inv.values = inversa->values;
    for(int l = 0; l < inv.row; l++){
        for(int c = 0; c < inv.column; c++){
            cout << inv.values.at(l).at(c);
            if (c < inv.column-1) {
                cout << ", ";
            } else {
                cout << endl;
            }
        }
    }
    cout << "resultado obtido: ";
    for(int i = 0; i < resultado.size(); i++){
        cout << resultado[i];
        if (i < resultado.size()-1){
            cout << ", ";
        }
    }
    cout << endl << endl;
}

double calculaErroMedio(vector<double> encontrados, vector<double> reais){
    double soma = 0;
    for(int i = 0; i < encontrados.size(); i++){
        soma = soma + abs(encontrados.at(i) - reais.at(i));
    }
    return soma/encontrados.size();
}

Matrix receberMatrizEntrada(){
    int n; //deslocamentos
    cout << "Digite o numero de deslocamentos N: ";
    cin >> n;
    
    double temp = 0.0;
    Matrix M(n, n+1);
    
    cout << " -- Valores da matriz [A] --\n";
    //dois for loops
    for(int l=0; l<n; l++){ for(int c=0; c<n; c++){
        cout << "digite o valor na linha "<< l <<" e coluna "<< c << ": ";
        cin >> temp;
        M.inputValue(l, c, temp);
    }}
    
    cout << " -- Valores do vetor {b} --\n";
    //um for loop
    for(int p=0; p<n; p++){
        cout << "digite o valor na posicao "<< p <<": ";
        cin >> temp;
        M.inputValue(p, n, temp);
    }

    return M;
}

int main(){
    //Matrix m(3, 4);
    //m.inputValue(0, 0, 5); m.inputValue(0, 1, 1); m.inputValue(0, 2, 1); m.inputValue(0, 3, 5);
    //m.inputValue(1, 0, 3); m.inputValue(1, 1, 4); m.inputValue(1, 2, 1); m.inputValue(1, 3, 6);
    //m.inputValue(2, 0, 3); m.inputValue(2, 1, 3); m.inputValue(2, 2, 6); m.inputValue(2, 3, 0);
    
    Matrix i(3, 3); //inversa
    Matrix m = receberMatrizEntrada();

    double valorerro;
    cout << "Digite o valor do erro: ";
    cin >> valorerro;
    cout << "\n\n";
    //limitei o numero maximo de iterações pro GaussJacobi a 20
    vector<double> reais{1, 1, -1};

    GaussSeidel GS(3);
    GaussJacobi GJ(3);

    cout << " ---- QUADRO RESPOSTA ----";
    GS.resolverPorInversa(&m, &i, valorerro);
    quadroResposta("Gauss Seidel Inverso", &i, GS.resposta);
    GJ.resolverPorInversa(&m, &i, valorerro);
    quadroResposta("Gauss Jacobi Inverso", &i, GJ.resposta);
    
    cout << "-------- Informações Extras ----------" << endl << endl;

    salvarArquivo("GaussSeidelInverso", GS.iteracoes, calculaErroMedio(GS.resposta, reais), valorerro);
    printResultado("GaussSeidelInverso", GS.resposta, GS.iteracoes, calculaErroMedio(GS.resposta, reais), valorerro);
    // for(int i = 0; i < m.row; i++){
    //     cout << GS.resposta[i] << '\n';
    // }

    salvarArquivo("GaussJacobiInverso", GJ.iteracoes, calculaErroMedio(GJ.resposta, reais), valorerro);
    printResultado("GaussJacobiInverso", GJ.resposta, GJ.iteracoes, calculaErroMedio(GJ.resposta, reais), valorerro);
    // for(int i = 0; i < m.row; i++){
    //     cout << GJ.resposta[i] << '\n';
    // }

    cout << "------------------------------------------" << endl << endl;
    
    GS.resolver(&m, valorerro);
    salvarArquivo("GaussSeidelNormal", GS.iteracoes, calculaErroMedio(GS.resposta, reais), valorerro);
    printResultado("GaussSeidelNormal", GS.resposta, GS.iteracoes, calculaErroMedio(GS.resposta, reais), valorerro);
    // for(int i = 0; i < m.row; i++){
    //     cout << GS.resposta[i] << '\n';
    // }

    cout << '\n';
    GJ.resolver(&m, valorerro);
    salvarArquivo("GaussJacobiNormal", GJ.iteracoes, calculaErroMedio(GJ.resposta, reais), valorerro);
    printResultado("GaussJacobiNormal", GJ.resposta, GJ.iteracoes, calculaErroMedio(GJ.resposta, reais), valorerro);
    // for(int i = 0; i < m.row; i++){
    //     cout << GJ.resposta[i] << '\n';
    // }

    //Valores obtidos pelas formas de resolver sao diferentes ou seja, posso utilizar isso na analise
    //Aparentemente o Gauss Jacobi roda bem mais iteracoes do que o Gauss Seidel
}