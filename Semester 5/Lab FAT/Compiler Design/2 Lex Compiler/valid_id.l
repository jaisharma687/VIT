%{
    #include <stdio.h>
%}

%%
^[A-Z][a-zA-Z0-9_]*$    {printf("Valid");}
.*                      {printf("Invalid");}
%%

int main() {
    printf("Enter the identifier: \n");
    yylex();
    return 0;
}

int yywrap() {
    return 1;
}
