#ifndef FUNCTION_H
#define FUNCTION_H

#include <iostream>
class Function
{
 public:
    virtual double evaluateAt(double value) = 0;
};

class SimpleFunction : public Function
{
public:
    double (*func)(double ) ;
    SimpleFunction(double (*x)(double));
    virtual double evaluateAt( double a);

};

class CompositionFunction: public Function
{
    public:
    double (*f1)(double);
    double (*f2)(double);
    CompositionFunction( double (*first)(double) , double (*second)(double) ) ;

    virtual double evaluateAt(double );

};

class DerivativeFunction: public Function
{
public:
    double (*func)(double);
    double x;
    DerivativeFunction(double(*func)(double) , double x);
    virtual double evaluateAt(double a);

};

#endif // FUNCTION_H
