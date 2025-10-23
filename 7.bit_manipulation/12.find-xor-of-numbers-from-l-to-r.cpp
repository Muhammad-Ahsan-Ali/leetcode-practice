class Solution
{
private:
    int xorTillN(int n)
    {
        int offset = n % 4;
        if (offset == 1)
            return 1;
        if (offset == 2)
            return n + 1;
        if (offset == 3)
            return 0;
        if (offset == 0)
            return n;
    }

public:
    int findXOR(int l, int r)
    {
        return xorTillN(l - 1) ^ xorTillN(r);
    }
};