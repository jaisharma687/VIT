%{
    #include <stdio.h>
    #include "Sty.tab.h"
    void yyerror(char *);
    int yylex(void);
%}
 
%token ID NUM
%%
S   : ID '=' E ';' '\n'         {printf("Valid Statement\n");}
E   : E '+' T
    | E '-' T
    | T
T   : T '*' F
    | T '/' F
    | F
F   : '(' E ')'
    | ID
    | NUM
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
