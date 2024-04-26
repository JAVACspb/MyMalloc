#include <stdio.h>
#include <assert.h>
#include "free.h"


#define HEAP_CAPACITY 640000
#define HEAP_ALLOCED_CAP 1024
//структура для отслеживания
typedef struct {
    void *start; // начало кусочка
    size_t size; // размер собственно
}Chunk;



char heap[HEAP_CAPACITY] = {0}; // типо наша "Куча"
size_t heap_size = 0; // отслеживаем количество выделенной папмяти

Chunk heap_alloced[HEAP_ALLOCED_CAP] = {0}; // хранит инфу о каждом выделенном блоке памяти
size_t heap_alloced_size = 0; // как бы индекс массива из уже отслежываемых блоков(их количество), ссылается на след.свобод позицию в массиве для выделения памяти

Chunk_List alloced_chunks = {0};
Chunk_List freed_chunks = {0};

void chunk_list_dump(const Chunk_List *list){
    printf("Chunks (%zu):\n", list->co);
    for(size_t i = 0; i < heap_alloced_size; i++){
        printf(" start: %p, size: %zu\n",
               heap_alloced[i].start, heap_alloced[i].size);
    }
}

void *heap_alloc(size_t size){
    if(size > 0) {
        assert(heap_size + size <=
               HEAP_CAPACITY); // проверяю что не выешл за пределы пула, влезет ли блок размером size
        void *ptr = heap + heap_size; // получил указатель на первый свободный элемент после выделения памяти
        heap_size += size; // меняем заполненность, странное слово

        chunk_list_insert(&alloced_chunks, ptr, size);
//        const Chunk chunk = {
//                .start = ptr, // начало выделенного блока
//                .size = size, // количество выделенной памяти
//        };
//
//        assert(heap_alloced_size <
//               HEAP_ALLOCED_CAP); // проверяем есть ли место в нашем массиве "отслеживания выделений"
//        heap_alloced[heap_alloced_size++] = chunk; // добавили запись в "наш массив"
        return ptr; // ретюрн сбствн
    }else{
        return NULL;
        //реальный алокатор вернет уникальный указатель но я не реальный аллокатор )))
    }
}
// массив для просмотра выделенный данныхь и их метаданных типо
void head_dump_alloced_chunks(void){
    printf("Allocated Chunks (%zu):\n", heap_alloced_size);
    for(size_t i = 0; i < heap_alloced_size; i++){
        printf(" start: %p, size: %zu\n",
               heap_alloced[i].start, heap_alloced[i].size);
    }
}

