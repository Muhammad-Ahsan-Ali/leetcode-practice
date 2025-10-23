class Solution
{
public:
    string customSortString(string order, string s)
    {
        unordered_map<char, int> fq;
        for (auto &c : order)
            fq[c] = 0;

        for (auto &c : s)
            if (fq.find(c) != fq.end())
                fq[c]++;
        string ans;

        for (auto &c : order)
            ans.append(fq[c], c);

        for (auto &c : s)
            if (fq.find(c) == fq.end())
                ans.push_back(c);

        return ans;
    }
};