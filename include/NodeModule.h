#ifndef NODE_MODULE_H
#define NODE_MODULE_H

#include <string.h>
#include "MapNode.h"
#include "CommandBase.h"


#define CMD_NODE_STRUCT __attribute__ ((unused,section("cmdnode")))

typedef CommandBase* (*cmdfunc)(void);

typedef struct{
  const char *cmdname;
  cmdfunc call;
}cmd_table;

extern int __start_cmdnode;
extern int __stop_cmdnode;

#define CMD_NODE(name,function) cmd_table __cmd_table_##name CMD_NODE_STRUCT = { #name,function }

class NodeModule{
 public:
  NodeModule();
  CommandBase *buildCmd(const char *pName);
 private:
  cmd_table *mCmd;
  int mCmdCount;
};


#endif
