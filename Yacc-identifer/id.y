%{
#include <stdio.h>
void yyerror();
int yylex();
int flag = 0;
%}

%token IDENTIFIER

%%
E : IDENTIFIER;
%%

void main()
{
    printf("Enter a valid identifier: ");
    yyparse();
    if (flag == 0)
        printf("\nValid Identifier!\n");
}

void yyerror()
{
    printf("\nInvalid Identifier!\n\n");
    flag = 1;
}