#ifndef QFP_CHIP_H
#define QFP_CHIP_H

#include "BaseChip.h"
#include "DynamicString.h"
#include "PcbPad.h"
#include "StdPackages.h"


class QfpChip: public BaseChip{
 public:
  QfpChip(SoicTabEntry *pTable, int pCnt);
 private:
  char * buildChip(int pId);
  SoicTabEntry *mTab;
};

#endif
