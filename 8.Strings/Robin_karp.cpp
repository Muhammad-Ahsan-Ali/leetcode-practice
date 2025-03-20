int myPow(int x, int n)
{
    int ans = 1;
    int pow = n;

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

    return ans;
}

long calcHash(string str, int length)
{
    long hash = 0;
    int prime = 101;

    for (int i = 0; i < length; i++)
    {
        hash += str[i] * myPow(prime, i);
    }
    return hash;
}

long upadateHash(char prevChar, long prevHash, char newChar, int ptrnLength)
{
    int prime = 101;
    long newHash = (prevHash - prevChar) / prime;
    newHash = newChar * myPow(prime, ptrnLength - 1);
    return newHash;
}
bool rabin_karp(string str, string Ptrn)
{
    int n = str.length();
    int m = Ptrn.length();
    long hashPtrn = calcHash(Ptrn, m);
    long hashStr = calcHash(str, m);

    for (int i = 0; i <= n - m; i++)
    {
        if (hashStr == hashPtrn)
        {
            // Check if the substring matches
            if (str.substr(i, m) == Ptrn)
                return true;
        }

        // Update the hash for the next window
        if (i < n - m)
        {
            hashStr = upadateHash(str[i], hashStr, str[i + m], m);
        }
    }

    return false;
}
