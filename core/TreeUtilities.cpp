#include "TreeUtilities.h"


MapNode *NodeCopy(MapNode *pNode){
  LeafNode *ln;
  KeyValNode *kvn;
  ListNode *lst, *nlst;
  MapNode *mn;
  StringNode *sn;
  int c;
  switch(pNode->nodeType()){
  case 1:
    ln = (LeafNode*)pNode;
    return getNode(ln->value());
  case 2:
    kvn = (KeyValNode*)pNode;
    if(VXM_ACTIVE_CHK){
      if(ACTIVE_LIST_US != NULL){
	mn = ACTIVE_LIST_US->getNode(kvn->key());
	if(mn != NULL){
	  return mn;
	}
      }
    }
    mn = NodeCopy(kvn->value());
    return getKeyVal(kvn->key(),mn);
  case 3:
    lst = (ListNode*)pNode;
    nlst = emptyList();
    for(c = 0; c < lst->count(); c++){
      nlst->append(NodeCopy(lst->getNode(c)));
    }
    return nlst;
  case 4:
    sn = (StringNode*)pNode;
    return getStringNode(sn->value());
  }
  printf("I shouldn't get here\n");
  return NULL;
}

MapNode *TreeClone(MapNode *pNode){
  return NodeCopy(pNode);
}

MapNode *FindNode(MapNode *pNode, const char *pArg){
  MapNode *mn;
  ListNode *lst;
  KeyValNode *kvn;
  int c;
  switch(pNode->nodeType()){
  case 1:
    if(pNode->compare(pArg) == 0){
      return pNode;
    }else{
      return NULL;
    }
  case 2:
    kvn = (KeyValNode *) pNode;
    if(kvn->compare(pArg) == 0){
      return kvn;
    }else{
      return FindNode(kvn->value(), pArg);
    }
  case 3:
    lst = (ListNode *) pNode;
    for(c = 0; c < lst->count(); c++){
      mn = FindNode(lst->getNode(c), pArg);
      if(mn != NULL) return mn;
    }
    break;
  }
  return NULL;
}


void ProcTree(BaseTreeProc *pBtp, MapNode *pNode){
  LeafNode *ln;
  ListNode *lst;
  KeyValNode *kvn;
  StringNode *str;
  int c;
  switch(pNode->nodeType()){
  case 1:
    ln = (LeafNode*) pNode;
    pBtp->process(ln);
    break;
  case 2:
    kvn = (KeyValNode *) pNode;
    pBtp->process(kvn);
    ProcTree(pBtp, kvn->value());
    break;
  case 3:
    lst = (ListNode *) pNode;
    for(c = 0; c < lst->count(); c++){
      ProcTree(pBtp, lst->getNode(c));
    }
    break;
  case 4:
    str = (StringNode *) pNode;
    pBtp->process(str);
    break;
  }
}

void TraceTreePriv(BaseTreeProc *pBtp, MapNode *pNode, MapList *pList){
  LeafNode *ln;
  ListNode *lst;
  KeyValNode *kvn;
  StringNode *str;
  int c;
  pList->append(pNode);
  switch(pNode->nodeType()){
  case 1:
    ln = (LeafNode*) pNode;
    pBtp->process(pList);
    break;
  case 2:
    kvn = (KeyValNode *) pNode;
    TraceTreePriv(pBtp, kvn->value(), pList);
    break;
  case 3:
    lst = (ListNode *) pNode;
    for(c = 0; c < lst->count(); c++){
      TraceTreePriv(pBtp, lst->getNode(c), pList);
    }
    lst->cleanup();
    if(lst->count() == 0){
      printf("Rem list\n");
      c = pList->count() - 1;
      while(c > 0){
	c--;
	if(pList->getNode(c)->nodeType() == 3){
	  printf("invalidating\n");
	  ((ListNode*)pList->getNode(c))->invNode(pList->getNode(c+1));
	  c = 0;
	}
      }
    }
    break;
  case 4:
    str = (StringNode *) pNode;
    pBtp->process(pList);
    break;
  }
  pList->pop();
}

void TraceTree(BaseTreeProc *pBtp, MapNode *pNode){
  MapList *ml;
  ml = new MapList();
  TraceTreePriv(pBtp, pNode, ml);
  delete ml;
}

void RemoveFromList(MapNode *pNode){
  MapNode *tmp;
  ListNode *ln;
  tmp = pNode;
  printf("Removing\n");
  printNode(pNode, 0);
  while(tmp->getParent() != NULL && tmp->getParent()->nodeType() != 3){
    tmp = tmp->getParent();
  }
  ln = (ListNode *) tmp->getParent();
  ln->remove(tmp);
  //Remove all and delete all lost keys and leafs from master list also
}

void RegisterNode(MapNode *pNode){
  MapList *ml;
  SETUP_ACTIVE;
  ml = VXM_ACTIVE_LIST;
  ADD_LOOKUP(pNode);
  ml->append(pNode);
}
