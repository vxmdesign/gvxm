#include "PcbProcess.h"


void DoNetList(FILE *pFout, BomKeyNode *pBkn, ListNode *pNetList){
  KeyValNode *kvn;
  MapNode *mn;
  ListNode *ln;
  int c,d;
  const char *net_in;
  char net_out[32];
  for(c = 0; c < pNetList->count(); c++){
    mn = pNetList->getNode(c);
    if(mn->nodeType() == 2){
      kvn = (KeyValNode*)mn;
      mn = kvn->value();
      if(mn->nodeType() == 3 && mn != pNetList){
	net_in = kvn->key();
	if(net_in[0] != '*'){
	  strcpy(net_out, net_in);
	}else{
	  sprintf(net_out, "unnamed_%s", &(net_in[1]));
	}
	fprintf(pFout, "%s\t", net_out);
	
	ln = (ListNode *) mn;
	for(d = 0; d < ln->count(); d++){
	  fprintf(pFout, "%s",pBkn->printRef(ln->getNode(d)));
	}
	fprintf(pFout, "\n");
      }
    }
  }  
}


void PcbProcess(const char *pCircuit){
  FILE *net;
  FILE *pcb;
  BomKeyNode *bkn;
  ListNode *ln;
  MapNode *mn;
  MapNode *tmp;
  char netname[32];
  char pcbname[32];
  sprintf(netname, "%s.net", pCircuit);
  sprintf(pcbname, "%s.pcb", pCircuit);
  net = fopen(netname, "w");
  pcb = fopen(pcbname, "w");

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
  DoNetList(net, bkn, ln);
  bkn->fprintPcb(pcb);
  fclose(net);
  fclose(pcb);
}

