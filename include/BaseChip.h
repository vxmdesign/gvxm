#ifndef BASE_CHIP_H
#define BASE_CHIP_H

#include "DynamicString.h"
#include "DbEntry.h"
#include "TextBlock.h"
#include <map>
#include <string>
#include <malloc.h>

using namespace std;

class BaseChip{
 public:
  BaseChip();
  TextBlock *getChipUnique(const char *pPart);
  TextBlock *getChipByRpl(const char *pRpl, const char *pPart);
  TextBlock *getChipByCid(const char *pCid, const char *pPart);
  void registerLayout(const char *pRpl, const char *pCid, int pId);
 private:
  TextBlock * localBuild(const char *pPart, int pId);
  virtual char * buildChip(int pId) = 0;
  map<string, int> mRplMap;
  map<string, int> mCidMap;

};

#endif
