%{
#include <stdio.h>
#include "Sty.tab.h"
void yyerror(char *);
int yylex(void);
%}

%token ID

%%
S   : ID A B ID '\n' {printf("Valid Statement\n");}
A   : ID
    | ' '
B   : ID
    | ' '
%%

int main(){
    printf("Enter the statement: ");
    yyparse();
    return 0;
}

int yywrap(){
    return 1;
}

void yyerror(char *err){
    fprintf(stderr, "%s\n", err);
}