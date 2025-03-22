/*#include <iostream>
struct Info {
 int* ar;
 int size;
 int min;
 int max;
 double aver;
 int stat[256];
 
 Info():
 Info(int size);
 Info(int min, int max);
 Info(bool, int);
 Info(int, int, int, int)
 
 Info();
 -Info();
};


Info::Info() {
 std::cout<< func << std::endl;
 ar = nullptr;
 size = 0;
 min = std :: numeric_limits<int>::max();
 max= std:: numeric_limits<int>::min();
 aver= 0;
 memset(stat, 0×00, 256 * sizeof(int));
}
Info::-Info(){
 
}

int main (int argc, char** arvg) {
 Info* test = new struct Info();
 if (test== nullptr){
  return 1;
 }
 std:: cout<<"min" << test->min<<"ggʻ"<<test->max<<std::endl;
 delete test;
 return 0;
}

#include <iostream>

using namespace std;

//CreateAr(int size);

void insertion_sort (int a[],int lo);

int main()
{
    int a[] = {4, 7, 8, 3, 5, 1, 2, 6, 9};
    int lo=9;
    insertion_sort(a, lo);

    for (int i = 0  i < lo; i++) 
    {
        cout << "a = ["<< i<<"] = " <<a[i] << endl;
    }
    return 0;
}




void insertion_sort (int a[],int lo)
{
    for( int i =1; i< lo; i++) {
        int key = a[i];
        int j = i -1;
        while (j>=0 && a[j]> key ){
            a[j+1] = a[j];
            j = j-1;
        }
        a[j+1]=key;
    }
}
*/
#include <iostream>

int* CreateAr(int size) {
    // Выделение памяти для массива размером size
    int* array = new int[size];
    return array;  // Возвращаем указатель на первый элемент массива
}

int main() {
    int size = 9;
    int* myArray = CreateAr(size);  // Создаем массив

    // Используем массив
    for (int i = 0; i < size; ++i) {
        myArray[i] = i * 10;  // Заполняем массив значениями
    }

    // Выводим значения массива
    for (int i = 0; i < size; ++i) {
        std::cout << myArray[i] << " ";
    }
    std::cout << std::endl;

    // Освобождаем память
    delete[] myArray;

    return 0;
}
