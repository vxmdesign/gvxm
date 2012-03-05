#ifndef COMP_COMMAND_H
#define COMP_COMMAND_H

#include "CommandBase.h"
#include "NodeModule.h"
#include "StringNode.h"
#include "ListNode.h"
#include "DslInterface.h"

enum CompType { RESISTOR, CAPACITOR};

class CompCommand: public CommandBase{
 public:
  CompCommand(CompType pComp);
  void addNode(Modifier *pMod, MapNode *pNode);
  MapNode *close();
 private:
  ListNode *mList;
  MapNode *mRoot;
  char mId[32];
  CompType mType;
};

CommandBase *newResCommand();
CommandBase *newCapCommand();


#endif
