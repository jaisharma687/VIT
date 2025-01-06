%{
    #include<stdio.h>
    #include"Sty.tab.h"
    void yyerror(char *);
    int yylex(void);
%}

%token IF ID NUM

%%
S   : IF '(' T ')' '{' E '}'    {printf("Valid Statement.");}
T   : F RO F
RO  : '=' '='
    | '<' '='
    | '>' '='
    | '>'
    | '<'
E   : ID '=' C ';'
C   : F OP F X
X   : OP F X
    |
OP  : '+'
    | '-'
    | '*'
    | '/'
F   : '(' C ')'
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