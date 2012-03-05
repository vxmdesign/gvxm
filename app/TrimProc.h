#ifndef TRIM_PROC_H
#define TRIM_PROC_H

#include "BaseTreeProc.h"
#include "ListNode.h"


class TrimProc: public BaseTreeProc{
 public:
  TrimProc(MapNode *pRoot);
  void process(MapList *pList);
 private: 
  MapNode *mRoot;
};


#endif
