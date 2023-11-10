// 12-Given a sorted array and a no x, find if there is a pair with sum eqaul to x  in the array
bool issPair(int arr[], int n, int x)
{
    int left = 0, right = n - 1;
    while (left < right)
    {
        if (arr[left] + arr[right] == x)
            return true;
        else if (arr[left] + arr[right] > x)
            right--;
        else
            left++;
    }
    return false;
}
// O(n) time and O(1) space
bool isPair(int arr[], int low, int high, int x)
// Given a sorted array and a no x, find if there is a triplet with sum eqaul to x  in the array
bool isTiplet(int arr[], int x)
{
    for (int i = 0; i < n; i++)
    {
        if (isPair(arr, i + 1, n - 1, x - arr[i]))
            return true
    }
    return false;
}
//therefore if the array is unsorted  the first sort the array and then apply this logic 
//O(n logn)+O(n^2)   for sorting and then this function
//=O(n^2) 
//with hashing this can be done in O(n^2) time and O(n) auxillary space but for already sorted array this wiil be best

//13 Median of two sorted arrays of diff sizes
//We assume the first array is smaller than the second array,if not then we swap the array
double getMedian(int a1[],int a2[],int n1,int n2)
{
    int begin =0,end=n1
    while(begin<=end)
    {
        int i1=(begin+end)/2;
        int i2=((n1+n2+1)/2)-i1;

        int min1=(i1==n1)?INT_MAX:a1[i1];
        int min2=(i2==n2)?INT_MAX:a2[i2];
        int max1=(i1==0)?INT_MIN:a1[i1-1];
        int max2=(i2==0)?INT_MIN:a2[i2-1];

        if(max1<=min2 && max2<=min1)
        {
            if((n1+n2)%2==0)
               return ((double)(max(max1,max2)+min(min1,min2))/2);
            else
              return (double)max(max1,max2);
        }
        else if(max1>min2)
           end=i1-1;
        else
           begin1=i1+1;
    }
}
//Time complexity O(log n1)
//16-Reapeating element-only one element is repeating any no of times


//17 Allocate minimum no of pages-array of no of pages in the books is given and the no studennts is given
//every student should read contiguous books only and the maximum no of pages read by any student should be minimized
//basically distributing the books so minimum gets every student

int minPages(int arr[],int n,int k)
{
    int sum=0,mx=0;
    for(int i=0;i<n;i++)
    {
        sum=sum+arr[i];
        mx=max(mx,arr[i]);
    }
    int low=mx,high=sum,res=0;
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(isFeasible(arr,n,k,mid))
        {
            res=mid;
            high=mid-1;
        }
        else 
            low=mid+1;
    }
    return res;
}
bool isFeasible(int arr[],int n,int k,int ans)
{
    int req=1,sum=0;
    if(int i=0;i<n;i++)
    {
        if(num+arr[i]>ans)
        {
            req++;
            sum=arr[i];
        }
        else
            sum=sum+arr[i];
    }
    return (req<=k);
}
//O(n*log(sum-mx))