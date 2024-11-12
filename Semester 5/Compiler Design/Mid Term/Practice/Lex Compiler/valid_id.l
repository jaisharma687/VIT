N 	[0-9]
Num {N}+
L [a-zA-Z]+
Inval {Num}+({L}+)|({L}+{Num}+)

%%
{Inval} {printf("%s : Invalid and its length %d\n" , yytext, yyleng);}
{Num} 	{printf("%s : Valid Number\n", yytext);}
{L} 	{printf("%s : Valid name and its length %d\n", yytext, yyleng);}
. 	    {printf("%s : Invalid and its length %d\n", yytext, yyleng);}
%%
int main()
{
	printf("Enter to check: ");
	yylex();
}

int yywrap()
{
	return 1;
}
