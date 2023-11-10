#include <iostream>
#include <unordered_set>
// 16 count distinct elements-put in unordered  set and get the size
int countDistinct(int arr[], int n)
{
    unordered_set<int> s(arr, arr + n);
    return s.size();
} // O(n) time and O(n) aux space

// 17 count frequency-put in hash map and increse its value with every appearance
int countfreq(int arr[], int n)
{
    unoredered_map<int, int> h;
    for (int x : arr)
        h[x]++;
    for (auto e : h)
        cout << e.first << " " << e.second << endl;
}

// 18 intersection-
int intersection(int a[], int b[], int m, int n)
{
    unordered_set<int> s;
    for (int i = 0; i < m; i++)
        s.insert(a[i]);
    int res = 0;
    for (int j = 0; i < n; j++)
    {
        if (s.find(b[j]) != s.end())
        {
            res++;
            s.erase(b[j]);
        }
    }
    return res;
}
// O(m+n) time and O(m) aux space

// 19 union -insert in unordered set both array elements and return the size

// 20 check if there is a pair present with a given sum int the array
bool isPair(int arr[], int n, int sum)
{
    unordered_set<int> s;
    for (int i = 0; i < n; i++)
    {
        if (s.find(sum - arr[i]) != s.end())
            return true;
        s.insert(arr[i]);
    }
    return false;
}

// 21- check if a sub array(continuous) present with sum 0;
bool is0subarray(int arr[], int n)
{
    unordered_set<int> h;
    int presum = 0;
    for (int i = 0; i < n; i++)
    {
        presum += arr[i];
        if (h.find(presum) != h.end())
            return true;
        if (presum == 0)
            return 0;
        h.insert(presum);
    }
    return false;
}

// 22 subarray(subarray) with given sum
bool is0subarray(int arr[], int n)
{
    unordered_set<int> h;
    int presum = 0;
    for (int i = 0; i < n; i++)
    {
        presum += arr[i];
        if (h.find(presum - sum) != h.end())
            return true;
        if (presum == sum)
            return true;
        h.insert(presum);
    }
    return false;
}

// 23-longest subarray with given sum
int maxlen(int arr[], int n, int sum)
{
    unordered_map<int, int> h;
    int presum = 0, res = 0;
    for (int i = 0; i < n; i++)
    {
        presum += arr[i];
        if (presum == sum)
            res = i + 1;
        if (h.find(presum) == h.end())
            h.insert({presum, i});
        if (h.find(presum - sum) != h.end())
            res = max(res, i - h[presum - sum]);
    }
    return res;
}

//*** 24 longest subarray with equal no of zeros and ones
//the problem will be same as above if we replace every zero with -1
int maxlen(int arr[], int n,)
{
    unordered_map<int, int> h;
    int presum = 0, res = 0;
    for (int i = 0; i < n; i++)
    {
        presum += arr[i];
        if (presum == 0)
            res = i + 1;
        if (h.find(presum) == h.end())
            h.insert({presum, i});
        if (h.find(presum) != h.end())
            res = max(res, i - h[presum - sum]);
    }
    return res;
}//O(n) time and aux space

//25 longest common span subarray with same sum in two arrays
//both are binary arrays
//sol-we will make a new array=a[i]-b[i] then find longest subarray with zero sum

//26longest subsequence of consequitive integers 
