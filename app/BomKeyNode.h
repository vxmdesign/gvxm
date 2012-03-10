#ifndef BOM_KEY_NODE_H
#define BOM_KEY_NODE_H


#include <malloc.h>
#include "Vxm.h"
#include "DslInterface.h"
#include "KeyValNode.h"
#include "TreeUtilities.h"
#include "AppUtilities.h"

typedef struct BOM_ITEM{
  char refChar;
  TextBlock *block;
  int idNum;
  MapNode *node;
  struct BOM_ITEM *next;
}BomItem;

class BomKeyNode: public KeyValNode{
 public:
  BomKeyNode();
  void addComponent(MapNode *pNode);
  void setMajor(int pMajor);
  int count();
  const char* printRef(MapNode *pNode);
  void fprintPcb(FILE *pFout);

 private:
  void buildItem(const char *pId, KeyValNode *pKvn);
  int refCount(char pRef);
  ListNode *mList;
  BomItem *mHead;
  int mMajor;
  int mCount;
  char mTmpRef[32];
};

#endif
