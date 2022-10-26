%{
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "y.tab.h"
%}

%%
"i"		   {return (TOK_IF);}
"t"		   {return (TOK_THEN);}
"e"		   {return (TOK_ELSE);}
"a"		   {return (TOK_A);}
"b"		   {return (TOK_B);}
"\n"		   { return (newline); }
.    {fprintf(stderr,"Invalid input\n"); 
        exit(1);}
%%

int yywrap() {return -1;}