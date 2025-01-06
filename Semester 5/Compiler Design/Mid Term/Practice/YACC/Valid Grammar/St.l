%{
    #include<stdio.h>
    #include"Sty.tab.h"
%}

%%
[abcd]   return *yytext;
%%