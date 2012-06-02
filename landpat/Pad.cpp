#include "Pad.h"

PadGroup::PadGroup(int pCount, Orient pOrt){
  int c;
  mOrt = pOrt;
  mOffset = 0;
  mScale.dx = 0;
  mScale.dy = 0;
  mCount = pCount;
  mLineWidth = 1;
  mPads = (PadInfo *) malloc(sizeof(PadInfo) * mCount);
  for(c = 0;c < mCount; c++){
    mPads[c].pscale = &(mScale);
    mPads[c].pco.x = 0;
    mPads[c].pco.y = 0;
    mPads[c].ort = mOrt;
  }
}

void PadGroup::setESpace(double pE){
  double sign;
  int c;
  if((mOrt & 0x2) == 0){
    sign = 1;
  }else{
    sign = -1;
  }
  for(c = 0; c < mCount; c++){
    if((mOrt & 0x1) == 1){
      mPads[c].pco.x = c * pE * sign;
    }else{
      mPads[c].pco.y = c * pE * sign;
    }
  }
}

void PadGroup::setXYDim(double pX, double pY){
  mScale.dx = pX;
  mScale.dy = pY;
}

void PadGroup::move(double pDx, double pDy){
  int c;
  for(c = 0; c < mCount; c++){
    mPads[c].pco.x += pDx;
    mPads[c].pco.y += pDy;
  }
}

void PadGroup::center(){
  double a1;
  double a2;
  int a1c, a2c;
  a1c = 0;
  a2c = 0;
  if((mOrt & 0x1) == 1){
    a1 = mPads[0].pco.x;
    a2 = mPads[mCount - 1].pco.x;
    a1c = -1;
  }else{
    a1 = mPads[0].pco.y;
    a2 = mPads[mCount - 1].pco.y;
    a2c = -1;
  }
  a1 = (a1 + a2) / 2;
  move(a1 * a1c, a1 * a2c);
}

void PadGroup::generatePads(DynamicString *pDs){
  int c;
  for(c = 0; c < mCount; c++){
    buildPad(pDs, &(mPads[c]), mOffset+c+1);
  }
}

void PadGroup::setOffset(int pOff){
  mOffset = pOff;
}

void PadGroup::setSilkWidth(double pLineWidth){
  mLineWidth = pLineWidth;
}

double PadGroup::getSilkWidth(){
  return mLineWidth;
}

void PadGroup::generateBox(DynamicString *pDs, BoxDef *pBd){
  silkLine(pDs, pBd->x1, pBd->y1, pBd->x2, pBd->y1);
  silkLine(pDs, pBd->x2, pBd->y1, pBd->x2, pBd->y2);
  silkLine(pDs, pBd->x1, pBd->y2, pBd->x2, pBd->y2);
  silkLine(pDs, pBd->x1, pBd->y1, pBd->x1, pBd->y2);
  switch(pBd->bm){
  case TOP_LEFT:
    silkLine(pDs, pBd->x1 + 1.0, pBd->y1, pBd->x1, pBd->y1 + 1.0);
    break;
  case TOP_RIGHT:
    silkLine(pDs, pBd->x2 - 1.0, pBd->y1, pBd->x2, pBd->y1 + 1.0);
    break;
  case BOT_LEFT:
    silkLine(pDs, pBd->x1 + 1.0, pBd->y2, pBd->x1, pBd->y2 - 1.0);
    break;
  case BOT_RIGHT:
    silkLine(pDs, pBd->x2 - 1.0, pBd->y2, pBd->x2, pBd->y2 - 1.0);
    break;
  default:
    break;
 }
}

