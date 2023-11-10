int binarySearch(int arr[], int n, int x)
{
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == x)
            return mid;
        else if (x < arr[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}
int BinarySearch2(int arr[], int low, int high, int x)
{
    if (low >= high)
        return -1;
    int mid = (low + high) / 2;
    if (arr[mid] == x)
        return mid;
    else if (arr[mid] < x)
        return BinarySearch2(arr, mid + 1, high, x);
    else
        return BinarySearch2(arr, low, mid - 1, x);
}
// O(log n) for successful search
// Theta(log n) for unsuccessful search

// 4 First occurance in array using binary search
int firOcc(int arr[], int n, int x)
{
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] > x)
            high = mid - 1;
        else if (arr[mid < x])
            low = mid + 1;
        else
        {
            if (mid == 0 || arr[mid - 1] != arr[mid])
                return mid;
            else
                high = mid - 1
        }
    }
    return -1;
}
// 5 index of last occurance using binary search
int lastOcc(int arr[], int n, int x)
{
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] < x)
            low = mid + 1;
        else if (arr[mid < x])
            high = mid - 1;
        else
        {
            if (mid != n - 1 || arr[mid] != arr[mid + 1])
                return mid;
            else
                low = mid + 1;
        }
    }
    return -1;
}
// 6 Counting the no of occurances in a sorted array using binary search
int count(int arr[], int n, int x)
{
    int first = firOcc(arr, n, x);
    if (first == -1)
        return 0;
    else
        return (lastOcc(arr, n, x) - first + 1);
}
// 8 finding squareroot
int sqroot(int x)
{
    int low = 1, high = x, ans = -1;
    while (low <= high)
    {
        int mid = (low + mid) / 2;
        int mSq = mid * mid;
        if (mSq == x)
            return mid;
        else if (msq > x)
            high = mid - 1;
        else
        {
            low = mid + 1;
            ans = mid;
        }
    }
    return ans;
}
// 9 searching in infite array using binary search
//  arrays cannot be infinite but they contain millions of entries which making nearly infinite
int infinite(int arr[], int x)
{
    if (arr[0] == x)
        return 0;
    int i = 1;
    while (arr[i] < x)
        i = i * 2;
    if (arr[i] == x)
        return i;
    return binarySearch(arr[], i / 2 + 1, i - 1, x);
}
// 10 searching an element in rotated array-using binary search
// after rotating also one half will be sorted no matter what
int search(int arr[], int n, int x)
{
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == x)
            return mid;
        if (arr[low] < arr[mid])
        {
            if (x >= arr[low] && x < arr[mid])
                high = mid - 1;
            else
                low = mid + 1;
        }
        else
        {
            if (x > arr[mid] && arr[high] >= x)
                low = mid + 1;
            else
                high = mid - 1;
        }
    }
}
// 11 Peak element-Greater than both of its neighbours
int getAPeak(int arr[], int n)
{
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if ((mid == 0 || arr[mid - 1] <= arr[mid]) && (mid == n - 1 || arr[mid + 1] <= arr[mid]))
            return mid;
        if (mid > 0 && arr[mid - 1] >= arr[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}
