#include <iostream>
#include "./Classes/ClassMatriz.h"

using namespace std;

int main(){
    Matrix m(3, 4);
    m.inputValue(0, 0, 3); m.inputValue(0, 1, 4); m.inputValue(0, 2, 2); m.inputValue(0, 3, 1);
    m.inputValue(1, 0, 7); m.inputValue(1, 1, -2); m.inputValue(1, 2, 3); m.inputValue(1, 3, 5);
    m.inputValue(2, 0, 2); m.inputValue(2, 1, 1); m.inputValue(2, 2, 8); m.inputValue(2, 3, -4);
    
    //eliminação de Gauss aparentemente funcionando
    //tá tendo aquela problema caso o valor seja MUITO próximo de 0
    //então quando o valor está em um limite tal, eu simplesmente aproximo pra 0
    //pensar em como fazer pra adicionar o vetor de respostas
    

    m.GaussElimination();
    m.resolutionTriangleUpper();
    //resolucao aparentemente funcionando bem
   
    //m.print();
}