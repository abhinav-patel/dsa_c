//only oddd occuring no.
int findOdd(int arr[],int n)
{
    int res=0;
    for(i=0;i<n;i++)
        res=res^arr[i];
    return res;
}
//x^0=x   x^x=0

//array contains nos from 1 to (n+1) once only and one no is missing.
int findMisssing(int arr[],int n)
{
    
}