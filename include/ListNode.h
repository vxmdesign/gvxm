#ifndef LIST_NODE_H
#define LIST_NODE_H


#include "MapNode.h"
#include "MapList.h"

class ListNode: public MapNode{
 public: 
  ListNode();
  ListNode(MapNode *pNode);
  int nodeType();
  int nodeException();
  int compare(const char *pName);
  void append(MapNode *pNode);
  MapNode *getNode(int pIndex);
  MapNode *getNode(const char *pName);
  void remove(MapNode *pNode);
  int count();
  void invNode(MapNode *pNode);
  void cleanup();
 private:
  int mDirty;
  MapList *mList;
};

#endif
