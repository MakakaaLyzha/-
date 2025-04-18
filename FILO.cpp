#include "FILO.h"
#include <iostream>

// Конструктор по умолчанию
FILO::FILO() : size(64), lastIndex(0) {
    ar = new int[size];
}

// Конструктор с параметром
FILO::FILO(int size) : size(size), lastIndex(0) {
    ar = new int[size];
}

// Деструктор
FILO::~FILO() {
    delete[] ar;
    ar = nullptr;
}

// Добавление элемента в конец стека
int FILO::addToEnd(int element) {
    if (lastIndex < size) {
        ar[lastIndex++] = element;
        return 0; // Успешно добавлен
    }
    return -1; // Ошибка: стек полон
}

// Извлечение элемента из конца стека
int FILO::getFromEnd(int* element) {
    if (lastIndex > 0) {
        *element = ar[--lastIndex];
        return 0; // Успешно извлечен
    }
    return -1; // Ошибка: стек пуст
}

// Очистка стека
void FILO::flush() {
    lastIndex = 0;
}
int main(){
    return 0;
}