#ifndef DSL_INTERFACE_H
#define DSL_INTERFACE_H

#include <malloc.h>
#include "Vxm.h"
#include "MapNode.h"
#include "MapList.h"
#include "ListNode.h"
#include "LeafNode.h"
#include "KeyValNode.h"
#include "StringNode.h"
#include "CommandBase.h"
#include "TreeUtilities.h"
#include "VxmUtilities.h"
#include "Modifier.h"

MapNode *getNode(const char *pName);
ListNode *getList(MapNode *pNode);
ListNode *emptyList();
KeyValNode *getKeyVal(const char *pName, MapNode *pNode);
StringNode *getStringNode(const char *pStr);
void closeActive(MapNode *pNode);
void pushIdentifier(const char *pName);
MapNode *getIdentifier(const char *pName, int pDeref);
void pushTable();
int isActive(MapNode *pNode);
MapNode* popTable(MapNode *pNode);
Modifier *getMod(argMod pMod, const char *pStr);
void freeMod(Modifier *pMod);
MapNode* autoName(MapNode *pNode);

#endif
