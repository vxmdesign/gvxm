#ifndef VXM_H
#define VXM_H


#include "MapNode.h"
#include "MapList.h"
#include "SymbolTable.h"
#include "StrQueue.h"
#include "NodeModule.h"
#include "Modifier.h"
#include "PartMap.h"
#include <malloc.h>
#include <stack>

//#include "SymStack.h"

using namespace std;

typedef struct{
  SymbolTable *symbols;
  SymbolData *activeData;
  MapNode *activeNode;
  StrQueue *select;
  int hiddenIdNum;
  //  SymStack *tableStack;
  stack<SymbolData*> tableStack;
  stack<CommandBase*> cmdStack;
  map<MapNode*,SymbolData*> lkupTable;

  NodeModule *cmdNodes;
  PartMap *parts;
}VxmInfo;

#define VXM_ACTIVE      gVxm.activeData
#define VXM_ACTIVE_CHK  (gVxm.activeData != NULL)
#define ACTIVE_LIST_US  (gVxm.activeData->slist)
#define ACTIVE_NODE_US  (gVxm.activeData->snode)
#define VXM_ACTIVE_NODE (VXM_ACTIVE_CHK?ACTIVE_NODE_US:NULL)
#define VXM_ACTIVE_LIST (VXM_ACTIVE_CHK?ACTIVE_LIST_US:NULL)
#define SETUP_ACTIVE    (VXM_ACTIVE_CHK?NULL:(VXM_ACTIVE=gVxm.symbols->newSymbol()))

#define PUSH_TABLE      do{gVxm.tableStack.push(VXM_ACTIVE);VXM_ACTIVE=gVxm.symbols->newSymbol();}while(0)
#define POP_TABLE       do{VXM_ACTIVE=gVxm.tableStack.top();gVxm.tableStack.pop();}while(0)

#define PUSH_CMD(x)     gVxm.cmdStack.push(gVxm.cmdNodes->buildCmd((x)))
#define ACTIVE_CMD      gVxm.cmdStack.top()
#define POP_CMD         gVxm.cmdStack.pop()

#define ADD_LOOKUP(x)   (gVxm.lkupTable[(x)] = gVxm.activeData)
#define SYMBOLDATA(x)   (gVxm.lkupTable[(x)])

#define IS_NODE_ACTIVE(x)      (gVxm.activeData != NULL && gVxm.activeData->slist->contains(x) == 1)

#define GET_SYMBOL(x)          (gVxm.symbols->getNode(x))
#define GET_TOP_SYMBOL         (GET_SYMBOL(gVxm.select->top()))
#define SET_VXM_ACTIVE_NODE(x) (VXM_ACTIVE_CHK?(gVxm.activeData->snode=x):NULL)

#define GET_KEY_VALUE(x)       (((KeyValNode*)(x))->value())

extern VxmInfo gVxm;

#endif
