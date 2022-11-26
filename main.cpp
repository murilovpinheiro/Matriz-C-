#include <iostream>
#include <fstream>
#include "./Classes/EntradaSaida/EntradaSaida.h"

Matrix benchmark(){
    //Matriz A
    //    | 5   3   1 |
    //    | 5   6   1 |
    //    | 1   6   7 |
    //Vetor b
    //    | 1 |
    //    | 2 |
    //    | 3 |
        
    Matrix m(3, 4);
    
    m.inputValue(0, 0, 5); m.inputValue(0, 1, 3); m.inputValue(0, 2, 1); m.inputValue(0, 3, 1);
    m.inputValue(1, 0, 5); m.inputValue(1, 1, 6); m.inputValue(1, 2, 1); m.inputValue(1, 3, 2);
    m.inputValue(2, 0, 1); m.inputValue(2, 1, 6); m.inputValue(2, 2, 7); m.inputValue(2, 3, 3);
    return m;
}

int main(){
    EntradaSaida io;
    //Matrix m(3, 4);
    //m.inputValue(0, 0, 5); m.inputValue(0, 1, 1); m.inputValue(0, 2, 1); m.inputValue(0, 3, 5);
    //m.inputValue(1, 0, 3); m.inputValue(1, 1, 4); m.inputValue(1, 2, 1); m.inputValue(1, 3, 6);
    //m.inputValue(2, 0, 3); m.inputValue(2, 1, 3); m.inputValue(2, 2, 6); m.inputValue(2, 3, 0);
    
    Matrix i(3, 3); //inversa
    Matrix m = benchmark();
    Matrix m2(3, 4);
    m2.values = m.values;
    Gauss G(3);
    G.transformar(&m2);
    G.resolver(&m2);

    double valorerro;
    cout << "Digite o valor do erro: ";
    cin >> valorerro;
    cout << "\n\n";
    //limitei o numero maximo de iterações pro GaussJacobi a 20

    
    GaussSeidel GS(3);
    GaussJacobi GJ(3);
    

    vector<double> reais = G.resposta;

    cout << " ---- QUADRO RESPOSTA ----";
    GS.resolverPorInversa(&m, &i, valorerro);
    io.quadroResposta("Gauss Seidel Inverso", &i, GS.resposta);
    GJ.resolverPorInversa(&m, &i, valorerro);
    io.quadroResposta("Gauss Jacobi Inverso", &i, GJ.resposta);
    
    cout << "-------- Informações Extras ----------" << endl << endl;

    io.salvarArquivo("GaussSeidelInverso", GS.iteracoes, io.calculaErroMedio(GS.resposta, reais), valorerro);
    io.printResultado("Gauss Seidel por Inversa", GS.resposta, GS.iteracoes, io.calculaErroMedio(GS.resposta, reais), valorerro);
    // for(int i = 0; i < m.row; i++){
    //     cout << GS.resposta[i] << '\n';
    // }

    io.salvarArquivo("GaussJacobiInverso", GJ.iteracoes, io.calculaErroMedio(GJ.resposta, reais), valorerro);
    io.printResultado("Gauss Jacobi por Inversa", GJ.resposta, GJ.iteracoes, io.calculaErroMedio(GJ.resposta, reais), valorerro);
    // for(int i = 0; i < m.row; i++){
    //     cout << GJ.resposta[i] << '\n';
    // }

    cout << "------------------------------------------" << endl << endl;
    
    GS.resolver(&m, valorerro);
    io.salvarArquivo("GaussSeidelNormal", GS.iteracoes, io.calculaErroMedio(GS.resposta, reais), valorerro);
    io.printResultado("Gauss Seidel Normal", GS.resposta, GS.iteracoes, io.calculaErroMedio(GS.resposta, reais), valorerro);
    // for(int i = 0; i < m.row; i++){
    //     cout << GS.resposta[i] << '\n';
    // }

    cout << '\n';
    GJ.resolver(&m, valorerro);
    io.salvarArquivo("GaussJacobiNormal", GJ.iteracoes, io.calculaErroMedio(GJ.resposta, reais), valorerro);
    io.printResultado("Gauss Jacobi Normal", GJ.resposta, GJ.iteracoes, io.calculaErroMedio(GJ.resposta, reais), valorerro);
    // for(int i = 0; i < m.row; i++){
    //     cout << GJ.resposta[i] << '\n';
    // }

    cout << "\n" << "Valor Real (Obtido atraves do Metodo de Eliminacao de Gauss): " << endl;
    for(int i = 0; i < m.row; i++){
        cout << G.resposta[i] << ' ';
    }
    
    //m.inputValue(0, 0, 5); m.inputValue(0, 1, 1); m.inputValue(0, 2, 1); m.inputValue(0, 3, 5);
    //m.inputValue(1, 0, 3); m.inputValue(1, 1, 4); m.inputValue(1, 2, 1); m.inputValue(1, 3, 6);
    //m.inputValue(2, 0, 3); m.inputValue(2, 1, 3); m.inputValue(2, 2, 6); m.inputValue(2, 3, 0);

    //Valores obtidos pelas formas de resolver sao diferentes ou seja, posso utilizar isso na analise
}