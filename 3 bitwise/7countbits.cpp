//counting the no of set bits in the no
int count1(int n)
{
    int res=0;
    while(n>0)
    {
        if(n%2!=0)   //res=res+(n&1)
           res++;    
        n=n/2;      //n=n>>1
    }
    return res;
}//O(n)

//Brian Kerningam's algorithm
int count2(int n)
{
    int res=0;
    while(n>0)
    {
        n=n&(n-1);
        res++;
    }
    return res;
}//O(bit count)

//Lookup table method for 32 bits
int table[256];
void initialize()
{
    table[0]=0;
    for(int i=1;i<256;i++)
       table[i]=(i&1)+table(i/2);
}
int count3(int n)
{
    int res=table[n&0*ff];
    res=res>>8;
    res=res+table[n&0*ff];
    res=res>>8;
    res=res+table[n&0*ff];
    res=res>>8;
    res=res+table[n&0*ff];
    return res;
}//O(1) 