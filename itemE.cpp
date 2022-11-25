#include <iostream>
#include "./Classes/Metodos/Headers/GaussJacobi.h"
#include "./Classes/Metodos/Headers/gauss.h"
#include "./Classes/Metodos/Headers/GaussJordan.h"
#include "./Classes/Metodos/Headers/GaussSeidel.h"
#include "./Classes/Metodos/Headers/LU.h"

using namespace std;

int main(){
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


}