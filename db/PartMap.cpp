#include "PartMap.h"


PartMap::PartMap(){

}

void PartMap::addPart(DbEntry *pEntry, TextBlock *pBlock){
  mPartMap[string(pEntry->uid)] = pBlock;
}

TextBlock *PartMap::getPart(const char *pName){
  return new TextBlock(mPartMap[pName]);
}
