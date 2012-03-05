#include "NetLeafProc.h"

NetLeafProc::NetLeafProc(ListNode *pList, NetLeafOper pNfo){
  mList = pList;
  mNfo = pNfo;
  if(mNfo == TAG_ONE) mPinCount = 1;
  mMapped = 0;
}

void NetLeafProc::process(LeafNode *pNode){
  if(mNfo == TAG_ONE && mPinCount == 0) return;
  if(pNode->getMark() != 1){ 
    pNode->setMark(1);
    mMapped++;
    mList->append(pNode);
    if(mNfo == TAG_ONE) mPinCount--;
  } 
}

void NetLeafProc::setMapCount(int pCnt){
  mPinCount = pCnt;
}


int NetLeafProc::mapped(){
  return mMapped;
}

int NetLeafProc::valid(){
  if(mNfo == TAG_ONE && mPinCount != 0) return 0;
  return 1;
}

