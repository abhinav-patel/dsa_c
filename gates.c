#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int and(int a,int b)
{
    if(a==1 && b==1)
        return 1;
    return 0;
}
int or(int a,int b)
{
    if(a==1||b==1)
        return 1;
    return 0;
}
int not(int a)
{
    if(a==1)
         return 0;
    return 1;
}
int main()
{
    int a[]={0,0,1,1},b[]={0,1,0,1};
    int x;
    printf("Truth table of AND gate\n");
    printf("A\tB\tOutput\n");
    for(int i=0;i<4;i++)
    {
        x=and(a[i],b[i]);
        printf("%d\t%d\t  %d\n",a[i],b[i],x);
    }

    printf("Truth table of OR gate\n");
    printf("A\tB\tOutput\n");
    for(int i=0;i<4;i++)
    {
        x=or(a[i],b[i]);
        printf("%d\t%d\t  %d\n",a[i],b[i],x);
    }

    printf("Truth table of NOT gate\n");
    printf("Input\tOutput\n");
    for(int i=0;i<=1;i++)
    {
        x=not(i);
        printf("%d\t  %d\n",i,x);
    }
    return 0;
}

