%{
#include <stdio.h>
#include "Sty.tab.h"
%}

D   [0-9]
NUM {D}+
SO  [\n]
PO  [()]
ASO =
AO  [-+*/%]

%%
{NUM}   {yylval = atoi(yytext); return NUM;}
{SO}    return *yytext;
{PO}    return *yytext;
{ASO}   return *yytext;
{AO}    return *yytext;
%%