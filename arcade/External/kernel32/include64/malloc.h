#ifndef _SIZE_T_DEFINED
typedef unsigned long long size_t;
#define _SIZE_T_DEFINED
#endif
void * _alloca(size_t size);
void * calloc(size_t num, size_t size);
void   free(void *memblock);
void * malloc(size_t size);
void * realloc(void *memblock, size_t size);

