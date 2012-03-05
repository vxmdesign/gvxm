#ifndef NET_LEAF_PROC_H
#define NET_LEAF_PROC_H

#include "MapList.h"
#include "BaseTreeProc.h"
#include "TreeUtilities.h"

enum NetLeafOper { TAG_ONE, TAG_ALL };

class NetLeafProc: public BaseTreeProc{
 public:
  NetLeafProc(ListNode *pList, NetLeafOper pNfo);
  void process(LeafNode *pNode);
  void setMapCount(int pCnt);
  int mapped();
  int valid();
 private:
  ListNode *mList;
  NetLeafOper mNfo;
  int mPinCount;
  int mMapped;
};



#endif
