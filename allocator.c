#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

#define HEAP_CAPACITY 640000
#define HEAP_ALLOCED_CAP 1024
//структура для отслеживания
typedef struct {
    void *start; // начало кусочка
    size_t size; // размер собственно
}Heap_Chunk;

char heap[HEAP_CAPACITY] = {0}; // типо наша "Куча"
size_t heap_size = 0; // отслеживаем количество выделенной папмяти

Heap_Chunk heap_alloced[HEAP_ALLOCED_CAP] = {0}; // хранит инфу о каждом выделенном блоке памяти
size_t heap_alloced_size = 0; // как бы индекс массива из уже отслежываемых блоков(их количество), ссылается на след.свобод позицию в массиве для выделения памяти

void *heap_alloc(size_t size){
    assert(heap_size + size <= HEAP_CAPACITY); // проверяю что не выешл за пределы пула, влезет ли блок размером size
    void *result = heap + heap_size; // получил указатель на первый свободный элемент после выделения памяти
    heap_size += size; // меняем заполненность, странное слово

    const Heap_Chunk chunk = {
            .start = result, // начало выделенного блока
            .size = size, // количество выделенной памяти
    };

    assert(heap_alloced_size < HEAP_ALLOCED_CAP); // проверяем есть ли место в нашем массиве "отслеживания выделений"
    heap_alloced[heap_alloced_size++] = chunk; // добавили запись в "наш массив"
    return result; // ретюрн сбствн
}
// массив для просмотра выделенный данныхь и их метаданных типо
void head_dump_alloced_chunks(void){
    for(size_t i = 0; i < heap_alloced_size; i++){
        printf(" start: %p, size: %zu\n",
               heap_alloced[i].start, heap_alloced[i].size);
    }
}
void *heap_free(void *ptr){
    (void) ptr;
    assert(false && "heap_free is not implemented");
}
