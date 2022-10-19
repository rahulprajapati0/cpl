%{
	#include<stdio.h>
%}

spl ^([!@#$&*_])$
token1 ^([!@#$&*_][0-9a-zA-Z]*)$
token2 ^([0-9][!@#$&*_a-zA-Z]*)$
token3 ^([a-zA-Z][!@#$&*_0-9]*[a-zA-Z])$



%%
{spl} printf("spl\n");
{token1} printf("t1\n");
{token2} printf("t2\n");
{token3} printf("t3\n");
.* printf("error\n");
%%

int yywrap (void)
{
	return 0;
}

int main()
{
	yylex();
	return 0;
}
