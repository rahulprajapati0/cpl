%{
#include<stdio.h>
%}

keyword ^(begin|end|else)$
zero ^([0])$
id ^([a-zA-Z]+[0-9a-zA-Z]*)$
integer ^([1-9][0-9]*)$
signedint ^([+|-][0-9]+)$
rel ^(<|<=|>|>=|=|<>)$
spl ^([!@#$&*_])$

%%

{keyword} printf("Keyword\n");
{integer} printf("Integer\n");
{zero} printf("Integer\n");
{id} printf("Identifier\n");
{signedint} printf("si\n");
{rel} printf("rel\n");
{spl} printf("spl\n");
.* printf("Error\n");

%%

int yywrap (void){}

int main()
{
	yylex();
	return 0;
}


