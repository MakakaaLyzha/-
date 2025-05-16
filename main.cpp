// main.cpp
#include <iostream>
#include <iomanip>
#include <fstream>
#include "sorts_middle.h"
#include "MeasTime.h"

void printArray(int* ar, int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << ar[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    int sizes[] = {100, 500, 750, 900, 1400, 2000, 2500, 4100, 5000, 7800, 9500, 12000, 13000, 15000, 25000, 33000, 50000, 100000, 140000, 180000, 250000, 400000, 500000, 655000, 800000, 840000, 1000000};
    int largeSizes[] = {1250000, 1400000, 1800000, 2000000, 2500000, 3000000};

    std::cout << "N\tBubble\tInsert\tSelect\tQuick\tMerge\n";

    for (int size : sizes) {
        int* ar = new int[size];

        // Заполнение массива случайными значениями
        for (int i = 0; i < size; ++i) {
            ar[i] = rand() % 10000;
        }

        // Измерение времени для каждой сортировки
        double bubbleSortTime = measureTime(bubbleSort, ar, size, true);
        double insertionSortTime = measureTime(insertionSort, ar, size, true);
        double selectionSortTime = measureTime(selectionSort, ar, size, true);
        double quickSortTime = measureTime(quickSort, ar, size, true);
        double mergeSortTime = measureTime(mergeSort, ar, size, true);

        std::cout << size << "\t" << bubbleSortTime << "\t" << insertionSortTime << "\t" << selectionSortTime << "\t" << quickSortTime << "\t" << mergeSortTime << "\n";

        delete[] ar;
    }

    for (int size : largeSizes) {
        int* ar = new int[size];

        // Заполнение массива случайными значениями
        for (int i = 0; i < size; ++i) {
            ar[i] = rand() % 10000;
        }

        // Измерение времени для быстрой сортировки и сортировки слиянием
        double quickSortTime = measureTime(quickSort, ar, size, true);
        double mergeSortTime = measureTime(mergeSort, ar, size, true);

        std::cout << size << "\t-\t-\t-\t" << quickSortTime << "\t" << mergeSortTime << "\n";

        delete[] ar;
    }

    return 0;
}
