#include <iostream>
#include <cmath>
using namespace std;
double tanh (double x){
    return (exp(x) - exp(-x))/(exp(x) + exp(-x));

}
int main(){
    double input;
    cout<<"eneter the number:";
    cin>>input;
    double result = tanh(input);
    cout<<"the hyperbolic tan function of"<<input<<"is"<<result;
    return 0;
}
