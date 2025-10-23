class Solution
{
public:
    int distinctPrimeFactors(vector<int> &nums)
    {
        int n = nums.size();

        // Create a sieve array to mark prime numbers up to 1000
        vector<int> prime(1001, 1);

        // Implement Sieve of Eratosthenes to mark non-prime numbers
        for (int i = 2; i * i < 1001; i++)
        {
            if (prime[i] == 1)
            { // If i is a prime
                for (int j = i * i; j <= 1000; j += i)
                {
                    prime[j] = 0; // Mark multiples of i as non-prime
                }
            }
        }

        // Store all prime numbers in a separate vector
        vector<int> res;

        for (int i = 2; i < 1001; i++)
        {
            if (prime[i] == 1)
            {
                res.push_back(i); // Collect prime numbers
            }
        }

        int cnt = 0; // Counter for distinct prime factors

        // Check for prime factors in the given array
        for (int i : res)
        { // Iterate over prime numbers
            for (int j : nums)
            { // Iterate over numbers in the input array
                if (j % i == 0)
                {          // If i is a factor of j
                    cnt++; // Count this prime factor
                    break; // Move to the next prime to avoid double counting
                }
            }
        }

        return cnt; // Return the count of distinct prime factors
    }
};
