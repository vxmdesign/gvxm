#ifndef SELECT_COMMAND_H
#define SELECT_COMMAND_H

#include "CommandBase.h"
#include "NodeModule.h"
#include "ListNode.h"
#include "TreeMarkProc.h"
#include "TrimProc.h"

#include "VxmUtilities.h"
#include "TreeUtilities.h"

class SelectCommand: public CommandBase{
 public:
  SelectCommand();
  void addNode(Modifier *pMod, MapNode *pNode);
  MapNode *close();
};

CommandBase *newSelectCommand();


#endif
