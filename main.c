#include <stdio.h>
#include "allocator.h"
int main() {
    // Выделим память для некоторых данных
    int *numbers = (int *)heap_alloc(10 * sizeof(int));
    if (numbers == NULL) return -1; // проверка на успешное выделение памяти

    for (int i = 0; i < 10; i++) {
        numbers[i] = i;
    }

    for (int i = 0; i < 10; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    // Попытка выделить чрезмерно большой объем памяти
    void *big_block = heap_alloc(650000); // Это спровоцирует assert и аварийное завершение программы


    return 0;
}
