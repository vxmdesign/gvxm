#include "TreeMarkProc.h"

TreeMarkProc::TreeMarkProc(MapNode *pRoot){
  mMarkState = 0;
  mRoot = pRoot;
}

void TreeMarkProc::process(LeafNode *pNode){
  pNode->setMark(MARK_VAL(1));

}

void TreeMarkProc::process(StringNode *pNode){
  pNode->setMark(MARK_VAL(1));

}

void TreeMarkProc::process(KeyValNode *pNode){
  pNode->setMark(MARK_VAL(2));
}

void TreeMarkProc::process(ListNode *pNode){
  pNode->setMark(MARK_VAL(2));
}

void TreeMarkProc::Mark(){
  mMarkState = 1;
  ProcTree(this, mRoot);
}

void TreeMarkProc::UnMark(){
  mMarkState = 0;
  ProcTree(this, mRoot);
}
