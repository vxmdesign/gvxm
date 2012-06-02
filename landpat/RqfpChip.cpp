#include "RqfpChip.h"

RqfpChip::RqfpChip(RqfpTabEntry *pTable, int pCnt){
  int c;
  for(c = 0; c < pCnt; c++){
    registerLayout(pTable[c].rpl, pTable[c].cid, c);
  }
  mTab = pTable;
}

char * RqfpChip::buildChip(int pId){
  DynamicString *ds;
  PcbGroup *pg1;
  PcbGroup *pg2;
  PcbGroup *pg3;
  PcbGroup *pg4;
  BoxDef bd;
  char *tmp;
  int pincnth;
  int pincntv;
  int e;
  
  e = (int)(mTab[pId].e * 100);
  pincnth = (int)(mTab[pId].d2 * 100);
  pincnth = pincnth / e;
  pincntv = (int)(mTab[pId].d1 * 100);
  pincntv = pincntv / e;
  
  pincnth++;
  pincntv++;
  
  pg1 = new PcbGroup(pincnth, N_HORZ);
  pg2 = new PcbGroup(pincnth, HORZ);
  pg3 = new PcbGroup(pincntv, N_VERT);
  pg4 = new PcbGroup(pincntv, VERT);

  ds = new DynamicString();

  ds->append("Element[0x00000000 \"%s\" \"$1\" \"\" 10000 10000 -3150 -3150 0 100 \"\"](\n", mTab[pId].cid);  

  pg1->setXYDim(mTab[pId].y, mTab[pId].x);
  pg1->setESpace(mTab[pId].e);
  pg1->center();
  pg1->move(0, mTab[pId].c1 / 2);
  pg1->setOffset(pincnth + pincntv);  
  pg1->generatePads(ds);
  

  pg2->setXYDim(mTab[pId].y, mTab[pId].x);
  pg2->setESpace(mTab[pId].e);
  pg2->center();
  pg2->move(0, -(mTab[pId].c1 / 2));
  pg2->generatePads(ds);


  pg3->setXYDim(mTab[pId].y, mTab[pId].x);
  pg3->setESpace(mTab[pId].e);
  pg3->center();
  pg3->move(-(mTab[pId].c2 / 2), 0);
  pg3->setOffset(pincnth*2 + pincntv);
  pg3->generatePads(ds);


  pg4->setXYDim(mTab[pId].y, mTab[pId].x);
  pg4->setESpace(mTab[pId].e); 
  pg4->center();
  pg4->move(mTab[pId].c2 / 2,0);
  pg4->setOffset(pincnth);
  pg4->generatePads(ds);
  bd.x2 = (mTab[pId].g2 / 2) - 0.5;
  bd.x1 = -bd.x2;
  bd.y2 = (mTab[pId].g1 / 2) - 0.5;
  bd.y1 = -bd.y2;
  pg4->generateBox(ds, &bd);
  ds->append(")\n");

  tmp = ds->str();
  
  delete pg1;
  delete pg2;
  delete ds;
  return tmp;
}

