%{
    int ch=0,digit=0,pos=0,neg=0,spl=0,spc=0,op=0;
%}
%%
[0-9] digit++,pos++;
[a-zA-Z] ch++;
[-][0-9] neg++,digit++;
[!@#$&()<>,.\{}:;"] spl++;
[ \n\t] spc++;
[+-/*^%=] op++;
%%

int main()
{
    yyin = fopen("input.c","r");
    yylex();
    printf("Character count:\t\t %d\n",ch);
    printf("Digit count:\t\t\t %d\n",digit);
    printf("Positive count:\t\t\t %d\n",pos);
    printf("Negative count:\t\t\t %d\n",neg);
    printf("Special character count:\t %d\n",spl);
    printf("White space count:\t\t %d\n",spc);
    printf("Operator count:\t\t\t %d\n",op);
}
int yywrap()
{
    return 1;
}