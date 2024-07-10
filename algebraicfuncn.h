#ifndef ALGEBRAICFUNCN_H
#define ALGEBRAICFUNCN_H
#include "Matrix.h"
#include<vector>
using namespace std;
namespace linearalgebra {
    Matrix hardmandmult(const Matrix &m1, const Matrix &m2);
    Matrix add(const Matrix &m1, const Matrix &m2);
    Matrix transpose(const Matrix &m);
    Matrix dotproduct(const Matrix &m1, Matrix &m2);
    Matrix subtraction(const Matrix &m1, const Matrix &m2);
    Matrix multvalue(const Matrix &m1, double value);
    double dotproduct(const vector<double> &v1,const vector<double> &v2);
    Matrix dotproduct(const vector<double> &v1,const Matrix &m2);
    double subtrvector(const vector<double> &v1,const vector<double> &v2);
    Matrix concetanate(const Matrix &m1, const Matrix &m2);
    vector<double> flatten(const Matrix &m);
    Matrix multiply(const Matrix &m1, const Matrix &m2);
    Matrix reshape(const vector<double> &v1, Shape shape);
}
#endif // MAIN_H
