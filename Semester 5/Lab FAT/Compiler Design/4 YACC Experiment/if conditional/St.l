%{
    #include<stdio.h>
    #include"Sty.tab.h"
%}

L   [a-zA-Z]
D   [0-9]
ID  {L}({L}|{D})*
NUM {D}+
PA  [()]
CP  [{}]
RO  [=<>]
OP  [-+/*]
ES  [;]

%%
"if"    return (IF);
{ID}    return (ID);
{NUM}   return (NUM);
{PA}    return *yytext;
{CP}    return *yytext;
{RO}    return *yytext;
{OP}    return *yytext;
{ES}    return *yytext;
%%