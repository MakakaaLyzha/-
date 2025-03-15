#include “dz1.h”

#include <iostream>

//
void ShowNum_reverse(const int* array, size_t size_ar) {
    for (size_t i = size_ar; i-- > 0;) {
        std::cout << array[i] << "\t";
    }
    std::cout << std::endl;
}

// Function to print numbers in forward order
void ShowNum(const int* array, size_t size_ar) {
    for (size_t i = 0; i < size_ar; ++i) {
        std::cout << array[i] << "\t";
    }
    std::cout << std::endl;
}

void ShowEven(const int* array, size_t size_ar) {
    for (size_t i = 0; i < size_ar; ++i) {
        //
        if ((array[i] & 1) == 0) {
            std::cout << array[i] << "\t";
        }
    }
    std::cout << std::endl;
}

int main(int argc, char** argv) {
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    size_t size_ar = sizeof(array) / sizeof(array[0]);

    std::cout << "Reverse order:" << std::endl;
    ShowNum_reverse(array, size_ar);

    std::cout << "Forward order:" << std::endl;
    ShowNum(array, size_ar);

    std::cout << "Even numbers:" << std::endl;
    ShowEven(array, size_ar);

    return 0;
}
