#ifndef NETLIST_COMMAND_H
#define NETLIST_COMMAND_H

#include "CommandBase.h"
#include "NodeModule.h"
#include "MapList.h"
#include "ListNode.h"
#include "DslInterface.h"
#include "BomKeyNode.h"
#include "NetLeafProc.h"


class NetListCommand: public CommandBase{
 public:
  NetListCommand();
  void addNode(Modifier *pMod, MapNode *pNode);
  MapNode *close();
 private:
  BomKeyNode *mBkn;
};

CommandBase *newNetListCommand();


#endif
