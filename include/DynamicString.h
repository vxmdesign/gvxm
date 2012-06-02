#ifndef DYNAMIC_STRING_H
#define DYNAMIC_STRING_H

#include <malloc.h>
#include <string.h>
#include <stdarg.h>



class DynamicString{
 public:
  DynamicString();
  DynamicString(const char *pStr);
  void append(const char *pStr,...);
  char* str();
 private:
  void cAppend(const char *pStr);
  void expand(int pSize);

  char *mStr;
  int mSize;
  int mLen;
};


#endif
