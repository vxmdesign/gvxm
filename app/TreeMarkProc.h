#ifndef TREE_MARK_PROC_H
#define TREE_MARK_PROC_H

#include "MapList.h"
#include "BaseTreeProc.h"
#include "TreeUtilities.h"

class TreeMarkProc: public BaseTreeProc{
 public:
  TreeMarkProc(MapNode *pRoot);
  void Mark();
  void UnMark();
  void process(LeafNode *pNode);
  void process(StringNode *pNode);
  void process(ListNode *pNode);
  void process(KeyValNode *pNode);
 private:
  MapNode *mRoot;
  int mMarkState;
};

#define MARK_VAL(x) ((mMarkState == 1)?(x):0)

#endif
