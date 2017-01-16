//
//  LinearAlgebraTools.hpp
//  NeuralNet
//
//  Created by Logan Thomas on 1/15/17.
//  Copyright © 2017 Logan Thomas. All rights reserved.
//

#ifndef LinearAlgebraTools_hpp
#define LinearAlgebraTools_hpp

#include <stdio.h>
#include <vector>
#include <iostream>
#include <algorithm>
// this is a debug flag
#define DBG

#ifdef DBG
#include <assert.h>
#endif

/* Matrix class
 *
 * This is a basic resizable matrix class that will come in handy in Neural Networks
 */
template< typename valType>
class Matrix{
public:
    //default constructor
    Matrix();
    Matrix(size_t nRows, size_t nCol);
    Matrix( const Matrix<valType>& T);
    Matrix<valType>& operator=(const Matrix<valType>& right);
    
    /* --------------------------------------------------------
     * Basic Getters and Setters
     *
     */
    void setSize( size_t nRows, size_t nCol);
    size_t getRows() const;
    size_t getCols() const;
    void fill( valType val );
    
    // element
    valType& operator()(size_t i, size_t j);
    valType operator()(size_t i, size_t j) const;
    valType getMultVal( const Matrix<valType>& rhs, size_t i, size_t j);
    
    /*-------------------------------------------
     * Assigment operators
     */
    Matrix<valType>& operator*=(const valType& mult);
    Matrix<valType>& operator+=(const valType& val);
    Matrix<valType>& operator/=(const valType& val);
    Matrix<valType>& operator-=(const valType& val);
    
    /* ------------------------------------------
     * Operations that produce a new matrix
     */
    Matrix<valType> operator*(const valType& mult);
    Matrix<valType> operator/(const valType& val);
    Matrix<valType> operator+(const valType& val);
    Matrix<valType> operator-(const valType& val);
    
    
    /* ------------------------------------------
     * Matrix Assignment Operators
     */
    Matrix<valType>& operator+=(const Matrix<valType>& rhs);
    Matrix<valType>& operator-=(const Matrix<valType>& rhs);

    /* ------------------------------------------
     * Matrix Operators that produce a new matrix of the same size
     */
    Matrix<valType> operator+(const Matrix<valType>& rhs);
    Matrix<valType> operator-(const Matrix<valType>& rhs);
    // Matrix Multiplication types
    Matrix<valType> operator*( const Matrix<valType>& rhs);
    Matrix<valType> hadmardMult( const Matrix<valType>& rhs);
    Matrix<valType> kroneckerMult( const Matrix<valType>& rhs );
    // Transpose
    Matrix<valType> T();
    // Matrix Concatenation
    Matrix<valType> horzcat( const Matrix<valType>& rhs);
    // Vertical Concatenation
    Matrix<valType> vertcat( const Matrix<valType>& rhs);
    // print operator
    std::ostream& operator<< (std::ostream & out);
private:
    size_t rows, columns;
    std::vector<valType> data;
};


#endif /* LinearAlgebraTools_hpp */