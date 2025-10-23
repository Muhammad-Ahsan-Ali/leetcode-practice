class Solution
{
public:
    int numPairsDivisibleBy60(vector<int> &time)
    {
        unordered_map<int, int> mp;
        int cnt = 0;

        for (auto val : time)
        {
            int r = val % 60;
            cnt += mp[abs(60 - r) % 60];
            mp[val % 60]++;
        }
        return cnt;
    }
};