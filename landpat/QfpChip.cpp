#include "QfpChip.h"

QfpChip::QfpChip(SoicTabEntry *pTable, int pCnt){
  int c;
  for(c = 0; c < pCnt; c++){
    registerLayout(pTable[c].rpl, pTable[c].cid, c);
  }
  mTab = pTable;
}

char * QfpChip::buildChip(int pId){
  DynamicString *ds;
  PcbGroup *pg1;
  PcbGroup *pg2;
  PcbGroup *pg3;
  PcbGroup *pg4;
  BoxDef bd;
  char *tmp;
  int pincnt;
  int e;
  
  e = (int)(mTab[pId].e * 100);
  pincnt = (int)(mTab[pId].d * 100);
  pincnt = pincnt / e;
  pincnt++;

  pg1 = new PcbGroup(pincnt, N_HORZ);
  pg2 = new PcbGroup(pincnt, HORZ);
  pg3 = new PcbGroup(pincnt, N_VERT);
  pg4 = new PcbGroup(pincnt, VERT);

  ds = new DynamicString();

  ds->append("Element[0x00000000 \"%s\" \"$1\" \"\" 10000 10000 -3150 -3150 0 100 \"\"](\n", mTab[pId].cid);  

  pg1->setXYDim(mTab[pId].y, mTab[pId].x);
  pg1->setESpace(mTab[pId].e);
  pg1->center();
  pg1->move(0, mTab[pId].c / 2);
  pg1->setOffset(pincnt*2);  
  pg1->generatePads(ds);
  

  pg2->setXYDim(mTab[pId].y, mTab[pId].x);
  pg2->setESpace(mTab[pId].e);
  pg2->center();
  pg2->move(0, -(mTab[pId].c / 2));
  pg2->generatePads(ds);


  pg3->setXYDim(mTab[pId].y, mTab[pId].x);
  pg3->setESpace(mTab[pId].e);
  pg3->center();
  pg3->move(-(mTab[pId].c / 2), 0);
  pg3->setOffset(pincnt*3);
  pg3->generatePads(ds);


  pg4->setXYDim(mTab[pId].y, mTab[pId].x);
  pg4->setESpace(mTab[pId].e); 
  pg4->center();
  pg4->move(mTab[pId].c / 2,0);
  pg4->setOffset(pincnt);
  pg4->generatePads(ds);
  bd.x2 = (mTab[pId].g / 2) - 0.5;
  bd.x1 = -bd.x2;
  bd.y2 = bd.x2;
  bd.y1 = bd.x1;
  bd.bm = TOP_LEFT;
  pg4->generateBox(ds, &bd);
  ds->append(")\n");

  tmp = ds->str();
  
  delete pg1;
  delete pg2;
  delete ds;
  return tmp;
}

