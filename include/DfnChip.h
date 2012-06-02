#ifndef DFN_CHIP_H
#define DFN_CHIP_H

#include "BaseChip.h"
#include "DynamicString.h"
#include "PcbPad.h"
#include "StdPackages.h"


class DfnChip: public BaseChip{
 public:
  DfnChip(DfnTabEntry *pTable, int pCnt);
 private:
  char * buildChip(int pId);
  DfnTabEntry *mTab;
};

#endif
