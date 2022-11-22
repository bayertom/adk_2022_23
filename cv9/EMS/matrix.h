/*
 * matrix.h
 */

#ifndef __MATRIX_H__
#define __MATRIX_H__

#include <iostream>
#include <tuple>

class Matrix {

    private:
        int rows_, cols_;
        double **p;

    public:
        Matrix(int, int);
        Matrix(double**, int, int);
        Matrix();
        ~Matrix();
        Matrix(const Matrix&);
        Matrix& operator=(const Matrix&);

        inline double& operator() (int x, int y) const { return p[x][y]; }

        Matrix& operator+=(const Matrix&);
        Matrix& operator-=(const Matrix&);
        Matrix& operator*=(const Matrix&);
        Matrix& operator*=(double);
        Matrix& operator/=(double);
        Matrix  operator^(int);
        
        friend std::ostream& operator<<(std::ostream&, const Matrix&);
        friend std::istream& operator>>(std::istream&, Matrix&);

        std::tuple<int, int> size() const{return {rows_, cols_};}
        void swapRows(int, int);
        Matrix transpose();
        Matrix diff();
        double mean();

        static Matrix createIdentity(int);
        static Matrix solve(Matrix, Matrix);
        static Matrix bandSolve(Matrix, Matrix, int);

        // functions on vectors
        static double dotProduct(Matrix, Matrix);

        // functions on augmented matrices
        static Matrix augment(Matrix, Matrix);
        Matrix gaussianEliminate();
        Matrix rowReduceFromGaussian();
        void readSolutionsFromRREF(std::ostream& os);
        Matrix inverse();
        Matrix sqrtm();

    private:

        void allocSpace();
        Matrix expHelper(const Matrix&, int);
};

Matrix operator+(const Matrix&, const Matrix&);
Matrix operator-(const Matrix&, const Matrix&);
Matrix operator*(const Matrix&, const Matrix&);
Matrix operator*(const Matrix&, double);
Matrix operator*(double, const Matrix&);
Matrix operator/(const Matrix&, double);
Matrix operator|(const Matrix& m1, const Matrix& m2);

#endif
