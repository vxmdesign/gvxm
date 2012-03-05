#include "StrQueue.h"

StrQueue::StrQueue(){
  mCount = 0;
  mHead = 0;
  mTail = 0;
}

StrQueue::StrQueue(const char *pStr){
  strcpy(mChar, pStr);
  mCount = 1;
  mHead = 1;
  mTail = 0;
}

void StrQueue::push(const char *pStr){
  int i;
  char *tmp;
  if(mCount >= MAX_Q_SIZE) return;
  i = mHead * MAX_Q_LEN;
  tmp = &(mChar[i]);
  strcpy(tmp, pStr);
  mHead++;
  mHead = mHead % MAX_Q_SIZE;
  mCount++;
}

const char *StrQueue::top(){
  char *tmp;
  int i;
  if(mCount == 0) return NULL;
  i = mTail  * MAX_Q_LEN;
  tmp = &(mChar[i]);
  return tmp;
}

void StrQueue::pop(){
  mTail++;
  mTail = mTail % MAX_Q_SIZE;
  mCount--;
}

int StrQueue::count(){
  return mCount;
}
