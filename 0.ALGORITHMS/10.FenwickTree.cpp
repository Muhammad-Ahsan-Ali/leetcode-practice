
class FT
{
private:
    vector<long long> f;
    int n;

public:
    FT(const vector<long long> &arr)
    {
        n = arr.size();
        f.assign(n + 1, 0);

        for (int i = 0; i < n; i++)
        {
            update(i + 1, arr[i]); // 1-based indexing
        }
    }

    // Point update: add 'add' to index 'i'
    void update(long long i, long long add)
    {

        while (i <= n)
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

    // Binary uplifting finding prefix sum lower bound

    long long find(int val)
    {
        int idx = 0, prevSum = 0;
        for (int i = log2(n); i >= 0; i--)
        {
            if (ft[idx + (1 << i)] + prevSum < val)
            {
                idx += (1 << i);
                prevSum += ft[idx + (1 << i)];
            }
        }

        return idx + 1;
    }
};
