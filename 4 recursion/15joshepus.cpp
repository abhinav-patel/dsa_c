int jos(int n, int k)
{
    if (n == 1)
        return 0;
    else
        return (jos(n - 1, k) + k) % n;
}
// this result suffecient if the numbering started from zero
int jos2(int n, int k)
{
    return jos(n, k) + 1;
}//if numbering starts from 1;