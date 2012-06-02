#include "DynamicString.h"

DynamicString::DynamicString(){
  mLen = 0;
  mSize = 32;
  mStr = (char *) malloc(sizeof(char)* 32);
}

DynamicString::DynamicString(const char *pStr){
  int l;
  mLen = strlen(pStr);
  l = mLen;
  if(l < 16) l = 16;
  l = l * 2;
  mSize = l;
  mStr = (char *) malloc(sizeof(char) * mSize);
  strcpy(mStr, pStr);
}


void DynamicString::cAppend(const char * pStr){
  int newsize;
  newsize = strlen(pStr) + mLen;
  if(mSize < newsize){
    expand(newsize);
  }
  strcpy(&(mStr[mLen]), pStr);
  mLen = newsize;
}

char* DynamicString::str(){
  return mStr;
}

void DynamicString::expand(int pSize){
  int newsize;
  char *newstr;
  newsize = mSize;
  while(newsize < pSize){
    newsize = newsize * 2;
  }
  newstr = (char *) malloc(sizeof(char) * newsize);
  strcpy(newstr, mStr);
  free(mStr);
  mSize = newsize;
  mStr = newstr;
}


void DynamicString::append(const char *pStr, ...){
  va_list ap;
  char tmp[256];

  va_start(ap, pStr);

  vsnprintf(tmp, 255, pStr, ap);

  va_end(ap);

  cAppend(tmp);
}
