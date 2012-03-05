#ifndef COMMAND_BASE_H
#define COMMAND_BASE_H

#include "MapNode.h"
#include "ListNode.h"
#include "Modifier.h"


class CommandBase{
 public:
  void process(Modifier *pMod, MapNode *pNode);
  virtual MapNode *close()=0;
 private:
  virtual void addNode(Modifier *pMod, MapNode *pNode)=0;
};

#endif
