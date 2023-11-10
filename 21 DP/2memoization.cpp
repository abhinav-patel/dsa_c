//memoization method (top-down method) easy to write
int memo[n+1]={-1};
int fibb(int n)
{
    if(memo[n]==-1)
    {
        int res;
        if(n==0||n==1)
           res=n;
        else
           res=fib(n-1)+fib(n-2);
        memo[n]=res;
    }
    return memo[n];
}

//tabulation method (bottom to top method) faster
int fibo(int n)
{
    int f[n+1];
    f[0]=1;f[1]=1;
    for(int i=2;i<=n;i++)
    {
        f[i]=f[i-1]+f[i-2];
    }
    return f[n];
}