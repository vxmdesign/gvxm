#include <stdio.h>
#include <string.h>
#include "StdPackages.h"
#include "TextBlock.h"
#include "DbFile.h"
#include "Vxm.h"

int main(){
  TextBlock  *ftr;
  DbFile *db;
  char output[4096];
  int i;
  int c;
  //printf("%s\n", output);
  db = new DbFile("../data/part.db");
  gVxm.parts = db->buildPartMap();
  ftr = gVxm.parts->getPart("TAIL");
  ftr->buildBlock(output);
  i = strlen(output);
  i = i - 4;
  for(c = 0; c < 5; c++){
    printf("%d: %c\n", output[i + c], output[i + c]);
  }
  //printf("%s\n", output);
}
