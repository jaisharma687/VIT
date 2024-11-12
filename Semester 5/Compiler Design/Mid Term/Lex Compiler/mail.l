Institutional 	[a-zA-Z0-9._%+-]+@vitstudent.ac.in
Gmail 			[a-zA-Z0-9._%+-]+@gmail.com
Outlook 		[a-zA-Z0-9._%+-]+@outlook.com
Unknown 		[a-zA-Z0-9._%+-]+@[a-zA-Z0-9._]+\.[a-zA-Z]{2,4}

%%
{Institutional} 	{ printf("Institutional Email ID\n"); }
{Gmail} 			{ printf("Gmail Email ID\n"); }
{Outlook} 			{ printf("Outlook Email ID\n"); }
{Unknown} 			{ printf("Unknown Domain\n"); }
.|\n
%%

int main() {
	char email[100];
	printf("Enter your email ID: ");
	scanf("%s", email);
	int yylval = strlen(email);
	yy_scan_string(email);
	printf("Length of the email ID: %d\n", yylval);
	yylex();
	return 0;
}

int yywrap()
{
	return 1;
}