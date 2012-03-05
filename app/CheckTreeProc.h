#ifndef CHECK_TREE_PROC_H
#define CHECK_TREE_PROC_H

#include "MapList.h"
#include "BaseTreeProc.h"
#include "TreeUtilities.h"

class CheckTreeProc: public BaseTreeProc{
 public:
  CheckTreeProc(MapNode *pRoot);
  void process(LeafNode *pNode);
  void process(StringNode *pNode);
  void process(ListNode *pNode);
  void process(KeyValNode *pNode);
  int contains();
 private:
  MapNode *mNode;
  int mFound;
};



#endif
