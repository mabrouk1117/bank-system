#include "Function.h"
using namespace std;

double test1 (double a){
    return a*a;
}

double test2 (double a){
    return a*a;
}

double cube (double n) {
    return n * n * n;
}

double second (double d) {
    return d * d - 5 * d - 4;
}

double fun (double d) {
    return d * d - 3 * d - 4;
}


int main()
{

    CompositionFunction foo (test1, test2);
    cout<<foo.evaluateAt(2)<<endl;
    SimpleFunction fooo([](double a){return a*a;});
    cout<<fooo.evaluateAt(2)<<endl;
    DerivativeFunction foooo(cube,0.1);
    cout<<foooo.evaluateAt(2)<<endl;

    return 0;
}
