#ifndef DYNAMIC_ARRAY_COPY_H
#define DYNAMIC_ARRAY_COPY_H

#include <iostream>

template <typename T>
class DynamicArrayCopy {
private:
    T** array;
    int rows, cols;

public:
    DynamicArrayCopy(int _rows, int _cols);
    ~DynamicArrayCopy();

    void copyByRows(const DynamicArrayCopy& source);
    void copyByColumns(const DynamicArrayCopy& source);
    void copyRow(int destRow, const DynamicArrayCopy& source, int srcRow);
    void copyColumn(int destCol, const DynamicArrayCopy& source, int srcCol);
    void copyMainDiagonal(const DynamicArrayCopy& source);

    friend std::ostream& operator<<(std::ostream& os, const DynamicArrayCopy& obj);
    friend std::istream& operator>>(std::istream& is, DynamicArrayCopy& obj);
};

#endif
