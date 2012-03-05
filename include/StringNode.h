#ifndef STRING_NODE_H
#define STRING_NODE_H

#include <stdio.h>
#include <string.h>
#include "MapNode.h"
#include "VxmUtilities.h"

class StringNode: public MapNode{
 public:
  StringNode(const char *pStr);
  int nodeType();
  int nodeException();
  const char *value();
  int compare(const char *pName);
 private:
  char mStr[128];
};

#endif
