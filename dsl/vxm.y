%{
    #include <stdio.h>
    #include "DslInterface.h"
    int yylex(void);
    void yyerror(char *);
%}
%error-verbose
%union
{
	char strVal[64];
	MapNode *mnVal;
	ListNode *lnVal;
	CommandBase *cbVal;
	Modifier *mdVal;
}

%token <strVal> LEAF
%token <strVal> SYMBOL
%token <strVal> STRING
%type <lnVal> nlist
%type <mnVal> map_obj
%type <mnVal> bsymbol
%type <mnVal> esymbol
%type <mnVal> close_table
%type <cbVal> close_cmd
%type <cbVal> elist
%type <mdVal> mod
%%

program:
        program map_obj ';'         { closeActive($2); }
	|
	;

map_obj:
	bsymbol			{ $$ = $1;}
	| esymbol		{ $$ = $1; } 
	| SYMBOL ':' map_obj 	{ $$ = getKeyVal($1,$3);} 
	| '{' nlist '}'		{ $$ = $2; } 
	| open_table close_table { $$ = $2; }
	| open_cmd close_cmd	{ $$ = $2->close(); }  
	| '@' map_obj		{ $$ = autoName($2); }
	;

open_cmd:
	SYMBOL '('		{ PUSH_CMD($1);}
	;

close_cmd:
	elist ')'		{ $$ = $1;POP_CMD; } 
	;

open_table:
	'['			{ pushTable();}
	;
close_table:
	map_obj ']'		{$$=popTable($1); }
	;

nlist:
	nlist ',' map_obj 	{ $1->append($3); $$=$1; } 
	| map_obj 		{ $$ = getList($1); }
	;

elist:
	elist ',' mod map_obj	{ $1->process($3,$4); $$ = $1; freeMod($3);}
	| mod map_obj		{ $$ = ACTIVE_CMD; $$->process($1,$2); freeMod($1);}
	;

esymbol:
	SYMBOL designator_list  { $$=getIdentifier($1,0); } 
	| '*' SYMBOL designator_list { $$=getIdentifier($2,1);}
	;
	
designator_list:
	designator
	| designator_list designator
	;

designator:
	'.' LEAF		{ pushIdentifier($2); } 
	| '.' SYMBOL		{ pushIdentifier($2); } 
	;

bsymbol:
	LEAF			{ $$ = getNode($1); } 
	| SYMBOL		{ $$ = getNode($1); } 
	| STRING		{ $$ = getStringNode($1); } 
	;
mod:
	'+'			{ $$ = getMod(MOD_PLUS, NULL); } 
	| '-' 			{ $$ = getMod(MOD_MINUS, NULL); } 
	| '<' LEAF '>'		{ $$ = getMod(MOD_STRING, $2); } 
	| '<' SYMBOL '>'	{ $$ = getMod(MOD_STRING, $2); } 
	|			{ $$ = getMod(MOD_NONE, NULL); } 
	;

%%

void yyerror(char *s) {
    fprintf(stderr, "%s\n", s);
    fprintf(stderr, "ye called\n");
}
