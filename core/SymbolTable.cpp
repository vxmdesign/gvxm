#include "SymbolTable.h"

SymbolTable::SymbolTable(){

}

SymbolData *SymbolTable::newSymbol(KeyValNode *pKeyVal, MapList *pList){
  SymbolData *sd;
  sd = (SymbolData*) malloc(sizeof(SymbolData));
  sd->slist = pList;
  sd->snode = pKeyVal;
  mSymbols[pKeyVal->key()] = sd;
  return sd;
}

SymbolData *SymbolTable::newSymbol(){
  SymbolData *sd;
  sd = (SymbolData*) malloc(sizeof(SymbolData));
  sd->slist = new MapList();
  return sd;
}


void SymbolTable::addSymbol(SymbolData *pSd){
  KeyValNode *kv;
  kv = (KeyValNode*)pSd->snode;
  mSymbols[kv->key()] = pSd;
}

MapNode *SymbolTable::getNode(const char *pName){
  SymbolData *sd;
  sd = mSymbols[pName];
  if(sd == NULL) return NULL;
  return sd->snode;
}

MapList *SymbolTable::getList(const char *pName){
  SymbolData *sd;
  sd = mSymbols[pName];
  if(sd == NULL) return NULL;
  return sd->slist;
}

SymbolData *SymbolTable::getInfo(const char *pName){
  return mSymbols[pName];
}
