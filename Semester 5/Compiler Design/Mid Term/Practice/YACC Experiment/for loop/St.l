%{
    #include<stdio.h>
    #include"Sty.tab.h"
%}

L   [a-zA-Z]
D   [0-9]
ID  {L}({L}|{D})*
NUM {D}+
RO  [=<>]
OP  [-+*/]
PA  [()]
CA  [{}]
ES  [;]

%%
"for"   return (FOR);
{ID}    return (ID);
{NUM}   return (NUM);
{RO}    return *yytext;
{OP}    return *yytext;
{PA}    return *yytext;
{CA}    return *yytext;
{ES}    return *yytext;
%%