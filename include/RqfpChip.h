#ifndef RQFP_CHIP_H
#define RQFP_CHIP_H

#include "BaseChip.h"
#include "DynamicString.h"
#include "PcbPad.h"
#include "StdPackages.h"


class RqfpChip: public BaseChip{
 public:
  RqfpChip(RqfpTabEntry *pTable, int pCnt);
 private:
  char * buildChip(int pId);
  RqfpTabEntry *mTab;
};

#endif
