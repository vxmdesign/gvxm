#ifndef MAP_LIST_H
#define MAP_LIST_H

//#include "dbg_malloc.h"
#include <malloc.h>
#include "MapNode.h"

typedef struct MAP_LINK{
  int refCount;
  int nodeType;
  MapNode *node;
  struct MAP_LINK *next;
} mapLink;

class MapList{
 public:
  MapList();
  MapList(MapNode *pNode);
  int contains(const char *pName);
  int contains(MapNode *pNode);
  void append(MapNode *pNode);
  void invNode(MapNode *pNode);
  void cleanup();
  void remove(MapNode *pNode); 
  void pop();
  void inc(MapNode *pNode);
  void dec(MapNode *pNode);
  MapNode *getNode(int pIndex);
  MapNode *getNode(const char *pName);
  int count();
 private:
  mapLink *getMapByNode(MapNode *pNode);
  int mCount;
  mapLink *mHead;
};

#endif
