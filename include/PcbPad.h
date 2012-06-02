#ifndef PCB_PAD_H
#define PCB_PAD_H

#include "Pad.h"

#define PCB_CONV(x) ((int)((x) * ((1000.0 * 100.0)/25.4)))

typedef struct{
  double x1;
  double y1;
  double x2;
  double y2;
  double thick;
  double clearance;
  double mask;
  int id;
}PcbParams;

class PcbGroup: public PadGroup { 
 public:
  PcbGroup(int pCount, Orient pOrt);
 private:
  void silkLine(DynamicString *pDs, double x1, double y1, double x2, double y2);
  void printPad(DynamicString *pDs, PcbParams *pPp);
  void buildPad(DynamicString *pDs, PadInfo *pPad, int pId);
};


#endif
