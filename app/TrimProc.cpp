#include "TrimProc.h"



TrimProc::TrimProc(MapNode *pRoot){
  mRoot = pRoot;
}

void TrimProc::process(MapList *pList){
  int c;
  int i;
  MapNode *tmp;
  ListNode *ln;
  c = pList->count() - 1;
  if(pList->getNode(c)->getMark() != 1) return;
  for(i = 0; i < pList->count(); i++){
    if(pList->getNode(i) == mRoot) return;
  }
  while(c > 0){
    c--;
    tmp = pList->getNode(c);
    if(tmp->getMark() != 2 && tmp->nodeType() == 3){
      ln = (ListNode*) tmp;
      ln->invNode(pList->getNode(c+1));
      return;
    }
  }
}
