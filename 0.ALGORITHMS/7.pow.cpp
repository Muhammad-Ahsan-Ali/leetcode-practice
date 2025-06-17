long long myPow(long long x, long long n)
{
    long long ans = 1;
    long long pow = n;

    while (pow > 0)
    {
        if (pow % 2 == 1)
        {
            ans = (ans * x) % MOD;
            pow--;
        }
        else
        {
            x = (x * x) % MOD;
            pow = pow / 2;
        }
    }

    return ans;
}