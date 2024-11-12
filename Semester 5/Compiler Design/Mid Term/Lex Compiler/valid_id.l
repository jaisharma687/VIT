%{
#include <stdio.h>
%}

%%
^[A-Z][A-Za-z0-9_]*$    { printf("Valid"); }
.*                      { printf("Invalid"); }
%%

int main() {
    printf("Enter a variable name to check: ");
    yylex();
    return 0;
}

int yywrap()
{
	return 1;
}