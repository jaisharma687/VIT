%{
    #include<stdio.h>
    #include"Sty.tab.h"
%}

ID      [a-d]
SO      [\n]

%%
{ID}    return(ID);
{SO}    return *yytext;
%%