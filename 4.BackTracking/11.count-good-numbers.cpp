class Solution
{
private:
    int mod = 1e9 + 7;

    long long myPow(long long x, long long n)
    {

        long long ans = 1;
        long long pow = n;

        while (pow > 0)
        {
            if (pow % 2 == 1)
            {
                ans = (ans * x) % mod;
                pow--;
            }
            else
            {
                x = (x * x) % mod;
                pow = pow / 2;
            }
        }

        return ans;
    }

public:
    int countGoodNumbers(long long n)
    {

        long long odd = n / 2;
        long long even = (n / 2) + (n % 2);

        return (myPow(4, odd)) * (myPow(5, even)) % mod;
    }
};