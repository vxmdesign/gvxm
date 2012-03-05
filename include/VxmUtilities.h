#ifndef VXM_UTILITIES_H
#define VXM_UTILITIES_H


#include "Vxm.h"
#include "LeafNode.h"
#include "KeyValNode.h"
#include "ListNode.h"
#include "StringNode.h"

void printNode(MapNode *pNode, int ptidx);
int isActive(MapNode *pNode);
void stripQuotes(const char *pSrc, char *pDst);
void getHiddenId(char *pId);


#endif

