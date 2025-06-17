 
class FT
{
private:
    vector<long long> f;

public:
    // Constructor
    FT(long long size)
    {
        f.assign(size + 2, 0);
    }

    // Point update: add 'add' to index 'i'
    void update(long long i, long long add)
    {
        while (i < n)
        {
            f[i] += add;
            i = i + (i & (-i));
        }
    }

    // Prefix sum query: sum from 1 to i
    long long sum(long long i)
    {
        long long s = 0;
        while (i > 0)
        {
            s += f[i];
            i = i - (i & (-i));
        }
        return s;
    }

    // Range sum: sum from l to r
    long long rangeSum(long long l, long long r)
    {
        return sum(r) - sum(l - 1);
    }
};
