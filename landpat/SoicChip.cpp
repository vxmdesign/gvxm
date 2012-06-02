#include "SoicChip.h"

SoicChip::SoicChip(SoicTabEntry *pTable, int pCnt){
  int c;
  for(c = 0; c < pCnt; c++){
    registerLayout(pTable[c].rpl, pTable[c].cid, c);
  }
  mTab = pTable;
}

char * SoicChip::buildChip(int pId){
  DynamicString *ds;
  PcbGroup *pg1;
  PcbGroup *pg2;
  BoxDef bd;
  char *tmp;
  int pincnt;
  int e;
  
  e = (int)(mTab[pId].e * 100);
  pincnt = (int)(mTab[pId].d * 100);
  pincnt = pincnt / e;
  pincnt++;

  pg1 = new PcbGroup(pincnt, HORZ);
  pg2 = new PcbGroup(pincnt, N_HORZ);

  ds = new DynamicString();

  ds->append("Element[0x00000000 \"%s\" \"$1\" \"\" 10000 10000 -3150 -3150 0 100 \"\"](\n", mTab[pId].cid);  
  pg1->setXYDim(mTab[pId].y, mTab[pId].x);
  pg1->setESpace(mTab[pId].e);
  pg1->center();
  pg2->setXYDim(mTab[pId].y, mTab[pId].x);
  pg2->setESpace(mTab[pId].e);
  pg2->center();
  pg1->move(0, mTab[pId].c / 2);
  pg2->move(0, -(mTab[pId].c / 2));
  pg2->setOffset(pincnt);
  pg1->generatePads(ds);
  pg2->generatePads(ds);

  bd.x2 = (mTab[pId].d + mTab[pId].x)/2;
  bd.x1 = -bd.x2;
  bd.y2 = (mTab[pId].g / 2) - 1.0;
  bd.y1 = -bd.y2;
  bd.bm = BOT_LEFT;
  pg1->generateBox(ds, &bd);
  ds->append(")\n");

  tmp = ds->str();
  
  delete pg1;
  delete pg2;
  delete ds;
  return tmp;
}

