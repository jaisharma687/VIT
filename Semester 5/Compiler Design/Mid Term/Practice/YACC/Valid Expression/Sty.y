%{
    #include<stdio.h>
    #include"Sty.tab.h"
    void yyerror(char *);
    int yylex(void);
%}

%token ID NUM

%%
S   : ID '=' E ';'      {printf("Valid Expression.");}
E   : T X Y
X   : '-' T X
    |
Y   : '+' T Y
    |
T   : F P Q
P   : '*' F P
    |
Q   : '/' F Q
    |
F   : '(' E ')'
    | ID
    | NUM
%%

int main(){
    printf("Enter the Expression:\n");
    yyparse();
    return 0;
}

int yywrap(){
    return 1;
}

void yyerror(char *err){
    fprintf(stderr, "%s\n", err);
}