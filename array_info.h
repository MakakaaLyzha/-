#pragma once

#include <cstddef> 


struct ArrayInfo {
    int* ar;          
    int size;         
    int ind_max;      
    int ind_min;      
    double mean;      
};
struct MinMax {
    int ind_min;
    int ind_max;
};


struct CountNum {
    int pos;
    int neg;
    int zero;
};


void getInfoArray(struct ArrayInfo* arInfo);
struct MinMax GetMaxMin(const int* ar, int size);
struct CountNum GetStatNumber(const int* ar, int size);


void foo();
