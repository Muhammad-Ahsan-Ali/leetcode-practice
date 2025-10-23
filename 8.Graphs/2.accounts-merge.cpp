struct DSU
{
    vector<int> p;
    DSU() : p(26, -1) {};

    int findPrnt(int x) { return p[x] < 0 ? x : p[x] = findPrnt(p[x]); }

    void unite(int a, int b)
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

    bool contradicts(int a, int b) { return findPrnt(a) == findPrnt(b); }
};

class Solution
{
public:
    bool equationsPossible(vector<string> &equations)
    {

        DSU dsu;

        for (auto equation : equations)
            if (equation[1] == '=')
            {
                int a = equation[0] - 'a';
                int b = equation[3] - 'a';
                dsu.unite(a, b);
            }

        for (auto equation : equations)
            if (equation[1] == '!')
            {
                int a = equation[0] - 'a';
                int b = equation[3] - 'a';
                if (dsu.contradicts(a, b))
                    return false;
            }

        return true;
    }
};