#include "DumbCommand.h"

DumbCommand::DumbCommand(){
  mList = new ListNode();
}

void DumbCommand::addNode(Modifier *pMod, MapNode *pNode){
  printf("Dumb node append\n");

  mList->append(pNode);
}

MapNode *DumbCommand::close(){
  printf("Dumb node close\n");
  return mList;
}


CommandBase *newDumbCommand(){
  return new DumbCommand();
}

CMD_NODE(dumb,newDumbCommand);
