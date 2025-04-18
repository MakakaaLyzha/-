#include "array_info.h"
#include <iostream>

void ShowElement(const int* ar, int size, int col_count, char delimeter){
    for (int k = 0; k < size; k++){
      std::cout << ar[k] << delimeter;
      if ((k+1) % col_count == 0){
          std::cout << "\n";
      }
      else if (k+1 == size){
        std::cout << "\n";
      }
    
    }
}