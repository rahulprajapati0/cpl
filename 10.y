%{
#include <stdio.h>
#include <stdlib.h>
int yylex();
int yyerror(char *s);
%}

%token TOK_IF TOK_THEN TOK_ELSE TOK_A TOK_B newline

%%

// S -> iCtS | iCtSeS | a
// C -> b

ST : S newline {printf("Valid\n"); return 1;}
   | error newline   {printf("Invalid\n"); return 1;}

S : TOK_IF C TOK_THEN S | TOK_IF C TOK_THEN S TOK_ELSE S | TOK_A
C : TOK_B

  ;

%%

int yyerror(char* s) { return 0; }

int main()
{
    while(1)
      yyparse();
    return 0;
}