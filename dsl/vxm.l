    /* calculator #1 */
L [a-zA-Z_]
D [0-9]
H [a-fA-F]
Q [a-zA-Z0-9_]

%{
    #include <stdlib.h>
    #include <string.h>
    #include "DslInterface.h"
    #include "y.tab.h"
    void yyerror(char *);
%}

%%
{L}({D}|{L})*	{ strcpy(yylval.strVal,yytext); return SYMBOL; } 
{Q}* {strcpy(yylval.strVal,yytext); return LEAF; }
[{}:()\-+<>@,=\;\.\]\[\*]    { return *yytext; } 
[ \t\n]       ;       /* skip whitespace */

L?\"(\\.|[^\\"])*\" { strcpy(yylval.strVal,yytext); return STRING;}

.           { printf("%s\n",yytext); yyerror("Unknown character");}

%%

int yywrap(void) {
    return 1;
}
