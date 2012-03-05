#include "SelectCommand.h"

SelectCommand::SelectCommand(){
  
}

void SelectCommand::addNode(Modifier *pMod, MapNode *pNode){
  TreeMarkProc *tm;
  TrimProc *tp;
  MapNode *tmp;
  tm = new TreeMarkProc(pNode);
  tm->Mark();

  //ProcTree(tm, pNode);
  
  //  printf("Setting pins\n");
  //  printNode(lp->getList(), 0);
  tmp = pNode;

  while(tmp != NULL && tmp->nodeType() != 3){
    tmp = tmp->getParent();
  }
  if(tmp != NULL){
    tp = new TrimProc(pNode);
    TraceTree(tp, tmp);
    //    printNode(tmp, 0);
    delete tp;
  }

  tm->UnMark();
  delete tm;
}

MapNode *SelectCommand::close(){
  return new LeafNode("test");

}

CommandBase *newSelectCommand(){
  return new SelectCommand();
}

CMD_NODE(select,newSelectCommand);
