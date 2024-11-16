%{
#include <stdio.h>
#include "Sty.tab.h"
void yyerror(char *);
int yylex(void);
%}

%token NUM

%%
L   : T '\n'        {printf("%d\n",$1);}
T   : F '+' '+'     {$$ = $1;}
    | F '-' '-'     {$$ = $1;}
    | '+' '+' F     {$$ = $3 + 1;}
    | '-' '-' F     {$$ = $3 - 1;}
F   : NUM           {$$ = $1;}
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