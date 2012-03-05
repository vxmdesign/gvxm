#ifndef DUMB_COMMAND_H
#define DUMB_COMMAND_H

#include "CommandBase.h"
#include "NodeModule.h"

#include "ListNode.h"


class DumbCommand: public CommandBase{
 public:
  DumbCommand();
  void addNode(Modifier *pMod, MapNode *pNode);
  MapNode *close();
 private:
  ListNode *mList;
};

CommandBase *newDumbCommand();


#endif
