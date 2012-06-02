#include <stdio.h>
#include "StdPackages.h"
#include "BaseChip.h"
#include "PatternDb.h"
#include "DbFile.h"
#include "TextBlock.h"
#include "DbFile.h"
#include "Vxm.h"

int main(int argc, char **argv){
  char output[0xffff];
  PatternDb *db;
  DbFile *df;
  TextBlock *tmp;
  TextBlock *hdr;
  TextBlock *ftr;
  
  if(argc != 2){
    printf("Usage: \n");
    printf("FootPrint <unq>\n");
    return 0;
  }

  db = new PatternDb();
  df = new DbFile("./data/part.db");
  
  gVxm.parts = df->buildPartMap();
  hdr = gVxm.parts->getPart("HEAD");
  ftr = gVxm.parts->getPart("TAIL");
  
  tmp = db->getBlockUnique(argv[1], "AG1");
  
  if(tmp == NULL) return 0;
  tmp->setArg("U1", 1);
  
  hdr->buildBlock(output);
  printf("%s\n", output);
  tmp->buildBlock(output);
  printf("%s\n", output);
  ftr->buildBlock(output);
  printf("%s\n", output);
  
}
