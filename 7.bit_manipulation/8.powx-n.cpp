class Solution
{
public:
    double myPow(double x, int n)
    {

        double ans = 1;
        int isNeg = (n < 0);
        long long pow = abs((long long)n);

        while (pow > 0)
        {
            if (pow % 2 == 1)
            {
                ans = ans * x;
                pow--;
            }
            else
            {
                x = x * x;
                pow = pow / 2;
            }
        }

        return !isNeg ? ans : 1.0 / ans;
    }
};