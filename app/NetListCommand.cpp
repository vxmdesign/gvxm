#include "NetListCommand.h"

NetListCommand::NetListCommand(){
  MapList *ml;
  MapNode *mn;
  ml = VXM_ACTIVE_LIST;
  if(ml == NULL){
    printf("No active List!\n"); 
    return;
  }
  mn = getNode("bom");
  if(mn == NULL){
    printf("Could not find BOM\n");
    return;
  }
  mBkn = dynamic_cast<BomKeyNode*>(mn);
  if(mBkn == NULL){
    printf("Not correct type\n");
    return;
  }
  mList = emptyList();
  //  printf("Netlist called\n");

}

void NetListCommand::addNode(Modifier *pMod, MapNode *pNode){
  MapNode *mn;
  ListNode *ln;
  ListNode *nlst;
  int c;
  NetLeafProc *nlp;
  //  LeafNode *tmp;
  if(mBkn == NULL){
    printf("Invalid. No bom\n");
    return;
  }
  if(pNode->nodeType() != 2){
    printf("Not a keyval, no net name\n");
    return;
  }
  mn = GET_KEY_VALUE(pNode);

  if(mn->nodeType() == 3){
    ln = (ListNode*)mn;
    nlst = emptyList();
    if(pMod->mod == MOD_MINUS){
      nlp = new NetLeafProc(nlst, TAG_ONE);
    }else{
      nlp = new NetLeafProc(nlst, TAG_ALL);
    }
    for(c = 0; c < ln->count(); c++){
      nlp->setMapCount(1);
      ProcTree(nlp, ln->getNode(c));
      if(nlp->valid() != 1){
	printf("Unable to map netlist\n");
	return;
      }
    }
  }
  ((KeyValNode*)pNode)->resetValue(nlst);
  mList->append(pNode);
  //  printf("%s: ", ((KeyValNode*)pNode)->key());
  //for(c = 0; c < nlst->count(); c++){
  //  tmp = (LeafNode *) nlst->getNode(c);
  //  mBkn->printRef(tmp, tmp->value());
  //}
  //printf("\n");
}

MapNode *NetListCommand::close(){
  KeyValNode *kvn;
  kvn = getKeyVal("netlist", mList);
  mList->append(kvn);
  return mList;
}


CommandBase *newNetListCommand(){
  return new NetListCommand();
}

CMD_NODE(netlist,newNetListCommand);
