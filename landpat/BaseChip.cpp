#include "BaseChip.h"

BaseChip::BaseChip(){

}

TextBlock *BaseChip::getChipUnique(const char *pPart){
  return localBuild(pPart, 0);
}

TextBlock *BaseChip::getChipByRpl(const char *pRpl, const char *pPart){
  int i;
  if(mRplMap.find(string(pRpl)) == mRplMap.end()){
    return NULL;
  }
  i = mRplMap[string(pRpl)];
  return localBuild(pPart, i);
}

TextBlock *BaseChip::getChipByCid(const char *pCid, const char *pPart){
  int i;
  if(mCidMap.find(string(pCid)) == mCidMap.end()){
    return NULL;
  }
  i = mCidMap[string(pCid)];
  return localBuild(pPart, i);
}


TextBlock *BaseChip::localBuild(const char *pPart, int pId){
  char *tmp;
  DbEntry *db;
  TextBlock *tb;
  db = (DbEntry*) malloc(sizeof(DbEntry));
  tmp = buildChip(pId);
  strcpy(db->uid, pPart);
  db->args = 0;
  db->len = strlen(tmp);
  tb = new TextBlock(db, tmp);
  return tb;
}


void BaseChip::registerLayout(const char *pRpl, const char *pCid, int pId){
  mRplMap[string(pRpl)] = pId;
  mCidMap[string(pCid)] = pId;
}
