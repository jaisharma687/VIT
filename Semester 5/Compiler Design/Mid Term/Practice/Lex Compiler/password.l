%{
    #include<stdio.h>
    #include<stdbool.h>
    bool has_upper = false;
    bool has_lower = false;
    bool has_symbol = false;
    bool has_number = false;
    int len = 0;
%}

lower       [a-z]+
upper       [A-Z]+
num         [0-9]+
symbol      [^a-zA-Z0-9]+

%%
{lower}     {has_lower = true; len+=yyleng;}
{upper}     {has_upper = true; len+=yyleng;}
{num}       {has_number = true; len+=yyleng;}
{symbol}    {has_symbol = true; len+=yyleng;}
%%

int main(){
    char password[100];
    printf("Enter the password:\n");
    scanf("%s", password);
	yy_scan_string(password);
    yylex();
    if(len<6){
        printf("Password length should be at least 6 characters.\n");
    }
    else if(has_lower && has_upper && !has_number && !has_symbol){
        printf("Weak Password.\n");
    }
    else if(has_number && !has_symbol){
        printf("Moderate Password.\n");
    }
    else if(has_symbol){
        printf("Strong Password.\n");
    }
    else{
        printf("Password doesnt satisfy any condition.\n");
    }
    return 0;
}

int yywrap(){
    return 1;
}