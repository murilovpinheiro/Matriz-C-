#include "./GaussJacobi.h"

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

int GaussJacobi::resolver(Matrix *m, double eps){
    vector<double> x0(m->row);
    vector<double> xK(m->row);
    vector<vector<double>> c(m->row, vector<double>(m->column - 1));
    vector<double> g(m->row);
    obterC(m, &c);
    obterG(m, &g);
    obterXZero(m, &x0);
    for(int i = 0; i < m->row; i++){
        cout << x0.at(i)<<'\n';
    }
    for(int i = 0; i < m->row; i++){
        for(int j = 0; j < m->column - 1; j++){
            cout << c.at(i).at(j) << "  ";
        }
        cout << '\n';
    }
    for(int i = 0; i < m->row; i++){
        cout << g.at(i)<<'\n';
    }
    //Processo Iterativo:
    /*double aux;
    for(int i = 0; i < m->row; i++){
        aux = 0;
        for(int j = 0; i < m->column - 1; i++){
            aux += m->
        }
    }*/


    return 0;
}