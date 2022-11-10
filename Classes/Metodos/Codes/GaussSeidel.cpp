#include "../Headers/GaussSeidel.h"

GaussSeidel::GaussSeidel(int n) : MetodoNumerico(n) {}

int GaussSeidel::obterXZero(Matrix *m, vector<double>* x0){
    for(int i = 0; i < m->row; i++){
        x0->at(i) = 0;
    }
    return 0;
}


int GaussSeidel::obterC(Matrix *m, vector<vector<double>> *c){
    for(int i = 0; i < m->row; i++){
        for(int j = 0; j < m->column - 1; j++){
            if(i == j) continue;
            c->at(i).at(j) = -m->values.at(i).at(j) / m->values.at(i).at(i);
        }
    }
    return 0;
}
    
int GaussSeidel::obterG(Matrix *m, vector<double> *g){
    for(int i = 0; i < m->row; i++){
        g->at(i) = m->values.at(i).at(m->column - 1) / m->values.at(i).at(i);
    }
    return 0;
}

double GaussSeidel::maximaDistancia(vector<double> vetor1, vector<double> vetor2, int size){
    double max = 0;
    for(int i = 0; i < size; i++){
            if(abs(vetor1.at(i) - vetor2.at(i)) > max){
                max = abs(vetor1.at(i) - vetor2.at(i));
            }
    }
    return max;
}

int GaussSeidel::resolver(Matrix* m, double eps){
    vector<double> xK(m->row);
    vector<double> xKMinus1(m->row);
    vector<vector<double>> c(m->row, vector<double>(m->column - 1));
    vector<double> g(m->row);
    obterC(m, &c);
    obterG(m, &g);
    obterXZero(m, &xK);

    //Debug caso eu queira ver quais são o x0, G e C obtidos
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
    double dist_max = numeric_limits<double>::max();
    int contador = 0;
    while ( dist_max > eps && contador < 20){
        xKMinus1 = xK;
        for(int i = 0; i < m->row; i++){
            aux = 0;
            for(int j = 0; j < m->column - 1; j++){
                if(j == i) continue;
                aux += -(m->values.at(i).at(j)) * xK.at(j);
            }
            aux += (m->values.at(i).at(m->column - 1));
            xK.at(i) = 1/m->values.at(i).at(i) * aux;
        }
        dist_max = maximaDistancia(xKMinus1, xK, m->row);
        contador++;
    }
        resposta = xK;
    return 0;
}

int GaussSeidel::inversa(Matrix* m, Matrix* inversa){
    vector<double> b(m->row);
    Matrix vetorB(m->row, 1);
    Matrix inv(m->row, m->column - 1);
    for(int i = 0; i < m->row; i++){
        vetorB.values.at(i).at(0) = m->values.at(i).at(m->column - 1);
        m->values.at(i).at(m->column - 1) = 0;
    }
    for(int i = 0; i < m->column - 1; i++){
        m->values.at(i).at(m->column - 1) = 1;
        resolver(m, 0.0001);
        m->print();
        for(int j = 0; j < m->column - 1; j++){
            inv.values.at(j).at(i) = resposta.at(j);
        }
        cout << endl;
        m->values.at(i).at(m->column - 1) = 0;
    }
    inv.print();
    inv.multMatrix(vetorB);
    for(int i = 0; i < m->row; i++){
        m->values.at(i).at(m->column - 1) = vetorB.values.at(i).at(0);
    }
    vetorB.print();
    inv.print();
    return 0;
}