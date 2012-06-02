#ifndef TEXT_BLOCK_H
#define TEXT_BLOCK_H

#include <stdio.h>
#include <string.h>
#include <malloc.h>

#include "DbEntry.h"

typedef struct{
  char *blk;
  char arg[16];
  int argnum;
}segblk;

class TextBlock{
 public:
  TextBlock(DbEntry *pEntry, char *pBlock);
  TextBlock(TextBlock *pBlock);
  TextBlock(const char *pUid, char *pBlock);

  void setArg(const char *pArg, int pArgnum);
  int blockLen();
  int argCount();
  void buildBlock(char *pOutput);
  char *getBlock();
  char *cleanBlock();

  DbEntry *getEntry();
 private:
  void parseBlock();
  char *mBlock;
  DbEntry *mEntry;
  segblk mblks[10];
};




#endif
