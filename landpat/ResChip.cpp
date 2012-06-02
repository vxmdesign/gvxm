#include "ResChip.h"

ResChip::ResChip(ResTabEntry *pTable, int pCnt){
  int c;
  for(c = 0; c < pCnt; c++){
    registerLayout(pTable[c].rpl, pTable[c].cid, c);
  }
  mTab = pTable;
}

char * ResChip::buildChip(int pId){
  DynamicString *ds;
  PcbGroup *pg;
  char *tmp;
  pg = new PcbGroup(2, HORZ);
  ds = new DynamicString();

  ds->append("Element[0x00000000 \"%s\" \"$1\" \"$2\" 10000 10000 -3150 -3150 0 100 \"\"](\n", mTab[pId].cid);  
  pg->setXYDim(mTab[pId].x, mTab[pId].y);
  pg->setESpace(mTab[pId].c);
  pg->center();
  pg->generatePads(ds);
  ds->append(")\n");

  tmp = ds->str();
  
  delete pg;
  delete ds;
  return tmp;
}

