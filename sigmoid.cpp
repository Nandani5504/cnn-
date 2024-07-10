#include <iostream>
#include <cmath>
using namespace std;
double sigmoid(double x){
    return 1.0/(1.0+ exp(-x));

}
int main(){
    double input;
    cout<<"enter the number";
    cin>> input;
    double result = sigmoid(input);
    cout<<"the sigmoid of"<<input<<"is"<<result;
    return 0;

}