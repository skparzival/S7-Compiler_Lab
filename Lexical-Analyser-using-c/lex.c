#include<stdio.h>
#include<ctype.h>
#include<string.h>

int main()
{
    FILE *input;
    int j=0;
    int i,flag;
    char ch,str[20];
    input = fopen("input.c","r");
    char keyword[30][30] = {"int","main","if","else","do","while","include","void","printf","scanf"};
    printf("Lexeme \t\tToken \n\n");
    while(!feof(input))
    {
        i=0;
        flag=0;
        ch=fgetc(input);
        if( ch=='+' || ch== '-' || ch=='*' || ch=='/' )
        {
            printf("%c\t\t Operator\n",ch);
        }
        else if( ch==';' || ch=='{' || ch=='}' || ch=='(' || ch==')' || ch=='?' || ch=='@' ||ch=='!'|| ch=='%')
        {
            printf("%c\t\t Special symbol\n",ch);
        }
        else if(isdigit(ch))
        {
            printf("%c\t\t Digit\n",ch);
        }
        else if(isalpha(ch))
        {
            str[i]=ch;
            i++;
            ch=fgetc(input);
            while(isalnum(ch) && ch!=' ')
            {
                str[i]=ch;
                i++;
                ch=fgetc(input);
            }
            str[i]='\0';
            for(j=0;j<=30;j++)
            {
                if(strcmp(str,keyword[j])==0)
                {
                    flag=1;
                    break;
                }
            }
            if(flag==1)
            {
                printf("%s\t\t Keyword\n",str);
            }
            else
            {
                printf("%s\t\t Identifier\n",str);
            }
        }
    }
    fclose(input);
    return 0;
}