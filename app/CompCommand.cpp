#include "CompCommand.h"

CompCommand::CompCommand(CompType pComp){
  mRoot = NULL;
  mType = pComp;
  mList = NULL;
}

void CompCommand::addNode(Modifier *pMod, MapNode *pNode){
  LeafNode *lf;
  KeyValNode *kvn;
  if(pMod->mod == MOD_NONE){
    if(mRoot != NULL){
      printf("Cannot reset root\n");
    }else{
      mRoot = pNode;
    }
    return;
  }
  if(pMod->mod == MOD_STRING){
    if(strcmp(pMod->modStr, "value") == 0){
      kvn = getKeyVal("*arg2", pNode);
    }else{
      kvn = getKeyVal(pMod->modStr, pNode);
    }
  }else if(pMod->mod == MOD_PLUS){
    if(pNode->nodeType() == 1){
      lf = (LeafNode*) pNode;
      sprintf(mId, "STD%s", lf->value());
      kvn = getKeyVal("pid", getStringNode(mId));
      //      printf("std value: %s\n", mId);
    }
  }
  if(mList == NULL){
    mList = getList(kvn);
  }else{
    mList->append(kvn);
  }

}

MapNode *CompCommand::close(){
  mList->append(mRoot);
  return mList;
}


CommandBase *newResCommand(){
  return new CompCommand(RESISTOR);
}

CommandBase *newCapCommand(){
  return new CompCommand(CAPACITOR);
}


CMD_NODE(res,newResCommand);
CMD_NODE(cap,newCapCommand);
