#include "sorts.h"
#include <iostream>
#include <algorithm>

//incertion sort
void insertion_sort(int* ar, int size, bool isAscending){
  if (isAscending){
    for (int i = 1; i < size; i++){
      for (int m = 0; m < i; m++){
        int tmp_val = 0;
        if (ar[m] > ar[i]){
          tmp_val = ar[m];
          ar[m] = ar[i];
          ar[i] = tmp_val;
        }
      }
    }
  } else{
    for (int i = 1; i < size; i++){
      for (int m = 0; m < i; m++){
        int tmp_val = 0;
        if (ar[m] < ar[i]){
          tmp_val = ar[m];
          ar[m] = ar[i];
          ar[i] = tmp_val;
        }
      }
    }
  }
    for (int i = 0; i < size; i++){
    std::cout << ar[i] << " ";
  }
  std::cout << std::endl;
}


//buble sort
void bubble_sort(int* ar, int size, bool isAscending){
  int tmp_val = 0;
  int size_const = size;
  if (isAscending){
    while (size != 0){
      for (int i = 0; i < size-1; i++){
        if (ar[i] > ar[i+1]){
          tmp_val = ar[i];
          ar[i] = ar[i+1];
          ar[i+1] = tmp_val;
        }
      }
      size -= 1;
    }
  } else {
    while (size != 0){
      for (int i = 0; i < size-1; i++){
        if (ar[i] < ar[i+1]){
          ar[i] = tmp_val;
          ar[i] = ar[i+1];
          ar[i+1] = tmp_val;
        }
      size -= 1;
      }
    }
  }
  for (int i=0; i < size_const; i++){
    std::cout << ar[i] << " ";
  }
  std::cout << "\n";
}

//selection sort
void selection_sort(int* ar, int size, bool isAscending){
  if (isAscending){
      for (int k = 0; k < size-1; k++){
        int min_index = k;
        for (int i = k+1; i < size; i++){
          if (ar[i] < ar[min_index]){
            min_index = i;
          }
        }
      std::swap(ar[k], ar[min_index]);  
      }
  } else{
      for (int k = 0; k < size-1; k++){  
        int min_index = k;
        for (int i = k+1; i < size; i++){
          if (ar[i] > ar[min_index]){
            min_index = i;
          }
        }
      std::swap(ar[k], ar[min_index]);  
      }
  }
}


int main(){

  
  return 0;
}