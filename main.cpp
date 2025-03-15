#include "dz1.h"

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
