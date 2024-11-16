%{
    #include<stdio.h>
    #include"Sty.tab.h"
    void yyerror(char *);
    int yylex(void);
%}

%%
S   : 'a' A B 'b'     {printf("Valid Input");}
A   : 'c'
    |
B   : 'd'
    |
%%

int main(){
    printf("Enter the input:\n");
    yyparse();
    return 0;
}

int yywrap(){
    return 1;
}

void yyerror(char *err){
    fprintf(stderr, "%s\n", err);
}