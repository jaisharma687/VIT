%{
#include <stdio.h>
#include "Sty.tab.h"
%}

NUM [0-9]+
SO  [\n]
AO  [-+]

%%
{NUM}   {yylval = atoi(yytext); return NUM;}
{SO}    return *yytext;
{AO}    return *yytext;
%%