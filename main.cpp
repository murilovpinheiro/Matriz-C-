#include <iostream>
#include "./Classes/Metodos/Headers/GaussJacobi.h"
#include "./Classes/Metodos/Headers/gauss.h"
#include "./Classes/Metodos/Headers/GaussJordan.h"
#include "./Classes/Metodos/Headers/GaussSeidel.h"
#include "./Classes/Metodos/Headers/LU.h"

using namespace std;

int main(){
    Matrix m(3, 4);
    Matrix i(3, 3);
    m.inputValue(0, 0, 5); m.inputValue(0, 1, 1); m.inputValue(0, 2, 1); m.inputValue(0, 3, 5);
    m.inputValue(1, 0, 3); m.inputValue(1, 1, 4); m.inputValue(1, 2, 1); m.inputValue(1, 3, 6);
    m.inputValue(2, 0, 3); m.inputValue(2, 1, 3); m.inputValue(2, 2, 6); m.inputValue(2, 3, 0);
    
    //limitei o numero maximo de iterações pro GaussJacobi a 20

    GaussSeidel GS(3);

    GaussJacobi GJ(3);

    GS.resolverPorInversa(&m, &i);
    GJ.resolverPorInversa(&m, &i);
    for(int i = 0; i < m.row; i++){
        cout << GS.resposta[i] << '\n';
    }

    cout << "------------------------------------\n";

    for(int i = 0; i < m.row; i++){
        cout << GJ.resposta[i] << '\n';
    }
}