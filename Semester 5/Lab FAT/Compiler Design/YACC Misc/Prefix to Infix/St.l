%{
    #include<stdio.h>
    #include "Sty.tab.h"
%}

D   [0-9]
NUM {D}+
ES  [\n]
OP  [-+/*%]
RO  [=<>]
PA  [()]

%%
{NUM}   return (NUM);
{OP}    return *yytext;
{RO}    return *yytext;
{ES}    return *yytext;
{PA}    return *yytext;
%%