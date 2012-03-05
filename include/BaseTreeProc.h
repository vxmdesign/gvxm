#ifndef BASE_TREE_PROC_H
#define BASE_TREE_PROC_H


#include "LeafNode.h"
#include "ListNode.h"
#include "KeyValNode.h"
#include "StringNode.h"




class BaseTreeProc{
 public:
  virtual void process(LeafNode *pNode);
  virtual void process(ListNode *pNode);
  virtual void process(KeyValNode *pNode);
  virtual void process(StringNode *pNode);
  virtual void process(MapList *pNode);
};


#endif
