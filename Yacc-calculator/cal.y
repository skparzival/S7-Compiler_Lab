%{
    #include<stdio.h>
    int flag=0, res=0;
%}
%token NUMBER
%left '+' '-'
%left '*' '/' '%'
%left '(' ')'
%%
E:E'+'E {res=$1+$3;}
|E'-'E {res=$1-$3;}
|E'*'E {res=$1*$3;}
|E'/'E {res=$1/$3;}
|E'%'E {res=$1%$3;}
|'('E')' {res=$2;}
| NUMBER {res=$1;}
;
%%
void main()
{
    printf("\nEnter Expression: ");
    yyparse();
    if(flag==0) {
    printf("\nEntered expression is Valid\n\n");
    printf("Result: %d\n",res);}
}
void yyerror()
{
    printf("\nEntered expression is Invalid\n\n");
    flag=1;
}