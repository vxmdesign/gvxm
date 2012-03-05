#include "BomKeyNode.h"

BomKeyNode::BomKeyNode(): KeyValNode("bom", mList = emptyList()){
  mHead = NULL;
  mMajor = 1;
  mCount = 0;
}

void BomKeyNode::addComponent(MapNode *pNode){
  MapNode *mn;
  KeyValNode *kvn;
  StringNode *svn;
  mn = FindNode(pNode, "pid");
  if(mn->nodeType() == 2){
    kvn = (KeyValNode *) mn;
    svn = (StringNode*) kvn->value();
    //printf("Bom: %s\n", svn->value());
    buildItem(svn->value(),(KeyValNode*) pNode);
  }
  mList->append(pNode);
}

void BomKeyNode::buildItem(const char *pId, KeyValNode *pKvn){
  char op[4096];
  BomItem *tmp;
  char args[10];
  KeyValNode *kvn;
  StringNode *svn;
  int c;
  tmp = (BomItem *)malloc(sizeof(BomItem));
  tmp->refChar = pKvn->key()[0];
  tmp->node = pKvn;
  if(tmp->refChar >= 'a' && tmp->refChar <= 'z'){
    tmp->refChar = (tmp->refChar - 'a') + 'A';
  }
  tmp->block = new TextBlock(gVxm.parts->getPart(pId));
  mCount++;
  tmp->idNum = refCount(tmp->refChar);
  if(tmp->block == NULL){
    printf("block not found for %s\n", pId);
    return;
  }

  sprintf(args, "%c%d%02d", tmp->refChar, mMajor, tmp->idNum);
  tmp->block->setArg(args, 1);
  for(c = 2; c <= tmp->block->argCount(); c++){
    sprintf(args,"*arg%d", c);
    kvn = (KeyValNode*)FindNode(pKvn, args);
    svn = (StringNode*) kvn->value();
    tmp->block->setArg(svn->value(), c);
  }
  tmp->next = mHead;
  mHead = tmp;
  tmp->block->buildBlock(op);
  printf("%s\n", op);
}

void BomKeyNode::setMajor(int pMajor){
  mMajor = pMajor;
}

int BomKeyNode::count(){
  return mCount;
}

int BomKeyNode::refCount(char pRef){
  BomItem *tmp;
  int cnt;
  tmp = mHead;
  cnt = 0;
  while(tmp != NULL){
    if(tmp->refChar == pRef) cnt++;
    tmp = tmp->next;
  }
  cnt++;
  return cnt;
}

void BomKeyNode::printRef(MapNode *pNode, const char *tag){
  BomItem *tmp;
  tmp = mHead;
  while(tmp != NULL){
    if(AcontainsB(tmp->node, pNode) == 1){
      //printf("REF: %c%d%02d\n", tmp->refChar, mMajor, tmp->idNum);      
      printf("%c%d%02d-%s ", tmp->refChar, mMajor, tmp->idNum,tag);      
      return;
    }
    tmp = tmp->next;
  }
}
