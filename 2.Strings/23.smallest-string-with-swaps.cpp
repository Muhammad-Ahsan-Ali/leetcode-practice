class Solution
{
private:
    vector<int> getComb(int u, vector<vector<int>> &connections, vector<bool> &visit)
    {
        stack<int> st;
        st.push(u);
        visit[u] = true;
        vector<int> comb;
        comb.push_back(u);

        while (!st.empty())
        {
            int cur = st.top();
            st.pop();

            for (auto adj : connections[cur])
            {
                if (!visit[adj])
                {
                    visit[adj] = true;
                    st.push(adj);
                    comb.push_back(adj);
                }
            }
        }

        return comb;
    }

public:
    string smallestStringWithSwaps(string s, vector<vector<int>> &pairs)
    {
        int v = s.length();
        vector<vector<int>> connections(v);

        for (auto pi : pairs)
        {
            connections[pi[0]].push_back(pi[1]);
            connections[pi[1]].push_back(pi[0]);
        }

        vector<vector<int>> combs;
        vector<bool> visit(v, false);

        for (int u = 0; u < v; u++)
        {
            if (!visit[u])
            {
                vector<int> comb = getComb(u, connections, visit);
                combs.push_back(comb);
            }
        }

        string output(v, ' ');

        for (auto comb : combs)
        {

            vector<char> charComb;

            for (auto i : comb)
                charComb.push_back(s[i]);

            sort(charComb.begin(), charComb.end());
            sort(comb.begin(), comb.end());

            for (int i = 0; i < comb.size(); i++)
                output[comb[i]] = charComb[i];
        }
        return output;
    }
};