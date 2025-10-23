class Solution
{
public:
    int maximumWhiteTiles(vector<vector<int>> &tiles, int carpetLen)
    {
        int n = tiles.size();

        vector<pair<int, int>> ptiles;
        for (int i = 0; i < n; i++)
            ptiles.push_back({tiles[i][0], tiles[i][1]});

        sort(ptiles.begin(), ptiles.end());

        vector<long long> prefix;
        prefix.push_back(ptiles[0].second - ptiles[0].first + 1);

        for (int i = 1; i < n; i++)
            prefix.push_back(prefix.back() + ptiles[i].second - ptiles[i].first + 1);

        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            int curEnd = ptiles[i].first + carpetLen - 1;
            int idx = upper_bound(ptiles.begin(), ptiles.end(),
                                  make_pair(curEnd, INT_MAX)) -
                      ptiles.begin() - 1;

            int curCover = 0;
            if (idx >= 0 && ptiles[idx].first <= curEnd && curEnd <= ptiles[idx].second)
            {
                curCover += curEnd - ptiles[idx].first + 1;
                idx--;
            }

            if (idx >= i)
                curCover += prefix[idx] - (i > 0 ? prefix[i - 1] : 0);

            ans = max(curCover, ans);
        }
        return ans;
    }
};