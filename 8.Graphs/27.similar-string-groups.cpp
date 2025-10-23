struct DSU
{
    vector<int> p;

    DSU(int n) : p(n, -1) {}

    int findParent(int x) { return p[x] < 0 ? x : p[x] = findParent(p[x]); }

    void unite(int a, int b)
    {
        a = findParent(a);
        b = findParent(b);
        if (a == b)
            return;

        if (p[a] > p[b])
            swap(a, b);

        p[a] += p[b];
        p[b] = a;
    }
};

class Solution
{
public:
    int numSimilarGroups(vector<string> &strs)
    {
        int n = strs.size();
        DSU dsu(n);

        unordered_map<string, int> indexes;
        for (int i = 0; i < n; i++)
            indexes[strs[i]] = i;

        function<void(string, int)> storeAllPos = [&](string str, int idx) -> void
        {
            int m = str.length();
            for (int i = 0; i < m; i++)
                for (int j = i + 1; j < m; j++)
                {
                    swap(str[i], str[j]);
                    if (indexes.count(str))
                        dsu.unite(indexes[str], idx);
                    swap(str[i], str[j]);
                }
        };

        for (int i = 0; i < n; i++)
            storeAllPos(strs[i], i);

        int cnt = 0;
        unordered_set<int> groups;
        for (int i = 0; i < n; i++)
        {
            int prnt = dsu.findParent(i);
            groups.insert(prnt);
        }

        return groups.size();
    }
};

// optimization

struct DSU
{
    vector<int> p;

    DSU(int n) : p(n, -1) {}

    int findParent(int x) { return p[x] < 0 ? x : p[x] = findParent(p[x]); }

    void unite(int a, int b)
    {
        a = findParent(a);
        b = findParent(b);
        if (a == b)
            return;

        if (p[a] > p[b])
            swap(a, b);

        p[a] += p[b];
        p[b] = a;
    }
};

class Solution
{
public:
    int numSimilarGroups(vector<string> &strs)
    {
        int n = strs.size();
        DSU dsu(n);

        unordered_map<string, int> indexes;
        for (int i = 0; i < n; i++)
            indexes[strs[i]] = i;

        function<bool(string &, string &)> similar = [&](string &a, string &b) -> bool
        {
            int diff = 0;
            for (int i = 0; i < a.size(); ++i)
            {
                if (a[i] != b[i] && ++diff > 2)
                    return false;
            }
            return diff == 0 || diff == 2;
        };

        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                if (similar(strs[i], strs[j]))
                    dsu.unite(i, j);

        unordered_set<int> groups;
        for (int i = 0; i < n; i++)
            groups.insert(dsu.findParent(i));

        return groups.size();
    }
};