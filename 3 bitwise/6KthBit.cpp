#include <stdio.h>
void kbit(int n,int k) //right shift
{
    if(n>>(k-1)&1==1)
       printf("Yes");
    else
       printf("no");
}
void kbit1(int n,int k)
{
    if(n&(1<<(k-1))!=0)
       printf("Yes");
    else
       printf("no");
}