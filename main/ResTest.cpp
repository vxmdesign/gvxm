#include <stdio.h>
#include "StdPackages.h"
#include "ResChip.h"
#include "TextBlock.h"
#include "DbFile.h"
#include "Vxm.h"

int main(){
  ResChip *rc;
  TextBlock *tmp;
  TextBlock *hdr, *ftr;
  TextBlock *std;
  DbFile *db;
  char output[4096];
  rc = new ResChip(res_table, 7);
  tmp = rc->getChipByRpl("102A", "A123");
  tmp->setArg("R1", 1);
  tmp->setArg("25K", 2);
  
  //printf("%s\n", output);
  db = new DbFile("../data/part.db");
  gVxm.parts = db->buildPartMap();
  hdr = gVxm.parts->getPart("HEAD");
  ftr = gVxm.parts->getPart("TAIL");
  std = gVxm.parts->getPart("STD0805");
  std->setArg("R2", 1);
  std->setArg("25K", 2);
  hdr->buildBlock(output);
  printf("%s\n", output);
  tmp->buildBlock(output);
  printf("%s\n", output);
  std->buildBlock(output);
  printf("%s\n", output);
  ftr->buildBlock(output);
  printf("%s\n", output);
}
