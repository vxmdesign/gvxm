#ifndef PAD_H
#define PAD_H

#include <malloc.h>
#include "DynamicString.h"

typedef struct{
  double x;
  double y;
}PadCoord;

typedef struct{
  double dx;
  double dy;
}PadScales;

typedef enum { VERT = 0, HORZ = 1, N_VERT = 2, N_HORZ = 3 } Orient;

typedef struct{
  PadCoord pco;
  Orient ort;
  PadScales *pscale;
}PadInfo;

typedef enum { NO_MARK = 0, TOP_LEFT, TOP_RIGHT, BOT_LEFT, BOT_RIGHT } BoxMark;

typedef struct{
  double x1;
  double y1;
  double x2;
  double y2;
  BoxMark bm;
}BoxDef;

class PadGroup{
 public:
  PadGroup(int pCount, Orient pOrt);
  void setESpace(double pE);
  void setXYDim(double pX, double pY);
  void setOffset(int pOff);
  void center();
  void move(double pDx, double pDy);
  void generatePads(DynamicString *pDs);
  void generateBox(DynamicString *pDs, BoxDef *pBd);
  void setSilkWidth(double pLineWidth);
  double getSilkWidth();
 private:
  virtual void silkLine(DynamicString *pDs, double x1, double y1, double x2, double y2) = 0;
  virtual void buildPad(DynamicString *pDs, PadInfo * pPad, int pId) = 0;
  PadScales mScale;
  PadInfo *mPads;
  int mCount;
  int mOffset;
  Orient mOrt;
  double mLineWidth;
}; 

#endif
