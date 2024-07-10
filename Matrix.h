#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
#include <iostream>
#include <random>

extern std::default_random_engine random_engine;
struct Shape {
    int rows;
    int columns;
};
class Matrix {
public:
    Matrix();
    Matrix(int rows, int columns, bool init=false);
    Matrix(const std::vector<std::vector<double>> &array);
    void set(int row, int column, double value);
    double get(int row, int column) const;
    int getRows() const { return rows; }
    int getColumns() const { return columns; }
    void pretty_print() const;

private:
    std::vector<std::vector<double>> array;
    int rows;
    int columns;
};

#endif // MATRIX_H
