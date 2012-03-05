#ifndef STR_QUEUE_H
#define STR_QUEUE_H

#include <stdio.h>
#include <malloc.h>
#include <string.h>


#define MAX_Q_SIZE 32
#define MAX_Q_LEN 32


class StrQueue{
 public:
  StrQueue();
  StrQueue(const char *pStr);
  void push(const char *pStr);
  const char *top();
  void pop();
  int count();
 private:
  int mCount;
  int mHead;
  int mTail;
  char mChar[MAX_Q_SIZE * MAX_Q_LEN];
};


#endif
