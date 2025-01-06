%{
int has_upper = 0;
int has_lower = 0;
int has_digit = 0;
int has_symbol = 0;
int length = 0;
%}

lower [a-z]+
Upper [A-Z]+
Num [0-9]+
Symbol [!@#$%^&*()_+\-=\[\]{};\\|,.<>\/?]+

%%
{lower}		{has_lower = 1; length += yyleng;}
{Upper} 	{has_upper = 1; length += yyleng;}
{Num} 		{has_digit = 1; length += yyleng;}
{Symbol} 	{has_symbol = 1; length += yyleng;}
.|\n 		{length += yyleng;}
%%

int main() 
{
	char password[100];
	printf("Enter your password: ");
	scanf("%s", password);
	yy_scan_string(password);
	yylex();
	if (length < 6) printf("Password is too short. Minimum length is 6 characters.\n");
	else if (has_upper && has_lower && has_digit && has_symbol) printf("Strong Password\n");
	else if (has_upper && has_lower && has_digit) printf("Moderate Password\n");
	else if (has_upper && has_lower) printf("Weak Password\n");
	else printf("Password doesn't meet the minimum criteria.\n");
	return 0;
}

int yywrap()
{
	return 1;
}
