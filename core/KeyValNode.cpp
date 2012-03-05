#include "KeyValNode.h"

KeyValNode::KeyValNode(const char *pName, MapNode *pNode){
  if(strlen(pName) >= 32){
    setException(1);
    mName[0] = '\0';
    mNode = NULL;
    return;
  }
  strcpy(mName, pName);
  mNode = pNode;
  pNode->setParent(this);
}

int KeyValNode::nodeType(){
  return 2;
}

int KeyValNode::nodeException(){
  int r;
  if((r = inException()) != 0){
    return r;
  }
  return mNode->inException();
}

int KeyValNode::compare(const char *pName){
  return strcmp(pName,mName);
}

const char * KeyValNode::key(){
  return mName;
}

MapNode *KeyValNode::value(){
  return mNode;
}

MapNode *KeyValNode::resetValue(MapNode *pNode){
  MapNode *r;
  r = mNode;
  mNode = pNode;
  return r;
}
