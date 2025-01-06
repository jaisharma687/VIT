%{
#include <stdio.h>
#include <stdlib.h>
void yyerror(char *);
int yylex(void);
%}

%token NUM

%%
L   :E '\n'     {printf("%d\n",$1);}
E   :E '+' T    {$$ = $1 + $3;}
    |E '-' T    {$$ = $1 - $3;}
    |T          {$$ = $1;}
T   :T '*' F    {$$ = $1 * $3;}
    |T '/' F    {$$ = $1 / $3;}
    |F          {$$ = $1;}
F   :F '%' J    {$$ = $1 % $3;}
    |J          {$$ = $1;}
J   :'(' E ')'  {$$ = $2;}
    |NUM        {$$ = $1;}
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