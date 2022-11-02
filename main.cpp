#include <iostream>
#include "./Classes/Metodos/Headers/GaussJacobi.h"

using namespace std;

int main(){
    Matrix m(3, 4);
    m.inputValue(0, 0, 10); m.inputValue(0, 1, 2); m.inputValue(0, 2, 1); m.inputValue(0, 3, 7);
    m.inputValue(1, 0, 1); m.inputValue(1, 1, 5); m.inputValue(1, 2, 1); m.inputValue(1, 3, -8);
    m.inputValue(2, 0, 2); m.inputValue(2, 1, 3); m.inputValue(2, 2, 10); m.inputValue(2, 3, 6);
    
    //eliminação de Gauss aparentemente funcionando
    //tá tendo aquela problema caso o valor seja MUITO próximo de 0
    //então quando o valor está em um limite tal, eu simplesmente aproximo pra 0
    //pensar em como fazer pra adicionar o vetor de respostas
    
    GaussJacobi GJ(3);

    GJ.resolver(&m, 0.03);
    
    
}