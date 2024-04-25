#include <stddef.h>  // Для size_t

#ifndef MYMALLOC_ALLOCATOR_H
#define MYMALLOC_ALLOCATOR_H

void *heap_alloc(size_t size);
void head_dump_alloced_chunks(void);
void *heap_free(void *ptr);

#endif //MYMALLOC_ALLOCATOR_H
