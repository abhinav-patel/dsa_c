void power(string str)
{
    int n=str.length();
    int size=pow(2,n);
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i&(1<<j)!=0)
                print(str[j]);
        }
        printf("\n");
    }
}
//O(2^n * n) time 