%{
    #include<stdio.h>
    #include"Sty.tab.h"
    int yylex(void);
    void yyerror(char *);
%}

%token FOR ID NUM

%%
S   : FOR '(' I ';' C ';' P ')' '{' E '}'     {printf("Valid Statement.");}
I   : ID '=' F
C   : ID RO F
P   : ID IN
    | ID '=' ID OP F
IN  : '+' '+'
    | '-' '-'
E   : ID '=' X ';'
X   : F OP F Y
Y   : OP F Y
    |
RO  : '>'
    | '<'
    | '<' '='
    | '>' '='
    | '=' '='
OP  : '+'
    | '-'
    | '*'
    | '/'
F   : '(' E ')'
    | ID  
    | NUM
%%

int main(){
    printf("Enter the code:\n");
    yyparse();
    return 0;
}

int yywrap(){
    return 1;
}

void yyerror(char *err){
    fprintf(stderr,"%s\n",err);
}