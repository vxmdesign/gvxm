#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

#include <map>
#include <string>
#include <malloc.h>
#include "MapNode.h"
#include "MapList.h"
#include "KeyValNode.h"

using namespace std;


typedef struct{
  MapList *slist;
  MapNode *snode;
}SymbolData;

class SymbolTable{
 public:
  SymbolTable();
  SymbolData *newSymbol(KeyValNode *pKeyVal, MapList *pList);
  SymbolData *newSymbol();
  void addSymbol(SymbolData *pSd);
  MapNode *getNode(const char *pName);
  MapList *getList(const char *pName);
  SymbolData *getInfo(const char *pName);
 private:
  map<string,SymbolData*> mSymbols;
};

#endif
