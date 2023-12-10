#include "DynamicArrayCopy.h"

template <typename T>
DynamicArrayCopy<T>::DynamicArrayCopy(int _rows, int _cols) : rows(_rows), cols(_cols) {
    array = new T * [rows];
    for (int i = 0; i < rows; ++i) {
        array[i] = new T[cols];
    }
}

template <typename T>
DynamicArrayCopy<T>::~DynamicArrayCopy() {
    for (int i = 0; i < rows; ++i) {
        delete[] array[i];
    }
    delete[] array;
}

template <typename T>
void DynamicArrayCopy<T>::copyByRows(const DynamicArrayCopy& source) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            array[i][j] = source.array[i][j];
        }
    }
}

template <typename T>
void DynamicArrayCopy<T>::copyByColumns(const DynamicArrayCopy& source) {
    for (int j = 0; j < cols; ++j) {
        for (int i = 0; i < rows; ++i) {
            array[i][j] = source.array[i][j];
        }
    }
}

template <typename T>
void DynamicArrayCopy<T>::copyRow(int destRow, const DynamicArrayCopy& source, int srcRow) {
    for (int j = 0; j < cols; ++j) {
        array[destRow][j] = source.array[srcRow][j];
    }
}

template <typename T>
void DynamicArrayCopy<T>::copyColumn(int destCol, const DynamicArrayCopy& source, int srcCol) {
    for (int i = 0; i < rows; ++i) {
        array[i][destCol] = source.array[i][srcCol];
    }
}

template <typename T>
void DynamicArrayCopy<T>::copyMainDiagonal(const DynamicArrayCopy& source) {
    int minDim = (rows < cols) ? rows : cols;
    for (int i = 0; i < minDim; ++i) {
        array[i][i] = source.array[i][i];
    }
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const DynamicArrayCopy<T>& obj) {
    for (int i = 0; i < obj.rows; ++i) {
        for (int j = 0; j < obj.cols; ++j) {
            os << obj.array[i][j] << " ";
        }
        os << '\n';
    }
    return os;
}

template <typename T>
std::istream& operator>>(std::istream& is, DynamicArrayCopy<T>& obj) {
    for (int i = 0; i < obj.rows; ++i) {
        for (int j = 0; j < obj.cols; ++j) {
            is >> obj.array[i][j];
        }
    }
    return is;
}
