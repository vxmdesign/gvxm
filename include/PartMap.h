#ifndef PART_MAP_H
#define PART_MAP_H

#include <map>
#include <string>
#include "DbEntry.h"
#include "TextBlock.h"

using namespace std;
class PartMap{
 public:
  PartMap();
  void addPart(DbEntry *pEntry, TextBlock *pBlock);
  TextBlock *getPart(const char *pName);
 private:
  map<string,TextBlock*> mPartMap;
};

#endif
