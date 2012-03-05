#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include "DbEntry.h"
#include "TextBlock.h"
#include "DbFile.h"

int main(int argc, char **argv){
  char buffer[0xFFFF];
  int c;
  int len;
  DbFile *dbf;
  DbEntry *dbe;
  TextBlock *tb;
  c = 0;
  if(argc != 3){
    printf("Invalid args\n");
    return -1;
    
  }
  dbf = new DbFile(argv[1]);
  dbe = (DbEntry *) malloc(sizeof(DbEntry));
  strcpy(dbe->uid, argv[2]);
  
  while(fgets(&(buffer[c]), sizeof(buffer), stdin) != NULL){
    c= strlen(buffer);
  }
  len = c;
  dbe->len = c;
  dbe->args = 0;
  for(c = 0; c < len; c++){
    if(buffer[c] == '$') dbe->args++; 
  }
  //  printf("Input: \n%s\n", buffer);
  tb = new TextBlock(dbe, buffer);
  dbf->addBlock(tb);
  dbf->saveDb(argv[1]);
  return 0;
}
