#include "array_info.h"
#include <iostream>
#include <limits>
void getInfoArray(struct ArrayInfo* arInfo) {
    if (arInfo == nullptr || arInfo->ar == nullptr || arInfo->size <= 0) {
        return;
    }
    double sum = 0;
    for (int i = 0; i < arInfo->size; ++i) {
        sum += arInfo->ar[i];
    }
    arInfo->mean = sum / arInfo->size;
    MinMax mm = GetMaxMin(arInfo->ar, arInfo->size);
    arInfo->ind_min = mm.ind_min;
    arInfo->ind_max = mm.ind_max;
}

// Fu
struct MinMax GetMaxMin(const int* ar, int size) {
    MinMax result = {0, 0};
    if (ar == nullptr || size <= 0) {
        return result;
    }

    int minVal = std::numeric_limits<int>::max();
    int maxVal = std::numeric_limits<int>::min();

    for (int i = 0; i < size; ++i) {
        if (ar[i] < minVal) {
            minVal = ar[i];
            result.ind_min = i;
        }
        if (ar[i] > maxVal) {
            maxVal = ar[i];
            result.ind_max = i;
        }
    }
    return result;
}

// ggghelp
struct CountNum GetStatNumber(const int* ar, int size) {
    CountNum result = {0, 0, 0};
    if (ar == nullptr || size <= 0) {
        return result;
    }

    for (int i = 0; i < size; ++i) {
        if (ar[i] > 0) {
            result.pos++;
        } else if (ar[i] < 0) {
            result.neg++;
        } else {
            result.zero++;
        }
    }
    return result;
}

//jjjjjjjjjjjjjj
void foo() {}

//2 ver create adress 

//#include "array_info.h"
#include <cstdlib> 
#include <ctime>   

int* CreateAr(int size) {
    return new int[size]; 


int* CreateAr(int size, int number) {
    int* array = new int[size]; 
    for (int i = 0; i < size; ++i) {
        array[i] = number; 
    }
    return array; 
}

int* CreateAr(int size, int min, int max) {
    int* array = new int[size]; 
    std::srand(std::time(0)); 
    for (int i = 0; i < size; ++i) {
        array[i] = min + std::rand() % (max - min + 1); 
    return array; 
}
int* myArray = CreateAr(5);

delete[] myArray;
}

