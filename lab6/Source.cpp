#include <iostream>
#include "DynamicArrayCopy.h"

int main() {
    // Приклад використання класу
    DynamicArrayCopy<int> intArray(3, 3);
    std::cout << "Enter integer array elements:\n";
    std::cin >> intArray;

    DynamicArrayCopy<int> copyArray(3, 3);
    copyArray.copyByRows(intArray);
    std::cout << "Copied array by rows:\n" << copyArray;

    copyArray.copyByColumns(intArray);
    std::cout << "Copied array by columns:\n" << copyArray;

    copyArray.copyRow(1, intArray, 0);
    std::cout << "Copied selected row:\n" << copyArray;

    copyArray.copyColumn(2, intArray, 1);
    std::cout << "Copied selected column:\n" << copyArray;

    copyArray.copyMainDiagonal(intArray);
    std::cout << "Copied main diagonal:\n" << copyArray;

    return 0;
}
