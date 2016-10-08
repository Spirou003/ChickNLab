#ifndef MATRIX_CPP
#define MATRIX_CPP

#include "Matrix.hpp"

namespace
{
    char CHAR_ARRAY_ERR[255];
}

template <typename T>
Matrix<T>::Matrix(unsigned int l, unsigned int c):
Matrix_tab(00), Matrix_line(l), Matrix_column(c), Matrix_malloc(false)
{
    if (l == 0 || c == 0)
    {
        sprintf(CHAR_ARRAY_ERR, "Matrix must have at least one dimension (L = %d , C = %d)", l, c);
        throw std::length_error(CHAR_ARRAY_ERR);
    }
    T** tab = new T*[l];
    unsigned int i = 0;
    try
    {
        while (i < l)
        {
            tab[i] = new T[c];
            i++;
        }
    }
    catch(...)
    {
        while (i > 0)
        {
            i--;
            delete[](tab[i]);
        }
        delete[](tab);
        throw;
    }
    if (Matrix_tab != 00)
    {
        UnMake();
    }
    Matrix_tab = tab;
}

template <typename T>
void Matrix<T>::Make()
{
    unsigned int l = Matrix_line, c = Matrix_column;
    T** tab = new T*[l];
    unsigned int i = 0;
    bool ok = true;
    while (i < l && ok)
    {
        ok = (tab[i] = (T*)malloc(sizeof(T)*c));
        i++;
    }
    if (!ok)
    {
        while (i > 0)
        {
            i--;
            free(tab[i]);
        }
        delete[](tab);
        throw std::runtime_error("Cannot allocate memory");
    }
    Matrix_tab = tab;
}

template <typename T>
void Matrix<T>::UnMake() throw()
{
    unsigned int i = 0;
    while (i < Matrix_line)
    {
        free(Matrix_tab[i]);
        i++;
    }
    delete[](Matrix_tab);
}

template <typename T>
Matrix<T>::Matrix(T const & d, unsigned int l, unsigned int c):
Matrix_tab(00), Matrix_line(l), Matrix_column(c), Matrix_malloc(true)
{
    if (l == 0 || c == 0)
    {
        sprintf(CHAR_ARRAY_ERR, "Matrix must have at least one dimension (L = %d , C = %d)", l, c);
        throw std::length_error(CHAR_ARRAY_ERR);
    }
    Make();
    unsigned int i = 0, j;
    while (i < l)
    {
        j = 0;
        try
        {
            while (j < c)
            {
                new(&(Matrix_tab[i][j])) T(d);
                j++;
            }
        }
        catch(...)
        {
            while (j > 0)
            {
                j--;
                Matrix_tab[i][j].~T();
            }
            while (i > 0)
            {
                i--;
                j = 0;
                while (j < c)
                {
                    Matrix_tab[i][j].~T();
                    j++;
                }
            }
            UnMake();
            throw;
        }
        i++;
    }
}

template <typename T>
Matrix<T>::Matrix(Matrix<T> const & M):
Matrix_tab(00), Matrix_line(M.Matrix_line), Matrix_column(M.Matrix_column), Matrix_malloc(true)
{
    Make();
    unsigned int i = 0, j;
    while (i < Matrix_line)
    {
        j = 0;
        try
        {
            while (j < Matrix_column)
            {
                new(&(Matrix_tab[i][j])) T(M.Matrix_tab[i][j]);
                j++;
            }
        }
        catch(...)
        {
            while (j > 0)
            {
                j--;
                Matrix_tab[i][j].~T();
            }
            while (i > 0)
            {
                i--;
                j = 0;
                while (j < Matrix_column)
                {
                    Matrix_tab[i][j].~T();
                    j++;
                }
            }
            UnMake();
            throw;
        }
        i++;
    }
}

template <typename T>
Matrix<T>::Matrix(Matrix<T> const * M):
Matrix_tab(00), Matrix_line(0), Matrix_column(0), Matrix_malloc(true)
{
    if (M == 00)
    {
        throw std::invalid_argument("Cannot copy null pointer");
    }
    Matrix_line = M->Matrix_line;
    Matrix_column = M->Matrix_column;
    Make();
    unsigned int i = 0, j;
    while (i < Matrix_line)
    {
        j = 0;
        try
        {
            while (j < Matrix_column)
            {
                new(&(Matrix_tab[i][j])) T(M->Matrix_tab[i][j]);
                j++;
            }
        }
        catch(...)
        {
            while (j > 0)
            {
                j--;
                Matrix_tab[i][j].~T();
            }
            while (i > 0)
            {
                i--;
                j = 0;
                while (j < Matrix_column)
                {
                    Matrix_tab[i][j].~T();
                    j++;
                }
            }
            UnMake();
            throw;
        }
        i++;
    }
}

template <typename T>
Matrix<T>::~Matrix() throw()
{
    if (Matrix_malloc)
    {
        unsigned int i = 0, j;
        while (i < Matrix_line)
        {
            j = 0;
            while (j < Matrix_column)
            {
                Matrix_tab[i][j].~T();
                j++;
            }
            free(Matrix_tab[i]);
            i++;
        }
    }
    else
    {
        unsigned int i = 0;
        while (i < Matrix_line)
        {
            delete[](Matrix_tab[i]);
            i++;
        }
    }
    delete[](Matrix_tab);
}

template <typename T>
T & Matrix<T>::operator()(unsigned int l, unsigned int c)
{
    if (l >= Matrix_line || c >= Matrix_column)
    {
        sprintf(CHAR_ARRAY_ERR, "(L , C) = (%d , %d), dimensions are %d x %d", l, c, Matrix_line, Matrix_column);
        throw std::out_of_range(CHAR_ARRAY_ERR);
    }
    return Matrix_tab[l][c];
}

template <typename T>
T const & Matrix<T>::operator()(unsigned int l, unsigned int c) const
{
    if (l >= Matrix_line || c >= Matrix_column)
    {
        sprintf(CHAR_ARRAY_ERR, "(L , C) = (%d , %d), dimensions are %d x %d", l, c, Matrix_line, Matrix_column);
        throw std::out_of_range(CHAR_ARRAY_ERR);
    }
    return Matrix_tab[l][c];
}

template <typename T>
T & Matrix<T>::At(unsigned int l, unsigned int c) throw()
{
    return Matrix_tab[l][c];
}

template <typename T>
T const & Matrix<T>::At(unsigned int l, unsigned int c) const throw()
{
    return Matrix_tab[l][c];
}

template <typename T>
unsigned int Matrix<T>::Line() const throw()
{
    return Matrix_line;
}

template <typename T>
unsigned int Matrix<T>::Column() const throw()
{
    return Matrix_column;
}

#endif

