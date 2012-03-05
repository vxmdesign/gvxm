#ifndef LEAF_NODE_H
#define LEAF_NODE_H

#include <stdio.h>
#include <string.h>
#include "MapNode.h"

class LeafNode: public MapNode{
 public:
  LeafNode(const char *pName);
  int nodeType();
  int nodeException();
  const char *value();
  int compare(LeafNode *pLn);
  int compare(const char *pName);
 private:
  char mName[32];
};

#endif
