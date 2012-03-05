#include "MapList.h"

void dbg_free(void *ptr){
  //  printf("Freeing 0x%08x\n", (unsigned long)ptr);
  free(ptr);
}

void *dbg_malloc(int size){
  void *tmp;
  tmp = malloc(size);
  //printf("Malloc 0x%08x\n", (unsigned long)tmp);
  return tmp;
}

MapList::MapList(){
  mHead = NULL;
  mCount = 0;
}

MapList::MapList(MapNode *pNode){
  mHead = NULL;
  mCount = 0;
  append(pNode);
}

void MapList::append(MapNode *pNode){
  mapLink *tmp, *mp;
  tmp = (mapLink *)malloc(sizeof(mapLink));
  tmp->node = pNode;
  tmp->next = NULL;
  tmp->nodeType = pNode->nodeType();
  tmp->refCount = 1;
  if(mHead == NULL){
    mHead = tmp;
    mCount = 1;
    return;
  }
  mp = mHead;
  while(mp->next != NULL){
    mp = mp->next;
  }
  mp->next = tmp;
  mCount++;
}


void MapList::invNode(MapNode *pNode){
  mapLink *tmp;
  tmp = mHead;
  while(tmp != NULL && tmp->node != pNode) tmp = tmp->next;
  if(tmp == NULL){
    return;
  }
  tmp->node = NULL;
}

void MapList::cleanup(){
  mapLink *tmp, *del;
  int ichk;
  if(mHead == NULL){
    return;
  }
  while(mHead != NULL && mHead->node == NULL){
    del = mHead;
    mHead = mHead->next;
    free(del);
    mCount--;
  }
  if(mHead != NULL){
    tmp = mHead;
    while(tmp->next != NULL){
      if(tmp->next->node == NULL){
	del = tmp->next;
	tmp->next = tmp->next->next;
	free(del);
	mCount--;
      }else{
	tmp = tmp->next;
      }
    }
  }
  ichk = 0;
  tmp = mHead;
  while(tmp != NULL){
    if(tmp->node == NULL) printf("Sanity Check failed\n");
    tmp = tmp->next;
    ichk++;
  }
  if(ichk != mCount){
    printf("Count sanity check failed True: %d Exp: %d\n", ichk, mCount);
  }
}

void MapList::remove(MapNode *pNode){
  mapLink *tmp, *del;
  printf("Remove Node\n");
  tmp = mHead;
  if(mHead->node == pNode){
    if(mHead->refCount == 1){
      mHead = mHead->next;
      free(tmp);
      mCount--;
    }else{
      mHead->refCount--;
    }
  }
  while(tmp->next != NULL && tmp->next->node != pNode){ 
    tmp = tmp->next;
  }
  if(tmp->next == NULL) return;
  if(tmp->next->refCount == 1){
    del = tmp->next;
    tmp->next = tmp->next->next;
    free(del);
    mCount--;
  }else{
    tmp->next->refCount--;
  }
}

void MapList::pop(){
  mapLink *tmp;
  if(mHead == NULL) return;
  if(mHead->next == NULL){
    mCount = 0;
    free(mHead);
    mHead = NULL;
    return;
  }
  tmp = mHead;
  while(tmp->next->next != NULL) tmp = tmp->next;
  mCount--;
  free(tmp->next);
  tmp->next = NULL;
}


int MapList::count(){
  return mCount;
}

MapNode *MapList::getNode(const char *pName){
  mapLink *tmp;
  tmp = mHead;
  while(tmp != NULL && (tmp->node->compare(pName) != 0)){
    tmp= tmp->next;
  }
  if(tmp == NULL) return NULL;
  return tmp->node;
}

MapNode *MapList::getNode(int pIndex){
  mapLink *tmp;
  int c;
  if(pIndex >= mCount) return NULL;
  tmp = mHead;
  for(c = 0; c < pIndex; c++){
    tmp = tmp->next;
  }
  return tmp->node;
}

int MapList::contains(const char *pName){
  return -1;
}

int MapList::contains(MapNode *pNode){
  if(getMapByNode(pNode) == NULL) return 0;
  return 1;
}

mapLink *MapList::getMapByNode(MapNode *pNode){
  mapLink *tmp;
  tmp = mHead;
  while(tmp != NULL){
    if(tmp->node == pNode) return tmp;
    tmp = tmp->next;
  }
  return NULL;
}

void MapList::inc(MapNode *pNode){
  mapLink *tmp;
  tmp = getMapByNode(pNode);
  if(tmp != NULL) tmp->refCount++;
}

void MapList::dec(MapNode *pNode){
  mapLink *tmp;
  tmp = getMapByNode(pNode);
  if(tmp != NULL){
    tmp->refCount--;
    if(tmp->refCount == 0){
      //delete tmp->node;
      //...etc///
    }
  }
}

