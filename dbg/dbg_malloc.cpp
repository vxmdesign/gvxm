#include "dbg_malloc.h"

#define LIST_SIZE 1000

dbg_malloc_entry dme[LIST_SIZE];

void init_malloc(){
  int c;
  for(c = 0; c < LIST_SIZE; c++){
    dme[c].active = 0;
  }
}


void ptr_chk(int idx, void *ptr, int size){
  unsigned int a1,a2,b1,b2;
  a1 = (unsigned int)dme[idx].ptr;
  a2 = a1 + dme[idx].size;
  b1 = (unsigned int)ptr;
  b2 = b1 + size;
  if(b1 >= a1 && b1 < a2){
    printf("dbg1 0x%08x 0x%08x 0x%08x\n",a1,a2,b1);
  }
  if(b2 >= a1 && b2 < a2){
    printf("dbg2\n");
  }
  if(b1 < a1 && b2 > b2){
    printf("dbg3\n");
  }
}

void *dbg_malloc(int size){
  void *tmp;
  int c;
  int chk;
  chk = 0;
  tmp = malloc(size);
  printf("Malloc: 0x%08x\n", (unsigned int) tmp);

  for(c = 0; c < LIST_SIZE; c++){
    if(dme[c].active == 0){
      if(chk == 0){
	dme[c].ptr = tmp;
	dme[c].size = size;
	dme[c].active = 1;
	chk = 1;
      }
    }else{
      ptr_chk(c,tmp,size);
    }
  }
  return tmp;
}

void dbg_free(void *ptr){
  int c;
  for(c = 0; c < LIST_SIZE; c++){
    if(dme[c].ptr == ptr){
      printf("Freeing 0x%08x\n", (unsigned int) ptr);
      free(ptr);
      dme[c].active = 0;
      return;
    }
  }
  printf("Pointer not found error\n");
}
