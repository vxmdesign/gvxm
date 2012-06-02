#ifndef SOIC_CHIP_H
#define SOIC_CHIP_H

#include "BaseChip.h"
#include "DynamicString.h"
#include "PcbPad.h"
#include "StdPackages.h"


class SoicChip: public BaseChip{
 public:
  SoicChip(SoicTabEntry *pTable, int pCnt);
 private:
  char * buildChip(int pId);
  SoicTabEntry *mTab;
};

#endif
