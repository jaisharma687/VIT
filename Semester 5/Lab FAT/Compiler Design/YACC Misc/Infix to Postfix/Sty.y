%{
    #include <stdio.h>
    #include"Sty.tab.h"
    void yyerror(char *);
    int yylex(void);
    int stack[100], top = -1;
    void push(int);
    int pop(void);
%}

%token NUM

%%
S   : E '\n'    { printf("\nPostfix Expression Value: %d\n", $1); }
E   : E '+' T   { $$ = $1 + $3; printf("+ "); }
    | E '-' T   { $$ = $1 - $3; printf("- "); }
    | T         { $$ = $1; }
T   : T '*' F   { $$ = $1 * $3; printf("* "); }
    | T '/' F   { $$ = $1 / $3; printf("/ "); }
    | F         { $$ = $1; }
F   : '(' E ')' { $$ = $2; }
    | NUM       { $$ = $1; printf("%d ", $1); }
%%

void push(int num)
{
    stack[++top] = num;
}

int pop(void)
{
    return stack[top--];
}

int main(void)
{
    printf("Enter an infix expression to convert to postfix:\n");
    yyparse();
    return 0;
}

int yywrap(void)
{
    return 1;
}

void yyerror(char *s)
{
    fprintf(stderr, "%s\n", s);
}