#include <assert.h>
#include <stdbool.h>
#include "allocator.h"

#define HEAP_FREED_CAP 1024

typedef struct {
    size_t count;
    Chunk chunks[HEAP_ALLOCED_CAP];
}Chunk_List;

int chunk_list_find(const Chunk_List *list, void *ptr){
    assert(false && "TODO: chunk_list_find is not implemented");
    return -1;
}
void chunk_list_insert(Chunk_List *list, void *ptr, size_t size){
    assert(false && "TODO: chunk_list_insert is not implemented");
}
void chunk_list_remove(Chunk_List *list, size_t index){
    assert(false && "TODO: chunk_list_remove is not implemented");
}

Chunk heap_freed[HEAP_FREED_CAP] = {{0}};
size_t heap_freed_size = 0;

void *heap_free(void *ptr){
    assert(false && "heap_free is not implemented");
}
