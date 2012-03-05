#include "StringNode.h"

StringNode::StringNode(const char *pStr){
  if(strlen(pStr) >= 128){
    setException(1);
    mStr[0]='\0';
    return;
  }
  
  stripQuotes(pStr, mStr);

}


int StringNode::nodeType(){
  return 4;
}

int StringNode::nodeException(){
  return inException();
}


const char *StringNode::value(){
  return mStr;
}

int StringNode::compare(const char *pName){
  return -1;
}
