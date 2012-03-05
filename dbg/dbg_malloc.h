#ifndef DBG_MALLOC_H
#define DBG_MALLOC_H

#include<malloc.h>


typedef struct{
  void *ptr;
  int size;
  int active;
}dbg_malloc_entry;

void init_malloc();
void *dbg_malloc(int size);
void dbg_free(void *ptr);



#endif
