const long long MOD = 1e9 + 7;

long long ncr(int n, int r)
{
    long long ans = 1;
    if (r > n - r)
        r = n - r;

    for (int i = 0; i < r; i++)
    {
        ans = (ans * (n - i) / (i + 1));
    }

    return ans;
}

// n!/(n-r)!r!
// n*n-1*n-2*(n-r)! / (n-r)!r!
// n*n-1*n-2* /  r!
