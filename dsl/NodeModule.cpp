#include "NodeModule.h"

NodeModule::NodeModule(){
  int *d1;
  int *d2;
  
  d1 = &__start_cmdnode;
  d2 = &__stop_cmdnode;
  mCmd = (cmd_table*)d1;
  mCmdCount = ((d2-d1) * 4)/sizeof(cmd_table);
  
}

CommandBase *NodeModule::buildCmd(const char *pName){
  int c;
  for(c = 0; c < mCmdCount; c++){
    if(strcmp(pName, mCmd[c].cmdname) == 0){
      return mCmd[c].call();
    }
  }
  return NULL;
}
