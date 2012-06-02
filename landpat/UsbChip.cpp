#include "UsbChip.h"

typedef struct{
  double pE;
  double pX;
  double pY;
  double mE;
  double mX1;
  double mX2;
  double mY;
  double mG;
  double mQ;
}usbx;

usbx ug={0.8, 0.5, 2.25, 9.85, 4.0, 3.5, 2.05, 4.25, 4.225};


UsbChip::UsbChip(){
  
}

char * UsbChip::buildChip(int pId){
  DynamicString *ds;
  PcbGroup *pg1;
  PcbGroup *pg2;
  PcbGroup *pg3;
  char *tmp;

  pg1 = new PcbGroup(2, VERT);
  pg2 = new PcbGroup(2, VERT);
  pg3 = new PcbGroup(5, VERT);

  ds = new DynamicString();

  ds->append("Element[0x00000000 \"USBC\" \"$1\" \"\" 10000 10000 -3150 -3150 0 100 \"\"](\n");  
  pg1->setXYDim(ug.mX1, ug.mY);
  pg1->setESpace(ug.mE);
  pg1->center();
  pg2->setXYDim(ug.mX2, ug.mY);
  pg2->setESpace(ug.mE);
  pg2->center();
  pg2->move(ug.mG,0);
  pg3->setXYDim(ug.pY, ug.pX);
  pg3->setESpace(ug.pE);
  pg3->center();
  pg3->move(ug.mQ,0);
  
  pg2->setOffset(5);
  pg1->setOffset(7);

  pg1->generatePads(ds);
  pg2->generatePads(ds);
  pg3->generatePads(ds);

  //  bd.x2 = (mTab[pId].d + mTab[pId].x)/2;
  //bd.x1 = -bd.x2;
  //bd.y2 = (mTab[pId].g / 2) - 1.0;
  //bd.y1 = -bd.y2;
  //bd.bm = BOT_LEFT;
  //pg1->generateBox(ds, &bd);
  ds->append(")\n");

  tmp = ds->str();
  
  delete pg1;
  delete pg2;
  delete ds;
  return tmp;
}

