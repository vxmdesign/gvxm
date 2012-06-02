#include "TextBlock.h"

TextBlock::TextBlock(const char *pUid, char *pBlock){
  int c;
  mEntry = (DbEntry*) malloc(sizeof(DbEntry));
  strcpy(mEntry->uid, pUid);
  mEntry->len = strlen(pBlock);
  mBlock = pBlock;
  mEntry->args = 0;
  for(c = 0; c < mEntry->len; c++){
    if(mBlock[c] == '$') mEntry->args++;
  }
  parseBlock();
}

TextBlock::TextBlock(TextBlock *pBlock){
  int c;
  mBlock = pBlock->mBlock;
  mEntry = pBlock->mEntry;
  c = 0;
  while(pBlock->mblks[c].argnum != 0){
    mblks[c].argnum = pBlock->mblks[c].argnum;
    mblks[c].blk = pBlock->mblks[c].blk;
    c++;
  }
  mblks[c].argnum = 0;
  mblks[c].blk = pBlock->mblks[c].blk;
}

TextBlock::TextBlock(DbEntry *pEntry, char *pBlock){
  mEntry = pEntry;
  mBlock = pBlock;
  parseBlock();
}

void TextBlock::setArg(const char *pArg, int pArgnum){
  int c;
  c = 0;
  while(mblks[c].argnum != 0){
    if(mblks[c].argnum == pArgnum){
      strcpy(mblks[c].arg, pArg);
    }
    c++;
  }
}

int TextBlock::blockLen(){
  int sz;
  int c;
  c = 0;
  sz = 0;
  while(mblks[c].argnum != 0){
    sz += strlen(mblks[c].blk);
    sz += strlen(mblks[c].arg);
    c++;
  }
  sz += strlen(mblks[c].blk) + 1;
  return sz;
}

void TextBlock::buildBlock(char *pOutput){
  int c;
  int idx;
  int tmplen;
  c = 0;
  idx = 0;
  while(mblks[c].argnum != 0){
    strcpy(&(pOutput[idx]), mblks[c].blk);
    idx = strlen(pOutput);
    strcpy(&(pOutput[idx]), mblks[c].arg);
    idx = strlen(pOutput);
    c++;
  }
  tmplen = strlen(mblks[c].blk);
  strcpy(&(pOutput[idx]), mblks[c].blk);
}

char *TextBlock::cleanBlock(){
  int c;
  char *tmp;
  c = 0;
  while(mblks[c].argnum != 0){
    c++;
    tmp = mblks[c].blk;
    tmp = tmp - 2;
    tmp[0] = '$';
  }
  return mBlock;
}

char *TextBlock::getBlock(){
  return mBlock;
}

DbEntry *TextBlock::getEntry(){
  return mEntry;
}

void TextBlock::parseBlock(){
  char *st;
  int cidx;
  int aidx;
  st = mBlock;
  aidx = 0;
  cidx = 0;
  while(st[cidx] != '\0'){
    if(st[cidx] == '$'){

      if(st[cidx+1] < '0' || st[cidx+1] > '9'){
	printf("Invalid arg symbol %c\n", st[cidx+1]);
	return;
      }
      mblks[aidx].blk = st;
      mblks[aidx].argnum = st[cidx + 1] - '0';
      //      printf("Found arg num %d\n", mblks[aidx].argnum);
      st[cidx] = '\0';
      st = &(st[cidx + 2]);
      cidx = 0;
      aidx++;
    }else{
      cidx++;
    }
  }
  mblks[aidx].blk = st;
  mblks[aidx].argnum = 0;
}

int TextBlock::argCount(){
  int c;
  int max;
  c = 0;
  max = 0;
  while(mblks[c].argnum != 0){
    if(mblks[c].argnum > max) max = mblks[c].argnum;
    c++;
  }
  return max;
}
