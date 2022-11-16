#include "Function.h"

SimpleFunction::SimpleFunction(double (*x)(double)){
        func = x;
}

double SimpleFunction::evaluateAt( double a){
        return func(a);
}

CompositionFunction::CompositionFunction( double (*first)(double) ,  double (*second)(double) ){
    f1 = first ;
    f2 = second ;
}

double CompositionFunction::evaluateAt(double a){
    return f1(f2(a)) ;
}

DerivativeFunction::DerivativeFunction(double(*func)(double) , double x){
    this->func = func ;
    this->x = x;
}

double DerivativeFunction::evaluateAt(double a){
    return (func(a+x) - func(a-x))/(2*x);
}
