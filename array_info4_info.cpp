#include <iostream>
#include <cstdlib> // Для функции rand()
#include <ctime>   // Для функции time()

// Функция, возвращающая адрес нулевого элемента массива
int* CreateAr(int size) {
    return new int[size];
}

// Функция, возвращающая адрес нулевого элемента массива, заполненного числами number
int* CreateAr(int size, int number) {
    int* array = new int[size];
    for (int i = 0; i < size; ++i) {
        array[i] = number;
    }
    return array;
}

// Функция, возвращающая адрес нулевого элемента массива, заполненного произвольными числами от min до max
int* CreateAr(int size, int min, int max) {
    int* array = new int[size];
    std::srand(static_cast<unsigned int>(std::time(nullptr))); // Инициализация генератора случайных чисел
    for (int i = 0; i < size; ++i) {
        array[i] = min + std::rand() % (max - min + 1);
    }
    return array;
}

int main() {
    // Пример использования функций
    int size = 5;
    int number = 10;
    int min = 1;
    int max = 100;

    // Создание массива с заданным размером
    int* array1 = CreateAr(size);
    std::cout << "Array 1 created with size " << size << std::endl;
    delete[] array1;

    // Создание массива, заполненного числами number
    int* array2 = CreateAr(size, number);
    std::cout << "Array 2 created and filled with number " << number << std::endl;
    delete[] array2;

    // Создание массива, заполненного случайными числами от min до max
    int* array3 = CreateAr(size, min, max);
    std::cout << "Array 3 created and filled with random numbers between " << min << " and " << max << std::endl;
    delete[] array3;

    return 0;
}
