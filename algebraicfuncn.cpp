#include "Matrix.h"
#include <iostream>
#include <cmath>
#include <random>
#include <vector>
#include <memory>
#include<cassert>

using namespace std;

namespace linearalgebra {
    // matrix multiplication 
    Matrix multiply(const Matrix &m1, const Matrix &m2) {
    assert(m1.getColumns() == m2.getRows());
        Matrix result(m1.getRows(), m2.getColumns(), true);
        for (int i = 0; i < result.getRows(); ++i) {
        for (int j = 0; j < result.getColumns(); ++j) {
            double sum = 0.0;
            for (int k = 0; k < m1.getColumns(); ++k) {
                sum += m1.get(i, k) * m2.get(k, j);
            }
            result.set(i, j, sum);
        }
    }
    return result;
}
    // hardmand multiplication
    Matrix hardmandmult(const Matrix &m1, const Matrix &m2) {
        assert(m1.getRows() == m2.getRows() && m1.getColumns() == m2.getColumns());
            Matrix m3(m1.getRows(), m1.getColumns(), true);
        cout << "Multiplication of two matrices is:" << endl;
        for (int i = 0; i < m3.getRows(); ++i) {
            for (int j = 0; j < m3.getColumns(); ++j) {
                m3.set(i, j, m1.get(i, j) * m2.get(i, j));
            }
        }
        return m3;
    }

    Matrix add(const Matrix &m1, const Matrix &m2) {
        assert(m1.getRows() == m2.getRows() && m1.getColumns() == m2.getColumns());
            Matrix m3(m1.getRows(), m1.getColumns(), true);
        for (int i = 0; i < m1.getRows(); ++i) {
            for (int j = 0; j < m1.getColumns(); ++j) {
                m3.set(i, j, m1.get(i, j) + m2.get(i, j));
            }
        }
        return m3;
    }
    Matrix transpose(const Matrix &m){
    Matrix m3(m.getRows(), m.getColumns(), true);
    for (int i = 0; i < m.getRows(); ++i) {
        for (int j = 0; j < m.getColumns(); ++j) {
        m3.set(j,i , m.get(i,j) );  
        }
    }
    return m3;
    }
    Matrix dotproduct(const Matrix &m1, Matrix &m2){
        assert(m1.getRows() == m2.getRows() && m1.getColumns() == m2.getColumns());
         Matrix m3(m1.getRows(), m1.getColumns(), true);
        for (int i = 0; i < m1.getRows(); ++i) {
            for (int j = 0; j < m1.getColumns(); ++j) {
                m3.set(i, j, m3.get(i, j) + m1.get(i, j) * m2.get(i, j));
            }
        }
        return m3;
    }
    Matrix subtraction(const Matrix &m1, const Matrix &m2) {
        assert(m1.getRows() == m2.getRows() && m1.getColumns() == m2.getColumns());
        Matrix m3(m1.getRows(), m1.getColumns(), true);
        for (int i = 0; i < m1.getRows(); ++i) {
            for (int j = 0; j < m1.getColumns(); ++j) {
                m3.set(i, j, m1.get(i, j) - m2.get(i, j));
            }
        }
        return m3;
    }
    Matrix multvalue(const Matrix &m1, double value) {
        Matrix m4(m1.getRows(), m1.getColumns(), true);
        cout << "Multiplication of two matrices is:" << endl;
        for (int i = 0; i < m4.getRows(); ++i) {
            for (int j = 0; j <m4.getColumns(); ++j) {
            m4.set(i, j, m1.get(i, j) * value);
            }
        }
        return m4;
    }
    double dotproduct(const vector<double> &v1,const vector<double> &v2){
        double result =0;
        for(size_t i= 0 ; i<v1.size(); ++i){//size_t i = 0 initializes the loop counter i to 0.
            result +=v1[i] *v2[i];
        }
        return result;
    }
    Matrix dotproduct(const vector<double> &v1,const Matrix &m2){
        assert(v1.size() == m2.getRows());//can remove not necessary the vector & row have same values
        Matrix m4(m2.getRows(), m2.getColumns(), true);
        for(size_t i= 0 ; i<v1.size(); ++i){
            for (int j = 0; j < m4.getRows(); ++j) {
             m4.set(i, j, v1[i] * m2.get(i, j));
            }
        }
        return m4;
    }
    double subtrvector(const vector<double> &v1,const vector<double> &v2){
        double subvector =0;
        for(size_t i= 0 ; i<v1.size(); ++i){//size_t i = 0 initializes the loop counter i to 0.
            subvector =v1[i] -v2[i];
        }
        return subvector;
    }
    // concetanate 
    Matrix concetanate(const Matrix &m1, const Matrix &m2){
        assert(m1.getRows() == m2.getRows() && m1.getColumns() == m2.getColumns());
        Matrix m5(m1.getRows(), m1.getColumns() + m2.getColumns(), true);
            for(int i = 0; i<m1.getRows(); i++){
                for(int j=0; j<m1.getColumns(); j++){
                    m5.set(i,j,m1.get(i,j));
                }
            for ( int j = m1.getColumns(); j < m1.getColumns() + m2.getColumns(); j++) {
                m5.set(i, j, m2.get(i, j - m1.getColumns()));
                }
            } 
            return m5;     
        }  
    //flatten 
    vector<double> flatten(const Matrix &m){
        vector<double> flattenmatrix(m.getRows() * m.getColumns());
            for (int i =0; i<m.getRows(); i++){
                for(int j=0;j<m.getColumns();j++){
                     flattenmatrix[((i*m.getColumns()) +j)]= m.get(i,j);
                }
            }
            return flattenmatrix;
    }
    //reshape 
    Matrix reshape(const vector<double> &v1, Shape shape){
        assert(v1.size()==(shape.rows*shape.columns));
        Matrix m6(shape.rows,shape.columns,true);
            for(int i=0; i<shape.rows;i++){
              for(int j=0; j<shape.rows;j++){
                m6.set(i,j,v1.at((i*shape.rows)+j));
              }
            }
            return m6;
        }
    //update kernel
    // learning_rate small number that control how we adjust the new weights
    // delta_conv is matrix that contains the gradient or changes of loss function wrt o/p of convolution operation
    void update_kernel(const Matrix &delta_conv, const Matrix &input,Matrix &kernel,double learning_rate){
        for(int i =0; i <kernel.getRows();++i){
            for(int j=0; j<kernel.getColumns();++j){
                double delta =0.0;//initializing the variable"delta" that accumulates the total chnage of element of the kernel
                for(int r=0; r< delta_conv.getRows();r++){
                    for(int c=0; c<delta_conv.getColumns();c++){
                        delta+= delta_conv.get(r,c)*input.get(r+i,c+j);
                    }
                }
              kernel.set(i, j, kernel.get(i, j) - learning_rate * delta);
  
            }
        }
    }
    Matrix max_pool(const Matrix &input,int pool_size,int stride){
        int output_rows = input.getRows()/pool_size;
        int output_cols = input.getColumns()/pool_size;
        Matrix pooled (output_rows, output_cols, false);
        for(int i=0; i<output_rows; ++i){// THIS will iterate over the o/p matrix and fill each element 
            for(int j=0; j<output_cols; ++j){
            double max_val = numeric_limits<double>::lowest();//initialising max_val variable to ensure any input value will be greater than max_val 
             //::in above is use to access "lowest" from numeric_limits<double>::lowest() this template  
             for (int m = 0; m < pool_size; ++m) {//this loops iterates over all elements inside the pooling window
                for (int n = 0; n < pool_size; ++n) {
                    int input_row = i * stride + m;//calculates indices of input matrices and i*stride move the pooling window
                    int input_col = j * stride + n;// stride move and m&n iterates inside the pooling window finding maximum
                    if (input_row < input.getRows() && input_col < input.getColumns()) {// this to check row and cols are within bound limit
                    max_val =max(max_val, input.get(input_row, input_col));
                        }
                    }
                }
            pooled.set(i,j, max_val);       
        }
    }
    return pooled;
    }
    // pool_flaten
    vector<double> pool_flaten(const Matrix &anymatrix) {
    int size = anymatrix.getColumns() * anymatrix.getRows();
    vector<double> flatten(size);
  for (int i = 0; i < anymatrix.getRows(); ++i) {
        for (int j = 0; j < anymatrix.getColumns(); ++j) {
            flatten[i * anymatrix.getColumns() + j] = anymatrix.get(i, j);
        }
    }
    return flatten;
}
    void update_weights(const Matrix &activations, const std::vector<double> &delta, Matrix &weights, double learning_rate) {
    for (int i = 0; i < weights.getRows(); ++i) {
        for (int j = 0; j < weights.getColumns(); ++j) {
            weights.set(i, j, weights.get(i, j) - learning_rate * activations.get(i, 0) * delta[j]);
        }
    }
}
// activations represent neurons of previous layer and delta represents the error
//calculate the new weights thorugh activations and learning_rate,delta

    void update_bias(const vector<double>& delta, vector<double>& bias, double learning_rate){
        for (size_t i = 0;  i < bias.size(); ++i) {
            bias[i] -= learning_rate * delta[i];
            }
        }
// size() returns a value of type size_t, which is an unsigned type representing the size of objects.
// bias of i th neuron is updated by the formula , computed the adjustment and subtracts from the current value
}

