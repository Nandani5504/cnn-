#include <iostream>
#include <cmath>
using namespace std;
double ReLU(double x){
    if(x>0){
        return x;
    }
    else{
        return 0;
    }
}
int main(){
    double input;
    cout<<"enter the number";
    cin>> input;
    double result = ReLU(input);
    cout<<"the ReLU of"<<input<<"is"<<result;
    return 0;

}