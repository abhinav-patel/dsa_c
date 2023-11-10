#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
void swap(int* xp, int* yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
//insertion sort
void insertion(int a[],int n)
{
    int j;int key;
    for(j=1;j<=n-1;j++)
    {
        key=a[j];
        int i=j-1;
        while(i>=0&&a[i]>key)
        {
            a[i+1]=a[i];
            i=i-1;
        }
        a[i+1]=key;
    }
}
//merge sort
void merge(int a[],int low,int mid,int high)
{
    int l[maxsize],i,j,k;
    i=low;
    j=mid+1;
    k=low;
    while(i<=mid && j<=high)
    {
        if(a[i]<=a[j])
            l[k++]=a[i++];
        else
            l[k++]=a[j++];
    }
    while(i<=mid)
        l[k++]=a[i++];
    while(j<=high)
        l[k++]=a[j++];
    for(i=low;i<=high;i++)
        a[i]=l[i];
}
void merge_sort(int a[],int high,int low)
{
    int mid ;
    if(low<high)
    {
        mid=(low+high)/2;
        merge_sort(a,low,mid);
        merge_sort(a,mid+1,high);
        merge(a,low,mid,high);
    }
}
/*bubble sort-compares the adjacent elements and in one pass the last element is sorted ie. the maximum 
element reches the last element*/
//O(n^2) time
//it is stable as well as Inplace algorithm
void bubbleSort(int arr[], int n)
{
    int i, j;
    int flag=0;
    for (i = 0; i < n - 1; i++)
    {
        flag=0;
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
                flag=1;
            }
        }
        if(flag==0)
            break;
    }  
}
//selection sort
void selectionSort(int arr[], int n)
{
    int i, j, min_idx;
    int c=0,d=n-1;
    for (i = 0; i < n-1; i++)
    {
        min_idx = i;
        for (j = i+1; j < n; j++)
        {
           c++;
           if (arr[j] < arr[min_idx])
              min_idx = j;
        }
 
        if(min_idx != i)
        {
            swap(&arr[min_idx], &arr[i]);
        }
    }
    printArray(arr,n);
    printf("%d\n%d",c,d);
}
//quick sort
//Lomuto partition method 
int partition1(int arr[], int low, int high)
{
    int pivot = arr[high]; 
    int i= (low- 1); 
    for (int j = low; j <= high - 1; j++) 
    {
        if (arr[j] < pivot)
        {
            i++; 
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
//Hoare Partition Method
int partition2(int arr[],int low,int high)
{
    int left,right,t,pivot;
    left=low;
    right=high;
    pivot=arr[left];
    while(1)
    {
        while(left<=right && arr[left]<=pivot)
            left++;
        while(left<=right && arr[right]>=pivot)
            right--;
        if(left>right)
            break;
        else
        {
                t=arr[left];
                arr[left]=arr[right];
                arr[right]=t;
        }
    }
    t=arr[low];
    arr[low]=arr[right];
    arr[right]=t;
    return right;
}
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
//heap sort
void heapify(int arr[], int N, int i)
{
   
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;
    if (left < N && arr[left] > arr[largest])
        largest = left;
    if (right < N && arr[right] > arr[largest])
        largest = right;
    if (largest != i)
    {
        swap(&arr[i], &arr[largest]);
        heapify(arr, N, largest);
    }
} 
void heapSort(int arr[], int N)
{
    for (int i = N / 2 - 1; i >= 0; i--)
        heapify(arr, N, i);
    printArray(arr, N);
    for (int i = N - 1; i >= 0; i--) 
    {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}
   