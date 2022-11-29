#include "./EntradaSaida.h"

EntradaSaida::EntradaSaida(){}

void EntradaSaida::salvarArquivo(string metodo, int iteracoes, double erromedio, double eps){
    ofstream arquivo;
    
    arquivo.open("metodos.csv", std::ios_base::app);
    arquivo << metodo << ','<< iteracoes << ','<< erromedio <<  ','<< eps << '\n';
    arquivo.close();
}

void EntradaSaida::printResultado(string metodo, vector<double> resposta, int iteracoes, double erromedio, double eps){
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

void EntradaSaida::quadroResposta(string nome, Matrix* inversa, vector<double> resultado){
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

double EntradaSaida::calculaErroMedio(vector<double> encontrados, vector<double> reais){
    double soma = 0;
    for(int i = 0; i < encontrados.size(); i++){
        soma = soma + abs(encontrados.at(i) - reais.at(i));
    }
    return soma/encontrados.size();
}

Matrix EntradaSaida::receberMatrizEntrada(int &n){
     //deslocamentos
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