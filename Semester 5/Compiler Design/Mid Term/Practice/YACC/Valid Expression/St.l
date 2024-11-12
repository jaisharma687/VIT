%{
    #include<stdio.h>
    #include"Sty.tab.h"
%}

L   [a-zA-Z]
D   [0-9]
ID  {L}({L}|{D})*
NUM {D}+
OP  [-+/*]
PA  [()]
SE  [;]
ASO [=]

%%
{ID}    return (ID);
{NUM}   return (NUM);
{OP}    return *yytext;
{PA}    return *yytext;
{SE}    return *yytext;
{ASO}   return *yytext;
%%

