#ifndef BOM_COMMAND_H
#define BOM_COMMAND_H

#include<stdlib.h>
#include "CommandBase.h"
#include "NodeModule.h"
#include "KeyValNode.h"
#include "StringNode.h"
#include "TextBlock.h"
#include "ListNode.h"
#include "DslInterface.h"
#include "Vxm.h"
#include "BomKeyNode.h"
#include "TreeUtilities.h"

class BomCommand: public CommandBase{
 public:
  BomCommand();
  void addNode(Modifier *pMod, MapNode *pNode);
  MapNode *close();
 private:
  BomKeyNode *mBkn;
};

CommandBase *newBomCommand();


#endif
