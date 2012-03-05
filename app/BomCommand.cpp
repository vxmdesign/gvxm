#include "BomCommand.h"

BomCommand::BomCommand(){
  mBkn = new BomKeyNode();
}


void BomCommand::addNode(Modifier *pMod, MapNode *pNode){
  //  printf("Dumb node append\n");
  KeyValNode *kvn;
  KeyValNode *k2;
  
  MapNode *mn;
  char lname[10];
  int i;
  int c;
  if(pNode->nodeType() != 2){
    printf("None Keyval bomb invalid\n");
    return;
  }
  mBkn->addComponent(pNode);
  if(pMod->mod == MOD_STRING){
    i = atoi(pMod->modStr);
    if(i < 2){
      printf("Invalid Modifier\n");
      return;
    }
    kvn = (KeyValNode*)pNode;
    for(c = 0; c < i - 1; c++){
      pushTable();
      mn = TreeClone(kvn->value());
      mn = popTable(mn);
      sprintf(lname, "%s_%d", kvn->key(),c + 2);
      k2 = getKeyVal(lname, mn);
      mBkn->addComponent(pNode);
    }
  }
}

MapNode *BomCommand::close(){
  //printf("Dumb node close\n");
  //KeyValNode *kvn;
  //kvn = getKeyVal("bom", mList);
  //  printNode(kvn, 0);
  RegisterNode(mBkn);
  return mBkn;
}


CommandBase *newBomCommand(){
  return new BomCommand();
}

CMD_NODE(bom,newBomCommand);
