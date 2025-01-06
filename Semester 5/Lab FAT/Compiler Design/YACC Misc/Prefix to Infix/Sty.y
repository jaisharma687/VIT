%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void yyerror(char *);
int yylex(void);

typedef struct {
    char str[100];
} YYSTYPE;

#define YYSTYPE YYSTYPE

%}

%token NUMBER

%%

input:
    expr '\n' { printf("\nInfix Expression: %s\n", $1.str); }
    ;

expr:
    '+' expr expr {
        snprintf($$.str, sizeof($$.str), "(%s + %s)", $2.str, $3.str);
    }
    | '-' expr expr {
        snprintf($$.str, sizeof($$.str), "(%s - %s)", $2.str, $3.str);
    }
    | '*' expr expr {
        snprintf($$.str, sizeof($$.str), "(%s * %s)", $2.str, $3.str);
    }
    | '/' expr expr {
        snprintf($$.str, sizeof($$.str), "(%s / %s)", $2.str, $3.str);
    }
    | NUMBER {
        snprintf($$.str, sizeof($$.str), "%s", yytext);
    }
    ;

%%

void yyerror(char *s) {
    fprintf(stderr, "Error: %s\n", s);
}

int main(void) {
    printf("Enter a prefix expression to convert to infix:\n");
    yyparse();
    return 0;
}
