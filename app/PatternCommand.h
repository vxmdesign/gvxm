#ifndef PATTERN_COMMAND_H
#define PATTERN_COMMAND_H

#include "CommandBase.h"
#include "NodeModule.h"
#include "ListNode.h"
#include "KeyValNode.h"
#include "StringNode.h"
#include "DbFile.h"
#include "PatternDb.h"
#include "VxmUtilities.h"


class PatternCommand: public CommandBase{
 public:
  PatternCommand();
  void addNode(Modifier *pMod, MapNode *pNode);
  MapNode *close();
 private:
  DbFile *mDb;
  PatternDb *mLandPat;
};

CommandBase *newPatternCommand();


#endif
