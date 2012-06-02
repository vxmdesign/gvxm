#ifndef VXM_UTILITIES_H
#define VXM_UTILITIES_H

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <malloc.h>
#include "Vxm.h"
#include "LeafNode.h"
#include "KeyValNode.h"
#include "ListNode.h"
#include "StringNode.h"


void printNode(MapNode *pNode, int ptidx);
int isActive(MapNode *pNode);
void stripQuotes(const char *pSrc, char *pDst);
void getHiddenId(char *pId);
char *fileLoader(const char *pFilename);

#endif

