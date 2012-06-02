#ifndef PATTERNDB_H
#define PATTERNDB_H


#include <stdio.h>
#include <map>
#include "StdPackages.h"
#include "BaseChip.h"
#include "ResChip.h"
#include "SoicChip.h"
#include "QfpChip.h"
#include "RqfpChip.h"
#include "DfnChip.h"
#include "UsbChip.h"
#include "TextBlock.h"
#include "DbFile.h"
#include "Vxm.h"


using namespace std;

class PatternDb{
 public:
  PatternDb();
  TextBlock *getBlockUnique(const char *pClass, const char *pUid);

  TextBlock *getBlockByRpl(const char *pRpl, const char *pUid);
  TextBlock *getBlockByCid(const char *pClass, const char *pCid, const char *pUid);
 private:
  BaseChip* mChip[STD_PATTERN_SIZE+1];
  map<string, BaseChip *> mChipMap; 
};

#endif
