#include <stddef.h>  // Для size_t

#ifndef MYMALLOC_ALLOCATOR_H
#define MYMALLOC_ALLOCATOR_H

#define HEAP_ALLOCED_CAP 1024

void *heap_alloc(size_t size);
void head_dump_alloced_chunks(void);
typedef struct {}Chunk;
#endif MYMALLOC_ALLOCATOR_H
