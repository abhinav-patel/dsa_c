// 1.count frequencies in a given string
void freq(string str)
{
    int count[26]={0};
    for(int i=0;i<str.length();i++)
    {
        count[str[i]-'a']++;
    }
    for(int i=0;i<26;i++)
    {
        if(count[i]>0)
            cout<<(char)(i+'a')<<" "<<cout[i]<<endl;
    }
}

//4 checking palindrome   
//naive-this requires auxillary space and requires time both O(n)
bool palindrome(string str)
{
    string rev=str;
    reverse(reverse.begin,reverse.end);
    return(rev==str);
}
//efficient
bool ispalindrome(string &str)// reference used becuse it will unnecessary copying 
{
    int begin=0;
    int end=str.length()-1;
    while(end>begin)
    {
        if(str[begin]!=str.end)
            return false;
        begin++;
        end--;
    }
    return true;
}// constant time and no auxillary space

//5.if subsequence
bool isSubsequence(string s1,string s2,int n,int m)
{
    int i=0,j=0;
    for(;i<n&&j<m;i++)
    {
        if(s1[i]==s2[j])
            j++;
    }
    return (j==m);
}

//6.check if the strings are anagram-both strings contain all characters with same frequencies but can be jumbled
//naive-sort both strings and check if both of them are equal-time O(nlog n)
//efficient- use frequency counting method
const int CHAR 256;
bool anangram(string s1,string s2)
{
    if(s1.length()!=s2.length())
       return false;
    int count[CHAR]={0};
    for(i=0;i<s1.length();i++)
    {
        count[s1[i]]++;
        count[s2[i]]--;
    }
    for(int i=0;i<CHAR;i++)
       if(count[i]!=0)
           return false;
    return true;
}

//7.Leftmost repeating character
//brute force- two nested loops
//better approach-count frequencies of using above method and then traverse the loop for the string and print the first char with frequency greater than 1
//efficient approach-
int leftmost(string str)
{
    int fIndex[CHAR];
    fill(fIndex,fIndex+CHAR,-1);
    int res=INT_MIN;
    for(int i=0;i<str.length();i++)
    {
        int fi=fIndex[str[i]]=i;
        if(fi==-1)
            fIndex[str[i]]=i;
        else
            res=min(res,fi);
    }
    return (res==INT_MAX)?-1:res;
}

