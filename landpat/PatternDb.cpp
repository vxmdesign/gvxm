#include "PatternDb.h"

PatternDb::PatternDb(){
  mChipMap["res"] = mChip[0] = new ResChip(res_table, std_table_size[0]);
  mChipMap["cap"] = mChip[1] = new ResChip(cap_table, std_table_size[1]);
  mChipMap["ind"] = mChip[2] = new ResChip(ind_table, std_table_size[2]);
  mChipMap["tan"] = mChip[3] = new ResChip(tan_table, std_table_size[3]);
  mChipMap["melf"] = mChip[4] = new ResChip(melf_table, std_table_size[4]);
  mChipMap["soic"] = mChip[5] = new SoicChip(soic_table, std_table_size[5]);
  mChipMap["ssop"] = mChip[6] = new SoicChip(ssop_table,  std_table_size[6]);
  mChipMap["sop"] = mChip[7] = new SoicChip(sop_table,  std_table_size[7]);
  mChipMap["qfp"] = mChip[8] = new QfpChip(qfp_table,  std_table_size[8]);
  mChipMap["rfq"] = mChip[9] = new RqfpChip(rqfp_table,  std_table_size[9]);
  mChipMap["dfn"] = mChip[10] = new DfnChip(dfn_table, std_table_size[10]);
  mChipMap["usb"] = mChip[11] = new UsbChip();
}

TextBlock *PatternDb::getBlockByRpl(const char *pRpl, const char *pUid){
  int c;
  TextBlock *tmp;
  for(c = 0; c < 10; c++){
    tmp = mChip[c]->getChipByRpl(pRpl, pUid);
    if(tmp != NULL) return tmp;
  }
  return NULL;
}

TextBlock *PatternDb::getBlockByCid(const char *pClass, const char *pCid, const char *pUid){
  BaseChip *bc;
  TextBlock *tmp;
  bc = mChipMap[pClass];
  if(bc == NULL) return NULL;
  tmp = bc->getChipByCid(pCid, pUid);
  return tmp;
}

TextBlock *PatternDb::getBlockUnique(const char *pClass, const char *pUid){
  BaseChip *bc;
  TextBlock *tmp;
  bc = mChipMap[pClass];
  if(bc == NULL) return NULL;
  tmp = bc->getChipUnique(pUid);
  return tmp;
}
