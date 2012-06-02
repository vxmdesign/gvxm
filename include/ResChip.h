#ifndef RES_CHIP_H
#define RES_CHIP_H

#include "BaseChip.h"
#include "DynamicString.h"
#include "PcbPad.h"
#include "StdPackages.h"


class ResChip: public BaseChip{
 public:
  ResChip(ResTabEntry *pTable, int pCnt);
 private:
  char * buildChip(int pId);
  ResTabEntry *mTab;
};

#endif
