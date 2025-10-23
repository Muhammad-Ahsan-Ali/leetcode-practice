class Solution
{
public:
    // Function to perform division without using multiplication, division, or mod operators
    int divide(int dividend, int divisor)
    {

        // If both dividend and divisor are the same, the result is 1
        if (dividend == divisor)
            return 1;

        // Boolean flag to determine if the result should be negative
        bool isNeg = (dividend < 0) ^ (divisor < 0);

        // Convert both dividend and divisor to long to avoid overflow and take absolute values
        long n = abs((long)dividend);
        long d = abs((long)divisor);

        long ans = 0; // Variable to store the quotient

        // Perform division using bit manipulation
        while (n >= d)
        {
            int pow = 0;

            // Find the highest power of 2 such that (divisor * 2^pow) <= dividend
            while (n >= (d << (pow + 1)))
            {
                pow++;
            }

            // Add 2^pow to the quotient
            ans += (1 << pow);

            // Subtract (divisor * 2^pow) from the dividend
            n -= (d << pow);
        }

        // Handle overflow cases when result exceeds 32-bit integer limits
        if (ans == (1L << 31) && isNeg)
        {
            return INT_MIN; // Return minimum integer value
        }
        if (ans == (1L << 31) && !isNeg)
        {
            return INT_MAX; // Return maximum integer value
        }

        // Return the final quotient with the correct sign
        return isNeg ? -ans : ans;
    }
};
