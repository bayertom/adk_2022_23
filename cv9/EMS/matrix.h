/*
 * matrix.h
 */

#ifndef __MATRIX_H__
#define __MATRIX_H__

#include <tuple>
#include <vector>
#include <ostream>
#include <iostream>
#include <iomanip>

class Matrix
{
private:
    std::vector<std::vector<double>> items;				//Matrix items
    unsigned int rows_count;			                //Total rows_count
    unsigned int columns_count;			                //Total columns_count

public:
    //Matrix() : rows_count (1), columns_count (1), items ( 1, std::vector ( 1, 0.0 ) ) {};
    Matrix ( const unsigned int rows_count_, const unsigned int columns_count_, const double item = 0 ) : rows_count ( rows_count_ ), columns_count ( columns_count_ ), items ( rows_count_, std::vector <double> ( columns_count_, item ) ) {}
    Matrix ( const unsigned int rows_count_, const unsigned int columns_count_, const double non_diag_item_val, const double diag_val );

public:

    //Get rows and columns count
    inline unsigned int rows() const {return rows_count;}
    inline unsigned int cols() const {return columns_count;}
    inline std::tuple <unsigned int, unsigned int> size() const{return {rows_count, columns_count};}

    //Get row, col
    Matrix row ( const unsigned int r ) const;
    Matrix col ( const unsigned int c ) const;

    //Set row, col, submatrix
    void row ( const Matrix & R, const unsigned int r );
    void col ( const Matrix & C, const unsigned int c );

    //Matrix operations
    Matrix trans();
    Matrix diff() const;
    double mean() const;
    std::tuple<double, int, int> min() const;
    std::tuple<double, int, int> max() const;
    Matrix sqrtm() const;
    void lu(Matrix &L, Matrix &U, Matrix &P, short &sign) const;
    Matrix inv() const;

    //Other methods
    void print (std::ostream * output = &std::cout) const;

public:

    Matrix & operator =  (const Matrix &M);
    Matrix & operator += (const Matrix &M);
    Matrix & operator -= (const Matrix &M);
    Matrix & operator *= (const Matrix &M);
    Matrix & operator *= (const double val);
    Matrix & operator /= (const double val);
    Matrix & operator |= (const Matrix & M);

    //Matrix operator (row, col)
    double & operator() ( const unsigned int row, const unsigned int col );
    double const & operator() ( const unsigned int row, const unsigned int col ) const;

    //Matrix operator (row1, col1, row2, col2)
    Matrix operator () ( const unsigned int r1, const unsigned int r2,
                                const unsigned int c1, const unsigned int c2 ) const;

    //Matrix operator (M, r, c): replace part of the matrix A with M
    void operator () (const Matrix  &M, const unsigned int row, const unsigned int col);
};

//Matrix operator + : Matrix + Matrix
Matrix operator + (const Matrix &A, const Matrix &B);

//Matrix operator - : Matrix - Matrix
Matrix operator - (const Matrix &A, const Matrix &B);

//Matrix operator * : Matrix * Matrix
Matrix operator * (const Matrix &A, const Matrix &B);

//Multiply matrix with a scalar
Matrix operator * (const double val, const Matrix &A);
Matrix operator * (const Matrix &A, const double val);

//Divide matrix with a scalar
Matrix operator / (const Matrix &A, double);

//Hadamard product
Matrix operator | (const Matrix &A, const Matrix &B);

#endif
