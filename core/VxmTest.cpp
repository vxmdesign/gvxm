#include <stdio.h>
#include <malloc.h>
#include "Vxm.h"
#include "DbFile.h"
extern int yyparse();
extern FILE *yyin;

VxmInfo gVxm;

int main(int argc, char **argv){
  FILE *f;
  DbFile *db;

  f = fopen(argv[1], "r");
  //  gManager = new NodeManager();
  gVxm.symbols = new SymbolTable();
  gVxm.select = new StrQueue();
  //gVxm.tableStack = 

  gVxm.hiddenIdNum = 0;
  gVxm.cmdNodes = new NodeModule();
  db = new DbFile("./data/part.db");
  gVxm.parts = db->buildPartMap();
  yyin = f;
  yyparse();
  return 0;
}
