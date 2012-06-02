#include <stdio.h>
#include "StdPackages.h"
#include "SoicChip.h"
#include "TextBlock.h"
#include "DbFile.h"
#include "Vxm.h"

int main(){
  SoicChip *rc;
  TextBlock *tmp;
  TextBlock *hdr, *ftr;
  DbFile *db;
  char output[4096];
  rc = new SoicChip(soic_table, 15);
  tmp = rc->getChipByRpl("303A", "A123");
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
