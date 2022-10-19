#include "operations.h"

double sumValues(double a, double b){
        return a + b;
}

double subValues(double a, double b){
        double value = a - b;
        if((value < 0.0001 && value > 0 ) || (value > - 0.0001 && value < 0) ) value = 0;
        // esse if é para valores muito próximos de 0
        return value;
}

double multValues(double a, double b){
        return a * b;
}

double divValues(double a, double b){
        return a / b;
}