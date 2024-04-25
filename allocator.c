#include <stdio.h>
#include <assert.h>

#define HEAP_CAPACITY 640000

char heap[HEAP_CAPACITY] = {0};
size_t heap_size = 0; // отслеживаем количество выделенной папмяти

void *heap_alloc(size_t size){
    assert(heap_size + size <= HEAP_CAPACITY); // проверяю что не выешл за пределы пула, влезет ли блок размером size
    void *result = heap + heap_size; // получил указатель на первый свободный элемент после выделения памяти
    heap_size += size; // меняем заполненность, странное слово
    return result; // ретюрн сбствн
}
