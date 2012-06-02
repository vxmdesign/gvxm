#include <stdio.h>
#include "StdPackages.h"
#include "QfpChip.h"
#include "TextBlock.h"
#include "DbFile.h"
#include "Vxm.h"

int main(int argc, char **argv){
  QfpChip *rc;
  TextBlock *tmp;
  TextBlock *hdr, *ftr;
  DbFile *db;
  char output[60000];
  rc = new QfpChip(qfp_table, 90);
  if(argc == 1){
    tmp = rc->getChipByRpl("555A", "A123");
  }else{
    tmp = rc->getChipByRpl(argv[1], "A123");
  }
  tmp->setArg("U1", 1);
  
  //printf("%s\n", output);
  db = new DbFile("../data/part.db");
  gVxm.parts = db->buildPartMap();
  hdr = gVxm.parts->getPart("HEAD");
  ftr = gVxm.parts->getPart("TAIL");
  hdr->buildBlock(output);
  printf("%s\n", output);
  tmp->buildBlock(output);
  printf("%s\n", output);
  ftr->buildBlock(output);
  printf("%s\n", output);
}
