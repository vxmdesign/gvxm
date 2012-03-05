#include "DbFile.h"

DbFile::DbFile(const char *pFilename){
  int fd;
  int c;
  fd = open(pFilename, O_RDONLY);
  c = 0;
  while(loadUnit(fd) == 1)c++;
  printf("Loaded %d entries\n", c);
  close(fd);
}

void DbFile::saveDb(const char *pFilename){
  DbUnit *db;
  int fd;
  unsigned int c;
  fd = open(pFilename, O_WRONLY);
  for(c = 0; c < mList.size(); c++){
    db = mList[c];
    write(fd, db->entry, sizeof(DbEntry));
    write(fd, db->ref->cleanBlock(), db->entry->len);
  }
  close(fd);
}

void DbFile::addBlock(TextBlock *pBlock){
  DbUnit *dbu;
  dbu = (DbUnit*) malloc(sizeof(DbUnit));
  dbu->ref = pBlock;
  dbu->entry = pBlock->getEntry();
  dbu->blk = pBlock->getBlock();
  mList.push_back(dbu);
}


void DbFile::shutdown(){
  //remove alloced stuff

}

int DbFile::loadUnit(int pFd){
  DbEntry tmp;
  DbUnit *dbu;
  int i;
  i = read(pFd, &tmp, sizeof(DbEntry));
  if(i != sizeof(DbEntry)) return 0;
  dbu = (DbUnit *) malloc(sizeof(DbUnit));
  dbu->entry = (DbEntry *)malloc(sizeof(DbEntry));
  *(dbu->entry) = tmp;
  dbu->blk = (char *) malloc(sizeof(char) * dbu->entry->len);
  i = read(pFd, dbu->blk, dbu->entry->len);
  if(i != dbu->entry->len){
    printf("Entry error\n");
    return 0;
  }
  dbu->ref = new TextBlock(dbu->entry, dbu->blk);
  mList.push_back(dbu);
  return 1;
}

PartMap *DbFile::buildPartMap(){
  unsigned int c;
  DbUnit *dbu;
  PartMap *pm;
  pm = new PartMap();
  for(c = 0; c < mList.size(); c++){
    dbu = mList[c];
    pm->addPart(dbu->entry, dbu->ref);
  }
  return pm;
}
