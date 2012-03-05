#include "CheckTreeProc.h"

CheckTreeProc::CheckTreeProc(MapNode *pNode){
  mFound = 0;
  mNode = pNode;
}

void CheckTreeProc::process(LeafNode *pNode){
  if(pNode == mNode){
    mFound = 1;
 }
}

void CheckTreeProc::process(StringNode *pNode){
  if(pNode == mNode){
    mFound = 1;
  }
}

void CheckTreeProc::process(KeyValNode *pNode){
  if(pNode == mNode){
    mFound = 1;
  }
}

void CheckTreeProc::process(ListNode *pNode){
  if(pNode == mNode){
    mFound = 1;
  }
}

int CheckTreeProc::contains(){
  return mFound;
}
