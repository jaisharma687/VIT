%{
#include <stdio.h>
#include "Sty.tab.h"
%}

L        [a-zA-Z]
D        [0-9]
ID       {L}({L}|{D})*
NUM      {D}+
SO       [;\n]
PO       [()]
ASO      =
AO       [-+*/]
RO       [><]
CP       [{}]

%%
"if"     return(IF);
{ID}     return(ID);
{NUM}    return(NUM);
{SO}     return *yytext;
{PO}     return *yytext;
{ASO}    return *yytext;
{AO}     return *yytext;
{RO}     return *yytext;
{CP}     return *yytext;
%%