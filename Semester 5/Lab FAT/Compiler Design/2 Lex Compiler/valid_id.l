%{
    #include <stdio.h>
%}


%%
^[A-Z][a-zA-Z0-9_]*$    {printf("Valid\n");}
.*                      {printf("Invalid\n");}
%%

int main(){
    char id[100];
    printf("Enter the identifier: \n");
    scanf("%s",id);
    yy_scan_string(id);
    yylex();
    return 0;
}

int yywrap(){
    return 1;
}