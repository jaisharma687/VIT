%{
    #include<stdio.h>
%}

Institution [a-zA-Z0-9._%+-]+@vitstudent.ac.in
Gmail       [a-zA-Z0-9._%+-]+@gmail.com
Outlook     [a-zA-Z0-9._%+-]+@outlook.com
Unknown     [a-zA-Z0-9._%+-]+@[a-zA-Z0-9._]+\.[a-zA-Z]{2,4}

%%
{Institution}   {printf("Email id is of Institution.\n");}
{Gmail}         {printf("Email id is of Gmail.\n");}
{Outlook}       {printf("Email id is of Outlook.\n");}
{Unknown}       {printf("Email id is of Unknown.\n");}
.|\n
%%

int main(){
    char email[100];
    printf("Enter your email id: ");
    scanf("%s",email);
    int len = strlen(email);
    yy_scan_string(email);
    printf("Email length is: %d\n",len);
    yylex();
    return  0;
}

int yywrap(){
    return 1;
}