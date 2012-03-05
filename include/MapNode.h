#ifndef MAP_NODE_H
#define MAP_NODE_H

#include <stdio.h>

class MapNode{
 public:
  virtual int nodeType()=0;
  virtual int nodeException()=0;
  virtual int compare(const char *pName)=0;
  void setException(int pEx);
  int inException();
  MapNode *getParent();
  void setParent(MapNode *pNode);
  void setMark(int pMark);
  int getMark();
 private:
  int mMark;
  int mException;
  MapNode *mParent;
};

#endif 
