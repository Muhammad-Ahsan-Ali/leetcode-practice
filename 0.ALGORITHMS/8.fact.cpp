
const long long MOD = 1e9 + 7;
const int N = 1e6;

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

long long modInverse(long long p, long long q)
{
    return (p * myPow(q, MOD - 2)) % MOD;
}

vector<long long> fact(N + 1);
vector<long long> ifact(N + 1);

void countfact()
{
    fact[0] = 1;
    for (int i = 1; i <= N; i++)
        fact[i] = (i * fact[i - 1]) % MOD;

    ifact[N] = myPow(fact[N], MOD - 2);
    for (int i = N - 1; i >= 0; i--)
        ifact[i] = (ifact[i + 1] * (i + 1)) % MOD;
}
