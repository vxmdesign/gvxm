#ifndef TREE_UTILITIES_H
#define TREE_UTILITIES_H


#include "Vxm.h"
#include "DslInterface.h"
#include "BaseTreeProc.h"

MapNode* TreeClone(MapNode *pNode);
void ProcTree(BaseTreeProc *pBtp, MapNode *pNode);
void RemoveFromList(MapNode *pNode);
void TraceTree(BaseTreeProc *pBtp, MapNode *pNode);
MapNode* FindNode(MapNode *pNode, const char *pArg);
void RegisterNode(MapNode *pNode);



#endif
