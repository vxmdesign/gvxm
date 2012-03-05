#include "ListNode.h"

ListNode::ListNode(){
  mList = new MapList();
  mDirty = 0;
}

ListNode::ListNode(MapNode *pNode){
  pNode->setParent(this);
  mList = new MapList(pNode);
}

int ListNode::nodeType(){
  return 3;
}

int ListNode::nodeException(){
  int c;
  int r;
  for(c = 0; c < mList->count(); c++){
    if((r = mList->getNode(c)->nodeException())!=0)return r;
  }
  return 0;
}

void ListNode::append(MapNode *pNode){

  pNode->setParent(this);
  mList->append(pNode);
}

int ListNode::count(){
  return mList->count();
}

MapNode *ListNode::getNode(int pIndex){
  //  if(mDirty == 1) printf("Warning!\n Dirty List\n");
  return mList->getNode(pIndex);
}

MapNode *ListNode::getNode(const char *pName){
  return mList->getNode(pName);
}

int ListNode::compare(const char *pName){
  return -1;
}

void ListNode::remove(MapNode *pNode){
  mList->remove(pNode);
}

void ListNode::invNode(MapNode *pNode){
  mList->invNode(pNode);
  mDirty = 1;
}

void ListNode::cleanup(){
  mList->cleanup();
  mDirty = 0;
}
