#include "AppUtilities.h"

int AcontainsB(MapNode *pA, MapNode *pB){
  CheckTreeProc ctp(pB);
  int i;
  ProcTree(&ctp, pA);
  i = ctp.contains();
  return i;
}
