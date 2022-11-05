#include "../Headers/GaussJacobi.h"

GaussJacobi::GaussJacobi(int n) : MetodoNumerico(n){}

int GaussJacobi::obterXZero(Matrix *m, vector<double> *x0){
    for(int i = 0; i < m->row; i++){
        x0->at(i) = m->values.at(i).at((m->column - 1)) / m->values.at(i).at(i);
    }
    return 0;
    //Nao é verdadeiramente necessário já que a convergencia é garantida independente de x0
    //Caso a diagonal seja 0 é melhor utilizar outra coisa
    //Posso utilizar um if para esse caso ou discutir depois uma aprox. fixa melhor
}

int GaussJacobi::obterC(Matrix *m, vector<vector<double>> *c){
    for(int i = 0; i < m->row; i++){
        for(int j = 0; j < m->column - 1; j++){
            if(i == j) continue;
            c->at(i).at(j) = -m->values.at(i).at(j) / m->values.at(i).at(i);
        }
    }
    return 0;
}

int GaussJacobi::obterG(Matrix *m, vector<double> *g){
    for(int i = 0; i < m->row; i++){
        g->at(i) = m->values.at(i).at(m->column - 1) / m->values.at(i).at(i);
    }
    return 0;
}


double GaussJacobi::maximaDistancia(vector<double> vetor1, vector<double> vetor2, int size){
    double max = 0;
    for(int i = 0; i < size; i++){
            if(abs(vetor1.at(i) - vetor2.at(i)) > max){
                max = abs(vetor1.at(i) - vetor2.at(i));
            }
    }
    return max;
}

int GaussJacobi::resolver(Matrix *m, double eps){
    vector<double> xK(m->row);
    vector<double> xKMinus1(m->row);
    vector<double> result(m->row);
    vector<vector<double>> c(m->row, vector<double>(m->column - 1));
    vector<double> g(m->row);
    obterC(m, &c);
    obterG(m, &g);
    obterXZero(m, &xK);
    // for(int i = 0; i < m->row; i++){
    //     cout << x0.at(i)<<'\n';
    // }
    // for(int i = 0; i < m->row; i++){
    //     for(int j = 0; j < m->column - 1; j++){
    //         cout << c.at(i).at(j) << "  ";
    //     }
    //     cout << '\n';
    // }
    // for(int i = 0; i < m->row; i++){
    //     cout << g.at(i)<<'\n';
    // }
    double aux;
    double dist_max = 1000000;
    int indice = 0;
    while ( dist_max > eps && indice < 20){
        xKMinus1 = xK;
        for(int i = 0; i < m->row; i++){
            aux = 0;
            for(int j = 0; j < m->column - 1; j++){
                if(j == i) continue;
                aux += -(m->values.at(i).at(j)) * xK.at(j);
            }
            aux += (m->values.at(i).at(m->column - 1));
            result.at(i) = 1/m->values.at(i).at(i) * aux;
        }
        xK = result;
        dist_max = maximaDistancia(xKMinus1, xK, m->row);
        for(int k = 0; k < m->row; k++){
            cout << xK.at(k) << "\n";
        }
        indice++;
    }
        resposta = xK;
        //FALTA SÓ O SEGUNDO TESTE
    return 0;
}