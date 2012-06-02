#include "PcbPad.h"

PcbGroup::PcbGroup(int pCount, Orient pOrt): PadGroup(pCount, pOrt){
  setSilkWidth(0.5);
}

void PcbGroup::silkLine(DynamicString *pDs, double x1, double y1, double x2, double y2){
  pDs->append("\tElementLine[");
  pDs->append("%d ", PCB_CONV(x1));
  pDs->append("%d ", PCB_CONV(y1));
  pDs->append("%d ", PCB_CONV(x2));
  pDs->append("%d ", PCB_CONV(y2));
  pDs->append("%d]\n", PCB_CONV(getSilkWidth()));
}

void PcbGroup::buildPad(DynamicString *pDs, PadInfo *pPad, int pId){
  PcbParams pp;
  double delta;
  int dx,dy;
  if(pPad->pscale->dx > pPad->pscale->dy){
    pp.thick = pPad->pscale->dy;
    delta = (pPad->pscale->dx - pp.thick)/2;
    if((pPad->ort & 0x1) != 0){
      dy = 1;
      dx = 0;
    }else{
      dy = 0;
      dx = 1;
    }
  }else{
    pp.thick = pPad->pscale->dx;
    delta = (pPad->pscale->dy - pp.thick)/2;
    if((pPad->ort & 0x1) != 0){
      dy = 0;
      dx = 1;
    }else{
      dy = 1;
      dx = 0;
    }
  }

  pp.x1 = pPad->pco.x + (delta * dx);
  pp.y1 = pPad->pco.y + (delta * dy);
  pp.x2 = pPad->pco.x - (delta * dx);
  pp.y2 = pPad->pco.y - (delta * dy);
  pp.mask = pp.thick * 1.01;
  pp.clearance = pp.thick * .05;
  pp.id = pId;
  printPad(pDs, &pp);
}

void PcbGroup::printPad(DynamicString *pDs, PcbParams *pPp){
  pDs->append("\tPad[");
  pDs->append("%d ", PCB_CONV(pPp->x1));
  pDs->append("%d ", PCB_CONV(pPp->y1));
  pDs->append("%d ", PCB_CONV(pPp->x2));
  pDs->append("%d ", PCB_CONV(pPp->y2));
  pDs->append("%d ", PCB_CONV(pPp->thick));
  pDs->append("%d ", PCB_CONV(pPp->clearance));
  pDs->append("%d ", PCB_CONV(pPp->clearance));
  pDs->append("\"%d\" ", pPp->id);
  pDs->append("\"%d\" ", pPp->id);
  pDs->append("\"square\"]\n");
}
