#include "PcbProcess.h"


void DoNetList(BomKeyNode *pBkn, ListNode *pNetList){
  KeyValNode *kvn;
  MapNode *mn;
  ListNode *ln;
  int c,d;
  for(c = 0; c < pNetList->count(); c++){
    mn = pNetList->getNode(c);
    if(mn->nodeType() == 2){
      kvn = (KeyValNode*)mn;
      mn = kvn->value();
      if(mn->nodeType() == 3 && mn != pNetList){
	printf("%s: ", kvn->key());
	ln = (ListNode *) mn;
	for(d = 0; d < ln->count(); d++){
	  pBkn->printRef(ln->getNode(d));
	}
	printf("\n");
      }
    }
  }  
}


void PcbProcess(const char *pCircuit){
  BomKeyNode *bkn;
  ListNode *ln;
  MapNode *mn;
  MapNode *tmp;
  mn = gVxm.symbols->getNode(pCircuit);
  if(mn == NULL){
    printf("Symbol not found\n");
    return;
  }
  tmp = FindNode(mn, "bom");
  if(tmp == NULL){
    printf("Not a circuit\n");
    return;
  }
  bkn = dynamic_cast<BomKeyNode*>(tmp);
  if(bkn == NULL){
    printf("Invalid bom\n");
    return;
  }
  tmp = FindNode(mn, "netlist");
  if(tmp == NULL || tmp->nodeType() != 2){
    printf("Invalid netlist\n");
    return;
  }
  tmp = GET_KEY_VALUE(tmp);
  if(tmp->nodeType() != 3){
    printf("Invalid netlist ListNode\n");
    return;
  }
  ln = (ListNode*) tmp;
  DoNetList(bkn, ln);
  bkn->printPcb();
}

