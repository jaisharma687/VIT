%{
#include<stdio.h>
#include"Sty.tab.h"
%}

L   [a-zA-Z]
D   [0-9]
ID  {L}({L}|{D})*
NUM {D}+
SO  [;\n]
PO  [()]
ASO =
AO  [-+*/]

%%
{ID}    return(ID);
{NUM}   return(NUM);
{AO}    return *yytext;
{PO}    return *yytext;
{ASO}   return *yytext;
{SO}    return *yytext;
%%