#include <stdio.h>
// 8.second largest element
int secLargest(int arr[], int n)
{
    int res = -1, largest = 0;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > arr[largest])
        {
            res = largest;
            largest = i;
        }
        else if (arr[i] != arr[largest])
        {
            if (res == -1 || arr[i] > arr[res])
                res = i;
        }
    }
    return res;
}
// 9.check if array sorted
bool isSorted(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        if (arr[i] < arr[i - 1])
            return false;
    }
    return true;
}
// 10 reverse an array
void reverse(int arr, int n)
{
    int low = 0, high = n - 1;
    while (low < high)
    {
        int temp = arr[low];
        arr[low] = arr[high];
        arr[high] = temp;
        low++;
        high--;
    }
}
// 11.remove duplicates from array
int remoDup(int arr, int n)
{
    int res = 1;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] != = arr[res])
        {
            arr[res] = arr[i];
            res++;
        }
    }
    return res;
}
// 12 move zeros to the end
void moveZeros(int arr[], int n)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != 0)
        {
            swap(arr[i], arr[count]);
            count++;
        }
    }
}
// 13left rotate an array by d places
void leftRotate(int arr[], int n, int d)
{
    reverse(arr, 0, d - 1);
    reverse(arr, d, n - 1);
    reverse(arr, 0, n - 1);
}
void rightRotate(int arr[], int n, int d)
{
    reverse(arr, 0, n - 1);
    reverse(arr, d, n - 1);
    reverse(arr, 0, d - 1);
}
// time complexity=O(d+n-d+n)=O(2n)=O(n)
// aux space O(1)

// 15.Leaders in array-when the num has no greater no then it in its right part of array
void leaders(int arr[], int n)
{
    int curr_lead = arr[n - 1];
    printf("%d,", curr_lead);
    for (int i = n - 2; i >= 0; i++)
    {
        if (arr[i] > curr_lead)
        {
            curr_lead = arr[i];
            printf("%d,", curr_lead);
        }
    }
}
// 16
int max_diff(int arr[], int n) // to calculate max diff in array
{
    int re = arr[1] - arr[0], minval = arr[0];
    for (int i = 1; i < n; i++)
    {
        res = max(res, arr[i] - minval);
        minval = min(minval, arr[i]);
    }
    return res;
}
// 17 printing the frequency in a sorted array
void freq(int arr[], int n)
{
    int freq = 1, i = 1;
    while (i < n)
    {
        while (i < n && arr[i] == arr[i - 1])
        {
            freq++;
            i++;
        }
        printf("%d  %d", arr[i - 1], freq);
        i++;
        freq = 1;
    }
    if (n == 1 || arr[n - 1] != arr[n - 2])
        printf("%d  1 ", arr[n - 1]);
}
// 18 Stock buy sell problem
int maxProfit(int price[], int n) // stock buy sell problem
{
    int profit = 0;
    for (int i = 1; i < n; i++)
    {
        if (price[i] > price[i - 1])
            profit = profit + (price[i] - price[i - 1]);
    }
    return profit;
}
// 20 trapping rain water problem
int getWater(int arr[], int n)
{
    int res = 0;
    int lmax[n], rmax[n];
    lmax[0] = arr[0];
    for (i = 1; i < n; i++)
        lmax[i] = max(arr[i], lmax[i - 1]);
    rmax[n - 1] = arr[n - 1];
    for (i = n - 2; i >= 0; i--)
        rmax[i] = max(arr[i], rmax[i + 1]);
    for (int i = 1; i < n - 1; i++)
        res = res + (min(lmax[i], rmax[i]) - arr[i]);
    return res;
}
// 21 maximum consecutive ones
int maxConse(boolean arr[], int n)
{
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
            curr = 0;
        else
        {
            curr++;
            res = max(res, curr);
        }
    }
    return res;
} // O(n)

// 22 maximu sum subarray
int maxSum(int arr[], int sum)
{
    int res = arr[0];
    int maxEnding = arr[0];
    for (int i = 1; i < n; i++)
    {
        maxEnding = max(maxEnding + arr[i], arr[i]);
        res = max(res, maxEnding);
    }
    return res;
}
// 23 Maximum Length Even odd subarrray
int maxEvenOdd(int arr[], int n)
{
    int res = 1, curr = 1;
    for (int i = 1; i < n; i++ 0)
    {
        if ((arr[i] % 2 == 0 && arr[i - 1] % 2 != 0) || (arr[i] % 2 != 0 && arr[i - 1] % 2 == 0))
        {
            curr++;
            res = max(res, curr);
        }
        else
            curr = 1;
    }
    return res;
}
// 24 maximum sum subArray in circular array
int overallMaxSum(int arr[], int n)
{
    int maxSum = maxSum(arr, n); // 22
    if (maxSum < 0)
        return maxSum;
    int arrSum = 0;
    for (int i = 0; i < n; i++)
    {
        arrSum = arrSum + arr[i];
        arr[i] = -arr[i];
    }
    int maxCircular = arrSum + maxSum(arr, n);
    return max(maxSum, maxCircular);
} // O(n) time

// 25Majority element-element appear more than n/2 times
int findMajority(int arr[], int n)
{
    int res = 0, count = 1;
    for (int i = 1; i < n; i++)
    {
        if (arr[res] == arr[i])
            count++;
        else
            count--;
        if (count == 0)
        {
            res = i;
            count = 1
        }
    }
    count = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == arr[res])
            count++;
        if (count <= n / 2)
            return res;
    }
}
// 27Window Sliding Technique-Maximum sum of k consicutive elements
int max(int arr[], int n, int k)
{
    int currsum = 0;
    for (int i = 0; i < k; i++)
        currsum += arr[i];
    int maxsum = currsum;
    for (int i = k; i < n; i++)
    {
        currsum += arr[i] - arr[i - k];
        maxsum = max(maxsum, currsum);
    }
    return maxsum;
}
// 28 prefix Sum-when to perform multiple queries on an array  then we do preprocessing on the
// array which may take O(n) or greater time but then the queries can be solved in O(1) time
void prefixSum(int arr[], int n)
{
    int prefix[n];
    prefix[0] = arr[0];
    for (int i = 1; i < n; i++)
        prefix[i] = prefix[i - 1] + arr[i];cmc
}
int getSum(int prefix[], int l, int r)
{
    if (l != 0)
        return prefix[r] - prefix[l - 1];
    else
        return prefix[r];
}
// find if the array has an equillibrium point-point whose left sum and right sum are equal
bool isEqPoint(int arr[], int n)
{
    int ssum = 0;
    for (int i = 0; i < n; i++)
        sum = sum + arr[i];
    int lsum = 0;
    for (int i = 0; i < n; i++)
    {
        if (lsum == sum - arr[i])
            return true;
        lsum += arr[i];
        sum -= arr[i]
    }
    return false;
}


