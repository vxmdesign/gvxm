#ifndef DB_FILE_H
#define DB_FILE_H

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <malloc.h>
#include <vector>
#include "TextBlock.h"
#include "DbEntry.h"
#include "PartMap.h"

typedef struct{
  DbEntry *entry;
  char *blk;
  TextBlock *ref;
}DbUnit;

using namespace std;

class DbFile{
 public:
  DbFile();
  DbFile(const char *pFilename);
  void saveDb(const char *pFilename);
  PartMap *buildPartMap();
  void addBlock(TextBlock *pBlock);
  void shutdown();
 private:
  int loadUnit(int pFd);
  vector<DbUnit *> mList;
};


#endif
