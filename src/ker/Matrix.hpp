#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <stdexcept>
#include <cstdlib>
#include <cstdio>

template <typename T>
class Matrix
{
    public:
        Matrix(unsigned int l = 1, unsigned int c = 1);
        Matrix(T const & d, unsigned int l = 1, unsigned int c = 1);
        Matrix(Matrix<T> const & m);
        Matrix(Matrix<T> const * m);
        ~Matrix() throw();

        T & operator()(unsigned int l, unsigned int c);
        T const & operator()(unsigned int l, unsigned int c) const;
        T & At(unsigned int l, unsigned int c) throw();
        T const & At(unsigned int l, unsigned int c) const throw();

        unsigned int Line() const throw();
        unsigned int Column() const throw();

    private:
        T ** Matrix_tab;
        unsigned int Matrix_line, Matrix_column;
        const bool Matrix_malloc;

        void Make();
        void UnMake() throw();
};

#include "Matrix.cpp"

#endif
