#include <iostream>
#include "./Classes/Gauss.h"
#include "./Classes/GaussJordan.h"
#include "./Classes/LU.h"

using namespace std;

int main(){
    Matrix m(3, 4);
    m.inputValue(0, 0, 3); m.inputValue(0, 1, 2); m.inputValue(0, 2, 4); m.inputValue(0, 3, 1);
    m.inputValue(1, 0, 1); m.inputValue(1, 1, 1); m.inputValue(1, 2, 2); m.inputValue(1, 3, 2);
    m.inputValue(2, 0, 4); m.inputValue(2, 1, 3); m.inputValue(2, 2, -2); m.inputValue(2, 3, 3);
    
    //eliminação de Gauss aparentemente funcionando
    //tá tendo aquela problema caso o valor seja MUITO próximo de 0
    //então quando o valor está em um limite tal, eu simplesmente aproximo pra 0
    //pensar em como fazer pra adicionar o vetor de respostas
    
    LU g(3);
    Matrix l(3, 3);

    g.transformar(&m, &l);

    l.print();
    
    //GAUSS E GAUSS JORDAN IMPLEMENTADOS E FUNCIONANDO BEM
}