#include "MapNode.h"


void MapNode::setException(int pEx){
  mException = pEx;
  mParent = NULL;
}

int MapNode::inException(){
  return mException;
}


MapNode *MapNode::getParent(){
  return mParent;
}

void MapNode::setParent(MapNode *pNode){
  mParent = pNode;
}

void MapNode::setMark(int pMark){
  mMark = pMark;
}

int MapNode::getMark(){
  return mMark;
}

