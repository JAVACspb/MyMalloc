#include <stdio.h>
#include "allocator.h"
int main() {
    // Выделим память для некоторых данных
    char *root = heap_alloc(10);
    if (root == NULL) return -1; // проверка на успешное выделение памяти

    for (int i = 0; i < 10; i++) {
        root[i] = (char) (i + 'A');
    }

    for (int i = 0; i < 10; i++) {
        printf("%d ", root[i]);
    }
    printf("\n");
    heap_free(root);
    // Попытка выделить чрезмерно большой объем памяти
    void *big_block = heap_alloc(650000); // Это спровоцирует assert и аварийное завершение программы


    return 0;
}
