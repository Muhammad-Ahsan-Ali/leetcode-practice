class Solution
{
    vector<int> prefix;
    int range = 0;

public:
    Solution(vector<int> &w)
    {
        for (int i = 0; i < w.size(); i++)
            if (i == 0)
                prefix.push_back(w[i]);
            else
                prefix.push_back(prefix.back() + w[i]);

        range = prefix.back();
    }

    int pickIndex()
    {
        int r = rand() % range + 1;
        int i = lower_bound(prefix.begin(), prefix.end(), r) - prefix.begin();
        return i;
    }
};