#include "CommandBase.h"

void CommandBase::process(Modifier *pMod, MapNode *pNode){
  int c;
  ListNode *ln;

  if(pNode->nodeType() != 3){
    addNode(pMod, pNode);
    return;
  }
  ln = (ListNode*)pNode;
  for(c = 0; c < ln->count(); c++){
    addNode(pMod, ln->getNode(c));
  }
}
