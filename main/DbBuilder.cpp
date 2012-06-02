#include <stdio.h>
#include <malloc.h>
#include "Vxm.h"
#include "DbFile.h"
#include "../app/PcbProcess.h"

extern int yyparse();
extern FILE *yyin;


int main(int argc, char **argv){
  FILE *f;
  f = fopen(argv[1], "r");
  gVxm.symbols = new SymbolTable();
  gVxm.select = new StrQueue();
  gVxm.hiddenIdNum = 0;
  gVxm.cmdNodes = new NodeModule();
  yyin = f;
  yyparse();
  return 0;
}
