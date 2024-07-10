#include <iostream>
#include<cmath>
#include<vector>
#include<numeric>
using namespace std;
vector<double> softmax(const vector<double>& input) {
    vector<double> result(input.size());
    double sum_exp = 0.0;
 for (double x:input){
    sum_exp+=exp(x);}
 for (size_t i=0; i < input.size(); ++i){
    result[i]=exp(input[i])/sum_exp;
}
return result;
}
int main(){
    size_t n;
    cout<<"enter the number of elements:";
    cin>>n;
    vector<double> input(n);
    cout<<"enter the values  elements";
    for (size_t i=0; i<n;++i){
        cin>>input[i];
    }
    vector<double> result = softmax(input);
    cout<<"the softmax values are:";
     for(double value: result){
        cout<<value<<" ";
        cout<<endl;
     }
     return 0;
}
