bool isPalindrome(string &str,int start ,int end)
{
    if(start>=end)
       return true;
    return (str[start]==str[end])&&isPalindrome(str,start+1,end-1);
}
//in c++ we have to pass the string reference
//T(n)=T(n-2)+O(1)
//O(n) time complexity and O(n) aux space
int digiSum(int n)
{
    if(n<=9)
       return n;
    else 
       return digiSum(n/10)+n%10;
}
//time and space complexity O(d)
//iterative better as time and space complexities are O(d) and O(1)

//Rope cutting problem we have to cut the rop in mazximum possible parts from the given options
//eg length=23 and a=13 b=12 c=11 
//then there will be two parts 11 and 12
int maxpieces(int n,int a,int b,int c)
{
    if(n==0)
       return  0;
    if(n<0)
       return -1;
    int res=max(maxpieces(n-a,a,b,c),maxpieces(n-b,a,b,c),maxpieces(n-c,a,b,c));
    if(res==-1)
       return -1;
    return res+1;
}
//time complexity O(3^n)
//better solved with Dp
string curr="";
int i=0;
subsets(s,curr,i);
void subsets(string s,string curr,int i)
{
    if(i==s.length())
    {
        printf(s);
        return;
    }
    subsets(s,curr,i+1);
    subsets(s,curr+s[i],i+1);
}
//this program checks if there is any subset with the given sum
int SumSubsets(int arr[],int n,int sum)
{
    if(n==0)
       return (sum==0)?1:0;
    return SumSubsets(int arr[], n-1,int sum)+SumSubsets(arr[],n-1,sum-arr[n-1]);   
}