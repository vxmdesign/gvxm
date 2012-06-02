#include "VxmUtilities.h"

void printNode(MapNode *pNode, int ptidx){
  int c;
  char tlst[16];
  LeafNode *lf;
  KeyValNode *kvn;
  ListNode *ln;
  StringNode *str;
  for(c = 0; c < ptidx; c++){
    tlst[c] = '\t';
  }
  tlst[ptidx] = '\0';

  switch(pNode->nodeType()){
  case 1:
    lf = (LeafNode *) pNode;
    printf("%sLeaf: %s\n",tlst,lf->value());
    break;
  case 2:
    kvn = (KeyValNode *) pNode;
    printf("%sKeyVal: %s\n", tlst, kvn->key());
    printNode(kvn->value(), ptidx+1);
    break;
  case 3:
    ln = (ListNode *) pNode;
    for(c = 0; c < ln->count(); c++){
      printNode(ln->getNode(c), ptidx+1);
    }
    break;
  case 4:
    str = (StringNode*) pNode;
    printf("%sString: %s\n",tlst, str->value());
    break;
  }
}

int isActive(MapNode *pNode){
  if(!(VXM_ACTIVE_CHK)) return 0;
  if(ACTIVE_LIST_US == NULL) return 0;
  return ACTIVE_LIST_US->contains(pNode);
}

void stripQuotes(const char *pSrc, char *pDst){
  int c;
  int i;
  c=0; 
  while(pSrc[c] != '\0' && pSrc[c] != '\"') c++;
  if(pSrc[c] == '\0'){
    strcpy(pDst, pSrc);
    return;
  }
  c++;
  i = 0;
  while(pSrc[c] != '\0' && pSrc[c] != '\"'){
    pDst[i] = pSrc[c];
    i++;
    c++;
  }
  pDst[i] = '\0';
}


void getHiddenId(char *pId){
  int i;
  int c;
  pId[5] = '\0';
  pId[0] = '*';
  i = gVxm.hiddenIdNum;
  for(c = 0; c < 4; c++){
    pId[c+1] = 'A' + (i & 0xf);
    i = i >> 4;
  }
  gVxm.hiddenIdNum++;
}

char *fileLoader(const char *pFilename){
  struct stat sz;
  char *fbuf;
  int fd;
  int i;
  stat(pFilename, &sz);
  if(sz.st_size == 0){
    return NULL;
  }
  fbuf = (char *) malloc((sizeof(char) * sz.st_size) + 1);
  fd = open(pFilename, O_RDONLY);
  if(fd <= 0){
    printf("Cannot open file??\n");
    free(fbuf);
    return NULL;
  }
  i = read(fd, fbuf, sz.st_size);
  if(i != sz.st_size){
    printf("Size mismatch\n");
    free(fbuf);
    return NULL;
  }
  close(fd);
  fbuf[sz.st_size] = '\0';
  return fbuf;
}
