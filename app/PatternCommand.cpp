#include "PatternCommand.h"

PatternCommand::PatternCommand(){
  mLandPat = new PatternDb();
  mDb = new DbFile();
}

void PatternCommand::addNode(Modifier *pMod, MapNode *pNode){
  KeyValNode *kvn;
  StringNode *sn;
  char *fin;
  TextBlock *tmp;

  if(pNode->nodeType() != 2) return;
  kvn = (KeyValNode *) pNode;
  if(kvn->value()->nodeType() != 4) return;
  sn = (StringNode *) kvn->value();

  switch(pMod->mod){
  case MOD_MINUS:
    printf("Part is unique: %s\n", kvn->key());
    tmp = mLandPat->getBlockUnique(kvn->key(), sn->value());
    break;
  case MOD_PLUS:
    printf("Part %s: From File: %s\n", kvn->key(), sn->value());
    fin = fileLoader(sn->value());
    tmp = new TextBlock(kvn->key(), fin);
    break;
  case MOD_STRING:
    printf("Part %s: By Cid: %s Class: %s\n", kvn->key(), sn->value(), pMod->modStr);
    tmp = mLandPat->getBlockByCid(pMod->modStr, sn->value(), kvn->key());
    break;
  default:
    printf("Part %s: From Rpl (default): %s\n", kvn->key(), sn->value());
    tmp = mLandPat->getBlockByRpl(sn->value(), kvn->key());
    break;
  }
  if(tmp != NULL){
    mDb->addBlock(tmp);
  }
}


MapNode *PatternCommand::close(){
  mDb->saveDb("./data/part.db");
  return new LeafNode("test");

}

CommandBase *newPatternCommand(){
  return new PatternCommand();
}

CMD_NODE(lands,newPatternCommand);
