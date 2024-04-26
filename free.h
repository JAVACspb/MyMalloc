

#ifndef MYMALLOC_FREE_H
#define MYMALLOC_FREE_H
typedef struct {}Chunk_List;
void *heap_free(void *ptr);
int chunk_list_find(const Chunk_List *list, void *ptr);
void chunk_list_insert(Chunk_List *list, void *ptr, size_t size);
void chunk_list_remove(Chunk_List *list, size_t index);

#endif MYMALLOC_FREE_H
