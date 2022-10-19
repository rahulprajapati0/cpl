%{
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
%}

keyword ^(begin|end|else)$
zero ^([0])$
id ^([a-zA-Z]+[0-9a-zA-Z]*)$
integer ^([1-9][0-9]*)$
signedint ^([+|-][0-9]+)$
rel ^(<|<=|>|>=|=|<>)$
spl ^([!@#$&*_])$
and_op ^(&&)$
or_op ^(||)$
dot_op ^(.)$
ptr_op ^(->)$
op ^([-+*/])$

%%

{keyword} {
		int i = 0;
		for(i = 0;yytext[i] != '\0';i++) 
			printf("%c",(char)((int)yytext[i] - 32));
      	}
{integer} printf("Integer\n");
{zero} printf("Integer\n");
{id} printf("Identifier\n");
{signedint} printf("si\n");
{rel} printf("rel\n");
{spl} printf("spl\n");
{and_op} printf("and_op\n");
{op} printf("%c\n",yytext[0]);
.* printf("Error\n");

%%

int yywrap (void){}

int main()
{
	yylex();
	return 0;
}


