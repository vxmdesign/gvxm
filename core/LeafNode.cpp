#include "LeafNode.h"

LeafNode::LeafNode(const char *pName){
  if(strlen(pName) >= 32){
    setException(1);
    mName[0]='\0';
    return;
  }
  strcpy(mName,pName);
}


int LeafNode::nodeType(){
  return 1;
}

int LeafNode::nodeException(){
  return inException();
}


const char *LeafNode::value(){
  return mName;
}

int LeafNode::compare(LeafNode *pLn){
  return strcmp(pLn->mName, mName);
}


int LeafNode::compare(const char *pName){
  return strcmp(pName,mName);

}
