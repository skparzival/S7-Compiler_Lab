#include<stdio.h>
#include<stdlib.h>

int main()
{
    unsigned int n;
    int x,ch;
    printf("Enter N: ");
    scanf("%u",&n);
    printf("\n1.Loop Roll\n2.Loop UnRoll\n3.Exit\n");
    while(1)
    {
        printf("\nEnter your choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: x=roll(n);
                    printf("Count of 1's: %d\n",x);
                    break;
            case 2: x=unroll(n);
                    printf("Count of 1's: %d\n",x);
                    break;
            case 3: exit(0);
            default:printf("\nWrong Choice\n");

        }
    }
    return 0;
}

int roll(unsigned int n)
{
    int bits=0,i=0;
    while(n!=0)
    {
        if(n&1) bits++;
            n>>=1;
        i++;
    }
    printf("\nLoop Roll:\n");
    printf("No. of iterations: %d\n",i);
    return bits;
}

int unroll(unsigned int n)
{
    int bits=0,i=0;
    while(n!=0)
    {
        if(n&1) bits++;
        if(n&2) bits++;
        if(n&4) bits++;
        if(n&8) bits++;
            n>>=4;
        i++;
    }
    printf("\nLoop UnRoll:\n");
    printf("No. of iterations: %d\n",i);
    return bits;
}