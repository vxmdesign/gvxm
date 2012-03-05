#ifndef KEYVAL_NODE_H
#define KEYVAL_NODE_H

#include <stdio.h>
#include <string.h>
#include "MapNode.h"

class KeyValNode: public MapNode{
 public:
  KeyValNode(const char *pName,MapNode *pNode);
  int nodeType();
  int nodeException();
  int compare(const char *pName);  
  const char *key();
  MapNode *value();
  MapNode *resetValue(MapNode *pNode);
 private:
  char mName[32];
  MapNode *mNode;
  
};

#endif
