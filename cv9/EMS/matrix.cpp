/*
 * matrix.cpp
 */

//#include <stdexcept>
#include <cmath>
#include <vector>

#include "matrix.h"

#define MIN_FLOAT 1e-37
#define MAX_FLOAT 1e37

Matrix:: Matrix ( const unsigned int rows_count_, const unsigned int columns_count_, const double non_diag_val, const double diag_val ) :
    rows_count ( rows_count_ ), columns_count ( columns_count_ ), items ( rows_count_, std::vector <double>( columns_count_, non_diag_val ) )
{
    //Create matrix with a specific value on the main diagonal
    for ( unsigned int i = 0; i < std::min ( rows_count, columns_count ) ; i++ )
    {
        items[i][i] = diag_val;
    }
}



Matrix & Matrix ::operator = (const Matrix &M )
{
    //Assignment operator =
    if ( this != &M )
    {
        //Matrix dimension are invalid, throw exception
        if ( rows_count !=  M.rows_count )
            throw std::invalid_argument ( "Exception: different rows count in operator =. Can not assign matrices.");

        //Matrix dimension are invalid, throw exception
        if ( columns_count != M.columns_count )
            throw std::invalid_argument ( "Exception: different columns count in operator =. Can not assign matrices.");

        //Process all lines
        for ( unsigned int i = 0; i < rows_count; i++ )
        {
            //Process columns_count of the actual row
            for ( unsigned int j = 0 ; j < columns_count; j++ )
                items[i][j] = M.items[i][j];
        }
    }

    return *this;
}


Matrix & Matrix :: operator += ( const Matrix &M )
{
    //Matrix operator += : Matrix += Matrix
    if ( this->rows_count !=  M.rows() )
        throw std::invalid_argument ( "Exception: different rows count.  Cannot compute A += B.");

    //Matrix dimension are invalid, throw exception
    if ( this->columns_count != M.cols() )
        throw std::invalid_argument ( "Exception: different columns count.  Cannot compute A += B.");

    //Process all lines
    for ( unsigned int i = 0;  i < rows_count; i++ )
    {
        //Process columns_count of the actual row
        for ( unsigned int j = 0 ; j < columns_count; j++ )
            items[i][j] = items[i][j]  + M( i, j);
    }

    return *this;
}


Matrix & Matrix :: operator -= ( const Matrix &M )
{
    //Matrix operators -= : Matrix -= Matrix
    if ( this->rows_count !=  M.rows() )
        throw std::invalid_argument ( "Exception: different rows count.  Cannot compute A += B.");

    //Matrix dimension are invalid, throw exception
    if ( this->columns_count != M.cols() )
        throw std::invalid_argument ( "Exception: different columns count.  Cannot compute A += B.");

    //Process all lines
    for ( unsigned int i = 0;  i < rows_count; i++ )
    {
        //Process columns_count of the actual row
        for ( unsigned int j = 0 ; j < columns_count; j++ )
            items[i][j] = items[i][j]  - M ( i, j );
    }

    return *this;
}

/*
Matrix & Matrix ::operator * ( const Matrix &M )
{
    //Matrix operator *= : Matrix *= Matrix
    if ( columns_count !=  M.rows() )
        throw std::invalid_argument ( "Exception: different rows and columns count. Cannot compute A *= B.");

    Matrix C ( rows_count, M.cols() );

    //Matrix multiplication
    for (unsigned int i = 0; i < rows_count; i++)
    {
        for (unsigned int k = 0; k < columns_count; k++)
        {
            for (unsigned int j = 0; j < M.cols(); j++)
            {
                C(i, j) += items[i][k] * M(k, j);
            }
        }
    }

    return C;
}
*/

Matrix & Matrix::operator *=(double val)
{
    //Matrix operator *= : Matrix *= scalar
    for (unsigned int i = 0; i < rows_count; i++)
    {
        for (unsigned int j = 0; j < columns_count; j++)
        {
            items[i][j] *= val;
        }
    }

    return *this;
}


Matrix & Matrix::operator /= (double val)
{
    //Matrix operator /= : Matrix /= scalar
    for (unsigned int i = 0; i < rows_count; ++i)
    {
        for (unsigned int j = 0; j < columns_count; ++j)
        {
            items[i][j] /= val;
        }
    }

    return *this;
}


Matrix & Matrix::operator |= (const Matrix & M)
{
    //Matrix operator |= : Matrix | Matrix (Hadamard product)
    if ( this->rows_count !=  M.rows() )
        throw std::invalid_argument ( "Exception: different rows count.  Cannot compute A += B.");

    //Matrix dimension are invalid, throw exception
    if ( this->columns_count != M.cols() )
        throw std::invalid_argument ( "Exception: different columns count.  Cannot compute A += B.");

    //Process all lines
    for ( unsigned int i = 0;  i < rows_count; i++ )
    {
        //Process columns_count of the actual row
        for ( unsigned int j = 0 ; j < columns_count; j++ )
        {
            items[i][j] = items[i][j] * M( i, j);
        }
    }

    return *this;
}



Matrix Matrix::row ( const unsigned int r ) const
{
    //Get row of the matrix
    //Matrix dimension invalid, throw exception
    if ( r > rows_count )
        throw std::out_of_range ( "Exception: row index exceeds rows_count.  " );

    //Call operator A(r1, r2, c1, c2)
    return (*this)(r, r, 0, columns_count - 1);
}


Matrix Matrix :: col ( const unsigned int c ) const
{
    //Get column of the matrix
    //Matrix dimension invalid, throw exception
    if ( c > columns_count )
        throw std::out_of_range ( "Exception: column index exceeds columns_count.  " );

    //Call operator A(r1, r2, c1, c2)
    return (*this)(0, rows_count - 1, c, c);
}


void Matrix::row ( const Matrix &M, const unsigned int r )
{
    //Set row vector of the matrix
    //Matrix dimension invalid, throw exception
    if ( r > rows_count )
        throw std::out_of_range ( "Exception: row index exceeds rows_count.  " );

    //Call operator A(M, r, c);
    (*this)(M, r, 0);
}



void Matrix::col ( const Matrix &M, const unsigned int c )
{
    //Set column vector of the matrix
    //Matrix dimension invalid, throw exception
    if ( c > columns_count )
        throw std::out_of_range ( "Exception: column index exceeds columns_count.  " );

    //Call operator A(M, r, c);
    (*this)(M, 0, c);
}



double & Matrix:: operator() ( const unsigned int row, unsigned int col )
{
    //Matrix operator ()()
    //Matrix dimension invalid, throw exception
    if ( row > rows_count )
        throw std::out_of_range ( "Exception: row index exceeds rows_count.  " );

    //Matrix dimension invalid, throw exception
    if ( col > columns_count )
        throw std::out_of_range ( "Exception: column index exceeds columns_count.  " );

    return items[row][col];
}


double const & Matrix:: operator() ( const unsigned int row, unsigned int col ) const
{
    //Matrix operator ()()
    //Matrix dimension invalid, throw exception
    if ( row > rows_count )
        throw std::out_of_range ( "Exception: row index exceeds rows_count.  " );

    //Matrix dimension invalid, throw exception
    if ( col > columns_count )
        throw std::out_of_range ( "Exception: column index exceeds columns_count.  " );

    return items[row][col];
}


Matrix Matrix::operator () ( const unsigned int r1, const unsigned int r2, const unsigned int c1, const unsigned int c2 ) const
{
    //Matrix operator (r1, r2, c1, c2): get submatrix of the matrix
    //Bad row index
    if ( r2 >  rows_count )
        throw std::out_of_range ( "BadDataException: row index r2 must not be greater than A.rows_count. Can not create the submatrix." );

    //Bad row index
    if ( c2 > columns_count )
        throw std::out_of_range ( "BadDataException: col index c2 must not be greater than A.columns_count. Can not create the submatrix. " );

    //Bad row index interval
    if ( r1 > r2 )
        throw std::out_of_range ( "BadDataException: row index r2 must not be smaller then r1. Can not create the submatrix. " );

    //Bad col index interval
    if ( c1 > c2 )
        throw std::out_of_range ( "BadDataException: col index c2 must not be smaller then c1. Can not create the submatrix. " );

    //Create sub-matrix
    Matrix M ( r2 - r1 + 1, c2 - c1 + 1 ) ;

    for ( unsigned int i = r1; i <= r2; i++ )
    {
        for ( unsigned int j = c1; j <= c2; j++ )
        {
            M ( i - r1, j - c1 ) = items[i][j];
        }
    }

    return M;
}


void Matrix::operator () (const Matrix &M, const unsigned int row, const unsigned int col)
{
    //Matrix operator (M, r, c): replace part of the matrix A at the position [row, col] with M
    const unsigned int m = M.rows(), n = M.cols();

    //Invalid index, throw exception
    if (m + row > rows_count)
        throw std::out_of_range("IndexOutOfBoundException: a submatrix does not fit at the specified row position, can not append a submatrix to the matrix. ");

    //Invalid index, throw exception
    if (n + col > columns_count)
        throw std::out_of_range("IndexOutOfBoundException: a submatrix does not fit at the specified col position, can not append a submatrix to the matrix.");

    //Copy submatrix
    for (unsigned int i = 0; i < m; i++)
    {
        for (unsigned int j = 0; j < n; j++)
        {
            items[i + row][j + col] = M(i, j);
        }
    }
}


void Matrix::print ( std::ostream * output ) const
{
    //Print matrix
    *output << std::showpoint << std::fixed << std::right;
    *output << '\n';

    for ( unsigned int i = 0; i < rows_count; i++ )
    {
        *output << "| ";

        for ( unsigned int j = 0; j < columns_count; j++ )
        {
            *output <<  std::setw ( 18 ) << std::setprecision ( 9 );
            items[i][j] < 1.0e16 ? *output << items[i][j] : *output << "---";
        }

        *output << " |" << '\n';
    }
}


Matrix Matrix::trans()
{
    //Transpose matrix
    Matrix AT(columns_count, rows_count);

    for (unsigned int i = 0; i < rows_count; ++i)
    {
        for (unsigned int j = 0; j < columns_count; ++j)
        {
            AT(j, i) = items[i][j];
        }
    }

    return AT;
}

Matrix Matrix::diff() const
{
    //Create differences of rows
    Matrix AD(rows_count - 1, columns_count);

    for (unsigned int i = 0; i < rows_count - 1; i++)
    {
        for (unsigned int j = 0; j < columns_count; j++)
        {
            AD(i, j) = items[i + 1][j] - items[i] [j];
        }
    }

    return AD;
}


double Matrix::mean() const
{
    //Compute mean
    double sum = 0.0;

    for (unsigned int i = 0; i < rows_count; i++)
    {
        for (unsigned int j = 0; j < columns_count; j++)
        {
            sum += items[i][j];
        }
    }

    return sum / (rows_count * columns_count);
}


std::tuple<double, int, int> Matrix::min() const
{
    //Find minimum element
    int row = 0, col = 0;
    double amin = items[0][0];

    //Process all items
    for (unsigned int i = 0; i < rows_count; i++)
    {
        for (unsigned int j = 0; j < columns_count; j++)
        {
            if (items[i][j] < amin)
            {
                amin = items[i][j];
                row = i; col = j;
            }
        }
    }

    return {amin, row, col};
}

std::tuple<double, int, int> Matrix::max() const
{
    //FInd maximum element
    int row = 0, col = 0;
    double amax = items[0][0];

    //Process all items
    for (unsigned int i = 0; i < rows_count; i++)
    {
        for (unsigned int j = 0; j < columns_count; j++)
        {
            if (items[i][j] > amax)
            {
                amax = items[i][j];
                row = i; col = j;
            }
        }
    }

    return {amax, row, col};
}


Matrix Matrix::sqrtm() const
{
    //Compute sqrt
    Matrix IS(rows_count, columns_count);

    for (unsigned int i = 0; i < rows_count; i++)
    {
        for (unsigned int j = 0; j < columns_count; j++)
        {
            IS(i, j) = sqrt(items[i][j]);
        }
    }

    return IS;
}

//LU decomposition of the matrix
void Matrix::lu(Matrix &L, Matrix &U, Matrix &P, short &sign) const
{
    //LU decomposition of A, L = lower triangular matrix, U = upper triangular matrix, P = permutation matrix

    //Set the determinant det(U) sign to 1
    sign = 1;

    //Is A rectangular matrix ?
    if (rows_count != columns_count)
    {
        throw std::invalid_argument ("Exception: invalid dimension of the matrix (rectangle matrix), can not perform LU decomposition.");
    }

    //Create row permutation vector
    Matrix PR(1, columns_count);

    //Create scale vector
    Matrix  S(1, columns_count);

    //Set diagonal items of L to 1, otherwise to 0
    //Set items of the row permutation matrix to <0; n-1>
    for (unsigned int i = 0; i < rows_count; i++)
    {
        L(i, i) = 1.0;
        PR(0, i) = i;

        for (unsigned int j = 0; j < rows_count; j++)
        {
            if (j != i)
                L(i, j) = 0;

            P(i, j) = 0;
        }
    }

    //Initialize U = A
    U = *this;

    //Find max item in each row to compute the scale vector
    for (unsigned int i = 0; i < columns_count; i++)
    {
        double max_val = 0.0;

        for (unsigned int j = 0; j < columns_count; j++)
        {
            if (fabs(U(i, j)) > max_val)
                max_val = fabs(U(i, j));
        }

        //Actualize scale vector
        if (max_val > MIN_FLOAT)
            S(0, i) = 1.0 / max_val;
    }

    //Start LU decomposition
    for (unsigned int j = 0; j < columns_count; j++)
    {
        for (unsigned int i = 0; i < j; i++)
        {
            double sum = U(i, j);

            //Compute new U ( i, j ) item: multiply ith row and j-th column
            for (unsigned int k = 0; k < i; k++) sum -= U(i, k) * U(k, j);

            U(i, j) = sum;
        }

        //Initialize max_val and pivot index
        double max_val = 0.0;
        unsigned int i_pivot = columns_count;

        //Find row that will be swapped and actualize row index
        for (unsigned int i = j; i < columns_count; i++)
        {
            double sum = U(i, j);

            //Compute new U ( i, j ) item: multiply ith row and j-th column
            for (unsigned int k = 0; k < j; k++) sum -= U(i, k) * U(k, j);

            //Compute new U (i, j)
            U(i, j) = sum;

            //Compute index of the pivot
            const double val = S(0, i) * fabs(sum);

            if (val >= max_val)
            {
                max_val = val;
                i_pivot = i;
            }
        }

        //Perform row swaps in U,PR: j <-> i_pivot
        if ((j != i_pivot) && (i_pivot < columns_count))
        {
            //Perform swap in U matrix
            const Matrix  U_temp = U(i_pivot, i_pivot, 0, columns_count - 1);
            U(U(j, j, 0, columns_count - 1), i_pivot, 0);
            U(U_temp, j, 0);

            //Perform swap in the row permutation matrix
            const unsigned int perm_temp = PR(0, i_pivot);
            PR(0, i_pivot) = PR(0, j);
            PR(0, j) = perm_temp;

            //Actualize also the scale vector
            S(0, i_pivot) = S(0, j);

            //Actualize sign of the determinant det(U)
            sign *= -1;
        }

        //Change diagonal item U ( j, j ) = 0 to "small" value before the devision
        if (U(j, j) == 0.0)
            U(j, j) = MIN_FLOAT;

        //Actualize U (i, j) from diagonal items
        if (j != columns_count - 1)
        {
            const double val = 1.0 / U(j, j);

            for (unsigned int i = j + 1; i < columns_count; i++)
                U(i, j) *= val;
        }
    }

    //Process L matrix together with U matrix
    for (unsigned int i = 0; i < columns_count; i++)
    {
        for (unsigned int j = 0; j < i; j++)
        {
            L(i, j) = U(i, j);
            U(i, j) = 0.0;
        }

        //Actualize permutation matrix from the row permutation matrix
        P(i, PR(0, i)) = 1.0;
    }
}


Matrix Matrix::inv() const
{
    //Inverse matrix calculation using LU decomposition
    //Rectangular matrix
    if (rows_count != columns_count)
    {
        throw std::invalid_argument ("Exception: invalid dimension of the matrix (rectangle matrix), can not perform LU decomposition.");
    }

    //Find maximum
    auto [max_val, row, col] = this->max();

    if (max_val > MAX_FLOAT)
        throw std::overflow_error ("Exception: bad scaled matrix, can not compute inverse matrix, max item > MAX_FLOAT.");

     //Create LU decomposition
     Matrix  L(rows_count, rows_count);
     Matrix  U(rows_count, rows_count);
     Matrix  P(rows_count, rows_count, 0, 1);
     short sign = 1;
     lu(L, U, P, sign);

     //Compute X = L^-1 (lower triangular matrix)
     Matrix  X(rows_count, rows_count);

     for (unsigned int j = 0; j < rows_count; j++)
     {
        X(j, j) = 1.0;

        for (unsigned int i = j + 1; i < rows_count; i++)
        {
            double sum = 0;

            for (unsigned int k = j; k <= i - 1; k++)
            {
                sum -= L(i, k) * X(k, j);
            }

            X(i, j) = sum;
        }
    }

    //Compute Y = U^-1 (upper triangular matrix)
    Matrix  Y(rows_count, rows_count);

    for (unsigned int j = 0; j < rows_count; j++)
    {
        Y(j, j) = 1 / U(j, j);

        for (int i = j - 1; i >= 0; i--)
        {
            double sum = 0.0;

            for (unsigned int k = i + 1; k <= j; k++)
            {
                sum -= U(i, k) * Y(k, j) / U(i, i);
            }

            Y(i, j) = sum;
        }
    }

    //Compute inverse matrix A^-1 = U^-1 * L^-1 = X * Y * P
    return Y * X * P;
}


//NON-member functions
//**************************************************

//Matrix operators + : Matrix + Matrix
Matrix operator + ( const Matrix &A, const Matrix &B )
{
    Matrix temp(A);
    return (temp += B);
}


//Matrix operators - : Matrix - Matrix
Matrix operator - ( const Matrix &A, const Matrix &B )
{
    Matrix temp(A);
    return (temp -= B);
}


//Matrix operator * : Matrix * Scalar
Matrix operator * (const Matrix &A, const double val )
{
    Matrix temp(A);
    return (temp *= val);
}

Matrix operator * ( const Matrix &A,  const Matrix &B)
{
    //Matrix operator *= : Matrix *= Matrix
    if ( A.cols() !=  B.rows() )
        throw std::invalid_argument ( "Exception: different rows and columns count. Cannot compute A *= B.");

    Matrix C ( A.rows(), B.cols() );

    //Matrix multiplication
    for (unsigned int i = 0; i < A.rows(); i++)
    {
        for (unsigned int k = 0; k < A.cols(); k++)
        {
            for (unsigned int j = 0; j < B.cols(); j++)
            {
                C(i, j) += A(i, k) * B(k, j);
            }
        }
    }

    return C;
}


//Matrix operator * : Scalar * Matrix
Matrix operator * (const double val, const Matrix &A)
{
    Matrix temp(A);
    return (temp *= val);
}

//Matrix operator / : Matrix / Scalar
Matrix operator / (const Matrix &A, const double val )
{
    Matrix temp(A);
    return (temp /= val);
}


//Matrix operator | : Matrix | Matrix (Hadamard product)
Matrix operator | (const Matrix &A, const Matrix &B )
{
    Matrix temp(A);
    return (temp |= B);
}
