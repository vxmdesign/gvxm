#include "DslInterface.h"

MapNode *getNode(const char *pName){
  MapList *ml;
  MapNode *mn;

  //  printf("GetNode: %s\n", pName);
  SETUP_ACTIVE;
  ml = VXM_ACTIVE_LIST;
  if((mn = ml->getNode(pName))==NULL){
    mn = new LeafNode(pName);
    ADD_LOOKUP(mn);
    ml->append(mn);
  }else{
    ml->inc(mn);
  }
  return mn;
}

ListNode *getList(MapNode *pNode){
  MapList *ml;
  ListNode *ln;
  SETUP_ACTIVE;
  ml = VXM_ACTIVE_LIST;

  ln = new ListNode(pNode);
  ml->append(ln);
  ADD_LOOKUP(ln);
  return ln;
}

ListNode *emptyList(){
  return new ListNode();
}

KeyValNode *getKeyVal(const char *pName, MapNode *pNode){
  MapList *ml;
  KeyValNode *kvn;

  //printf("GetKeyVal: %s\n", pName);
  SETUP_ACTIVE;
  ml = VXM_ACTIVE_LIST;
  if(ml->getNode(pName)==NULL){
    kvn = new KeyValNode(pName, pNode);
    ml->append(kvn);
    ADD_LOOKUP(kvn);
    return kvn;
  }
  printf("KeyVal already exists: %s\n", pName);
  return NULL;
}

void closeActive(MapNode *pNode){
  SET_VXM_ACTIVE_NODE(pNode);
  gVxm.symbols->addSymbol(VXM_ACTIVE);
  VXM_ACTIVE=NULL;
}

void pushIdentifier(const char *pName){
  gVxm.select->push(pName);
}

MapNode *getIdentifier(const char *pName, int pDeref){
  MapNode *mn;
  KeyValNode *kvn;
  ListNode *ln;
  if(gVxm.select->count() == 0){
    printf("This really shouldn't happen\n");
    return NULL;
  }
  mn = GET_SYMBOL(pName);
  if(mn == NULL){
    if(VXM_ACTIVE_CHK){
      mn = ACTIVE_LIST_US->getNode(pName);
    }
    if(mn == NULL){
      printf("You're an idiot. %s doesn't exist\n", gVxm.select->top());
      return NULL;
    }
  }
  while(gVxm.select->count() > 0){
    if(mn->nodeType() != 2){
      printf("Not KeyValType\n");
      return NULL;
    }
    kvn = (KeyValNode*) mn;
    mn = kvn->value();
    switch(mn->nodeType()){
    case 1:
    case 2:
      if(mn->compare(gVxm.select->top())!=0){
	printf("Node mismatch Exp: %s %s\n", gVxm.select->top(), ((KeyValNode*)mn)->key());
	return NULL;
      }
      break;
    case 3:
      ln = (ListNode*) mn;
      mn = ln->getNode(gVxm.select->top());
      if(mn == NULL){
	printf("Node not found in list Exp: %s\n", gVxm.select->top());
	return NULL;
      }
      break;
    case 4:
      printf("Cannot match strings\n");
      return NULL;
      break;
    }
    gVxm.select->pop();
  }
  if(pDeref == 1){
    if(mn->nodeType()==2){
      kvn = (KeyValNode *)mn;
      mn = kvn->value();
    }else{
      printf("Can only dereference keyvalue\n");
    }
  }
  return mn;
}

void pushTable(){
  PUSH_TABLE;
}

MapNode* popTable(MapNode *pNode){
  KeyValNode *newkv;
  char hName[6];
  getHiddenId(hName);
  if(!isActive(pNode)){
    pNode = TreeClone(pNode);
  }
  newkv = getKeyVal(hName, pNode);
  closeActive(newkv);
  POP_TABLE;
  return pNode;
}

StringNode *getStringNode(const char *pStr){
  StringNode *sn;
  MapList *ml;
  sn = new StringNode(pStr);
  SETUP_ACTIVE;
  ml = VXM_ACTIVE_LIST;
  ml->append(sn);
  ADD_LOOKUP(sn);
  return sn;
}

Modifier *getMod(argMod pMod, const char *pStr){
  Modifier *tmp;
  tmp = (Modifier *) malloc(sizeof(Modifier));
  tmp->mod = pMod;
  if(pMod == MOD_STRING){
    strcpy(tmp->modStr, pStr);
  }
  return tmp;
}

void freeMod(Modifier *pMod){
  free(pMod);
}

MapNode *autoName(MapNode *pNode){
  char hName[6];
  getHiddenId(hName);
  return getKeyVal(hName, pNode);
}
