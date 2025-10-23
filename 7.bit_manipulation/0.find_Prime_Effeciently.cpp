bool isPrime(int n)
{
    if (n < 2)
        return false; // 0 and 1 are not prime
    if (n == 2 || n == 3)
        return true; // 2 and 3 are prime numbers
    if (n % 2 == 0 || n % 3 == 0)
        return false; // Eliminate multiples of 2 and 3

    // Check divisibility from 5 to sqrt(n), skipping even numbers
    for (int i = 5; i * i <= n; i += 6)
    {
        if (n % i == 0 || n % (i + 2) == 0)
        {
            return false; // If divisible by any i or i+2, it's not prime
        }
    }
    return true;
}
