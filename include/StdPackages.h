#ifndef STD_PACKAGES_H
#define STD_PACKAGES_H

#define STD_PATTERN_SIZE 11

typedef struct{
  const char *rpl;
  const char *cid;
  double z;
  double g;
  double x;
  double y;
  double c;
}ResTabEntry;

typedef struct{
  const char *rpl;
  const char *cid;
  double z;
  double g;
  double x;
  double y;
  double c;
  double d;
  double e;
}SoicTabEntry;

typedef struct{
  const char *rpl;
  const char *cid;
  double z;
  double g;
  double x;
  double y;
  double c;
  double e;
}DfnTabEntry;



typedef struct{
  const char *rpl;
  const char *cid;
  double z1;
  double g1;
  double z2;
  double g2;
  double x;
  double y;
  double c1;
  double d1;
  double c2;
  double d2;
  double e;
}RqfpTabEntry;

extern ResTabEntry res_table[];
extern ResTabEntry cap_table[];
extern ResTabEntry ind_table[];
extern ResTabEntry tan_table[];
extern ResTabEntry melf_table[];
extern SoicTabEntry soic_table[];
extern SoicTabEntry ssop_table[];
extern SoicTabEntry sop_table[];
extern SoicTabEntry qfp_table[];
extern RqfpTabEntry rqfp_table[];
extern DfnTabEntry dfn_table[];

extern int std_table_size[];

#endif
