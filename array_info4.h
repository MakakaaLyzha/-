#ifndef ARRAY_INFO_H
#define ARRAY_INFO_H

// Функция, возвращающая адрес нулевого элемента массива
int* CreateAr(int size);

// Функция, возвращающая адрес нулевого элемента массива, заполненного числами number
int* CreateAr(int size, int number);

// Функция, возвращающая адрес нулевого элемента массива, заполненного произвольными числами от min до max
int* CreateAr(int size, int min, int max);

#endif // ARRAY_INFO_H

