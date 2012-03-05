#ifndef MODIFIER_H
#define MODIFIER_H

enum argMod { MOD_NONE, MOD_PLUS, MOD_MINUS, MOD_STRING };

typedef struct { 
  argMod mod;
  char modStr[64];
} Modifier;



#endif
