class DSU
{
    vector<int> p;

public:
    DSU(int n) : p(n, -1) {};

    int findPrnt(int x) { return p[x] < 0 ? x : p[x] = findPrnt(p[x]); }

    void join(int a, int b)
    {

        a = findPrnt(a);
        b = findPrnt(b);
        if (a == b)
            return;
        if (p[a] > p[b])
            swap(a, b);

        p[a] += p[b];
        p[b] = a;
    }

    int size(int x) { return -p[findPrnt(x)]; }
};

class Solution
{
public:
    int removeStones(vector<vector<int>> &stones)
    {
        int maxRow = 0;
        int maxCol = 0;

        for (auto &i : stones)
        {
            maxRow = max(maxRow, i[0]);
            maxCol = max(maxCol, i[1]);
        }

        int n = maxRow + maxCol + 2;
        DSU dsu(n);

        for (auto &&i : stones)
        {
            int row = i[0];
            int col = i[1] + maxRow + 1;
            dsu.join(row, col);
        }

        unordered_set<int> st;
        for (auto &&i : stones)
        {
            int row = i[0];
            st.insert(dsu.findPrnt(row));
        }
        return stones.size() - st.size();
    }
};