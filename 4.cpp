%{
#include<stdio.h>
%}

str1 ^(([ab]*[cd]*)+|[a][b]*[c]*[d]])$
str2 ^([01]*|[0]*[1]*)$
str3 ^(([0][1]*[2]|[0]*[2]+[1])+)$

%%
{str1} printf("str1\n");
{str2} printf("str2\n");
{str3} printf("str3\n");
.* printf("Prajapati loda\n");
%%


int yywrap (void){}

int main()
{
	yylex();
	return 0;
	
}
