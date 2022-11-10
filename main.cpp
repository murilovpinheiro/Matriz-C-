#include <iostream>
#include "./Classes/Metodos/Headers/GaussJacobi.h"
#include "./Classes/Metodos/Headers/gauss.h"
#include "./Classes/Metodos/Headers/GaussJordan.h"
#include "./Classes/Metodos/Headers/GaussSeidel.h"
#include "./Classes/Metodos/Headers/LU.h"

using namespace std;

int main(){
    Matrix m(3, 4);
    m.inputValue(0, 0, 5); m.inputValue(0, 1, 1); m.inputValue(0, 2, 1); m.inputValue(0, 3, 5);
    m.inputValue(1, 0, 3); m.inputValue(1, 1, 4); m.inputValue(1, 2, 1); m.inputValue(1, 3, 6);
    m.inputValue(2, 0, 3); m.inputValue(2, 1, 3); m.inputValue(2, 2, 6); m.inputValue(2, 3, 0);
    
    //eliminação de Gauss aparentemente funcionando
    //tá tendo aquela problema caso o valor seja MUITO próximo de 0
    //então quando o valor está em um limite tal, eu simplesmente aproximo pra 0

    //faltando alguns detalhes no GaussJacobi que vou organizar quando terminar o Seidel
    
    //limitei o numero maximo de iterações pro GaussJacobi a 20

    GaussSeidel GJ(3);

    GJ.resolver(&m, 0.05);

    for(int i = 0; i < m.row; i++){
        cout << GJ.resposta[i] << '\n';
    }
}