struct DSU
{
    vector<int> p; // parent (or negative size)

    DSU(int n) : p(n, -1) {}

    int find(int x)
    {
        return p[x] < 0 ? x : p[x] = find(p[x]);
    }

    void unite(int a, int b)
    {
        a = find(a);
        b = find(b);
        if (a == b)
            return;

        if (p[a] > p[b]) // means b is bigger since cnt is stored negative form so >
            swap(a, b);  // a becomes the new root

        p[a] += p[b]; // update size
        p[b] = a;     // merge b under a
    }
};

class Solution
{
public:
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>> &edgeList, vector<vector<int>> &queries)
    {

        auto lmda = [&](vector<int> &a, vector<int> &b)
        {
            return a[2] < b[2];
        };

        for (int i = 0; i < queries.size(); i++)
            queries[i].push_back(i);

        sort(edgeList.begin(), edgeList.end(), lmda);
        sort(queries.begin(), queries.end(), lmda);

        DSU dsu(n);

        vector<bool> res(queries.size(), 0);
        int j = 0;
        for (auto &q : queries)
        {
            int u = q[0], v = q[1], dis = q[2], idx = q[3];
            while (j < edgeList.size() && edgeList[j][2] < dis)
                dsu.unite(edgeList[j][0], edgeList[j][1]), j++;

            res[idx] = (dsu.find(u) == dsu.find(v)) ? 1 : 0;
        }
        return res;
    }
}; 