// sorts_middle.cpp
#include "sorts_middle.h"
#include <algorithm> // Для std::swap

// Пузырьковая сортировка
void bubbleSort(int* ar, int size, bool isAscending) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if ((isAscending && ar[j] > ar[j + 1]) || (!isAscending && ar[j] < ar[j + 1])) {
                std::swap(ar[j], ar[j + 1]);
            }
        }
    }
}

// Сортировка вставками
void insertionSort(int* ar, int size, bool isAscending) {
    for (int i = 1; i < size; ++i) {
        int key = ar[i];
        int j = i - 1;
        while (j >= 0 && ((isAscending && ar[j] > key) || (!isAscending && ar[j] < key))) {
            ar[j + 1] = ar[j];
            j--;
        }
        ar[j + 1] = key;
    }
}

// Сортировка выбором
void selectionSort(int* ar, int size, bool isAscending) {
    for (int i = 0; i < size - 1; ++i) {
        int extremumIndex = i;
        for (int j = i + 1; j < size; ++j) {
            if ((isAscending && ar[j] < ar[extremumIndex]) || (!isAscending && ar[j] > ar[extremumIndex])) {
                extremumIndex = j;
            }
        }
        std::swap(ar[i], ar[extremumIndex]);
    }
}

// Вспомогательная функция для быстрой сортировки
void quickSortHelper(int* ar, int left, int right, bool isAscending) {
    if (left >= right) return;
    int pivot = ar[(left + right) / 2];
    int i = left, j = right;
    while (i <= j) {
        while ((isAscending && ar[i] < pivot) || (!isAscending && ar[i] > pivot)) i++;
        while ((isAscending && ar[j] > pivot) || (!isAscending && ar[j] < pivot)) j--;
        if (i <= j) {
            std::swap(ar[i], ar[j]);
            i++;
            j--;
        }
    }
    quickSortHelper(ar, left, j, isAscending);
    quickSortHelper(ar, i, right, isAscending);
}

// Быстрая сортировка (сортировка Хоара)
void quickSort(int* ar, int size, bool isAscending) {
    quickSortHelper(ar, 0, size - 1, isAscending);
}

// Вспомогательная функция для сортировки слиянием
void merge(int* ar, int left, int mid, int right, bool isAscending) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int* L = new int[n1];
    int* R = new int[n2];

    for (int i = 0; i < n1; ++i) L[i] = ar[left + i];
    for (int j = 0; j < n2; ++j) R[j] = ar[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if ((isAscending && L[i] <= R[j]) || (!isAscending && L[i] >= R[j])) {
            ar[k] = L[i];
            i++;
        } else {
            ar[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        ar[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        ar[k] = R[j];
        j++;
        k++;
    }

    delete[] L;
    delete[] R;
}

// Вспомогательная функция для сортировки слиянием
void mergeSortHelper(int* ar, int left, int right, bool isAscending) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSortHelper(ar, left, mid, isAscending);
        mergeSortHelper(ar, mid + 1, right, isAscending);
        merge(ar, left, mid, right, isAscending);
    }
}

// Сортировка слиянием
void mergeSort(int* ar, int size, bool isAscending) {
    mergeSortHelper(ar, 0, size - 1, isAscending);
}
