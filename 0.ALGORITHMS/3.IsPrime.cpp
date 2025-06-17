
bool isPrime(ll x)
{
    if (x == 2 || x == 3)
        return true;

    if (x == 1 || x % 2 == 0 || x % 3 == 0)
        return false;

    for (ll i = 5; i * i <= x; i += 6)
    {
        if (x % i == 0 || x % (i + 2) == 0)
        {
            return false;
        }
    }
    return true;
}
