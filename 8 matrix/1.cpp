// 6 boundary travresal of the matrix in clockwise
void bTraversal(int arr[m][n], int m, int n)
{
    if (m == 1)
        for (int i = 0; i < n; i++)
            printf("%d ", arr[0][i]);

    else if (n == 1)
        for (int i = 0; i < m; i++)
            printf("%d ", arr[i][0]);

    else
    {
        for (int i = 0; i < n; i++)
            printf("%d ", arr[0][i]);
        for (int i = 1; i < m; i++)
            printf("%d ", arr[i][n - 1]);
        for (int i = n - 2; i >= 0; i++)
            printf("%d ", arr[m - 1][i]);
        for (int i = m - 2; i >= 1; i++)
            printf("%d ", arr[i][0]);
    }
} // O(m+n) time

// 7 Transpose of a matrix
void transpose(int arr[][])
{
    for (int i = 0; i < m; i++)
        for (int j = i + 1; j < n; j++)
            swap(arr[i][j], arr[j][i]);
}

//8 rotate the matrix by 90 in anticlockwise
//transpose and then reverse each column

//9 spiral traversal of the matrix starting in clockwise direction
void spiralTraversal(int arr[][],int m,int n)
{
    int top=0,bottom=m-1,left=0,right=n-1;
    while(top<=bottom && left <=right)
    {
        for (int i = left; i <=right ; i++)
          printf("%d ",arr[top][i]);
        top++;
        
        for(int i=top;i<=bottom;i++)
           printf("%d ",arr[i][right]);
        right--;

        if(top<=bottom)
        {
            for(int i=right;i>=left;i--)
               printf("%d ",arr[bottom][i]);
            bottom--;
        }
        if(left<=right)
        {
            for(int i=bottom;i>=top;i--)
               printf("%d ",arr[i][left]);
            left++;
        }
        
    }
}

//10 search in a row wise and collumn wise sorted array-we start from top right corner
void search(int arr[][],int m,int n,int x)
{
    int i=0;j=n-1;
    while(i<m && j>=0)
    {
        if(arr[i][j]==x)
        {
            printf("Found %d at %d,%d",x,i,j);
            return;
        }
        else if(arr[i][j]>x)
            j--;
        else
           i++;
    }
    printf("not found");
}//O(m+n)

//11 median of a row wise sorted array

