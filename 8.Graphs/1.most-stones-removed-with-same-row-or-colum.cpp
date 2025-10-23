class DSU
{
    vector<int> p;

    DSU(int n) : p(n, -1);

    int findPrnt(int x)
    {
        return p[x] < 0 ? x : p[x] = findPrnt(p[x]);
    }

    void join(int a, int b)
    {
        if (p[a] > p[b])
            swap(a, b);

        p[a] += p[b];
        p[b] = a;
    }

    int size(int x)
    {
        return -p[findPrnt(x)];
    }
};

class Solution
{
public:
    int removeStones(vector<vector<int>> &stones)
    {
        int maxRow = 0;
        int minRow = 0;

        for (auto &i : stones)
        {
            maxRow = max(maxRow, i[0]);
            minRow = min(minRow, i[1]);
        }

        int n = maxRow + minRow + 1;
        DSU dsu(n);

        for (auto &&i : stones)
        {
            int row = i[0];
            int col = i[1] + maxRow + 1;
            dsu.join(row, col);
        }

        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (dsu.findPrnt(i) == i)
                cnt++;
        }
        return stones.size() - cnt;
    }
};